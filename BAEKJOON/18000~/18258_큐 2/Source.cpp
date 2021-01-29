#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int nSize;
	cin >> nSize;
	string strCommand;
	queue<int> qu;
	for (int i = 0; i < nSize; i++)
	{
		cin >> strCommand;

		if (strCommand == "push")
		{
			int input;
			cin >> input;
			qu.push(input);
		}
		if (strCommand == "pop")
		{
			if (qu.empty())
				cout << -1 << '\n';
			else
			{
				cout << qu.front() << '\n';
				qu.pop();
			}			
		}
		if (strCommand == "size")
		{
			cout << qu.size() << '\n';
		}
		if (strCommand == "empty")
		{
			cout << qu.empty() << '\n';
		}
		if (strCommand == "front")
		{
			if (qu.empty())
				cout << -1 << '\n';
			else
				cout << qu.front() << '\n';
		}
		if (strCommand == "back")
		{
			if (qu.empty())
				cout << -1 << '\n';
			else
				cout << qu.back() << '\n';
		}
	}

	system("pause");

	return 0;
}