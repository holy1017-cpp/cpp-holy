#pragma once
#include <exception>
#include <iostream>
#include "exceptionEx.h"

using namespace std;


char const* exceptionEx::myException::what() const
{
    return "Unknown exception";
}

void exceptionEx::test() {   // ����ó��
    try
    {
        throw myException();
    }
    catch (exception& e)
    {
        std::cout << "myException:" << e.what() << "\n";
    }
}

