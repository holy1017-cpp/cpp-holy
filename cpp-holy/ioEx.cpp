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

        // �߸��� �Է��� �޾��� ���
        if (cin.fail()) {
            cout << "Wrong cinInt. Retry!" << endl; // ���� �޽��� ���
            cin.clear(); // ������Ʈ���� �ʱ�ȭ
            cin.ignore(256, '\n'); // �Է¹��۸� ���
            return cinInt(); // �Լ��� ��ȣ���Ѵ�
        }
        return retNum;
    }


    char* cinChar() {
        char s[1024] = "";

        cout << "Enter char: ";
        cin >> s;

        // �߸��� �Է��� �޾��� ���
        if (cin.fail()) {
            cout << "Wrong cinChar. Retry!" << endl; // ���� �޽��� ���
            cin.clear(); // ������Ʈ���� �ʱ�ȭ
            cin.ignore(256, '\n'); // �Է¹��۸� ���
            return cinChar(); // �Լ��� ��ȣ���Ѵ�
        }
        return s;
    }

    void test() {
        int i;
        char s[1024];
        cout << "Enter : ";
        cin >> i >> s;
        if (cin.fail())
            cout << "Wrong input." << endl; // ���� �޽��� ���
        else
        {
            cout << "i:" << i << endl;
            cout << "s:" << s << endl;
        }
        cin.clear(); // ������Ʈ���� �ʱ�ȭ
        cin.ignore(256, '\n'); // �Է¹��۸� ���

    }
        //------------------------------
     void test2(){
            cout << "cinInt:" << ioEx::cinInt() << endl;
            cout << "cinChar:" << ioEx::cinChar() << endl;
        }

}