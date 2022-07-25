
#pragma once
#include"TVector.hpp"
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
	}\
	Class(const TVec3<Type>& vec)\
		:TVec3<Type>(vec.GetConstData()[0],vec.GetConstData()[1],vec.GetConstData()[2])\
	{\
	}\
	Class(const TVec<Type,3>& vec)\
		:TVec3<Type>(vec.GetConstData()[0],vec.GetConstData()[1],vec.GetConstData()[2])\
	{\
	}\
	inline Class& operator=(const TVec3<Type>& vec)\
	{\
		this->m_data[0] = vec.GetConstData()[0];\
		this->m_data[1] = vec.GetConstData()[1];\
		this->m_data[2] = vec.GetConstData()[2];\
		return *this;\
	}

namespace TG {
	//系统是右手系
	template<class T>
	class TVec3
		:public TVec<T, 3>
	{
		TInit(TVec3,TVec<T,3>)
private: 
	public:
		TVec3();
		TVec3(const TVec<T, 3>&vec);
		TVec3(T x, T y, T z);

		T x() const;
		T y() const;
		T z() const;

		static const TVec3 normal;//(1,1,1 )
		static const TVec3 zero;//(0,0,0 )
		static const TVec3 up;//(0,1,0 )
		static const TVec3 down;//(0,-1,0 )
		static const TVec3 left;//(-1,0,0 )
		static const TVec3 right;//(1,0,0 )
		static const TVec3 forward;//(0,0,-1 )
		static const TVec3 back;//(0,0,1 )

		TVec3<T>& operator=(const TVec3<T>& vec);
	};


	template<class T> const TVec3<T> TVec3<T>::normal = { 1, 1, 1 };
	template<class T> const TVec3<T> TVec3<T>::zero = { 0,0,0 };
	template<class T> const TVec3<T> TVec3<T>::up = { 0,1,0 };
	template<class T> const TVec3<T> TVec3<T>::down = { 0,-1,0 };
	template<class T> const TVec3<T> TVec3<T>::left = { -1,0,0 };
	template<class T> const TVec3<T> TVec3<T>::right = { 1,0,0 };
	template<class T> const TVec3<T> TVec3<T>::forward = { 0,0,-1 };
	template<class T> const TVec3<T> TVec3<T>::back = { 0,0,1 };

	template<class T>
	inline TVec3<T>::TVec3()
		:TVec<T,3>()
	{
	}

	template<class T>
	inline TVec3<T>::TVec3(const TVec<T, 3>& vec)
	{
		this->m_data[0] = vec.GetConstData()[0];
		this->m_data[1] = vec.GetConstData()[1];
		this->m_data[2] = vec.GetConstData()[2];
	}

	template<class T>
	inline TVec3<T>::TVec3(T x, T y, T z)
		: TVec<T, 3>()
	{
		this->m_data[0] = x;
		this->m_data[1] = y;
		this->m_data[2] = z;
	}


	template<class T>
	inline T TVec3<T>::x() const
	{
		return this->m_data[0];
	}

	template<class T>
	inline T TVec3<T>::y() const
	{
		return this->m_data[1];
	}

	template<class T>
	inline T TVec3<T>::z() const
	{
		return this->m_data[2];
	}

	template<class T>
	inline TVec3<T>& TVec3<T>::operator=(const TVec3<T> & vec)
	{
		this->m_data[0] = vec.m_data[0];
		this->m_data[1] = vec.m_data[1];
		this->m_data[2] = vec.m_data[2];
		return *this;
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
