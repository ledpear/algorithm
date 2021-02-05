#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int TestSize;
	cin >> TestSize;

	for (int nTest = 0; nTest < TestSize; nTest++)
	{
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int posX = 0, posY = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'U')
			{
				if (y > posY)
					posY++;
			}
			if (s[i] == 'D')
			{
				if (y < posY)
					posY--;
			}
			if (s[i] == 'R')
			{
				if (x > posX)
					posX++;
			}
			if (s[i] == 'L')
			{
				if (x < posX)
					posX--;
			}

			if (x == posX && y == posY)
				break;
		}

		if (x == posX && y == posY)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	system("pause");

	return 0;
}