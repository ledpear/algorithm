#pragma once

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
		Ptr& operator= (Ptr&& rhs);

		//Modifiers
		T* release();
		void reset(T* newPtr = nullptr);
		void swap(Ptr& rhs);

		//Observers
		T* get() const { return _ptr; }
		//get_deleter();
		explicit operator bool() const { return (get() != Ptr()); }

		//Single-object version
		T& operator*() const { return *_ptr };
		T* operator->() const { return _ptr };
	};

//  	template <typename T>
//  	class PtrArr
//  	{
//  	private:
//  		T* _ptr;
// 		void deleter() { if (_ptr != nullptr) delete[] _ptr; }
//  	public:
// 		explicit Ptr(T* readPtr = nullptr) : _ptr(readPtr) {}
// 		~Ptr() { deleter(); }
// 
// 		//Copy constructor
// 		Ptr(const Ptr& rhs) = delete;
// 		//Move constructor
// 		Ptr(Ptr&& rhs) : _ptr(rhs->release()) {}
// 		//Assignment operator
// 		Ptr& operator= (const Ptr& rhs) = delete;
// 		//Move assignment operator
// 		Ptr& operator= (Ptr&& rhs);
// 
// 		//Modifiers
// 		T* release();
// 		void reset(T* newPtr = nullptr);
// 		void swap(Ptr& rhs);
// 
// 		//Observers
// 		T* get() const { return _ptr; }
// 		//get_deleter();
// 		explicit operator bool() const { return (get() != Ptr()); }
//  
//  		//Array version
//  		T& operator[](int index);
//  	};
}