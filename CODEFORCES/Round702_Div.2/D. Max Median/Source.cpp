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

	// �迭�� 1 ���� �� �ۿ� ���ų� ã������ ���� ù��° ���̸�
	// ù��° ���� ��ȯ�Ѵ�.
	if (n == 1 && k == 0) return v[0];

	// �迭�� ���� 5���� ���� �迭�� ������.
	// �ø� �ϱ� ���� �迭 ����� 4�� ���ϰ� 5�� ������.
	// m �� ���� �迭 �� ���� ������ �ϴ��� ��Ÿ����.
	int m = (n + 4) / 5;
	// �迭�� �ּҰ��� �����ϴ� �迭 m size ��ŭ �����. 
	// (������� �迭 ����� 11����� ) medians �� size�� 3�̴�.
	// medians �� ����迭�� �߰����� ������ ����.
	vector<int> *medians = new vector<int>[m];
	// ���� �迭�� ���� ��ŭ �ݺ��Ѵ�.
	for (int i = 0; i < m; i++) {
		// ���� �迭�� ������ ���� �迭���� Ȯ��
		if (5 * i + 4 < n) {
			// w �� ���� �迭�� ù��° ���� ����Ŵ
			vector<int> *w = v + 5 * i;
			// ���� �迭�� �ݱ����� ����
			for (int j0 = 0; j0 < 3; j0++) {
				int jmin = j0;
				for (int j = j0 + 1; j < 5; j++) {
					if (w[j] < w[jmin]) jmin = j;
				}
				swap(w[j0], w[jmin]);
			}
			// �߰����� ���� �� ����
			medians[i] = w[2];
		}
		// ������ ���� �迭�̸� ù��° ���� ����
		else {
			medians[i] = v[5 * i];
		}
	}
	// �迭�� �߰������� �̿��� pivot ���� ���Ѵ�.
	int pivot = MedianOfMedians(medians, m, m / 2);

	// �ʿ���� �߰��� �迭�� �����Ѵ�.
	delete[] medians;

	//pivot ���� �� �ڷ� ������.
	for (int i = 0; i < n; i++) {
		if (v[i] == pivot) {
			swap(v[i], v[n - 1]);
			break;
		}
	}

	// pivot ���� ���ؼ� ���� ���� �տ� ����
	int store = 0;
	for (int i = 0; i < n - 1; i++) {
		if (v[i] < pivot) {
			swap(v[i], v[store++]);
		}
	}
	// ���ĵ� �� �ٷ� �� ���� pivot�� �ٲٱ�.
	swap(v[store], v[n - 1]);

	// pivot index ���� ã������ index ���� ���ٸ�
	if (store == k) {
		return pivot;
	}
	// pivot index ���� ã������ index �� ���� ũ�ٸ�
	// ó������ pivot-1 ������ �迭���� Ž������ 
	else if (store > k) {
		return MedianOfMedians(v, store, k);
	}
	// pivot index ���� ã������ index ������ �۴ٸ�
	// pivot+1 ���� �������� �迭���� Ž������
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