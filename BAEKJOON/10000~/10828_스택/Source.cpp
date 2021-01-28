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

class cStack
{
public:
	cStack() {
		m_bEmpty = true;
		m_nSize = 0;
		m_pTop = nullptr;
	}
	bool getEmpty() { return m_bEmpty; };
	int getSize() { return m_nSize; };
	int getTop() 
	{ 
		if (m_bEmpty)
			return -1;
		else
			return m_pTop->data; 
	};
	void Push(int num)
	{
		node *nNode = new node;
		nNode->data = num;
		if (m_pTop != nullptr)
			nNode->link = m_pTop;
		else
			nNode->link = nullptr;

		m_pTop = nNode;
		m_bEmpty = false;
		m_nSize++;
	};
	int Pop() 
	{
		if (!m_bEmpty)
		{
			node *nNode = m_pTop;
			int nTemp = m_pTop->data;
			m_pTop = m_pTop->link;
			m_nSize--;
			if (m_nSize == 0)
				m_bEmpty = true;
			delete(nNode);
			return nTemp;
		}
		else
			return -1;		
	};
protected:
private:
	
	bool m_bEmpty;
	int m_nSize;
	node * m_pTop;
};

int main()
{
	int nCount;
	cin >> nCount;
	cStack custumStack;
	for (int i = 0; i < nCount; i++)
	{
		string strCommand;
		cin >> strCommand;

		if (strCommand.compare("push") == 0)
		{
			int nTemp;
			cin >> nTemp;
			custumStack.Push(nTemp);
		}
		if (strCommand.compare("pop") == 0)
		{
			cout << custumStack.Pop() << '\n';
		}
		if (strCommand.compare("size") == 0)
		{
			cout << custumStack.getSize() << '\n';
		}
		if (strCommand.compare("empty") == 0)
		{
			cout << custumStack.getEmpty() << '\n';
		}
		if (strCommand.compare("top") == 0)
		{
			cout << custumStack.getTop() << '\n';
		}
	}

	system("pause");
	return 0;
}