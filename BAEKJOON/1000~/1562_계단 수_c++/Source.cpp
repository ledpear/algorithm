#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

//define

using ull = unsigned long long;
using location = pair<int, int>;
using matrix = vector<vector<int>>;
using dp = vector<vector<vector<int>>>;

const int LIMIT = 1000000000;
//custum function

int DFS(int lastNum, int bitMask, int target, dp &DP, int place = 1)
{
	int result = 0;

	//��ǥ �ڸ����� ���� �ߴٸ� ���ǿ� �´��� Ȯ��
	if (place == target)
	{
		return bitMask == 0b1111111111;
	}

	//������ Ž���ߴ� ��Ȳ�̶�� �ش� �� ��ȯ
	if (DP[place][lastNum][bitMask] != -1)
	{
		return DP[place][lastNum][bitMask];
	}

	//���������� �ö� ��
	int routes[2] = { -1, 1 };
	for (auto route : routes)
	{
		int nextNum = lastNum + route;
		if (0 <= nextNum && nextNum <= 9)
		{
			result = (result + DFS(nextNum, bitMask | (1 << nextNum), target, DP, place + 1)) % LIMIT;
		}
	}

	return DP[place][lastNum][bitMask] = result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//DFS�� Ž���� �Ѵ�.
	//�� ������ Ž���ߴ� ��Ȳ(�ڸ���, �� ���ڸ�, ��Ʈ����ũ)�̶�� �ش� ����� ��ȯ�Ѵ�
	//Declaration
	int target(0), answer(0);
	cin >> target;

	//Solution
	//10�� �ڸ� �̸����� ���ǿ� �´� ���ڰ� ���� �� ����.
	if (target < 10)
	{
		//Output
		cout << "0\n";
	}
	else
	{
		//�޸������̼ǿ� �迭
		dp DP = dp(101, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
		//�� ���ڸ� ���� �����Ͽ� ���ڸ� ����� ���� �� ���ǿ� �´� ���ڸ� Ž��
		//�� ���ڸ��� 0�� ���ڴ� �����Ƿ� 1���� ����
		for (int digit(1); digit < 10; ++digit)
		{
			answer = (answer + DFS(digit, 1 << digit, target, DP)) % LIMIT;
		}

		//Output
		cout << answer << '\n';
	}

	return 0;
}