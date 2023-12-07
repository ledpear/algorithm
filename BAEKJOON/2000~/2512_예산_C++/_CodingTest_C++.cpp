#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int size = 0;
    cin >> size;
    vector<int> arr(size, 0);
    for (int& num : arr)
        cin >> num;

    int maxVal = 0;
    cin >> maxVal;

    int left = 0, right = *max_element(arr.begin(), arr.end());
    int answer = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int sum = 0;
        for (const int num : arr)
            sum += mid < num ? mid : num;

        if (sum <= maxVal)
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    cout << answer << endl;
}