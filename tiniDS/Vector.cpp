#include "Vector.h"

namespace tinids {
	template<typename T>
	void Vector<T>::copyFrom(T const* source, Rank lo, Rank hi)
	{
		data_ = new T[capacity_ = 2 * (hi - lo)];
		size_ = 0;
		while (lo < hi)
		{
			data_[size_++] = source[lo++];
		}
	}
	template<typename T>
	void Vector<T>::expand()
	{
		if (size_ > capacity_ / 2) {
			T* old_data = data_;
			data_ = new T[capacity_ *= 2];
			for (size_t i = 0; i < size_; i++)
			{
				data_[i] = old_data[i];
			}
			delete[] old_data;
		}
	}
	template<typename T>
	void Vector<T>::shrink()
	{
		if (size_ < capacity_ / 4) {
			T* old_data = data_;
			data_ = new T[capacity_ /= 2];
			for (size_t i = 0; i < size_; i++)
			{
				data_[i] = old_data[i];
			}
			delete[] old_data;
		}
	}
	template<typename T>
	Rank Vector<T>::max(Rank lo, Rank hi)
	{
		Rank res = lo;
		while(lo < hi)
		{
			if (data_[lo] > data_[res]) res = lo;
			++lo;
		}
		return res;
	}

	template<typename T>
	inline Vector<T>::Vector(Rank sz, T v)
	{
		data_ = new T[capacity_ = DEFAULT_CAPACITY];
		for (size_ = 0; size_ < sz; ++size_)
		{
			data_[size_] = v;
		}
	}
	template<typename T>
	Vector<T>::Vector(Vector<T> const& V)
	{
		copyFrom(V.data_, 0, V.size_);
	}
	template<typename T>
	Vector<T>::Vector(Vector<T> const& V, Rank lo, Rank hi)
	{
		copyFrom(V.data_, lo, hi);
	}
	template<typename T>
	Vector<T>::Vector(T const* A, Rank n)
	{
		copyFrom(A, 0, n);
	}
	template<typename T>
	Vector<T>::Vector(T const* A, Rank lo, Rank hi)
	{
		copyFrom(A, lo, hi);
	}
	template<typename T>
	Vector<T>::~Vector()
	{
		if (data_ != nullptr) delete[] data_;
	}
	template<typename T>
	size_t Vector<T>::size() const
	{
		return size_;
	}
	template<typename T>
	bool Vector<T>::empty() const
	{
		return !size_;
	}
	template<typename T>
	Rank Vector<T>::find(T const& e) const
	{
		return find(e, 0, size_);
	}
	template<typename T>
	Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const
	{
		for (size_t i = lo; i < hi; i++)
		{
			if (e == data_[i]) return i;
		}
		return -1;
	}
	template<typename T>
	T& Vector<T>::operator[](Rank r)
	{
		return data_[r];
	}
	template<typename T>
	const T& Vector<T>::operator[](Rank r) const
	{
		return data_[r];
	}
	template<typename T>
	Vector<T>& Vector<T>::operator=(Vector<T> const& V)
	{
		if (data_) delete[] data_;
		copyFrom(V.data_, 0, V.size_);
		return *this;
	}
	template<typename T>
	T Vector<T>::remove(Rank r)
	{
		T e = data_[r];
		remove(r, r + 1);
		return e;
	}
	template<typename T>
	Rank Vector<T>::remove(Rank lo, Rank hi)
	{
		if (lo == hi) return 0;
		hi = hi > size_ ? size_ : hi;
		lo = lo < 0 ? 0 : lo;
		while (hi < size_)
		{
			data_[lo++] = data_[hi++];
		}
		size_ = lo;
		shrink();
		return hi - lo;
	}
	template<typename T>
	void Vector<T>::insert(Rank pos, T const& e)
	{
		++size_;
		for (size_t i = size_ - 1; i > pos; ++i)
		{
			data_[i] = data_[i - 1];
		}
		data_[pos] = e;
		expand();
	}
	template<typename T>
	void Vector<T>::insert(T const& e)
	{
		insert(size_, e);
	}
}