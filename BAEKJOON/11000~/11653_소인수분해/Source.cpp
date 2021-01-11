#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int input;
	cin >> input;

	if (input == 1)
		return 0;

	int nSqrt = sqrt(input);

	vector<bool> PrimeNum(input + 1, 0);

	int pos;
	for (int i = 2; i < input + 1; i++)
	{
		pos = 2;
		if(PrimeNum[i])	continue;
		while(true)
		{
			if (i*pos > input) break;
			PrimeNum[i * pos++] = true;
		}
	}

	PrimeNum[1] = false;

	if (PrimeNum[input] == false)
		cout << input << endl;
	else
	{
		int i = 2;
		while (input > 1)
		{
			if (input % i == 0)
			{
				input = input / i;
				cout << i << endl;
			}
			else
			{
				while (true)
				{
					if (PrimeNum[++i] == false)	break;
				}
			}
		}
	}
	system("pause");
	return 0;
}