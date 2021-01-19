#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int input;
	cin >> input;

	vector<int> vDP(input + 1);


	if (input == 1)
	{
		cout << 1 << '\n';
	}
	else if (input == 2)
	{
		cout << 2 << '\n';
	}
	else
	{
		int num1 = 2;
		int num2 = 1;
		int temp;
		for (int i = 3; i <= input; i++)
		{
			temp = num1 + num2;
			num2 = num1;
			num1 = temp % 15746;
		}
		cout << num1 << '\n';
	}

	system("pause");

	return 0;
}