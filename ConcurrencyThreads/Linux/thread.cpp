#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <future>
using namespace std;
std::mutex _mu;
std::deque<int> processQueue;
std::condition_variable sleeper;
void ProcessCreator(int n, const char ch)
{
	while(n)
	{
		std::unique_lock<std::mutex> process_lock(_mu);
		processQueue.push_front(n);
		cout << endl << "Process Added by thread : " << ch << ", PID : " << n;
		process_lock.unlock();
		sleeper.notify_all();
		std::this_thread::sleep_for(chrono::seconds(2));
		n--;
	}
}
void ExecuteHandler(const char ch)
{
	int data = 0;
	while(data != 1)
	{
		std::unique_lock<std::mutex> process_queue_locker(_mu);
		sleeper.wait(process_queue_locker, [](){ return !processQueue.empty(); });
		data = processQueue.back();
		std::this_thread::sleep_for(chrono::seconds(1));
		processQueue.pop_back();
		cout <<  endl << "Process Executed by thread : " << ch << ", PID : " << data;
		process_queue_locker.unlock();
	}
}

int main()
{
	std::thread t1(ProcessCreator, 5, 'a');
	std::thread t2(ExecuteHandler, 'a');
	std::thread t3(ProcessCreator, 4, 'b');
	std::thread t4(ExecuteHandler, 'b');
	std::thread t5(ProcessCreator, 3, 'c');
	std::thread t6(ExecuteHandler, 'c');
	std::thread t7(ProcessCreator, 2, 'd');
	std::thread t8(ExecuteHandler, 'd');
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	cout << endl;
	return 0
}

/* Full mutex lock class */

/*
template <typename PARENT>
class LOCKABLE AnnotatedMixin : public PARENT
{
public:
    void lock() EXCLUSIVE_LOCK_FUNCTION()
    {
        PARENT::lock();
    }

    void unlock() UNLOCK_FUNCTION()
    {
        PARENT::unlock();
    }

    bool try_lock() EXCLUSIVE_TRYLOCK_FUNCTION(true)
    {
        return PARENT::try_lock();
    }
};

#ifdef DEBUG_LOCKORDER
void EnterCritical(const char* pszName, const char* pszFile, int nLine, void* cs, bool fTry = false);
void LeaveCritical();
std::string LocksHeld();
void AssertLockHeldInternal(const char* pszName, const char* pszFile, int nLine, void* cs) ASSERT_EXCLUSIVE_LOCK(cs);
void AssertLockNotHeldInternal(const char* pszName, const char* pszFile, int nLine, void* cs);
void DeleteLock(void* cs);
#else
void static inline EnterCritical(const char* pszName, const char* pszFile, int nLine, void* cs, bool fTry = false) {}
void static inline LeaveCritical() {}
void static inline AssertLockHeldInternal(const char* pszName, const char* pszFile, int nLine, void* cs) ASSERT_EXCLUSIVE_LOCK(cs) {}
void static inline AssertLockNotHeldInternal(const char* pszName, const char* pszFile, int nLine, void* cs) {}
void static inline DeleteLock(void* cs) {}
#endif
#define AssertLockHeld(cs) AssertLockHeldInternal(#cs, __FILE__, __LINE__, &cs)
#define AssertLockNotHeld(cs) AssertLockNotHeldInternal(#cs, __FILE__, __LINE__, &cs)

/**
 * Wrapped mutex: supports recursive locking, but no waiting
 * TODO: We should move away from using the recursive lock by default.
 */
class CCriticalSection : public AnnotatedMixin<std::recursive_mutex>
{
public:
    ~CCriticalSection() {
        DeleteLock((void*)this);
    }
};

/** Wrapped mutex: supports waiting but not recursive locking */
typedef AnnotatedMixin<std::mutex> CWaitableCriticalSection;

/** Just a typedef for std::condition_variable, can be wrapped later if desired */
typedef std::condition_variable CConditionVariable;

/** Just a typedef for std::unique_lock, can be wrapped later if desired */
typedef std::unique_lock<std::mutex> WaitableLock;

#ifdef DEBUG_LOCKCONTENTION
void PrintLockContention(const char* pszName, const char* pszFile, int nLine);
#endif

/** Wrapper around std::unique_lock<CCriticalSection> */
class SCOPED_LOCKABLE CCriticalBlock
{
private:
    std::unique_lock<CCriticalSection> lock;

