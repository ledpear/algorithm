#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

typedef struct node
{
	int data;
	struct node* FrontLink = nullptr;
	struct node* BackLink = nullptr;
};

class cDeque
{
public:
	cDeque()
	{
		nSize = 0;
		bEmpty = true;
		nFront = nullptr;
		nBack = nullptr;
	};

	int size() { return nSize; };
	bool empty() { return bEmpty; };
	int front()
	{
		if (bEmpty)
			return -1;
		else
			return nFront->data;
	}
	int back()
	{
		if (bEmpty)
			return -1;
		else
			return nBack->data;
	}
	void push_front(int num)
	{
		node* nTemp = new node;
		nTemp->data = num;
		if (bEmpty)
		{
			nFront = nTemp;
			nBack = nTemp;
			bEmpty = false;
		}
		else
		{
			nFront->FrontLink = nTemp;
			nTemp->BackLink = nFront;
			nFront = nTemp;
		}
		nSize++;
	}
	void push_back(int num)
	{
		node* nTemp = new node;
		nTemp->data = num;
		if (bEmpty)
		{
			nFront = nTemp;
			nBack = nTemp;
			bEmpty = false;
		}
		else
		{
			nBack->BackLink = nTemp;
			nTemp->FrontLink = nBack;
			nBack = nTemp;
		}
		nSize++;
	}
	int pop_front()
	{
		if (bEmpty)
			return -1;
		else
		{			
			node* nTemp = nFront;
			int nOutput = nTemp->data;
			nFront = nTemp->BackLink;
			delete(nTemp);
			nSize--;
			if (nSize == 0)
			{
				bEmpty = true;
				nFront = nullptr;
				nBack = nullptr;
			}

			return nOutput;
		}
	}
	int pop_back()
	{
		if (bEmpty)
			return -1;
		else
		{
			node* nTemp = nBack;
			int nOutput = nTemp->data;
			nBack = nTemp->FrontLink;
			delete(nTemp);
			nSize--;
			if (nSize == 0)
			{
				bEmpty = true;
				nFront = nullptr;
				nBack = nullptr;
			}

			return nOutput;
		}
	}
protected:
private:
	int nSize;
	bool bEmpty;
	node* nFront;
	node* nBack;
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int nSize;
	cin >> nSize;
	string strInput;
	cDeque dp;
	for (int i = 0; i < nSize; i++)
	{
		cin >> strInput;
		if (strInput == "push_front")
		{
			int nTemp;
			cin >> nTemp;
			dp.push_front(nTemp);
		}
		else if (strInput == "push_back")
		{
			int nTemp;
			cin >> nTemp;
			dp.push_back(nTemp);
		}
		else if (strInput == "pop_front")
		{
			cout << dp.pop_front() << '\n';
		}
		else if (strInput == "pop_back")
		{
			cout << dp.pop_back() << '\n';
		}
		else if (strInput == "size")
		{
			cout << dp.size() << '\n';
		}
		else if (strInput == "empty")
		{
			cout << dp.empty() << '\n';
		}
		else if (strInput == "front")
		{
			cout << dp.front() << '\n';
		}
		else if (strInput == "back")
		{
			cout << dp.back() << '\n';
		}
	}

	system("pause");

	return 0;
}