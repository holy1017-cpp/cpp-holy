#include "varEx.h"

namespace varEx {

    class CTest {
    public:
        CTest add(const CTest c) {
            CTest d;
            return d;
        }
    };

    void test2() {
        {
            // ����

            // l-value ����

            CTest t1;
            CTest& t2 = t1;
            //int& a = 10; // ����
            const int& b = 20;


            // r-value ����

            int&& c = 30;
            CTest&& t3 = t1.add(t2);
            //CTest&& t4 = t1; // error
            cout << &t3 << endl;
            cout << c << endl;
        }
    }

    void test()
    {



        {
            int �ѱ� = 4560; // C++11
            int ��(2354);
            int �� = { 37 };
            auto v = 10; // C++11 �ڷ��� �ڵ� ó��
            std::cout << �ѱ� << "\n";
            std::cout << �� << "\n";
            std::cout << �� << "\n";
            std::cout << 10 << "\n";
            try
            {
                short x = ��;// ���� �ȳ���
                std::cout << x << "\n";
            }
            catch (const std::exception& e)
            {
                std::cout << "����:" << e.what() << "\n";
            }
            try
            {
                float x = ��;
                std::cout << x << "\n";
            }
            catch (const std::exception& e)
            {
                std::cout << "����:" << e.what() << "\n";
            }
        }

        {
            int v;
            v = 15;//
            std::cout << v << "\n";
            v = 0b1010;//2��
            std::cout << v << "\n";
            v = 023;//8��
            std::cout << v << "\n";
            v = 0x2f;//16��
            std::cout << v << "\n";
        }
        {
            long long l;
            l = 321;
            std::cout << l << "\n";
            l = 321u;//unsigned
            std::cout << l << "\n";
            l = 321L;//long
            std::cout << l << "\n";
            l = 321uL;//unsigned long
            std::cout << l << "\n";
            l = 321ll;//long long
            std::cout << l << "\n";
        }
        {
            std::cout << 'A' << "\n";//ASC2
            std::cout << '\101' << "\n";//8��
            std::cout << '\x41' << "\n";//16��
        }
        {
            std::cout << 12. << "\n";// ����
            std::cout << 12.0 << "\n";// ����
            std::cout << 12e0 << "\n";// ����
            std::cout << 1.2e+3 << "\n";// ����

            std::cout << 12.0f << "\n";//
            std::cout << 12e2f << "\n";//
        }

        std::cout << "Hello World!\n";
        std::cout << "Hello World!" << std::endl;
    }

}