// cpp-holy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <exception>
#include "stdioEx.h"
#include "exceptionEx.h"
#include "constEx.h"
#include "ioEx.h"

//#define PI 3.14159 // 이렇게는 하지 말자

using namespace std;



namespace my {
    int c = 4;
}

int main()
{
    {
        constEx::f(7);
        //stdioEx::test();//정상
    }
    {
        static_cast<int>(5 / 10.0);
    }



    {
        int 한글 = 4560; // C++11
        int 값(2354);
        int ㄱ = { 37 }; 
        auto v = 10; // C++11 자료형 자동 처리
        std::cout << 한글 << "\n";
        std::cout << 값 << "\n";
        std::cout << ㄱ << "\n";
        std::cout << 10 << "\n";
        try
        {
            short x = ㄱ;// 오류 안나네
            std::cout << x << "\n";
        }
        catch (const std::exception& e)
        {
            std::cout << "오류:" << e.what() << "\n";
        }        
        try
        {
            float x = 값;
            std::cout << x << "\n";
        }
        catch (const std::exception& e)
        {
            std::cout << "오류:" << e.what() << "\n";
        }
    }

    {
        int v;
        v = 15;//
        std::cout << v << "\n";
        v = 0b1010;//2진
        std::cout << v << "\n";
        v = 023;//8진
        std::cout << v << "\n";
        v = 0x2f;//16진
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
        std::cout << '\101' << "\n";//8진
        std::cout << '\x41' << "\n";//16진
    }
    {
        std::cout << 12. << "\n";// 더블
        std::cout << 12.0 << "\n";// 더블
        std::cout << 12e0 << "\n";// 더블
        std::cout << 1.2e+3 << "\n";// 더블

        std::cout << 12.0f << "\n";//
        std::cout << 12e2f << "\n";//
    }

    std::cout << "Hello World!\n";
    std::cout << "Hello World!" << std::endl;
    {
        int b = 0;
        if (my::c > b)
        {
            cout << my::c << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    //------------------------------

    //------------------------------
    {
        cout << "cinInt:" << ioEx::cinInt() << endl;
        cout << "cinChar:" << ioEx::cinChar() << endl;
    }
    return 0;
}

// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
