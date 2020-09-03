#pragma once
#include <vector>

#include "forWhileEx.h"

void forWhile::testFor()
{
    {
        // The counter variable can be declared in the init-expression.
        for (int i = 0; i < 2; i++) {
            cout << i;
        }
        // Output: 01

        // The counter variable can be declared outside the for loop.
        int i;
        for (i = 0; i < 2; i++) {
            cout << i;
        }
        // Output: 01
        // These for loops are the equivalent of a while loop.
        i = 0;
        while (i < 2) {
            cout << i++;
        }
        // Output: 01
    }
    {
        int i, j;
        for (i = 5, j = 10; i + j < 20; i++, j++) {
            cout << "i + j = " << (i + j) << '\n';
        }

        for (int i = 10; i > 0; i--) {
            cout << i << ' ';
        }
        // Output: 10 9 8 7 6 5 4 3 2 1

        for (int i = 10; i < 20; i = i + 2) {
            cout << i << ' ';
        }
    }
    {
        int i;
        for (i = 0; i < 5; cout << i << '\n', i++) {
            ;
        }
    }
}

void forWhile::testForRang()
{
    // Basic 10-element integer array.
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Range-based for loop to iterate through the array.
    for (int y : x) { // Access by value using a copy declared as a specific type.
                       // Not preferred.
        cout << y << " ";
    }
    cout << endl;

    // The auto keyword causes type inference to be used. Preferred.

    for (auto y : x) { // Copy of 'x', almost always undesirable
        cout << y << " ";
    }
    cout << endl;

    for (auto& y : x) { // Type inference by reference.
        // Observes and/or modifies in-place. Preferred when modify is needed.
        cout << y << " ";
    }
    cout << endl;

    for (const auto& y : x) { // Type inference by const reference.
        // Observes in-place. Preferred when no modify is needed.
        cout << y << " ";
    }
    cout << endl;
    cout << "end of integer array test" << endl;
    cout << endl;

    // Create a vector object that contains 10 elements.
    vector<double> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i + 0.14159);
    }

    // Range-based for loop to iterate through the vector, observing in-place.
    for (const auto& j : v) {
        cout << j << " ";
    }
    cout << endl;
    cout << "end of vector test" << endl;
}

void forWhile::testForRang2()
{
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int r = 0;
    for (auto a : x) { // Copy of 'x', almost always undesirable
        cout << a << " " << &a << endl;        
        a++;
        cout << a << " " << &a << endl;        
        cout << x[r] << " " << &x[r] <<endl; // &x[r++] 라고는 적지 말기
        r++;
        cout << "---" <<endl;
    }    
    r = 0;
    for (auto& a : x) { // 주소값을 저장. x값도 편집 가능
        cout << a << " " << &a << endl;
        a++;
        cout << a << " " << &a << endl;
        cout << x[r] << " " << &x[r]<< endl;// &x[r++] 라고는 적지 말기
        r++;
        cout << "---" <<endl;
    }
}

void forWhile::testWhile()
{
    {
        int i = 0;
        do
        {
            printf_s("\n%d", i++);
        } while (i < 3);
    }
}

void forWhile::testTrim()
{
    char szbuf[] = "12345_____";

    printf_s("\nBefore trim: %s", szbuf);
    printf_s("\nAfter trim: %s\n", trim(szbuf));
}

char* forWhile::trim(char* szSource)
{
    char* pszEOS = 0;

    //  Set pointer to character before terminating NULL
    pszEOS = szSource + strlen(szSource) - 1;

    //  iterate backwards until non '_' is found
    while ((pszEOS >= szSource) && (*pszEOS == '_'))
        *pszEOS-- = '\0';

    return szSource;
}
