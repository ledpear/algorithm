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

using namespace std;

//define

using ull = unsigned long long ;
using location =  pair<int, int> ;
using matrix = vector<vector<int>>;
const int LIMIT = 1000000007;

//custum function
int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

size_t getSquaredNumber(size_t num, int exp)
{
	if (exp == 1)
	{
		return num;
	}

	if (exp % 2 == 0)
	{
		size_t half(getSquaredNumber(num, exp / 2));
		return (half * half) % LIMIT;
	}
	else
	{
		return (num * getSquaredNumber(num, exp - 1)) % LIMIT;
	}
}

int getExpectedValue(int N, int S)
{
	return ((S * getSquaredNumber(N, LIMIT - 2)) % LIMIT);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int diceSize(0), sumVal(0);
	cin >> diceSize;

	//Solution
	for (int index(0); index < diceSize; ++index)
	{
		int N(0), S(0);
		cin >> N >> S;
		int gcdVal(gcd(N, S));
		N /= gcdVal;
		S /= gcdVal;

		sumVal += getExpectedValue(N, S);
		sumVal %= LIMIT;
	}

	//Output
	cout << sumVal << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}