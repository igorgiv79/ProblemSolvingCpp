
#include <gtest/gtest.h>

// PROBLEM: reverse a string in place.

using namespace std;

void reverse_in_place (string &s) {
	if (s.length () == 1)
		return;

	auto b = s.begin (), e = s.end ()-1;
	while (b < e) {
		swap (*b, *e);
		++b;
		--e;
	}
}


TEST (ReverseInPlaceTest, basic) {

	string test;
	test = "test";
	reverse_in_place (test);
	EXPECT_EQ (test, "tset");

	test = "sample";
	reverse_in_place (test);
	EXPECT_EQ (test, "elpmas");

	test = "apple";
	reverse_in_place (test);
	EXPECT_EQ (test, "elppa");

	test = "a";
	reverse_in_place (test);
	EXPECT_EQ (test, "a");

	test = "ab";
	reverse_in_place (test);
	EXPECT_EQ (test, "ba");
}