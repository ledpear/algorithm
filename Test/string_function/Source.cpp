#include <iostream>
using namespace std;

void _strcpy(char* original, char *copy)
{
	int idx = 0;
	while (original[idx] && copy[idx])
	{
		copy[idx] = original[idx];
		++idx;
	}
}

int _strlen(const char* chArr)
{
	int idx(0);
	while (chArr[idx++]);
	return idx - 1;
}

int _strcmp(const char* mainStr, const char* compareStr)
{
	int idx = 0;
	while (mainStr[idx] || compareStr[idx])
	{
		if (mainStr[idx] < compareStr[idx])
		{
			return -1;
		}
		else if (mainStr[idx] > compareStr[idx])
		{
			return 1;
		}

		++idx;
	}

	return 0;
}

void cswap(const char& chArr1, const char& chArr2)
{
}

int main()
{
 	char chArr1[6] = { 'b', 'p', 'p', 'l', 'e' };
 	char chArr2[4] = { 'a' };


	const int *a = new int(10);
	const int *b = new int(20);

	a = b;

	a += 1;

// 	cout << "chArr1 : " << _strlen(chArr1) << '\n';
// 	cout << "chArr2 : " << _strlen(chArr2) << '\n';
// 	cout << '\n';
// 
// 	cout << "_strcpy\n";
// 	_strcpy(chArr1, chArr2);
// 	cout << "chArr1 : " << chArr1 << '\n';
// 	cout << "chArr2 : " << chArr2 << '\n';
// 	cout << '\n';
// 
// 	cout << "_strcmp\n";
// 	cout << _strcmp(chArr1, chArr2);
// 	cout << '\n';
// 
// 	////////////////////////////////////////////////
// 
// 	char chArr3[6] = { 'a', 'p', 'p', 'l', 'e' };
// 	char chArr4[6] = { 'a', 'l', 'e' };
// 
// 	cout << "_strlen\n";
// 	cout << "chArr3 : " << _strlen(chArr3) << '\n';
// 	cout << "chArr4 : " << _strlen(chArr4) << '\n';
// 	cout << '\n';
// 
// 	cout << "_strcpy\n";
// 	_strcpy(chArr3, chArr4);
// 	cout << "chArr3 : " << chArr3 << '\n';
// 	cout << "chArr4 : " << chArr4 << '\n';
// 	cout << '\n';
// 
// 	cout << "_strcmp\n";
// 	cout << _strcmp(chArr3, chArr4);
// 	cout << '\n';

	return 0;
}