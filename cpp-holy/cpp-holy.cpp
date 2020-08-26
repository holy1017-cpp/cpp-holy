// cpp-holy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int cinInt();
char* cinChar();

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Hello World!" << std::endl;
    int a = 1, b = 0;
    if (a>b)
    {
        cout<< a<<endl;
    }
    else
    {
        cout<< b<<endl;
    }
    //------------------------------
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

    //------------------------------
    cout << "cinInt:" << cinInt() << endl;
    cout << "cinChar:" << cinChar() << endl;

    return 0;
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
    char s[1024]="";

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

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
