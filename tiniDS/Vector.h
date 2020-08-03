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
		Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��
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
		Vector(T const* A, Rank n); //�������帴��
		Vector(T const* A, Rank lo, Rank hi); //����
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
		T& operator[] (Rank r); //�����±������������������������ʽ���ø�Ԫ��
		const T& operator[] (Rank r) const; //����������ֵ�����ذ汾
		Vector<T>& operator= (Vector<T> const& V); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
		T remove(Rank r);
		Rank remove(Rank lo, Rank hi);
		Rank insert(Rank pos, T const& e);
		Rank insert(T const& e);
		void sort();
		void sort(Rank lo, Rank hi);
		void unsort();
		void unsort(Rank lo, Rank hi);
		int deduplicate(); //����ȥ��
		int uniquify(); //����ȥ��
		// traverse
		void traverse(void (*) (T&)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
		template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�
	};   // Class Vector

	

}  // namespace tinids


