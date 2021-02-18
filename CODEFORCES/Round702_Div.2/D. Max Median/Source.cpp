#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> p;

int MedianOfMedians(vector<int> *v, int n, int k) {

	// 배열에 1 개의 값 밖에 없거나 찾으려는 값이 첫번째 값이면
	// 첫번째 값을 반환한다.
	if (n == 1 && k == 0) return v[0];

	// 배열을 원소 5개의 서브 배열로 나눈다.
	// 올림 하기 위해 배열 사이즈에 4를 더하고 5로 나눈다.
	// m 은 서브 배열 몇 개를 만들어야 하는지 나타낸다.
	int m = (n + 4) / 5;
	// 배열의 주소값을 저장하는 배열 m size 만큼 만든다. 
	// (예를들어 배열 사이즈가 11개라면 ) medians 의 size는 3이다.
	// medians 는 서브배열의 중간값을 저장할 예정.
	vector<int> *medians = new vector<int>[m];
	// 서브 배열의 갯수 만큼 반복한다.
	for (int i = 0; i < m; i++) {
		// 서브 배열중 마지막 서브 배열인지 확인
		if (5 * i + 4 < n) {
			// w 는 서브 배열의 첫번째 값을 가리킴
			vector<int> *w = v + 5 * i;
			// 서브 배열의 반까지만 정렬
			for (int j0 = 0; j0 < 3; j0++) {
				int jmin = j0;
				for (int j = j0 + 1; j < 5; j++) {
					if (w[j] < w[jmin]) jmin = j;
				}
				swap(w[j0], w[jmin]);
			}
			// 중간값을 구한 뒤 저장
			medians[i] = w[2];
		}
		// 마지막 서브 배열이면 첫번째 값을 저장
		else {
			medians[i] = v[5 * i];
		}
	}
	// 배열의 중간값들을 이용해 pivot 값을 구한다.
	int pivot = MedianOfMedians(medians, m, m / 2);

	// 필요없는 중간값 배열은 삭제한다.
	delete[] medians;

	//pivot 값을 맨 뒤로 보낸다.
	for (int i = 0; i < n; i++) {
		if (v[i] == pivot) {
			swap(v[i], v[n - 1]);
			break;
		}
	}

	// pivot 값과 비교해서 작은 값은 앞에 정렬
	int store = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] < pivot) {
			swap(v[i], v[store++]);
		}
	}
	// 정렬된 값 바로 뒤 값과 pivot값 바꾸기.
	swap(v[store], v[n - 1]);

	// pivot index 값이 찾으려는 index 값과 같다면
	if (store == k) {
		return pivot;
	}
	// pivot index 값이 찾으려는 index 값 보다 크다면
	// 처음부터 pivot-1 사이의 배열에서 탐색시작 
	else if (store > k) {
		return MedianOfMedians(v, store, k);
	}
	// pivot index 값이 찾으려는 index 값보다 작다면
	// pivot+1 부터 끝까지의 배열에서 탐색시작
	else {
		return MedianOfMedians(v + store + 1, n - store - 1, k - store - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize, nMinSize;
	cin >> nSize >> nMinSize;
	vector<int> vArr(nSize);

	for (int i = 0; i < nSize; i++)
		cin >> vArr[i];

	priority_queue<int, vector<int>, greater<int>> pq_Min;
	priority_queue<int> pq_Max;
	int nTemp, nMax;
	nMax = 0;
	for (int i = 0; i <= nSize - nMinSize; i++)
	{
		pq_Min = priority_queue<int, vector<int>, greater<int>>();
		pq_Max = priority_queue<int>();
		for (int j = i; j < nSize; j++)
		{
			nTemp = vArr[j];

			if (pq_Min.size() == pq_Max.size())
				pq_Max.push(nTemp);
			else
				pq_Min.push(nTemp);

			if (!pq_Max.empty() && !pq_Min.empty())
			{
				if (pq_Max.top() > pq_Min.top())
				{
					nTemp = pq_Max.top();
					pq_Max.pop();
					pq_Max.push(pq_Min.top());
					pq_Min.pop();
					pq_Min.push(nTemp);
				}
			}

			if (pq_Max.top() > nMax && pq_Min.size() + pq_Max.size() >= nMinSize)
			{
				nMax = pq_Max.top();
			}
		}
	}

	cout << nMax << '\n';

	system("pause");

	return 0;
}