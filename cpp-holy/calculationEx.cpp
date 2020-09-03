#include <cmath>
#include "calculationEx.h"

double calculationEx::Round(double x, int d)
{
	double a = x >= 0 ? 0.5 : -0.5;
	double p = pow(10, d);
	return trunc(x*p+a)/p;
}
