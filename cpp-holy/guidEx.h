#pragma once

#ifndef guidEx_H
#define guidEx_H

#include <iostream>
#include <Rpc.h>
#pragma comment(lib, "Rpcrt4.lib")

using namespace std;

namespace guidEx {

	class CGUID {

		UUID uuid;
		RPC_STATUS ret_val;
		wstring s;

	public:
		CGUID();

		void print();
		void printn();
	};

	void test();
}

#endif