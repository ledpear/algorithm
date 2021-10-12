#pragma once
#include <algorithm>

namespace sg
{
	template <typename T>
	class Ptr
	{
	private:
		T* _ptr;
		void deleter() { if (_ptr != nullptr) delete _ptr; }
	public:
		explicit Ptr(T* readPtr = nullptr) : _ptr(readPtr) {}
		~Ptr() { deleter(); }
		
		//Copy constructor
		Ptr(const Ptr& rhs) = delete;
		//Move constructor
		Ptr(Ptr&& rhs) : _ptr(rhs->release()) {}
		//Assignment operator
		Ptr& operator= (const Ptr& rhs) = delete;
		//Move assignment operator
		Ptr& operator= (Ptr&& rhs)
		{
			reset(rhs.release());
			return (*this);
		}

		//Modifiers
		T* release()
		{
			T* oldPtr = get();
			_ptr = Ptr();
			return oldPtr;
		}
		void reset(T* newPtr = nullptr)
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
		void swap(Ptr& rhs)
		{
			std::swap(_ptr, rhs._ptr);
		}

		//Observers
		T* get() const { return _ptr; }
		//get_deleter();
		explicit operator bool() const { return (get() != nullptr); }

		//Single-object version
		T& operator*() const { return *_ptr };
		T* operator->() const { return _ptr };
	};

  	template <typename T>
  	class PtrArr
  	{
  	private:
  		T* _ptr;
 		void deleter() { if (_ptr != nullptr) delete[] _ptr; }
  	public:
 		explicit PtrArr(T* readPtr = nullptr) : _ptr(readPtr) {}
 		~PtrArr() { deleter(); }
 
 		//Copy constructor
 		PtrArr(const PtrArr& rhs) = delete;
 		//Move constructor
 		PtrArr(PtrArr&& rhs) : PtrArr(rhs->release()) {}
 		//Assignment operator
 		PtrArr& operator= (const PtrArr& rhs) = delete;
 		//Move assignment operator
 		PtrArr& operator= (PtrArr&& rhs)
		{
			reset(rhs.release());
			return (*this);
		}
 
 		//Modifiers
 		T* release()
		{
			T* oldPtr = get();
			_ptr = PtrArr();
			return oldPtr;
		}
 		void reset(T* newPtr = nullptr)
		{
			T* oldPtr = get();
			_ptr = newPtr;
			if (oldPtr != _ptr)
			{
				if (nullptr != oldPtr)
				{
					delete[] oldPtr;
				}
			}
		}
 		void swap(PtrArr& rhs)
		{
			std::swap(_ptr, rhs._ptr);
		}
 
 		//Observers
 		T* get() const { return _ptr; }
 		//get_deleter();
 		explicit operator bool() const { return (get() != nullptr); }
  
  		//Array version
		T& operator[](size_t idx) const { return (get()[idx]); }
  	}; 	


}