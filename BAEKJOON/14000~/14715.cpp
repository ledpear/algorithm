// 14715.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
int dp[1000001];
int max(int a, int b) {
	return (a > b) ? a : b;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}

int ans(int k) {
	int x, y, z;
	int res = 0;
	int count = 0;
	int m = 10;
	x = -1;
	y = -1;
	z = sqrt((double)k);
	if (dp[k] != -1) {
		return dp[k];
	}
	for (int j = z; j >= 2; j--) {
		if (k%j == 0) {
			x = j;
			y = k / j;
			res = max(ans(x), ans(y)) + 1;
			if (m > res) {
				m = res;
			}
		}
	}
	if (x == -1) {
		dp[k] = 0;
		return 0;
	}
	else {
		dp[k] = m;
		return m;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	int size;
	int k;
	int x, y, z;
	cin >> k;
	cout << ans(k) << endl;
}

