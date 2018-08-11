#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include <deque>
#include <chrono>
#include <thread>
#include <condition_variable>
#include <future>
using namespace std;
int ComputeSum(std::future<pair<int,int> > &_future_value)
{
	auto p = _future_value.get();
	cout <<  p.first + p.second << endl;
	return 0;
}
int main(void)
{
	std::promise< pair<int,int> > _promise;
	std::future< pair<int,int> > _future_value = _promise.get_future();
	std::thread WorkerThread(ComputeSum, std::ref(_future_value));
	_promise.set_value(std::make_pair(10, 58));
	WorkerThread.join();
	return 0;
}
