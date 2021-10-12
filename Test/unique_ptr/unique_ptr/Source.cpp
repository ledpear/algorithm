#include "source.h"
#include <algorithm>
#include <iostream>

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

}