#pragma once

#ifndef exceptionEx_H
#define exceptionEx_H

#include <exception>

using namespace std;

namespace exceptionEx {
	class myException : public exception
	{
		virtual char const* what() const;
	} ;

	void test();
}

#endif