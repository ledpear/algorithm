// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct MusicPlay
{
	int Play;
	int Number;
};

struct MusicGenre
{
	string Name;
	int Play;
};

bool MusicGenreCompare(MusicGenre a, MusicGenre b)
{
	return a.Play > b.Play;
}

bool MusicPlayCompare(MusicPlay a, MusicPlay b)
{
	if (a.Play == b.Play)
		return a.Number < b.Number;
	else
		return a.Play > b.Play;
}	


int main()
{
	int nLast = -1;
	vector<string> genres = {"classic", "pop", "classic", "classic", "pop" };
	vector<int> plays = { 500, 600, 150, 800, 2500 };
	vector<int> answer;


	map<string, vector<MusicPlay>> Music;
	map<string, int> MusicTotal;

	map<string, vector<MusicPlay>>::iterator iter;
	for (int i = 0; i < plays.size(); i++)
	{
		iter = Music.find(genres[i]);

		if (iter == Music.end())	//»õ·Î¿î Àå¸£¸é
		{
			//À½¾Ç »ðÀÔ
			vector<MusicPlay> vPlaysTemp;
			MusicPlay mTemp;
			mTemp.Play = plays[i];
			mTemp.Number = i;
			vPlaysTemp.push_back(mTemp);
			Music[genres[i]] = vPlaysTemp;

			//ÃÑÇÕ
			MusicTotal[genres[i]] = plays[i];
		}
		else
		{
			vector<MusicPlay> vPlaysTemp = iter->second;
			MusicPlay mTemp;
			mTemp.Play = plays[i];
			mTemp.Number = i;
			vPlaysTemp.push_back(mTemp);
			Music[genres[i]] = vPlaysTemp;

			//ÃÑÇÕ
			MusicTotal[genres[i]] = MusicTotal[genres[i]] + plays[i];
		}
	}

	//ÃÑÇÕ Á¤·Ä
	vector<MusicGenre> MusicRank;
	map<string, int>::iterator Totaliter;
	for (Totaliter = MusicTotal.begin(); Totaliter != MusicTotal.end(); Totaliter++)
	{
		MusicGenre mTemp;
		mTemp.Name = Totaliter->first;
		mTemp.Play = Totaliter->second;
		MusicRank.push_back(mTemp);
	}
	sort(MusicRank.begin(), MusicRank.end(), MusicGenreCompare);

	//Àå¸£ ³» Á¤·Ä ¹× »ðÀÔ
	for (int nRank = 0; nRank < MusicRank.size(); nRank++)
	{
		vector<MusicPlay> vPlayTemp = Music[MusicRank[nRank].Name];

		sort(vPlayTemp.begin(), vPlayTemp.end(), MusicPlayCompare);

		for (int i = 0; i < vPlayTemp.size(); i++)
		{
			answer.push_back(vPlayTemp[i].Number);
			if (i == 1) break;
		}
	}

    return 0;
}

