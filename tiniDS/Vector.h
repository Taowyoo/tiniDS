#pragma once
namespace tinids {
	typedef int Rank;
#define DEFAULT_CAPACITY  3 

	template <typename T>
	class Vector
	{
	protected:
		Rank size_;
		Rank capacity_;
		T* data_;
		void copyFrom(T const* source, Rank lo, Rank hi);
		void expand();
		void shrink();
		Rank max(Rank lo, Rank hi); //选取最大元素

	public:
		// constuctor
		Vector(Rank sz = 0, T v = 0);
		Vector(Vector<T> const& V);
		Vector(Vector<T> const& V, Rank lo, Rank hi);
		Vector(T const* A, Rank n); //数组整体复制
		Vector(T const* A, Rank lo, Rank hi); //区间
		// deconstuctor
		~Vector();
		// read only access
		size_t size() const;
		bool empty() const;
		Rank find(T const& e) const;
		Rank find(T const& e, Rank lo, Rank hi) const;
		// editable access
		T& operator[] (Rank r); //重载下标操作符，可以类似于数组形式引用各元素
		const T& operator[] (Rank r) const; //仅限于做右值的重载版本
		Vector<T>& operator= (Vector<T> const& V); //重载赋值操作符，以便直接克隆向量
		// Dynamic operation
		T remove(Rank r);
		Rank remove(Rank lo, Rank hi);
		void insert(Rank pos, T const& e);
		void insert(T const& e);
	};   // Class Vector

}  // namespace tinids


