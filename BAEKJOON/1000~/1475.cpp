// 1475.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char input[10];
	cin >> input;
	int su[10] = { 0 };
	int max=0;
	for (int i = 0;; i++) {
		if (input[i] == NULL)break;
		su[(int)input[i] - 48]++;
	}
	if ((su[6] + su[9]) % 2 == 0)
		su[6] = (su[6] + su[9]) / 2;
	else
		su[6] = (su[6] + su[9]) / 2 + 1;
	for (int i = 0; i < 9; i++) {
		if (su[i] > max) {
			max = su[i];
		}
	}
	cout << max << endl;
    return 0;
}

