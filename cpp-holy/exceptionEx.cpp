#include <exception>
#include <iostream>
#include "exceptionEx.h"

using namespace std;

namespace exceptionEx {
    char const* myException::what() const
    {
        return "Unknown exception";
    }

    void test() {   // ����ó��
        try
        {
            throw me;
        }
        catch (exception& e)
        {
            std::cout << "myException:" << e.what() << "\n";
        }
    }
}