    void Enter(const char* pszName, const char* pszFile, int nLine)
    {
        EnterCritical(pszName, pszFile, nLine, (void*)(lock.mutex()));
#ifdef DEBUG_LOCKCONTENTION
        if (!lock.try_lock()) {
            PrintLockContention(pszName, pszFile, nLine);
#endif
            lock.lock();
#ifdef DEBUG_LOCKCONTENTION
        }
#endif
    }

    bool TryEnter(const char* pszName, const char* pszFile, int nLine)
    {
        EnterCritical(pszName, pszFile, nLine, (void*)(lock.mutex()), true);
        lock.try_lock();
        if (!lock.owns_lock())
            LeaveCritical();
        return lock.owns_lock();
    }

public:
    CCriticalBlock(CCriticalSection& mutexIn, const char* pszName, const char* pszFile, int nLine, bool fTry = false) EXCLUSIVE_LOCK_FUNCTION(mutexIn) : lock(mutexIn, std::defer_lock)
    {
        if (fTry)
            TryEnter(pszName, pszFile, nLine);
        else
            Enter(pszName, pszFile, nLine);
    }

    CCriticalBlock(CCriticalSection* pmutexIn, const char* pszName, const char* pszFile, int nLine, bool fTry = false) EXCLUSIVE_LOCK_FUNCTION(pmutexIn)
    {
        if (!pmutexIn) return;

        lock = std::unique_lock<CCriticalSection>(*pmutexIn, std::defer_lock);
        if (fTry)
            TryEnter(pszName, pszFile, nLine);
        else
            Enter(pszName, pszFile, nLine);
    }

    ~CCriticalBlock() UNLOCK_FUNCTION()
    {
        if (lock.owns_lock())
            LeaveCritical();
    }

    operator bool()
    {
        return lock.owns_lock();
    }
};

#define PASTE(x, y) x ## y
#define PASTE2(x, y) PASTE(x, y)

#define LOCK(cs) CCriticalBlock PASTE2(criticalblock, __COUNTER__)(cs, #cs, __FILE__, __LINE__)
#define LOCK2(cs1, cs2) CCriticalBlock criticalblock1(cs1, #cs1, __FILE__, __LINE__), criticalblock2(cs2, #cs2, __FILE__, __LINE__)
#define TRY_LOCK(cs, name) CCriticalBlock name(cs, #cs, __FILE__, __LINE__, true)

#define ENTER_CRITICAL_SECTION(cs)                            \
    {                                                         \
        EnterCritical(#cs, __FILE__, __LINE__, (void*)(&cs)); \
        (cs).lock();                                          \
    }

#define LEAVE_CRITICAL_SECTION(cs) \
    {                              \
        (cs).unlock();             \
        LeaveCritical();           \
    }

class CSemaphore
{
private:
    std::condition_variable condition;
    std::mutex mutex;
    int value;

public:
    explicit CSemaphore(int init) : value(init) {}

    void wait()
    {
        std::unique_lock<std::mutex> lock(mutex);
        condition.wait(lock, [&]() { return value >= 1; });
        value--;
    }

    bool try_wait()
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (value < 1)
            return false;
        value--;
        return true;
    }

    void post()
    {
        {
            std::lock_guard<std::mutex> lock(mutex);
            value++;
        }
        condition.notify_one();
    }
};

/** RAII-style semaphore lock */
class CSemaphoreGrant
{
private:
    CSemaphore* sem;
    bool fHaveGrant;

public:
    void Acquire()
    {
        if (fHaveGrant)
            return;
        sem->wait();
        fHaveGrant = true;
    }

    void Release()
    {
        if (!fHaveGrant)
            return;
        sem->post();
        fHaveGrant = false;
    }

    bool TryAcquire()
    {
        if (!fHaveGrant && sem->try_wait())
            fHaveGrant = true;
        return fHaveGrant;
    }

    void MoveTo(CSemaphoreGrant& grant)
    {
        grant.Release();
        grant.sem = sem;
        grant.fHaveGrant = fHaveGrant;
        fHaveGrant = false;
    }

    CSemaphoreGrant() : sem(nullptr), fHaveGrant(false) {}

    explicit CSemaphoreGrant(CSemaphore& sema, bool fTry = false) : sem(&sema), fHaveGrant(false)
    {
        if (fTry)
            TryAcquire();
        else
            Acquire();
    }

    ~CSemaphoreGrant()
    {
        Release();
    }

    operator bool() const
    {
        return fHaveGrant;
    }
};
*/
