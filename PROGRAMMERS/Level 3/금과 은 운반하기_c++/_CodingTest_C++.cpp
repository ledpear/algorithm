#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>

#include <queue>

using namespace std;

struct Info
{
    int gold;
    int silver;
    int weight;
    int time;
    int nextTime = 0;

    Info(int g, int s, int w, int t) 
        : gold(g), silver(s), weight(w), time(t) 
    {
        nextTime = time;
    }
};

struct comp
{
    bool operator()(const Info& lhs, const Info& rhs)
    {
        return lhs.nextTime > rhs.nextTime;
    }
};

//트럭은 각 마을마다 있고 동시 운용이 가능하다
//a는 필요한 금, b는 필요한 은
//g는 각 마을별 금, s는 각 마을별 은
//w는 각 마을별 트럭의 운용가능 무게, t는 시간

//금을 다 모을수 있는 최소시간
//은을 다 모을수 있는 최소시간
//각각 구한 후 더 큰쪽으로 했을때 반대쪽이 넘지 않으면 그게 최소가 될듯

//금을 우선시 했을때 최소시간
//은을 우선시 했을때 최소시간
//중 더 적은 시간

//우선순위 큐를 사용해서 정렬한다


int simulation(priority_queue<Info, vector<Info>, comp> pq, int needGold, int needSilver, bool isGoldFirst)
{
    int currTime = 0;
    int currFirst = 0, currSecond = 0;
    int needFirst = isGoldFirst ? needGold : needSilver;
    int needSecond = isGoldFirst ? needSilver : needGold;

    while (currFirst < needFirst || currSecond < needSecond)
    {
        //다음차례
        Info truck = pq.top();
        pq.pop();

        //시간 경과
        if (currTime < truck.nextTime)
            currTime = truck.nextTime;

        //우선순위 적용
        int& firstMetal = isGoldFirst ? truck.gold : truck.silver;
        int& secondMetal = isGoldFirst ? truck.silver : truck.gold;

        //gold 이동
        int moveFirst = firstMetal > truck.weight ? truck.weight : firstMetal;
        if (needFirst - currFirst < moveFirst)
            moveFirst = needFirst - currFirst;

        firstMetal -= moveFirst;
        currFirst += moveFirst;

        //silver 이동
        if (moveFirst != truck.weight)
        {
            int posibleWdight = truck.weight - moveFirst;
            int moveSecond = secondMetal > posibleWdight ? posibleWdight : secondMetal;
            secondMetal -= moveSecond;
            currSecond += moveSecond;
        }

        //시간 갱신 및 큐에 추가
        if (truck.gold != 0 || truck.silver != 0)
        {
            truck.nextTime += truck.time * 2;
            pq.push(truck);
        }
    }

    return currTime;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) 
{
    long long answer = -1;

    priority_queue<Info, vector<Info>, comp> ori_pq;
    for (int i = 0; i < g.size(); ++i)
        ori_pq.push(Info(g[i], s[i], w[i], t[i]));

    int minGold = simulation(ori_pq, a, b, true);
    int minSilver = simulation(ori_pq, a, b, false);
    int minTime = minGold < minSilver ? minGold : minSilver ;

    return minTime;
}

int main()
{
    //solution(10, 10, { 100 }, { 100 }, { 7 }, { 10 });
    //solution(90, 500, { 70,70,0 }, { 0,0,500 }, { 100,100,2 }, { 4,8,1 });
    solution(100, 100, { 70,10,100 }, { 10,40,100 }, {25,10,5 }, { 2,3,5 });
}