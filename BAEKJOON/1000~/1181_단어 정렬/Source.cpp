#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main()
{
	int input;
	cin >> input;
	vector<string> data(input);
	for (int i = 0; i < input; i++)
	{
		cin >> data[i];
	}
	sort(data.begin(), data.end(), compare);
	string strTemp = "";
	for (int i = 0; i < input; i++)
	{
		if(strTemp.compare(data[i]) != 0)
			cout << data[i] << endl;
		strTemp = data[i];
	}
	system("pause");
	return 0;
}