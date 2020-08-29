#pragma once

#include <iostream>
#include <exception>
#include "constEx.h"
#include "ioEx.h"

using namespace std;

namespace constEx {

    constexpr int fac(int n) {
        return n > 1 ? n * fac(n - 1) : 1;
    }

    void f(int x) {
        constexpr int a = fac(4);
        int b = fac(x);
        std::cout << "fac a:"<<a << "\n";//
        std::cout << "fac b:"<<b << "\n";//
    }

    void test() {
        {
            const int v = ioEx::cinInt();//입력받은 값으로 상수 초기화 가능
            std::cout << "v:" << v << "\n";
            try
            {
                constexpr int c = 31 + 85;//컴파일시에 초기화
                std::cout << "c:" << c << "\n";
            }
            catch (exception& e)
            {
                std::cout << "c 오류:" << e.what() << "\n";
            }
        }

        {
            const double PI{ 3.14159 };
            try
            {
                //PI = 1234;//컴파일 에러
            }
            catch (exception& e)
            {
                std::cout << "오류:" << e.what() << "\n";
            }
        }
    }
}