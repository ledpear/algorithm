// 6064.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int t, M, N, x, y;
	int fx, fy;
	
	cin >> t;
	while (t--) {
		cin >> M >> N >> x >> y;
		int temp;
		if (M > N) {
			temp = M;
			M = N;
			N = temp;
			temp = x;
			x = y;
			y = temp;
		}
		int num=x;
		int count = 0;
		fx = x;
		if (x % N == 0) fy = x;
		else fy = x % N;
		
		int i, j;
		i = fx; j = fy;
		while (1) {
			if (x == i && y == j)break;
			if (fx == i && fy == j)count++;
			if (count > 1)break;
			num = num + M;
			if (num % M == 0) i = M;
			else i = num % M;
			if (num % N == 0) j = N;
			else j = num % N;
			
			//cout << num << "\t" << i << "\t" << j << "\n";
		}
		if (count > 1) {
			cout << "-1\n";
		}
		else {
			cout << num << "\n";
		}
	}
    return 0;
}

