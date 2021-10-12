#include "source.h"
#include <iostream>

namespace sg
{
	bool foo(const Ptr<int>& ptr)
	{
		if (nullptr == ptr)
		{
			return false;
		}
		//blabla
		return true;
	}
}

int main()
{
	int *a = new int(5);
	int *b = new int(8);

	sg::Ptr<int> pa(a);
	sg::Ptr<int> pb(b);

	pa.swap(pb);


	/////////////////////////////////////////////////////////////////////////////////
	//PtrArr

	int *arrA = new int[3]{ 1, 2, 3 };
	int *arrB = new int[3]{ 4, 5, 6 };

	sg::PtrArr<int> paArr(arrA);
	sg::PtrArr<int> pbArr(arrB);

	paArr.swap(pbArr);

	for (int i = 0; i < 3; ++i)
		std::cout << paArr[i] << '\n';

	sg::Ptr<int> test;
	if (sg::foo(test))
	{
		std::cout << "is not Null Ptr\n";
	}
	else
	{
		std::cout << "is Null Ptr\n";
	}
}