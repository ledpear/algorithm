#include "source.h"
#include <algorithm>

namespace sg
{
	/////////////////////////////////////////////////////////////////////////////////
	//Ptr
	//Move assignment operator
	template<class T>
	Ptr<T>& Ptr<T>::operator= (Ptr&& rhs)
	{
		reset(rhs.release());
		return (*this);
	}

	//Modifiers
	template<class T>
	T* Ptr<T>::release()
	{
		T* oldPtr = get();
		_ptr = Ptr();
		return oldPtr;
	}

	template<class T>
	void Ptr<T>::reset(T* newPtr = nullptr)
	{
		T* oldPtr = get();
		_ptr = newPtr;
		if (oldPtr != _ptr)
		{
			if (oldPtr != nullptr)
			{
				delete oldPtr;
			}
		}		
	}

	//Observers
	template<class T>
	void Ptr<T>::swap(Ptr& rhs)
	{
		std::swap(_ptr, rhs._ptr);
	}


	/////////////////////////////////////////////////////////////////////////////////
	//PtrArr

	//Move assignment operator
// 	template<class T>
// 	PtrArr<T>& PtrArr<T>::operator= (PtrArr&& rhs)
// 	{
// 		reset(rhs.release());
// 		return (*this);
// 	}
// 
// 	//Modifiers
// 	template<class T>
// 	T* PtrArr<T>::release()
// 	{
// 		T* oldPtr = get();
// 		_ptr = PtrArr();
// 		return oldPtr;
// 	}
// 
// 	template<class T>
// 	void PtrArr<T>::reset(T* newPtr = nullptr)
// 	{
// 		T* oldPtr = get();
// 		_ptr = newPtr;
// 		if (oldPtr != _ptr)
// 		{
// 			if (oldPtr != nullptr)
// 			{
// 				delete oldPtr;
// 			}
// 		}
// 	}
// 
// 	//Observers
// 	template<class T>
// 	void PtrArr<T>::swap(Ptr& rhs)
// 	{
// 		std::swap(_ptr, rhs._ptr);
// 	}
}

int main()
{
	int a = 5;
	int b = 8;

 	sg::Ptr<int> pa(&a);
 	sg::Ptr<int> pb(&b);

	pa.swap(pb);

	return 0;
}