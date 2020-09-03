#include <string>

#include "functionEx.h"


namespace functionEx {
	void test()
	{
		{
			int i = 5;
			cout << "functionEx.i=" << i << endl;
			fc1(i);
			cout << "functionEx.i=" << i << endl;	
			fc2(i);
			cout << "functionEx.i=" << i << endl;
		}
	}
	void test3()
	{
		ex e;
		e.x = 4;
		e.y = 5;
		fc3(e);
	}

	void test4()
	{
		fc4();
		fc4('g');
		fc4(65);
		fc4('6',87);
	}

	void testswap()
	{
		int a = 5, b=3;
		swap(a, b);
		cout << "a:" << a <<",b:"<< b << endl;
	}

	void fc1(int i)
	{
		i = 9;
	}
	void fc2(int& i)
	{
		i = 9;
	}

	void fc3(const ex& e) {
		cout << "functionEx.fc3.x=" << e.x << endl;
		cout << "functionEx.fc3.y=" << e.y << endl;
	}
	void fc4(char c, int i)
	{
		cout << "functionEx.fc4.c=" << c << endl;
		cout << "functionEx.fc4.i=" << i << endl;
	}
	void swap(int& a, int& b)
	{
		int v = a;
		a = b;
		b = v;
	}



    void StPrint(St& st)
    {
        cout << "a:" << st.a << endl;
        cout << "b:" << st.b << endl;
        cout << "c:" << st.c << endl;
        cout << "d:" << st.d << endl;
    }

    void StAdd(St& o, St& a)
    {
        o.a += a.a;
        o.b += a.b;
        //strcat_s(o.c, a.c);//오류
        o.d += a.d;

        stcp(o.c, a.c);
    }

    void stcp(char* o,const char* a ,int m)
    {
        int io = strlen(o), ia = strlen(a);
        cout << "o:" << io << endl;
        cout << "a:" << ia << endl;

        int i = 0;
        for (; io + i < (io + ia >= m ? m : io + ia) - 1; i++)
        {
            cout << "o:" << o[io + i];
            cout << "a:" << a[i] << endl;
            o[io + i] = a[i];
        }
        o[io + i] = 0;
    }


    void StAdd(St& o, int a)
    {
        o.a += a;
        o.b += a;
        //strcat_s(o.c, a);
        o.d += a;
    }

    void testStPrint()
    {
        St s;
        s.a = 5;
        s.b = 4;
        //s.c = "bweertg";// 사용 불가
        //strcpy(s.c, "bweertg");//보안이슈로 아래로 변경
        strcpy_s(s.c, "kjrt");//보안이슈로 변경
        s.d = 7;

        StPrint(s);
    }

    void testStPrint2()
    {
        St s, s2;
        s.a = 5;
        s.b = 4;
        //s.c = "bweertg";// 사용 불가
        //strcpy(s.c, "bweertg");//보안이슈로 아래로 변경
        strcpy_s(s.c, "asdfqwer");//보안이슈로 변경
        s.d = 7;

        s2.a = 2;
        s2.b = 3;
        strcpy_s(s2.c, "zxcv");//보안이슈로 변경
        s2.d = 4;

        StAdd(s, s2);

        StPrint(s);     
    }



    void testStPrint3()
    {
        St s;
        s.a = 5;
        s.b = 4;
        //s.c = "bweertg";// 사용 불가
        //strcpy(s.c, "bweertg");//보안이슈로 아래로 변경

        string t = "subb12515uff";
        //strcpy_s(s.c, stcut(t));//보안이슈로 변경. 자리수 조심 끝은 무조간 0
        strcpy_s(s.c, (t.substr(0, cmax - 1)).c_str());//보안이슈로 변경. 자리수 조심 끝은 무조간 0
        //s.c=(t.substr(0, cmax - 1)).c_str();// 안됨
        s.d = 7;

        StPrint(s);

        StAdd(s, 3);

        StPrint(s);
    }

    inline const char* stcut(std::string& t) // inline  안먹힌다
    {
        return (t.substr(0, cmax - 1)).c_str(); // 결국 함수 나가면서 값 날라감
    }



    void testStPrint4()
    {
        St s = StSet(35, 23, "fadg", 75);

        StPrint(s);
    }

    void StSet(St& s, int a, int b, const char* c, int d) {
        s.a = a;
        s.b = b;
        //s.c = "bweertg";// 사용 불가
        //strcpy(s.c, "bweertg");//보안이슈로 아래로 변경
        strcpy_s(s.c, c);//보안이슈로 변경
        s.d = d;
    }

    St StSet(int a, int b, const char* c, int d) {
        St s;
        s.a = a;
        s.b = b;
        //s.c = "bweertg";// 사용 불가
        //strcpy(s.c, "bweertg");//보안이슈로 아래로 변경
        strcpy_s(s.c, c);//보안이슈로 변경
        s.d = d;
        return s;
    }
}