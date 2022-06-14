
#include"TObject.hpp"
#include"TVector.hpp"
#include"TVector2.hpp"
#include"TVector3.hpp"
#include<assert.h>
#include<iostream>
using namespace std;

class A:public TG::TObj{
	TInit(A,TObj)
};
void TestTObj() {
	A a;
	cout << boolalpha;
	cout << "TObjÀà²âÊÔ£º" << endl;

	assert(a.Inherit("A"));
	assert(a.Inherit("TObj"));
	assert(!a.Inherit("B"));
	assert(!static_cast<TG::TObj>(a).Inherit("A"));
	assert(a.GetType()._Equal("A"));

	cout << "Success" << endl << endl;
}

void TestTVec() {
	TG::TVec<float,2> v2;
	cout << boolalpha;
	cout << "TVecÀà²âÊÔ£º" << endl;
	assert(v2.Inherit("TObj"));
	assert(v2.Inherit("TVec"));
	assert(!v2.Inherit("TVec2"));


	TG::TVec<float, 2> t(2);
	TG::TVec<float, 2> t2(3);
	assert(t[0] == 2 && t[1] == 2);
	assert(abs(t2.Length() - 3*sqrt(2)) < 0.000001);
	cout << "Success" << endl << endl;
}

void TestTVec2() {
	TG::TVec2<float> f(1, 2);
	TG::TVec2<float> f2(3,12);
	cout << boolalpha;
	cout << "TVec2Àà²âÊÔ£º" << endl;
	assert((f2-f) == TG::TVec2<float>(2,10));
	TG::TVec2f v2(1, 2);
	cout << "Success" << endl << endl;
}
void TestTVec3() {
	TG::TVec3<float> f(1, 2, 2);
	TG::TVec3<float> f2(3, 12, 1);
	cout << boolalpha;
	cout << "TVec3Àà²âÊÔ£º" << endl;
	assert((f2 + f) == TG::TVec3<float>(4, 14, 3));
	assert(TG::TVec3f::back == TG::TVec3<float>::back);
	cout << "Success" << endl << endl;
}
#define w(s) #s
int main() {
	TestTObj();
	TestTVec();
	TestTVec2();
	TestTVec3();
	return 0;
}