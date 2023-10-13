#include <iostream>
#include <string>
#include <vector>

#include<cmath>

using namespace std;

long long solution2(int r1, int r2) 
{
    long long dr1, dr2;
    int upper, lower;
    long long answer = 0;

    // 왜 dr2*dr2하면 느리고, pow(dr2, 2)하면 빨라지지...?
    // 답도 틀렸다가 pow써서 맞았다... 왜...?
    dr1 = (long)r1; dr2 = (long)r2;
    for (int i = 1; i <= r1; i++) {
        upper = floor(sqrt(pow(dr2, 2) - pow(i, 2)));
        lower = ceil(sqrt(pow(dr1, 2) - pow(i, 2)));
        answer += (upper - lower + 1);
    }
    for (int i = r1 + 1; i <= r2; i++) {
        upper = floor(sqrt(pow(dr2, 2) - pow(i, 2)));
        answer += (upper + 1);
    }
    answer *= 4;

    return answer;
}

long long solution(int r1, int r2) 
{
    long long answer = 0;

    //X > 0 and Y >= 0 인 경우만 카운트 * 4
    //Y가 0일때부터 시작 X는 r1부터 반지름이 넘어가지 않을때 까지 or r2까지
    //반지름은 미리 제곱해놓는다

    //x 시작 값을 y가 n일때 r1이 되는 x의 값을 구해서 그것 보다 크거나 같은 정수부터 시작해야한다

    const long double minRadiusSq = pow( r1, 2);
    const long double maxRadiusSq = pow( r2, 2);

    for (int y = 1; y <= r2; ++y)
    {
        //x의 최솟값을 구한다
        const long double ySq = pow(y, 2);
        int xMin = (minRadiusSq > ySq) ? ceil(sqrt(minRadiusSq - ySq)) : 0;
        int xMax = floor(sqrt(maxRadiusSq - ySq));
                
        answer += xMax - xMin + 1;
    }

    return answer * 4;
}

int main()
{
    cout << solution(2, 3) << endl;
}