#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int GetHashCode(string str)
{
	int nSum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		nSum += str[i];
	}
	return nSum;
}

string main()
{
	vector<string> participant, vector<string> completion;	
	map<int, int> map;

	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");

	completion.push_back("eden");
	completion.push_back("kiki");

	std::map<int, int>::iterator iter;

	for (int i = 0; i < completion.size(); i++)
	{
		int Hash = GetHashCode(completion[i]);
		if (map.find(Hash) == map.end())
			map.insert(pair<int, int>(Hash, 1));
		else
			map[Hash]++;
	}

	for (int i = 0; i < participant.size(); i++)
	{
		int Hash = GetHashCode(participant[i]);
		if (map.find(Hash) == map.end())
			return participant[i];
		else if (map[Hash] == 0)
			return participant[i];
		else
			map[Hash]--;
	}
	
	//system("pause");
	return 0;
}