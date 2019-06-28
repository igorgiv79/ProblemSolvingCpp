
#include "pch.h"

#include <unordered_set>

#include <gtest/gtest.h>

using int_vector = std::vector<int>;
using int_pair = std::pair<int, int>;
using int_pair_vector = std::vector<int_pair>;

// the idea is to use the hash table to calculate the sum of 2 numbers;
// this results in an algorithm that has O(N) performance at the cost of 
// additional memory;
int_pair_vector find_pairs_equal_to (int_vector const &v, int N)
{
	int_vector v2 {v};
	std::sort (v2.begin (), v2.end ());

	int_pair_vector res;

	std::unordered_set<int> ht;
	for (int i : v) {
		int target = N - i;
		if (ht.find (target)!=ht.end()) {
			res.emplace_back (target, i);
		}
		else {
			ht.insert (i);
		}
	}

	return res;
}

// the idea is to sort the array and then given 2 pointers - front & back - 
// go towards the middle and look for pairs that add up to N;
int_pair_vector find_pairs_equal_to_v2 (int_vector const &v, int N)
{
	if (v.size () < 2) {
		return int_pair_vector {};
	}
	else if (v.size () == 2) {
		if (v[0] + v[1] == N) {
			return int_pair_vector {int_pair {v[0], v[1]}};
		}
	}

	int_vector v2 {v};
	std::sort (v2.begin (), v2.end ());
	if (v2[0] > N) {
		return int_pair_vector {};
	}

	int_pair_vector res;
	auto p = v2.begin (), q = v2.end () - 1;

	while (p!=q)
	{
		int sum = *p + *q;
		if (sum == N) {
			res.emplace_back (*p, *q);
			--q;
		}
		else if (sum > N) {
			while (--*q > N);
		}
		else {
			++p;
		}
	}

	return res;
}

struct test_case {
	int_vector numbers;
	int sum;
	int_pair_vector pairs;

	friend std::ostream& operator << (std::ostream &os, test_case const &tc)
	{
		os << "numbers: ";
		std::copy (tc.numbers.begin (), tc.numbers.end (), std::ostream_iterator<int> (std::cout, ","));
		os << std::endl;
		return os;
	}
};

struct FindPairsEqToNTest : testing::Test, testing::WithParamInterface<test_case> {

	FindPairsEqToNTest ()
	{}

	~FindPairsEqToNTest ()
	{}
};

struct FindPairsEqToNTest2 : testing::Test, testing::WithParamInterface<test_case> {};

TEST_P (FindPairsEqToNTest, FindPairsEqualToN) {
	auto tc = GetParam ().numbers;
	auto res=find_pairs_equal_to (tc, GetParam ().sum);
	EXPECT_EQ (res, GetParam ().pairs);
}

TEST_P (FindPairsEqToNTest2, FindPairsEqualToNV2) {
	auto tc = GetParam ().numbers;
	auto res = find_pairs_equal_to_v2 (tc, GetParam ().sum);
	EXPECT_EQ (res, GetParam ().pairs);
}

INSTANTIATE_TEST_CASE_P (Default, FindPairsEqToNTest,
	testing::Values (
		test_case {{1,2,3,4,5,6}, 7, int_pair_vector {int_pair{3,4}, int_pair{2,5}, int_pair{1,6}}},
		test_case {{1,2,3,4,5,6}, 8, int_pair_vector {int_pair{3,5}, int_pair{2,6}}}
	)
);

INSTANTIATE_TEST_CASE_P(Default, FindPairsEqToNTest2,
	testing::Values (
		test_case {{1,2,3,4,5,6}, 7, int_pair_vector {int_pair{1,6}, int_pair{2,5}, int_pair{3,4}}},
		test_case {{1,2,3,4,5,6}, 8, int_pair_vector {int_pair{2,6}, int_pair{3,5}}},
		test_case {{1}, 8, int_pair_vector {}},
		test_case {{1,7}, 8, int_pair_vector {int_pair{1,7}}},
		test_case {{9, 10}, 8, int_pair_vector {}}
	)
);