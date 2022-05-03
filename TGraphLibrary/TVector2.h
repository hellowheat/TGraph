/*
* v0.1,htp,2022/5/2
*/
#pragma once
#include"TVector.h"

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
	}

namespace TG {
	template<class T>
	class TVec2
		:public TVec<T, 2>
	{
		TInit(TVec2, TVec<T,2>)
	public:
		TVec2();
		TVec2(T x, T y);
	};

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

