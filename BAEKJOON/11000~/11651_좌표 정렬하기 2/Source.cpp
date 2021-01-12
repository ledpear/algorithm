#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	if (a[1] == b[1])
		return a[0] < b[0];
	else
		return a[1] < b[1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input;
	cin >> input;
	vector<vector<int>> data(input, vector<int>(2));
	for (int i = 0; i < input; i++)
	{
		cin >> data[i][0] >> data[i][1];
	}

	sort(data.begin(), data.end(), compare);

	for (int i = 0; i < input; i++)
	{
		cout << data[i][0] << " " << data[i][1] << "\n";
	}

	system("pause");

	return 0;
}