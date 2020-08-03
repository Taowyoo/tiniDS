#include "Vector.h"

namespace tinids {
	template<typename T>
	inline void Vector<T>::copyFrome(T const* source, Rank lo, Rank hi)
	{

	}
	template<typename T>
	void Vector<T>::expand()
	{
	}
	template<typename T>
	void Vector<T>::shrink()
	{
	}
	template<typename T>
	Rank Vector<T>::max(Rank lo, Rank hi)
	{
		return Rank();
	}

	template<typename T>
	void Vector<T>::bubbleSort(Rank lo, Rank hi)
	{
	}

	template<typename T>
	void Vector<T>::selectionSort(Rank lo, Rank hi)
	{
	}
	template<typename T>
	inline Vector<T>::Vector(Rank sz, T v)
	{
	}
	template<typename T>
	Vector<T>::Vector(Vector<T> const& V, Rank n)
	{
	}
	template<typename T>
	Vector<T>::Vector(Vector<T> const& V, Rank lo, Rank hi)
	{
	}
	template<typename T>
	Vector<T>::Vector(T const* A, Rank n)
	{
	}
	template<typename T>
	Vector<T>::Vector(T const* A, Rank lo, Rank hi)
	{
	}
	template<typename T>
	Vector<T>::~Vector()
	{
	}
	template<typename T>
	Rank Vector<T>::size() const
	{
		return Rank();
	}
	template<typename T>
	bool Vector<T>::empty() const
	{
		return false;
	}
	template<typename T>
	Rank Vector<T>::find(T const& e) const
	{
		return Rank();
	}
	template<typename T>
	Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const
	{
		return Rank();
	}
	template<typename T>
	Rank Vector<T>::search(T const& e) const
	{
		return Rank();
	}
	template<typename T>
	Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const
	{
		return Rank();
	}
	template<typename T>
	T& Vector<T>::operator[](Rank r)
	{
		// TODO: insert return statement here
	}
	template<typename T>
	const T& Vector<T>::operator[](Rank r) const
	{
		// TODO: insert return statement here
	}
	template<typename T>
	Vector<T>& Vector<T>::operator=(Vector<T> const& V)
	{
		// TODO: insert return statement here
	}
	template<typename T>
	T Vector<T>::remove(Rank r)
	{
		return T();
	}
	template<typename T>
	Rank Vector<T>::remove(Rank lo, Rank hi)
	{
		return Rank();
	}
	template<typename T>
	Rank Vector<T>::insert(Rank pos, T const& e)
	{
		return Rank();
	}
	template<typename T>
	Rank Vector<T>::insert(T const& e)
	{
		return Rank();
	}
	template<typename T>
	void Vector<T>::sort()
	{
	}
	template<typename T>
	void Vector<T>::sort(Rank lo, Rank hi)
	{
	}
	template<typename T>
	void Vector<T>::unsort()
	{
	}
	template<typename T>
	void Vector<T>::unsort(Rank lo, Rank hi)
	{
	}
	template<typename T>
	int Vector<T>::deduplicate()
	{
		return 0;
	}
	template<typename T>
	int Vector<T>::uniquify()
	{
		return 0;
	}
	template<typename T>
	template<typename VST>
	inline void Vector<T>::traverse(VST&)
	{
	}
}