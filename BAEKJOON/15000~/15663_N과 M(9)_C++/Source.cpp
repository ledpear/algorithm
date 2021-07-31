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

//custum function
void permutationPrint(vector<int>& numArr, vector<int>& permutation, int permutationSize, vector<bool>& used)
{
	//�迭�� ũ��� ��ǥ ũ�Ⱑ ������ ���
	if (permutation.size() == permutationSize)
	{
		for (auto num : permutation)
		{
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	//����� ���ڴ� �ǳ� �ڴ�
	vector<bool> nowUsed(10001);

	for (int index(0); index < numArr.size(); ++index)
	{
		if (!used[index] && !nowUsed[numArr[index]])
		{
			used[index] = true;
			nowUsed[numArr[index]] = true;
			permutation.push_back(numArr[index]);
			permutationPrint(numArr, permutation, permutationSize, used);
			permutation.pop_back();
			used[index] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int arrSize, permutationSize;
	cin >> arrSize >> permutationSize;

	vector<int> numArr(arrSize);
	for (size_t index(0); index < arrSize; ++index)
	{
		cin >> numArr[index];
	}
	sort(numArr.begin(), numArr.end());

	//Solution
	//Output
	vector<int> permutation;
	vector<bool> used(arrSize);

	permutationPrint(numArr, permutation, permutationSize, used);

	////////////////////////////////////
	system("pause");
	return 0;
}