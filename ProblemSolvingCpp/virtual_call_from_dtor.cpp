
#include "pch.h"

class Base {
public:

	Base () {}

	virtual ~Base () { 
		f (); 
	}

	virtual void f () {
		std::cout << "Base::f()" << std::endl;
	}
};

class Derived : public Base {
public:

	virtual void f () {
		std::cout << "Derived::f()" << std::endl;
	}
};

void testVirtualCallFromDtor () {
	Base *b = new Derived ();
	delete b;
}