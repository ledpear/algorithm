// 11399.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int count;
	cin >> count;
	int *num = new int[count];
	
	for (int i = 0; i < count; i++) {
		cin >> num[i];
	}
	sort(num, num + count);
	int sum = num[0];
	int total = num[0];
	for (int i = 1; i < count; i++) {
		sum = sum + num[i];
		total += sum;
	}
	cout << total << "\n";
    return 0;
}

