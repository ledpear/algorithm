#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef struct node
{
	int data;
	struct node* link;
};

class cQueue
{
public:
	cQueue()
	{
		m_bEmpty = true;
		m_nSize = 0;
		m_nFront = nullptr;
		m_nback = nullptr;
	};
	int GetSize() { return m_nSize; };
	bool GetEmpty() { return m_bEmpty; };
	int GetFront()
	{
		if (m_bEmpty)
			return -1;
		else
			return m_nFront->data;
	};
	int GetBack()
	{
		if (m_bEmpty)
			return -1;
		else
			return m_nback->data;
	};
	void Push(int input)
	{
		node* nTemp = new node;
		nTemp->data = input;
		nTemp->link = nullptr;
		if (m_nFront == nullptr)
		{
			m_nFront = nTemp;
		}
		if (m_nback == nullptr)
		{
			m_nback = nTemp;
		}
		else
		{
			m_nback->link = nTemp;
			m_nback = nTemp;
		}
		m_nSize++;
		m_bEmpty = false;
	};
	int Pop()
	{
		if (m_bEmpty)
			return -1;

		node* nTemp = m_nFront;
		int nOutput = nTemp->data;
		m_nFront = nTemp->link;
		m_nSize--;

		delete(nTemp);
		if (m_nSize == 0)
		{
			m_bEmpty = true;
			m_nback = nullptr;
		}

		return nOutput;
	};

protected:
private:
	bool	m_bEmpty;
	node*	m_nFront;
	node*	m_nback;
	int		m_nSize;
};

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int nSize;
	cin >> nSize;
	string strCommand;
	cQueue qu;
	for (int i = 0; i < nSize; i++)
	{
		cin >> strCommand;

		if (strCommand == "push")
		{
			int input;
			cin >> input;
			qu.Push(input);
		}
		if (strCommand == "pop")
		{
			cout << qu.Pop() << '\n';
		}
		if (strCommand == "size")
		{
			cout << qu.GetSize() << '\n';
		}
		if (strCommand == "empty")
		{
			cout << qu.GetEmpty() << '\n';
		}
		if (strCommand == "front")
		{
			cout << qu.GetFront() << '\n';
		}
		if (strCommand == "back")
		{
			cout << qu.GetBack() << '\n';
		}
	}

	system("pause");

	return 0;
}