#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
#include <queue>

vector<int> solution(vector<int> numbers) 
{
	//��ȸ�ϸ鼭 max���� ����Ѵ�
	//queue�� ���������� �ִ´�
	vector<int> answer;
	// 0: ���� 1: �� ū��
	deque<vector<int>> q;
	int index = numbers.size() - 1;
	int max = 0;
	for (index; index >= 0; --index)
	{
		//�ִ��� ������ �۰ų� ������ ������ -1
		int num = numbers[index];
		if (max <= num)
		{
			q.push_front(vector<int>{num, -1});
			if (max < num)
				max = num;

			continue;
		}

		//ť�� ��ȸ
		for (vector<int> backNum : q)
		{
			//�ڿ� ���� ������ ũ�ų�
			if ( num < backNum[0])
			{
				q.push_front(vector<int>{num, backNum[0]});
				if (max < backNum[0])
					max = backNum[0];

				break;
			}

			//������ ������ �� ū���� �� Ŭ��
			if (num < backNum[1])
			{
				q.push_front(vector<int>{num, backNum[1]});
				if (max < backNum[1])
					max = backNum[1];

				break;
			}
		}		
	}

	for (vector<int> backNum : q)
	{
		answer.push_back(backNum[1]);
	}

	return answer;
}

int main()
{
	vector<int> a;
	{
		a = solution(vector<int>{2, 3, 3, 5});
	}
	{
		a = solution(vector<int>{9,1,5,3,6,2});
	}
	return 0;
}