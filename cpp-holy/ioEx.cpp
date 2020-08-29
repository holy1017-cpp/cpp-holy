#pragma once
#include <iostream>
#include "ioEx.h"
using namespace std;

namespace ioEx {

    template <typename T>
    void out(T t)
    {
        cout << t << endl;
    }

    int cinInt() {
        int retNum;

        cout << "Enter int: ";
        cin >> retNum;

        // 잘못된 입력을 받았을 경우
        if (cin.fail()) {
            cout << "Wrong cinInt. Retry!" << endl; // 에러 메시지 출력
            cin.clear(); // 오류스트림을 초기화
            cin.ignore(256, '\n'); // 입력버퍼를 비움
            return cinInt(); // 함수를 재호출한다
        }
        return retNum;
    }


    char* cinChar() {
        char s[1024] = "";

        cout << "Enter char: ";
        cin >> s;

        // 잘못된 입력을 받았을 경우
        if (cin.fail()) {
            cout << "Wrong cinChar. Retry!" << endl; // 에러 메시지 출력
            cin.clear(); // 오류스트림을 초기화
            cin.ignore(256, '\n'); // 입력버퍼를 비움
            return cinChar(); // 함수를 재호출한다
        }
        return s;
    }

    void test() {
        int i;
        char s[1024];
        cout << "Enter : ";
        cin >> i >> s;
        if (cin.fail())
            cout << "Wrong input." << endl; // 에러 메시지 출력
        else
        {
            cout << "i:" << i << endl;
            cout << "s:" << s << endl;
        }
        cin.clear(); // 오류스트림을 초기화
        cin.ignore(256, '\n'); // 입력버퍼를 비움

    }
        //------------------------------
     void test2(){
            cout << "cinInt:" << ioEx::cinInt() << endl;
            cout << "cinChar:" << ioEx::cinChar() << endl;
        }

}