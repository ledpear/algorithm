// 2750.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int *num = new int[1000];
	int count,temp;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> num[i];
	}
	for (int i = count -1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (num[j] > num[j + 1]) {
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		cout << num[i] << "\n";
	}
    return 0;
}

