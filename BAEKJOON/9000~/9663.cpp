// 9663.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>`

using namespace std;
int boad[16];
int c = 0;

void queens(int i, int n);
bool promising(int i);

void queens(int i,int n) {
	
	if (promising(i)) {
		if (i == n) {
			c++;
		}
		else {
			for (int x = 1; x <= n; x++) {
				boad[i + 1] = x;
				queens(i + 1, n);
			}
		}
	}
}

bool promising(int i) {
	bool sw = true;
	
	for (int x = 1; x < i; x++) {
		if (boad[x] == boad[i] || (abs(boad[x] - boad[i]) == i - x)) {
			sw = false;
			return sw;
		}
	}
	return sw;
}

int main()
{
	int n;
	cin >> n;
	queens(0, n);
	cout << c << "\n";
    return 0;
}

