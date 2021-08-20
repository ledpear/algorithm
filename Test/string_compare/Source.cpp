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

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::ios_base;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

//define
//custum function

void printChArr(char chApp1[], char chApp2[])
{
	cout << "chApp1 : " << chApp1 << "\tchApp2 : " << chApp2 << '\n';
	cout << "strcmp : " << strcmp(chApp1, chApp2) << '\n' << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	char chApp1[6] = { 'c','h','a' };
	char chApp2[6] = { 'c','h','a' };

	//Solution
	printChArr(chApp1, chApp2);


	chApp1[3] = 'a';
	printChArr(chApp1, chApp2);

	chApp2[3] = 'a';
	printChArr(chApp1, chApp2);

	chApp2[4] = 'a';
	printChArr(chApp1, chApp2);

	chApp1[4] = 'a';
	printChArr(chApp1, chApp2);

	chApp2[0] = 'b';
	printChArr(chApp1, chApp2);

	chApp2[0] = 'C';
	printChArr(chApp1, chApp2);

	chApp1[0] = 'B';
	printChArr(chApp1, chApp2);

	////////////////////////////////////
	system("pause");
	return 0;
}