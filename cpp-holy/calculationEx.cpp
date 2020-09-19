#include <cmath>
#include "calculationEx.h"
#include <iostream>


using namespace std;

namespace calculationEx {

    double Round(double x, int d)
    {
        double a = x >= 0 ? 0.5 : -0.5;
        double p = pow(10, d);
        return trunc(x * p + a) / p;
    }


    void test(){
        double a = 12, b = 3, c = 4, d = ++c + ++a;
        cout << a << endl;
        cout << b << endl;
        cout << c << endl;
        cout << d << endl;
    }
}