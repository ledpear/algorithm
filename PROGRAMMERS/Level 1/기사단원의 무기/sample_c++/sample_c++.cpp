// sample_c++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) 
{
    int answer = 0;
    for (int i = 1; i <= number; ++i)
    {
        int count = 0;
        //제곱근의 가장 가까운 숫자 중 약수인것을 찾는다
        int end = static_cast<int>(sqrt(i));
        for (int j = 1; j <= end; ++j)
        {
            if (count > limit)
            {
                count = power;
                break;
            }

            if (i % j == 0)
            {
                if (j * j == i)
                    ++count;
                else
                    count += 2;
            }
        }

        if (count > limit)
            count = power;

        answer += count;
    }   

    return answer;
}

int main()
{
    //cout << solution(5, 3, 2) << endl;
    cout << solution(10, 3, 2) << endl;
}