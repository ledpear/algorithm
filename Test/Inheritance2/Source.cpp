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
using std::string;

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;

//define
//custum function

class people
{
private:
public:
	people()
	{
		printf("base class create\n");
	}
	~people()
	{
		printf("base class delete\n");
	}
};

class player : public people
{
private:
	string job;
public:
	player()
	{
		printf("derived class create\n");
	}

	~player()
	{
		printf("derived class delete\n");
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//베이스 클래스에 파생클래스 삽입
	player A;
	player B = A;


	//파생 클래스에 베이스 클래스 삽입
	//아예 컴파일 에러 발생
	//player B = people("baseClass", 14);

	//오버라이딩 확인
	//	people C = people("baseClass", 20);
	// 	player D = player("derived Class", 24, "tester");
	// 
// 	D.printInfo();
// 	D.playerInfo();

	////////////////////////////////////
	return 0;
}