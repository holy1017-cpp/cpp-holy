﻿// cpp-holy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#pragma once //비공식 헤더 중복 제거

#include <iostream>
#include <exception>
#include "stdioEx.h"
#include "exceptionEx.h"
#include "constEx.h"
#include "ioEx.h"
#include "forWhileEx.h"
#include "structEx.h"
#include "pointerEx.h"
#include "functionEx.h"
#include "inputWhileEx.h"
#include "threadEx.h"
#include "functionEx.h"
#include "varEx.h"
#include "classEx.h"
#include "guidEx.h"



//#define PI 3.14159 // 이렇게는 하지 말자

using namespace std;



int main()
{
    {   

        //varEx::test2();

        classEx::test();

        //guidEx::test();

        //functionEx::testStcut();
        //functionEx::testStPrint();
        //functionEx::testStPrint2();
        //functionEx::testStPrint3();
        //functionEx::testStPrint4();
        //functionEx::testswap();
        //threadEx::test();
        //threadEx::test2();
        //threadEx::testMutex();
        //inputWhileEx::test();
        //functionEx::test();
        //functionEx::test3();
        //functionEx::test4();
        //pointerEx::testPointer();
        //pointerEx::testArr2();
        //structRx::test();
        //constEx::f(7); // 정상
        //stdioEx::test();//정상
        //forWhile::testFor();
        //forWhile::testForRang();
        //forWhile::testForRang2();
        //forWhile::testTrim();
        //exceptionEx::test();
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
