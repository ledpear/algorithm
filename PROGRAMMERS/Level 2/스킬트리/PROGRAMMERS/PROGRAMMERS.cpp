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

	//��ųƮ���� ������� �˻� ����
	//1. ��ų�� ���� ������ �ִ��� �˻�
	//2. ��ų�� ���� ������� �����ִ��� �˻�

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

