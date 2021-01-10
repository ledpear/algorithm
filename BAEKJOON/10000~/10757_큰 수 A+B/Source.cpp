#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> a >> b;

	int a_pos = a.size() - 1;
	int b_pos = b.size() - 1;

	int a_num, b_num, temp;
	bool bCarry = false;

	string strResult = "";

	while (a_pos >= 0 || b_pos >= 0)
	{
		if (a_pos < 0)
			a_num = 0;
		else
			a_num = a[a_pos--] - '0';

		if (b_pos < 0)
			b_num = 0;
		else
			b_num = b[b_pos--] - '0';

		temp = a_num + b_num + bCarry;

		if (temp >= 10)
		{
			temp -= 10;
			bCarry = true;
		}
		else
			bCarry = false;

		strResult = to_string(temp) + strResult;
	}

	if (bCarry)
	{
		strResult = "1" + strResult;
	}

	if (strResult == "")
		strResult = "0";

	cout << strResult << endl;

	system("pause");

	return 0;
}