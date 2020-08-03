#pragma once
namespace tinids {
	typedef int Rank;

	template <typename T>
	class Vector
	{
	protected:
		Rank size_;
		Rank capacity_;
		T* data_;
		void copyFrome(T const* source, Rank lo, Rank hi);
		void expand();
		void shrink();
		Rank max(Rank lo, Rank hi); //选取最大元素
		void bubbleSort(Rank lo, Rank hi);
		void selectionSort(Rank lo, Rank hi);
		void mergeSort(Rank lo, Rank hi);
		void heapSort(Rank lo, Rank hi);
		void quickSort(Rank lo, Rank hi);
		void shellSort(Rank lo, Rank hi);

	public:
		// constuctor
		Vector(Rank sz = 0, T v = 0);
		Vector(Vector<T> const& V, Rank n);
		Vector(Vector<T> const& V, Rank lo, Rank hi);
		Vector(T const* A, Rank n); //数组整体复制
		Vector(T const* A, Rank lo, Rank hi); //区间
		// deconstuctor
		~Vector();
		// read only access
		Rank size() const;
		bool empty() const;
		Rank find(T const& e) const;
		Rank find(T const& e, Rank lo, Rank hi) const;
		Rank search(T const& e) const;
		Rank search(T const& e, Rank lo, Rank hi) const;
		// editable access
		T& operator[] (Rank r); //重载下标操作符，可以类似于数组形式引用各元素
		const T& operator[] (Rank r) const; //仅限于做右值的重载版本
		Vector<T>& operator= (Vector<T> const& V); //重载赋值操作符，以便直接克隆向量
		T remove(Rank r);
		Rank remove(Rank lo, Rank hi);
		Rank insert(Rank pos, T const& e);
		Rank insert(T const& e);
		void sort();
		void sort(Rank lo, Rank hi);
		void unsort();
		void unsort(Rank lo, Rank hi);
		int deduplicate(); //无序去重
		int uniquify(); //有序去重
		// traverse
		void traverse(void (*) (T&)); //遍历（使用函数指针，只读或局部性修改）
		template <typename VST> void traverse(VST&); //遍历（使用函数对象，可全局性修改）
	};   // Class Vector

	

}  // namespace tinids


