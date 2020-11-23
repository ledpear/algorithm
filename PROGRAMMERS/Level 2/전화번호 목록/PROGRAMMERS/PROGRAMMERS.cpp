// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool size_sort(string a, string b)
{
	return a.size() < b.size();
}

int main()
{
	vector<string> phone_book;
	phone_book.push_back("12");
	phone_book.push_back("123");
	phone_book.push_back("1235");
	phone_book.push_back("567");
	phone_book.push_back("88");

	sort(phone_book.begin(), phone_book.end(), size_sort);
	int nSize = 0;
	string strTemp = "";

	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		nSize = phone_book[i].size();

		for (int j = i + 1; j < phone_book.size(); j++)
		{
			strTemp = phone_book[j].substr(0, nSize);
			if (phone_book[i] == strTemp)
				return true;
		}
	}

	return false;
}

