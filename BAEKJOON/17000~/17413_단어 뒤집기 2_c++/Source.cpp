#include <iostream>
using namespace std;
const int SIZE = 100001;

int main()
{
	char str[SIZE], result[SIZE];
	cin.getline(str, SIZE);

	bool isTag = false;
	char wordTemp[SIZE];
	int idx = 0, tempIdx = 0, resultIdx = 0;
	while (str[idx])
	{
		if (str[idx] == '<')
		{
			isTag = true;
			if (tempIdx != 0)
			{
				--tempIdx;
				while (tempIdx >= 0)
				{
					result[resultIdx++] = wordTemp[tempIdx--];
				}
				tempIdx = 0;
			}
			result[resultIdx++] = '<';
		}
		else if (str[idx] == '>')
		{
			isTag = false;
			result[resultIdx++] = '>';
		}
		else
		{
			if (isTag)
			{
				result[resultIdx++] = str[idx];
			}
			else
			{
				if (str[idx] != ' ')
				{
					wordTemp[tempIdx++] = str[idx];
				}
				else
				{
					--tempIdx;
					while (tempIdx >=0)
					{
						result[resultIdx++] = wordTemp[tempIdx--];
					}
					tempIdx = 0;
					result[resultIdx++] = ' ';
				}
			}
		}
		++idx;
	}
	if (tempIdx)
	{
		--tempIdx;
		while (tempIdx >= 0)
		{
			result[resultIdx++] = wordTemp[tempIdx--];
		}
	}
	result[resultIdx] = '\0';
	cout << result << '\n';
	return 0;
}