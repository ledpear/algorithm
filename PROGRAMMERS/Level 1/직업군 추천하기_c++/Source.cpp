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
#include <vector>

using namespace std;

//define
#define INDEX_NAME -1

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;

//custum function
string solution(vector<string> table, vector<string> languages, vector<int> preference) 
{
	string answer("");
	//가장 처음 항목은 언어 그 이후 5개 항목은 언어
	//언어는 5점부터 1점까지 순서대로

	using language = map<string, int>;
	using occupation = vector<pair<string, language>>;	//0 : 직군, 그 이후는 언어
	
	int nTableSize(table.size());
	occupation vOccupations(nTableSize);

	//table 파싱
	for (int nTableIndex = 0; nTableIndex < nTableSize; ++nTableIndex)
	{
		string strName(""), strTemp("");
		int nItemIndex(INDEX_NAME);
		language mLanguages;

		for (char cCharacter : table[nTableIndex])
		{
			//공백을 만나기전 
			if (cCharacter != ' ')
			{
				if (nItemIndex == INDEX_NAME)
				{
					strName += cCharacter;
				}
				else
				{
					strTemp += cCharacter;
				}
			}
			//공백을 만났을 때 각각 알맞는 항목에 값 입력
			else
			{
				if (nItemIndex == INDEX_NAME)
				{
					nItemIndex = 0;
				}
				else
				{
					mLanguages.insert(make_pair(strTemp, 5 - nItemIndex));
					strTemp = "";
					++nItemIndex;
				}
			}
		}
		//마지막 값 insert
		mLanguages.insert(make_pair(strTemp, 5 - nItemIndex));
		//결과값 입력
		vOccupations[nTableIndex] = make_pair(strName, mLanguages);
	}

	int nLanguageSize(languages.size());

	//언어를 순회하면서 각각 직군의 점수를 계산
	int nMaxValue(INT_MIN), nMaxIndex(-1), nSameCount = 0;
	vector<int> vScore(nTableSize, 0);
	for (int nLanguageIndex = 0; nLanguageIndex < nLanguageSize; ++nLanguageIndex)
	{
		for (int nTableIndex = 0; nTableIndex < nTableSize; ++nTableIndex)
		{
			language mLanguages = vOccupations[nTableIndex].second;
			auto Language = mLanguages.find(languages[nLanguageIndex]);
			if (Language != mLanguages.end())
			{
				vScore[nTableIndex] += mLanguages[languages[nLanguageIndex]] * preference[nLanguageIndex];

				if (nMaxValue < vScore[nTableIndex])
				{
					nMaxValue = vScore[nTableIndex];
					nMaxIndex = nTableIndex;
					nSameCount = 1;
				}
				else if (nMaxValue == vScore[nTableIndex])
				{
					string strMaxLanguage = vOccupations[nMaxIndex].first;
					string strIndexLanguage = vOccupations[nTableIndex].first;
						
					if (strMaxLanguage > strIndexLanguage)
					{
						nMaxIndex = nTableIndex;
					}
				}
			}
		}
	}

	answer = vOccupations[nMaxIndex].first;

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration


	//Solution


	//Output
	cout << solution(vector<string>{ "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA" }
	, vector<string>{"JAVA", "JAVASCRIPT"}, vector<int>{7, 5}) << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}