#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//custum function
//template <typename T>
class BinaryNum
{
public:
	BinaryNum(int nDec = 0)
	{
		clear();
		nDecNumber = nDec;

		if (nDec == 0)
		{
			vBinNumber.push_back(0);
			strNumber += '0';
			return;
		}

		while (nDec > 0)
		{
			vBinNumber.push_back(nDec % 2);
			strNumber = to_string(vBinNumber.back()) + strNumber;
			nDec /= 2;
		}
	}

	BinaryNum& operator=(int nDec)
	{
		clear();
		nDecNumber = nDec;

		if (nDec <= 0)
		{
			vBinNumber.push_back(0);
			strNumber += '0';
		}
		else
		{
			while (nDec > 0)
			{
				vBinNumber.push_back(nDec % 2);
				strNumber = to_string(vBinNumber.back()) + strNumber;
				nDec /= 2;
			}
		}

		return *this;
	}

	int getDec() { return nDecNumber; }
	vector<bool> getBin() { return vBinNumber; }
	string getString() { return strNumber; }

protected:
private:
	vector<bool> vBinNumber;
	int nDecNumber;
	string strNumber;

	void clear()
	{
		nDecNumber = 0;
		vBinNumber.clear();
		strNumber = "";
	}
};

void PrintMap(const vector<vector<int>>& vMap)
{
	int nSizeX = vMap.size();
	int nSizeY = vMap[0].size();

	for (int i = 0; i < nSizeX; i++)
	{
		for (int j = 0; j < nSizeY; j++)
			cout << vMap[i][j] << ' ';
		cout << '\n';
	}
}

int main()
{
    std::cout << "Hello World!\n";
}