#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

int Min(int A, int B) { if (A < B) return A; return B; }

//custum function
bool lines[32][12];
int size_x, size_y, maxVal;
bool answer_find;

bool Run()
{
	for (int line(1); line <= size_y; ++line)
	{
		int target = line;
		for (int x(1); x <= size_x; ++x)
		{
			if (lines[x][line-1])
			{
				--line;
			}
			else if (lines[x][line])
			{
				++line;
			}
		}
		if (target != line)
		{
			return false;
		}
	}
	return true;
}

void BT(int count, int StartX)
{
	if (count >= 4)
	{
		return;
	}

	if (Run())
	{
		maxVal = min(maxVal, count);
		return;
	}

	for (int x(StartX); x <= size_x; ++x)
	{
		for (int y(1); y <= size_y; ++y)
		{
			if(lines[x][y - 1])
				continue;
			if(lines[x][y + 1])
				continue;
			if(lines[x][y])
				continue;

			lines[x][y] = true;
			BT(count + 1, x);
			lines[x][y] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//찾은 카운트보다 커지면 종료
	//더 낮은 카운트로 찾으면 갱신
	//Declaration
	int size_line(0);
	cin >> size_y >> size_line >> size_x;

	int x(0), y(0);
	for (int i(0); i < size_line; ++i)
	{
		cin >> x >> y;
		lines[x][y] = true;
	}

	//Solution
	maxVal = 4;
	answer_find = false;
	BT(0, 1);	

	//Output
	if (maxVal == 4)
	{
		cout << "-1\n";
	}
	else
	{
		cout << maxVal << '\n';
	}

	////////////////////////////////////
	system("pause");
	return 0;
}