#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input;
	cin >> input;
	vector<vector<int>> data(input, vector<int>(2));
	for (int i = 0; i < input; i++)
	{
		cin >> data[i][1] >> data[i][0];
	}

	sort(data.begin(), data.end());

	for (int i = 0; i < input; i++)
	{
		cout << data[i][1] << " " << data[i][0] << "\n";
	}

	system("pause");

	return 0;
}