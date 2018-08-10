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

