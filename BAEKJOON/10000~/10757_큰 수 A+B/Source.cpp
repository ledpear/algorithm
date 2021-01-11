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
		if (a_pos < 0)	//문자열 a 값 저장 및 예외처리
			a_num = 0;
		else
			a_num = a[a_pos--] - '0';

		if (b_pos < 0)	//문자열 b 값 저장 및 예외처리
			b_num = 0;
		else
			b_num = b[b_pos--] - '0';

		temp = a_num + b_num + bCarry;	// 저장할 값 계산

		if (temp >= 10)					// Carry값 계산
		{
			temp -= 10;
			bCarry = true;
		}
		else
			bCarry = false;

		strResult = to_string(temp) + strResult;	//문자열 저장
	}

	if (bCarry)	//만약 마지막 연산에서 Carry값이 있을경우 자리올림수 처리
	{
		strResult = "1" + strResult;
	}

	if (strResult == "")
		strResult = "0";

	cout << strResult << endl;

	system("pause");

	return 0;
}