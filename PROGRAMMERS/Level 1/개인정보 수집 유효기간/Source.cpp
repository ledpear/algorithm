#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>

#include <string>
#include <sstream>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
	vector<int> answer;
	//기준 날짜 스플릿
	for (int i = 0; i < today.size(); ++i)
	{
		if (today[i] == '.')
			today[i] = ' ';
	}
	stringstream ss;
	ss.str(today);
	int currYear;
	ss >> currYear;
	int currMonth;
	ss >> currMonth;
	int currDay;
	ss >> currDay;

	//약관 파싱
	map<char, int> termMap;
	for (string term : terms)
	{
		stringstream sss;
		sss.str(term);
		string name;
		sss >> name;
		string month;
		sss >> month;

		termMap.insert(pair<char, int>(name[0], atoi(month.c_str())));
	}

	//privacies순회하면서 파기할 개인정보 확인
	for (int i = 1; i <= privacies.size(); ++i)
	{
		//파싱
		stringstream sss;
		string privacy = privacies[i - 1];
		sss.str(privacy);
		string date;
		sss >> date;
		string termName;
		sss >> termName;

		//유효기간 확인
		int termNum = termMap[termName[0]];
		
		//파기 여부 확인
		for (int i = 0; i < date.size(); ++i)
		{
			if (date[i] == '.')
				date[i] = ' ';
		}
		stringstream iss;
		iss.str(date);
		int year;
		iss >> year;
		int month;
		iss >> month;
		int day;
		iss >> day;

		//기간을 더해주고 달 수 가 12개월이 넘으면 year를 더해준다
		year += termNum / 12;
		month += termNum % 12;
		if (month > 12)
		{
			month -= 12;
			++year;
		}

		--day;
		if (day < 1)
		{
			day = 28;
			if (month == 1)
				month = 12;
			else
				--month;			
		}

		//지금보다 유효기간을 더한 날짜가 전이면 파기
		//년
		if (currYear > year)
		{
			answer.push_back(i);
			continue;
		}
		else if (currYear < year)
			continue;
		//월
		if (currMonth > month)
		{
			answer.push_back(i);
			continue;
		}
		else if (currMonth < month)
			continue;
		//일
		if (currDay <= day)
			continue;

		answer.push_back(i);

	}

	return answer;
}

int main()
{
	vector<int> answer;
	answer = solution("2022.05.19", vector<string>{ "A 96", "B 12", "C 15" }, vector<string>{"2014.01.01 A", "2014.05.20 A", "2021.02.19 C", "2022.02.20 C"});
	answer = solution("2020.01.01", vector<string>{ "Z 3", "D 5" }, vector<string>{"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"});
	return 0;
}