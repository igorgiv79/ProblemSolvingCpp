
#include "pch.h"
#include <iostream>

#include <gtest/gtest.h>

template <class T, class P>
class DerivedFrom {
public:

	class No {};
	class Yes { No no[3]; };

	static Yes foo (T *);
	static No foo (...);

	enum {
		is = sizeof(foo(static_cast<P*>(0))) == sizeof(Yes)
	};
};

class C {

};

class D : public C {

};

class F {

};

template <class D, class B>
bool isDerivedFrom () {
	return DerivedFrom<B, D>::is;
}

TEST (DerivedFrom, UserDefClasses)
{
	EXPECT_EQ ((isDerivedFrom<D, C> ()), true);
	EXPECT_EQ ((isDerivedFrom<C, D> ()), false);
}
