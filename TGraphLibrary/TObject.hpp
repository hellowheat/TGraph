/*
* v0.1,htp,2022/5/2
* v0.12,htp,2022/5/3.
*	add toSub method
*/
#pragma once
#include<string>
#include<iostream>
namespace TG {
	//初始化,涉及模板类时，第一个参数为子类不写模板参数，第二个参数为父类要写
#define TInit(...) TCONNECT(TInit,TCOUNT(__VA_ARGS__))(__VA_ARGS__)

#define TCALCCOUNT2(_1,_2, _3,_4,_5, N, ...) N
#define TCALCCOUNT(arg) TCALCCOUNT2 arg
#define TCOUNT(...) TCALCCOUNT((__VA_ARGS__, 2, 2, 2, 2, 1, 0))

#define TCONNECT2(M, count)  M##count
#define TCONNECT1(M, count)  TCONNECT2(M, count)
#define TCONNECT(M, count)   TCONNECT1(M, count)

#define TInit2(MyClass,...) \
public:\
	inline virtual std::string GetType(){\
		return #MyClass; \
	}\
	inline virtual bool Inherit(const std::string& str){\
		if(str._Equal(#MyClass))return true;\
		return __VA_ARGS__::Inherit(str);\
	}\
private: 

#define TInit1(MyClass) \
public:\
	inline virtual std::string GetType(){\
		return #MyClass; \
	}\
	inline virtual bool Inherit(const std::string& str){\
		return str._Equal(#MyClass);\
	}\
private:

	class TObj
	{
	public:
		TObj() {
		}
		template<class C> C ToSub();

		TInit(TObj);

	};
	inline std::ostream& operator<<(std::ostream& os,TObj obj) {
		return os << "TObj object";
	}

	template<class C>
	inline C TObj::ToSub()
	{
		return *static_cast<C*>(this);
	}
}