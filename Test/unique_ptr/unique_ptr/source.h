#pragma once

namespace sg
{
	template <typename T>
	class Ptr
	{
	private:
		T* _ptr;
	};

	template <typename T>
	class PtrArr
	{
	private:
		T* _ptr;
	};
}