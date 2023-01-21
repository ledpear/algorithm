#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string solution(string s)
{
	//모든 단어의 첫문자가 대문자
	//시작은 true로 가고 단어 첫문자지나면 바로 false로 바꾸고
	//공백을 만나면 true로 바꿔준다
	//첫문자지만 영어가 아니면 그냥 false로만 바꿔주고 넘어간다
	//알파벳과 숫자 공백으로 만 이루어져있고
	//숫자는 단어의 첫 문자로만 나온다
	//숫자로만 이루어진 단어는 없으면 공백문자가 연속으로 나올 순 있다.
	string a = s;
	bool bigFlag = true;
	const int size = a.size();
	for (int i = 0; i < size; ++i)
	{
		//공백이면 플래그를 켜고 그냥 넘어간다
		if (a.at(i) == ' ')
		{
			bigFlag = true;
			continue;
		}

		const int ascii = static_cast<int>(a.at(i));
		bool isBig = bigFlag;
		bigFlag = false;

		//숫자면 플래그를 끄고 넘어간다
		if (a.at(i) >= '0' && a.at(i) <= '9')
			continue;

		//대문자여야 할 때 소문자이면 변환
		if ((isBig == true) && (a.at(i) >= 'a') && (a.at(i) <= 'z'))
		{
			a.at(i) -= 32;
			continue;
		}

		//소문자여야 할 때 대문자이면 변환
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