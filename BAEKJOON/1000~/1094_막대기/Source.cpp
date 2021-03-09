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

using namespace std;

//define
#define DEF_MIN -2147483648
#define DEF_MAX 2147483647

typedef unsigned long long ull;
typedef pair<ull, ull> p;
typedef vector<vector<int>> vmap;

//custum function
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	////////////////////////////////////
	//Declaration
	int nInput;
	BinaryNum binNum;
	vector<bool> vBin;
	int nResult = 0;

	//Input
	cin >> nInput;
	//binNum = BinaryNum(nInput);
	binNum = nInput;

	//Solution
	
	vBin = binNum.getBin();

	for (int i = 0; i < vBin.size(); i++)
	{
		if (vBin[i] == 1)
			nResult++;
	}

	//Output
	cout << nResult << '\n';

	////////////////////////////////////
	system("pause");
	return 0;
}