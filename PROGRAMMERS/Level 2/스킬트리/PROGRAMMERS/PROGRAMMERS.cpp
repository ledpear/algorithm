// PROGRAMMERS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	string skill = "CBD";
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");

	int answer = 0;

	//스킬트리를 순서대로 검사 진행
	//1. 스킬이 선행 순서가 있는지 검사
	//2. 스킬이 선행 순서대로 배우고있는지 검사

	bool bSkill[26] = { 0, };
	int nSkillTreePos = 0;
	int nError = 0;

	for (int i = 0; i < skill.size(); i++)
	{
		bSkill[skill[i] - 'A']++;
	}

	for (int i = 0; i < skill_trees.size(); i++)
	{
		for (int j = 0; j < skill_trees[i].size(); j++)
		{
			if(!bSkill[skill_trees[i][j] - 'A'])
				continue;

			if (skill[nSkillTreePos] == skill_trees[i][j])
				nSkillTreePos++;
			else
			{
				nError++;
				break;
			}
		}
		nSkillTreePos = 0;
	}

	answer = skill_trees.size() - nError;

    return 0;
}

