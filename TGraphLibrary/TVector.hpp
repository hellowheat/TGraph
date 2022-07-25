
#pragma once
#include"TObject.hpp"
namespace TG {
	//Vector
	template<class T,int N>
	class TVec
		:public TObj
	{
		TInit(TVec,TObj)
	public:
		TVec();
		TVec(T data);//Fill
		TVec(T*& data);
		TVec(const TVec& vec);
		T* GetData();
		const T* GetConstData() const;

		double Norm(int n) const;//·¶Êý
		double Length() const;
		void Normalize();
		TVec<T,N> Normalized() const;
		double Dot(TVec<T, N>vec) const;

		T operator[](int index);
		template<class B> TVec<T, N> operator+(const TVec<B, N>& vec) const;
		template<class B> TVec<T, N> operator-(const TVec<B, N>& vec) const;
		TVec<T, N> operator*(const double num) const;
		T operator*(const TVec<T, N>& vec) const;
		template<class B> bool operator==(const TVec<B, N>& vec) const;
		template<class B> bool operator!=(const TVec<B, N>& vec) const;

	protected:
		T m_data[N];
	}; 
	

	template<class T, int N> TVec<T, N> operator*(const double num,const TVec<T, N> vec) {
		return vec * num;
	}

	template<class T, int N>
	inline std::ostream& operator<<(std::ostream& os, TVec<T,N> obj) {
		os << "(";
		for(int i =0;i<N;i++)
		 os << (","+!i) << obj.GetData()[i];
		os << ")";
		 return os;
	}

	template<class T, int N>
	inline TVec<T, N>::TVec()
		:TObj()
	{

	}

	template<class T, int N>
	inline TVec<T, N>::TVec(T data)
	{
		for (int i = 0; i < N; i++)
			m_data[i] = data;
	}

	template<class T, int N>
	inline TVec<T, N>::TVec(T*& data)
	{
		for (int i = 0; i < N; i++)
			m_data[i] = data[i];
	}

	template<class T, int N>
	inline TVec<T, N>::TVec(const TVec& vec)
		:TObj()
	{
		for (int i = 0; i < N; i++) {
			m_data[i] = vec.m_data[i];
		}
	}

	template<class T, int N>
	inline T* TVec<T, N>::GetData()
	{
		return &m_data[0];
	}
	template<class T, int N>
	inline const T* TVec<T, N>::GetConstData() const
	{
		return m_data;
	}
	template<class T, int N>
	inline double TVec<T, N>::Norm(int n) const
	{
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += pow(abs(m_data[i], n));
		}
		return pow(sum, 1.0 / n);
	}
	template<class T, int N>
	inline double TVec<T, N>::Length() const
	{
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum += m_data[i] * m_data[i];
		}
		return sqrt(sum);
	}
	template<class T, int N>
	inline void TVec<T, N>::Normalize()
	{
		double len = Length();
		for (int i = 0; i < N; i++) {
			m_data[i] /= len;
		}
	}
	template<class T, int N>
	inline TVec<T, N> TVec<T, N>::Normalized() const
	{
		TVec<T, N>ans;

		double len = Length();
		for (int i = 0; i < N; i++) {
			ans.m_data[i] = m_data[i] / len;
		}
		return ans;
	}
	template<class T, int N>
	inline double TVec<T, N>::Dot(TVec<T, N> vec) const
	{
		double sum = 0;
		for (int i = 0; i < N; i++) {
			sum = m_data[i] * vec.m_data[i];
		}
		return sqrt(sum);
	}
	template<class T, int N>
	inline T TVec<T, N>::operator[](int index)
	{
		return m_data[index];
	}
	
	template<class T, int N>
	template<class B>
	inline TVec<T, N> TVec<T, N>::operator+(const TVec<B, N>& vec) const
	{
		TVec<T, N> ans;
		for (int i = 0; i < N; i++) {
			ans.m_data[i] = this->m_data[i] + vec.m_data[i];
		}
		return ans;
	}
	template<class T, int N>
	template<class B>
	inline TVec<T, N> TVec<T, N>::operator-(const TVec<B, N>& vec) const
	{
		TVec<T, N> ans;
		for (int i = 0; i < N; i++) {
			ans.m_data[i] = this->m_data[i] - vec.m_data[i];
		}
		return ans;
	}
	
	template<class T, int N>
	inline TVec<T, N> TVec<T, N>::operator*(const double num) const
	{
		TVec<T, N> ans;
		for (int i = 0; i < N; i++) {
			ans.m_data[i] = this->m_data[i] * num;
		}
		return ans;
	}
	template<class T, int N>
	inline T TVec<T, N>::operator*(const TVec<T, N>& vec) const
	{
		T ans = 0;
		for (int i = 0; i < N; i++) {
			ans += this->m_data[i] * vec.m_data[i];
		}
		return ans;
	}
	template<class T, int N>
	template<class B>
	inline bool TVec<T, N>::operator==(const TVec<B, N>& vec) const
	{
		for (int i = 0; i < N; i++) {
			if (this->m_data[i] != vec.m_data[i])return false;
		}
		return true;
	}

	template<class T, int N>
	template<class B>
	inline bool TVec<T, N>::operator!=(const TVec<B, N>& vec) const
	{
		for (int i = 0; i < N; i++) {
			if (this->m_data[i] != vec.m_data[i])return true;
		}
		return true;
	}
}

