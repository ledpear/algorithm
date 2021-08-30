#include <iostream>
#include <string>
#include <vector>
using namespace std;

void _strcpy(char* original, char *copy)
{
	for (original; *original != '\0'; ++original)
	{
		*copy++ = *original;
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

int getNumSize(int num)
{
	int count(0);
	while (num)
	{
		num /= 10;
		++count;
	}

	return count;
}

void _swap(int *numA, int* numB)
{
	int temp = *numA;
	*numA = *numB;
	*numB = temp;
}

void _swap(int &numA, int& numB)
{
	int temp = numA;
	numA = numB;
	numB = temp;
}

class testClass
{
private:
	int num;
public:
	testClass(int num = 5)
	{
		this->num = num;
	}
};

void _swap(string& iterA, string& iterB)
{
	auto temp = iterA;
	iterA = iterB;
	iterB = temp;
}

void _swap(vector<int>& iterA, vector<int>& iterB)
{
	auto temp = iterA;
	iterA = iterB;
	iterB = temp;
}

void _swap(testClass** iterA, testClass** iterB)
{
	auto temp = *iterA;
	*iterA = *iterB;
	*iterB = temp;
}

void _swap(testClass* iterA, testClass* iterB)
{
	testClass* temp = iterA;
	iterA = iterB;
	iterB = temp;
}

struct testStruct
{
	int i1;
	int d;
	char c1;
	char c2;
	int i2;
	char c3;
	char c4;

	testStruct(int ii1 = 1, double id = 2.0, char ic1 = 'a', char ic2 = 'b', int ii2 = 4, char ic3 = 'c', char ic4 = 'd')
		: i1(ii1), d(id), c1(ic1), c2(ic2), i2(ii2), c3(ic3), c4(ic4) {}
};

int main()
{
 	char chArr1[6] = { 'a', 'p', 'p', 'l', 'e' };
 	char chArr2[5] = { 'c' };

	int numA(4), numB(9);
	_swap(numA, numB);

	vector<int> vectorA(5, 1);
	vector<int> vectorB(9, -3);

	_swap(vectorA, vectorB);

	string strA("testA");
	string strB("testBB");

	_swap(strA, strB);

	testClass *testA = new testClass(3);
	testClass *testB = new testClass(79);

	_swap(&testA, &testB);

	testStruct ts;

	cout << sizeof(ts) << '\n';

	delete(testA);
	delete(testB);

	return 0;
}