#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

class cPQ
{
public:
	cPQ() 
	{
	}
	void push(int num) 
	{
		vArr.push_back(num);
		int pos, P_pos;
		pos = vArr.size() - 1;
		while (pos != 0)
		{
			int log = log2(pos + 1);
			P_pos = pow(2, log) - 2;
			if (vArr[pos] < vArr[P_pos])
			{
				int temp = vArr[pos];
				vArr[pos] = vArr[P_pos];
				vArr[P_pos] = temp;

				sort(pos, P_pos + 1);

				pos = P_pos;
			}
			else
			{
				sort(pos, P_pos + 1);
				break;
			}
		}
	}
	int mid()
	{
		return vArr[(vArr.size() - 1) / 2];
	}
	
private:
	void sort(int pos, int range)
	{
		int nVal = vArr[pos];
		while (true)
		{
			if (range == pos)
			{
				vArr[range] = nVal;
				break;
			}
			else if (vArr[pos - 1] > nVal)
			{
				vArr[pos] = vArr[pos - 1];
				pos--;
			}
			else
			{
				vArr[pos] = nVal;
				break;
			}
		}
	}

	vector<int> vArr;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int nSize, nTemp;
	cin >> nSize;
	//priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> vArr;
// 	cin >> nTemp;
// 	vArr.push_back(nTemp);

	cPQ cpq;
	for (int i = 0; i < nSize; i++)
	{
		cin >> nTemp;

		cpq.push(nTemp);


		cout << cpq.mid() << '\n';
	}
	system("pause");
	return 0;
}