#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int solution(int a, int b, int n) 
{
	//a���� ������ �ָ� b���� �ش�
	int answer = 0;

	int count = n;
	while (true)
	{
		//���� �� �ִ� �� ���
		int bonus = (count / a) * b;
		//����� ���Ѵ�
		answer += bonus;

		//�ѷ� ������Ʈ
		count = (count % a) + bonus;

		//a���� ������ ��
		if (count < a)
			break;
	}

	return answer;
}

int main()
{
	int a = 0;
	a = solution(2, 1, 20);
	a = solution(3, 1, 20);
	return 0;
}