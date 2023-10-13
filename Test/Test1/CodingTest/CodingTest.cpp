// CodingTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	auto test = [](int x, int y) {
		return x + y;
	};

	//cout << test(10, 20) << endl;
	{
		vector<int> a;
		cout << sizeof(a) << endl;
	}
	{
		list<int> a;
		cout << sizeof(a) << endl;
	}
	{
		queue<int> a;
		cout << sizeof(a) << endl;
	}
	{
		priority_queue<int> a;
		cout << sizeof(a) << endl;
	}
	{
		stack<int> a;
		cout << sizeof(a) << endl;
	}
	{
		set<int> a;
		cout << sizeof(a) << endl;
	}
	{
		map<int,int> a;
		cout << sizeof(a) << endl;
	}

	system("pause");


    return 0;
}

