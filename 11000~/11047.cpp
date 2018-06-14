// 11047.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int count, sum;
	cin >> count >> sum;
	int coinNum = 0;
	int *coin = new int[count];
	int i;
	for (i = 0; i < count; i++) {
		cin >> coin[i];
	}
	i = count - 1;
	while (sum != 0) {
		if (sum < coin[i]) {
			i--;
		}
		else {
			sum -= coin[i];
			coinNum++;
		}
	}

	cout << coinNum << "\n";

    return 0;
}