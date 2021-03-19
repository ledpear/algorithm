#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;
using job = vector<int>;

enum eJob
{
	eEmpty = -1,
	eInput = 0,
	eRun
};

//custum function
struct HeapCompare
{
	bool operator()(job a, job b)	//
	{
		if (a[1] == b[1])
			return a[0] > b[0];
		else
			return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	
	int answer = 0;

	priority_queue<job, vector<job>, HeapCompare> pqScheduler;
	job vNowSchedul(0);
	int nJobOrder(0), nMS(0), nJobSize(jobs.size()), nSum(0);
	sort(jobs.begin(), jobs.end());

	while (true)
	{
		//�۾� �߰�
		if (nJobOrder != nJobSize)
		{
			while (true)//�ش� ms�� �۾��� ���� �� ���� �߰�
			{
				if (nJobOrder == nJobSize)	//������ ũ��� �������� ��ȯ
				{
					break;
				}

				const vector<int> vJob = jobs[nJobOrder];

				if (nMS < vJob[eInput] )	//�ش�ð��� �۾��� ������ ��ȯ
				{
					break;
				}

				pqScheduler.push(vJob);
				++nJobOrder;
			}
		}

		if (pqScheduler.empty() == false)// ��⿭�� �۾��� ������ �߰�
		{
			vNowSchedul = pqScheduler.top();
			int nSchedulEndTime = nMS + vNowSchedul[eRun];

			pqScheduler.pop();

			//����ð� �ջ�
			nSum += nSchedulEndTime - vNowSchedul[eInput];

			//�ð� ����
			nMS = nSchedulEndTime;

			//�ʱ�ȭ
			vNowSchedul.clear();
		}
		else if (nJobOrder != nJobSize)//��⿭�� �۾��� ���� ���� �������� ���� �۾��� ������ �ð� ����
		{
			const vector<int> vJob = jobs[nJobOrder];
			nMS = vJob[eInput];
		}
		else
		{
			break;
		}
	}
	answer = nSum / nJobSize;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration

	//Solution
	cout << solution(vector<vector<int>>{ {0, 3}, { 1,9 }, { 2, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {0, 3}, { 0,9 }, { 0, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {8, 3}, { 3,9 }, { 2, 6 } }) << '\n';
	cout << solution(vector<vector<int>>{ {0, 3}, { 1,9 }, { 2, 6 } }) << '\n';

	//Output


	////////////////////////////////////
	system("pause");
	return 0;
}