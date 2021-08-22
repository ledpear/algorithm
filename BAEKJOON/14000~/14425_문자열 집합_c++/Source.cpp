#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	int setStrSize(0), checkStrSize(0);
	cin >> setStrSize >> checkStrSize;
	unordered_set<string> setStr;
	for (int idx(0); idx < setStrSize; ++idx)
	{
		string inputStr;
		cin >> inputStr;
		setStr.insert(inputStr);
	}

	int answer(0);
	for (int idx(0); idx < checkStrSize; ++idx)
	{
		string inputStr("");
		cin >> inputStr;
		if (setStr.find(inputStr) != setStr.end())
		{
			++answer;
		}
	}

	cout << answer << '\n';
	return 0;
}