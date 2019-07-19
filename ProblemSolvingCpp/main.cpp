
#include "pch.h"

#include <gtest/gtest.h>

//void testVirtualCallFromDtor ();

struct MyType
{
	MyType (std::initializer_list<int> list) {

	}

	MyType (int i) {}

	MyType& operator = (MyType const &other) {
		return *this;
	}

	MyType& operator= (MyType &&other) {
		return *this;
	}
};



int main (int argc, char *argv[])
{
//	testVirtualCallFromDtor ();

	int i = 0;
	int i2 (1);
	int i3 {2};
	double d = 0.5;
	int i4 = d;
	int i5 (d);
	//int i6 {d};

	MyType mt {1,2,3},
		mt2 = 1;

	mt2 = mt;

	mt2 = MyType {1};

	mt2 = std::move (mt);

	testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}
