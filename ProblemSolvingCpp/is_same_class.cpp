// InterviewPrep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <gtest/gtest.h>

template <class T, class P>
class SameClass {
public:

	enum {
		is = false
	};
};

template <class T>
class SameClass<T, T> {
public:

	enum {
		is = true
	};

};

template <class T, class P>
bool isSameClass () {
	return SameClass<T, P>::is;
}

class C {

};

class D : public C {
};

TEST (IsSameClass, UserDefTypes)
{
	EXPECT_EQ((isSameClass<C, C> ()), true);
	EXPECT_EQ ((isSameClass<C, D> ()), false);
}

TEST (IsSameClass, BasicTypes)
{
	EXPECT_EQ ((isSameClass<int, int> ()), true);
	EXPECT_EQ ((isSameClass<double, float> ()), false);
}

