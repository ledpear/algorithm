#include <iostream>
using namespace std;

int main()
{
	int testCase(0);
	cin >> testCase;
	cin.get();
	

	for (int test(0); test < testCase; ++test)
	{
		char inputStr[1001];
		char outputStr[1001];
		cin.getline(inputStr, 1001);
		int idx(0), o_idx(0);
		int wordIdx = 0;
		char tempWord[20];
		while (inputStr[idx] != '\0')
		{
			if (inputStr[idx] == ' ')
			{
				if (wordIdx != 0)
				{
					while (--wordIdx >= 0)
					{
						outputStr[o_idx++] = tempWord[wordIdx];
					}
					wordIdx = 0;
				}
				outputStr[o_idx++] = ' ';
			}
			else
			{
				tempWord[wordIdx++] = inputStr[idx];
			}
			idx++;
		}
		if (wordIdx != 0)
		{
			while (--wordIdx >= 0)
			{
				outputStr[o_idx++] = tempWord[wordIdx];
			}
		}
		outputStr[o_idx] = '\0';
		cout << outputStr << '\n';
	}
	return 0;
}