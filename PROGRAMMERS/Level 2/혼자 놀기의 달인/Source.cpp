#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int playGame(const vector<int>& cards, vector<bool>& opend, int start)
{
	//결과는 점수(오픈한 상자 수)
	int num = start;
	int count = 0;
	while (opend.at(num) == false)
	{
		opend[num] = true;
		++count;
		num = cards[num] - 1;
	}

	//만약 1번그룹에서 다 오픈한다면 처리해줘야한다
	//count가 cards의 size와 같으면 return 0한다
	if (cards.size() == count)
		return 0;

	return count;
}

int solution(vector<int> cards) 
{
	//0부터 순회하면서 1번 그룹과 2번그룹을 계산한다
	//전체 순회하여 가장 높은 점수을 반환
	//순회하는건 solution에서 하고 게임은 함수를 따로 만들어서 진행
	int answer = 0;
	const int size = cards.size();

	for (int i = 0; i < size - 1; ++i)
	{
		vector<bool> opend(size);

		//1번 그룹 게임
		int firstScore = playGame(cards, opend, i);

		//1번에서 다 돌아버렸다
		if (firstScore == 0)
			continue;

		int secondBestScore = 0;
		for (int j = i + 1; j < size; ++j)
		{
			//2번 그룹
			//1번 그룹에서 열었던 상자는 넘어간다
			if (opend.at(j) == true)
				continue;

			//1번 그룹이 돈 결과는 동일하니깐 배열 새로 만들어서 사용
			vector<bool> secondOpend = opend;

			//2번 그룹 게임
			int secondScore = playGame(cards, secondOpend, j);

			//점수 갱신
			if (secondBestScore < secondScore)
				secondBestScore = secondScore;
		}

		//최고 점수 등록
		const int totalScore = firstScore * secondBestScore;
		if (answer < totalScore)
			answer = totalScore;
	}

	return answer;
}

int main()
{
	return 0;
}