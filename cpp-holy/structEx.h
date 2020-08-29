#pragma once

#ifndef structRx_H
#define structRx_H

#include <iostream>

using namespace std;

namespace structRx {
	struct Ex {
		double x, y;
		int i;
		char c;
	};

	double xy(Ex e);

	void test();
}

#endif