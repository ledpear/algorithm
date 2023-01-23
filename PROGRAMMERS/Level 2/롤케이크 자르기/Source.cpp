#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

#include <set>
using namespace std;


int solution(vector<int> topping) 
{
	int answer = 0;
	//�߶��� �� ��ġ�� �������� ���ʿ� ���� ������ ���Ѵ�
	//���� �ʵ� ���Ѵ�(�� �ں��� Ž���ؾ���)
	//1���̳��� ���ϸ鼭 ���� ���̸� �ȴ�
	const int size = topping.size();
	//���� ���� ����
	vector<int> left = vector<int>(size, 0);
	{
		set<int> log;
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			if (log.find(topping.at(i)) == log.end())
			{
				++count;
				log.insert(topping.at(i));
			}
			left.at(i) = count;
		}
	}
	
	{
		set<int> log;
		int count = 0;
		for (int i = size - 1; i > 0; --i)
		{
			if (log.find(topping.at(i)) == log.end())
			{
				++count;
				log.insert(topping.at(i));
			}

			if(left[i - 1] == count)
				++answer;
		}
	}

	return answer;
}

int main()
{
	return 0;
}