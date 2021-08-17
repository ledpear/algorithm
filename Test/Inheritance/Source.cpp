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
	string name;
	int age;
public:
	people(string inputName, int inputAge)
	{
		name = inputName;
		age = inputAge;
	}

	void printInfo()
	{
		cout << "name : " << name << '\n';
		cout << "age : " << age << '\n';
	}
};

class player : public people
{
private:
	string job;
public:
	player(string inputName, int inputAge, string inputJob)
		: people(inputName, inputAge)
	{
		job = inputJob;
	}

	void printInfo()
	{
		people::printInfo();
		cout << "job : " << job << '\n';
	}

	void playerInfo()
	{
		cout << "player job : " << job << '\n';
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//���̽� Ŭ������ �Ļ�Ŭ���� ����
	people *A = new player("derived1 Class", 14, "player");
	people B = player("derived2 Class", 21, "tester");


 	A->printInfo();
	cout << '\n';
 	B.printInfo();










	//�Ļ� Ŭ������ ���̽� Ŭ���� ����
	//�ƿ� ������ ���� �߻�
	//player B = people("baseClass", 14);

	//�������̵� Ȯ��
	//	people C = people("baseClass", 20);
	// 	player D = player("derived Class", 24, "tester");
	// 
// 	D.printInfo();
// 	D.playerInfo();

	////////////////////////////////////
	system("pause");
	return 0;
}