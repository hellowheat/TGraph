
#pragma once
#include"TVector.hpp"

#define DoubleConstruct(Class,Type) \
public:\
	Class()\
		:TVec2<Type>(0, 0)\
	{\
	}\
	Class(Type x, Type y)\
		:TVec2<Type>(x, y)\
	{\
	}\
	Class(Type* data)\
		:TVec2<Type>(data[0], data[1])\
	{\
	}\
	Class(const TVec2<Type>& vec)\
		:TVec2<Type>(vec.GetConstData()[0],vec.GetConstData()[1])\
	{\
	}\
	Class(const TVec<Type,2>& vec)\
		:TVec2<Type>(vec.GetConstData()[0],vec.GetConstData()[1])\
	{\
	}\
	inline Class& operator=(const TVec2<Type>& vec)\
	{\
		this->m_data[0] = vec.GetConstData()[0];\
		this->m_data[1] = vec.GetConstData()[1];\
		return *this;\
	}

namespace TG {
	template<class T>
	class TVec2
		:public TVec<T, 2>
	{
		TInit(TVec2, TVec<T,2>)
	public:
		TVec2();
		TVec2(TVec<T, 2>&vec);
		TVec2(T x, T y);

		T x() const;
		T y() const;

		static const TVec2 normal;//(1,1 )
		static const TVec2 zero;//(0,0 )
		static const TVec2 up;//(0,1 )
		static const TVec2 down;//(0,-1 )
		static const TVec2 left;//(-1,0 )
		static const TVec2 right;//(1,0 )
	};


	template<class T> const TVec2<T> TVec2<T>::normal = { 1, 1 };
	template<class T> const TVec2<T> TVec2<T>::zero = { 0,0 };
	template<class T> const TVec2<T> TVec2<T>::up = { 0,1 };
	template<class T> const TVec2<T> TVec2<T>::down = { 0,-1 };
	template<class T> const TVec2<T> TVec2<T>::left = { -1,0 };
	template<class T> const TVec2<T> TVec2<T>::right = { 1,0 };

	template<class T>
	inline TVec2<T>::TVec2()
		: TVec<T,2>()
	{
	}

	template<class T>
	inline TVec2<T>::TVec2(T x, T y)
	{
		this->m_data[0] = x;
		this->m_data[1] = y;
	}

	template<class T>
	inline T TVec2<T>::x() const
	{
		return this->m_data[0];
	}

	template<class T>
	inline T TVec2<T>::y() const
	{
		return this->m_data[1];
	}


	/*
	* class:
		TVec2f
		TVec2i
		TVec2d
		TVec2l
	*/


	class TVec2f
		:public TVec2<float>
	{
		TInit(TVec2f, TVec2<float>)
		DoubleConstruct(TVec2f, float);
	};

	class TVec2i
		:public TVec2<int>
	{
		TInit(TVec2i, TVec2<int>)
		DoubleConstruct(TVec2i, int);
	};

	class TVec2d
		:public TVec2<double>
	{
		TInit(TVec2d, TVec2<double>)
		DoubleConstruct(TVec2d, double);
	};

	class TVec2l
		:public TVec2<long>
	{
		TInit(TVec2l, TVec2<long>);
		DoubleConstruct(TVec2l, long);
	};
}

