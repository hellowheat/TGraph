/*
* v0.1,htp,2022/5/2
*/
#pragma once
#include"TVector.h"
#define TrebleConstruct(Class,Type) \
public:\
	Class()\
		:TVec3<Type>(0, 0, 0)\
	{\
	}\
	Class(Type x, Type y, Type z)\
		:TVec3<Type>(x, y, z)\
	{\
	}\
	Class(Type* data)\
		:TVec3<Type>(data[0], data[1], data[2])\
	{\
	}
namespace TG {

	template<class T>
	class TVec3
		:public TVec<T, 3>
	{
		TInit(TVec3,TVec<T,3>)
private: 
	public:
		TVec3();
		TVec3(T x, T y, T z);

	};

	template<class T>
	inline TVec3<T>::TVec3()
		:TVec<T,3>()
	{
	}

	template<class T>
	inline TVec3<T>::TVec3(T x, T y, T z)
	{
		this->m_data[0] = x;
		this->m_data[1] = y;
		this->m_data[2] = z;
	}


	/*
	* class:
		TVec3f
		TVec3i
		TVec3d
		TVec3l
	*/
	class TVec3f
		:public TVec3<float>
	{
		TInit(TVec3f, TVec3<float>);
		TrebleConstruct(TVec3f, float);
	};

	class TVec3i
		:public TVec3<int>
	{
		TInit(TVec3i, TVec3<int>);
		TrebleConstruct(TVec3i, int);
	};

	class TVec3d
		:public TVec3<double>
	{
		TInit(TVec3d, TVec3<double>);
		TrebleConstruct(TVec3d, double);
	};

	class TVec3l
		:public TVec3<long>
	{
		TInit(TVec3l, TVec3<long>);
		TrebleConstruct(TVec3l, long);
	};
}
