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

//custum function
int charToIndex(char character)
{
	if (character == 'A')
	{
		return 0;
	}
	else if (character == 'C')
	{
		return 1;
	}
	else if (character == 'F')
	{
		return 2;
	}
	else if (character == 'J')
	{
		return 3;
	}
	else if (character == 'M')
	{
		return 4;
	}
	else if (character == 'N')
	{
		return 5;
	}
	else if (character == 'R')
	{
		return 6;
	}
	else if (character == 'T')
	{
		return 7;
	}
}

bool checkCondition(vector<int>& posCharacter, vector<string>& data)
{
	for (auto condition : data)
	{
		int firstCharacter = charToIndex(condition[0]);
		int secondCharacter = charToIndex(condition[2]);
		char oper = condition[3];
		int distance = condition[4] - '0';

		if (oper == '=')
		{
			if ((abs(posCharacter[firstCharacter] - posCharacter[secondCharacter]) - 1) != distance)
			{
				return false;
			}
		}
		else if (oper == '>')
		{
			if ((abs(posCharacter[firstCharacter] - posCharacter[secondCharacter]) - 1) <= distance)
			{
				return false;
			}
		}
		else if (oper == '<')
		{
			if ((abs(posCharacter[firstCharacter] - posCharacter[secondCharacter]) - 1) >= distance)
			{
				return false;
			}
		}
	}

	return true;
}

void BT(vector<int>& posCharacter, vector<string>& data, int& answer, int pos = 0)
{
	if (posCharacter.size() == pos)
	{
		if (checkCondition(posCharacter, data))
		{
			++answer;
		}

		return;
	}

	for (int index(0); index < posCharacter.size(); ++index)
	{
		if (posCharacter[index] == -1)
		{
			posCharacter[index] = pos;
			BT(posCharacter, data, answer, pos + 1);
			posCharacter[index] = -1;
		}
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;

	//캐릭터의 위치를 등록했는지
	//vector<bool> usedCharacter(8);
	//각 캐릭터의 위치 아직 안정했다면 -1, 각 캐릭터 인덱스에 위치가 입력되어 있다
	vector<int> posCharacter(8, -1);
	BT(posCharacter, data, answer);

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int n = 2;
	vector<string> data = { "N~F=0", "R~T>2" };

	//Solution
	int answer = solution(n, data);

	//Output
	cout << answer << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}