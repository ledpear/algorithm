#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string solution(string s)
{
	//��� �ܾ��� ù���ڰ� �빮��
	//������ true�� ���� �ܾ� ù���������� �ٷ� false�� �ٲٰ�
	//������ ������ true�� �ٲ��ش�
	//ù�������� ��� �ƴϸ� �׳� false�θ� �ٲ��ְ� �Ѿ��
	//���ĺ��� ���� �������� �� �̷�����ְ�
	//���ڴ� �ܾ��� ù ���ڷθ� ���´�
	//���ڷθ� �̷���� �ܾ�� ������ ���鹮�ڰ� �������� ���� �� �ִ�.
	string a = s;
	bool bigFlag = true;
	const int size = a.size();
	for (int i = 0; i < size; ++i)
	{
		//�����̸� �÷��׸� �Ѱ� �׳� �Ѿ��
		if (a.at(i) == ' ')
		{
			bigFlag = true;
			continue;
		}

		const int ascii = static_cast<int>(a.at(i));
		bool isBig = bigFlag;
		bigFlag = false;

		//���ڸ� �÷��׸� ���� �Ѿ��
		if (a.at(i) >= '0' && a.at(i) <= '9')
			continue;

		//�빮�ڿ��� �� �� �ҹ����̸� ��ȯ
		if ((isBig == true) && (a.at(i) >= 'a') && (a.at(i) <= 'z'))
		{
			a.at(i) -= 32;
			continue;
		}

		//�ҹ��ڿ��� �� �� �빮���̸� ��ȯ
		if ((isBig == false) && (a.at(i) >= 'A') && (a.at(i) <= 'Z'))
		{
			a.at(i) += 32;
			continue;
		}
	}

	return a;
}

int main()
{
	{
		string a = "aBCDEFG ZADIOWEN SDFKCL";
		cout << solution(a) << endl;
	}
	{
		string a = " aaaaa aaa";
		cout << solution(a) << endl;
	}
	{
		string a = "abc  ddd 123abc";
		cout << solution(a) << endl;
	}
	{
		string a = "3PEOPLE 4unFollowed 2ME   ";
		cout << solution(a) << endl;
	}
	{
		string a = "people      uNFOllowed      4me";
		cout << solution(a) << endl;
	}

	{
		string a = "        2ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		cout << solution(a) << endl;
	}

	{
		string a = "a";
		cout << solution(a) << endl;
	}
	{
		string a = "a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           a   bcd  hello           ";
		cout << solution(a) << endl;
	}
	return 0;
}