#include <iostream>
#include <vector>

using namespace std;

//custum function
vector<int> getPrimeNum(int limit)
{
	vector<int> primeNumArr;
	vector<bool> primeNumCheck(limit + 1);

	//�����佺�׳׽��� ü
	for (int num(2); num <= limit; ++num)
	{
		//�湮���� ���� ���̸� �Ҽ��̴�
		if (!primeNumCheck[num])
		{
			//�迭�� �߰��ϰ�
			primeNumArr.push_back(num);
			//������� �湮ó�� ���ش�
			int checkNum(num);
			while (checkNum <= limit)
			{
				primeNumCheck[checkNum] = true;
				checkNum += num;
			}
		}
	}

	return primeNumArr;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//�����佺�׳׽��� ü�� Ȱ���Ͽ� �Էµ� �� ������ �Ҽ� �迭�� �����Ѵ�
	//������ �Ҽ� �迭�� ���������� ���� ���鼭 ��ǥ ���̶� �������� Ȯ�� �Ѵ�
	//�� ���� ���� ��ǥ������ Ŀ���� �ش� �ݺ��� �����Ѵ�
	//Declaration
	int target = 0;
	int answer = 0;
	cin >> target;

	//Solution
	vector<int> primeNumArr = getPrimeNum(target);
	//ū ������ Ȯ���Ѵ�.
	for (int index = primeNumArr.size() - 1; index >= 0; --index)
	{
		int sumVal = primeNumArr[index];
		int sumIndex = index;

		//�����ؼ� ���� ���� ��ǥ ���� ��ġ�ϴ��� Ȯ���ϸ鼭 �����ϰ�
		//���� ���� ��ǥ������ Ŀ���� �����Ѵ�
		while (sumVal <= target)
		{
			if (sumVal == target)
			{
				++answer;
				break;
			}

			if (sumIndex > 0)
			{
				sumVal += primeNumArr[--sumIndex];
			}
			else
			{
				break;
			}
		}
	}

	//Output
	cout << answer << '\n';

	return 0;
}