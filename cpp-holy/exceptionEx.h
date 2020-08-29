#pragma once
#include <exception>

using namespace std;

namespace exceptionEx {
	class myException : public exception
	{
		virtual char const* what() const;
	} me;

	void test();
}