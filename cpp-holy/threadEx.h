#pragma once

#ifndef threadEx_H
#define threadEx_H

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;
using std::thread;
using std::vector;

namespace threadEx {
	void test();
	void worker();
	void worker(int& result, std::mutex& m);
	void worker(vector<int>::iterator start, vector<int>::iterator end,
		int* result);
	void test2();
	void testMutex();
	void testMutex1();
	void testMutex2();
}

#endif