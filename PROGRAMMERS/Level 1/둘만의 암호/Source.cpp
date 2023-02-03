#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int nextNum(int num)
{
	if (num == static_cast<int>('z'))
		return static_cast<int>('a');
	else
		return num + 1;
}

string solution(string s, string skip, int index) 
{
	string answer = "";

	//��ŵ�� ���ĺ��� ã�´�
	vector<bool> skipAlpha = vector<bool>('z' - 'a' + 1);
	for (char c : skip)
	{
		skipAlpha[c - 'a'] = true;
	}	

	for (char c : s)
	{
		//�ǳʶ� Ƚ��
		int count = 0;
		//���� ����
		int num = static_cast<int>(c);
		while (true)
		{
			//��ŵ�� ���ĺ��̸� count�� �ø��� �ʰ� num�� �ø���
			if (skipAlpha[num - static_cast<int>('a')])
			{
				num = nextNum(num);
				continue;
			}

			++count;
			if (count > index)
				break;

			//z�� �Ѿ�� a �ƴϸ� ���� ����
			num = nextNum(num);
		}

		answer.push_back(static_cast<char>(num));
	}

	return answer;
}

int main()
{
	string a = solution("ybcde", "az", 1);
	return 0;
}