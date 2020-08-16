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
		Rank max(Rank lo, Rank hi); //ѡȡ���Ԫ��

	public:
		// constuctor
		Vector(Rank sz = 0, T v = 0);
		Vector(Vector<T> const& V);
		Vector(Vector<T> const& V, Rank lo, Rank hi);
		Vector(T const* A, Rank n); //�������帴��
		Vector(T const* A, Rank lo, Rank hi); //����
		// deconstuctor
		~Vector();
		// read only access
		size_t size() const;
		bool empty() const;
		Rank find(T const& e) const;
		Rank find(T const& e, Rank lo, Rank hi) const;
		// editable access
		T& operator[] (Rank r); //�����±������������������������ʽ���ø�Ԫ��
		const T& operator[] (Rank r) const; //����������ֵ�����ذ汾
		Vector<T>& operator= (Vector<T> const& V); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
		// Dynamic operation
		T remove(Rank r);
		Rank remove(Rank lo, Rank hi);
		void insert(Rank pos, T const& e);
		void insert(T const& e);
	};   // Class Vector

}  // namespace tinids


