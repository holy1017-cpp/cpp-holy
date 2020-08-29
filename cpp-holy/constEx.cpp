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
            const int v = ioEx::cinInt();//�Է¹��� ������ ��� �ʱ�ȭ ����
            std::cout << "v:" << v << "\n";
            try
            {
                constexpr int c = 31 + 85;//�����Ͻÿ� �ʱ�ȭ
                std::cout << "c:" << c << "\n";
            }
            catch (exception& e)
            {
                std::cout << "c ����:" << e.what() << "\n";
            }
        }

        {
            const double PI{ 3.14159 };
            try
            {
                //PI = 1234;//������ ����
            }
            catch (exception& e)
            {
                std::cout << "����:" << e.what() << "\n";
            }
        }
    }
}