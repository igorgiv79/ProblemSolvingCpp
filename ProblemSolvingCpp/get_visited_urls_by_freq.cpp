
#include <gtest/gtest.h>

#include "pch.h"
#include "Tools.h"

/*
	This is the first question that I was asked on a face-2-face interview with ICE on 07/15/2019.
	Get the map of URLs visited by a user in the format {resource : number-of-visits} from the list describing 
	browsing history. The output must be sorted by the number of visits in the descending order.
	For example, given this input {amazon, google, apple, amazon, apple, facebook} the output should be
		{amazon : 2},
		{apple, 2},
		{google: 1},
		{facebook: 1}
*/

using entry = std::pair<std::string, int>;

std::ostream& operator << (std::ostream &os, std::vector<entry> const& es) {
	os << "{";

	for (auto &e : es) {
		os << "(" << e.first << "," << e.second << "), ";
	}

	os << "}";
	return os;
}

std::vector<entry> get_visited_urls_by_freq (std::list<std::string> const &input) {
	std::vector<entry> out;

	std::unordered_map<std::string, int> counts;
	for (std::string s : input) {
		auto i = counts.find (s);
		if (i != counts.end ()) {
			++i->second;
		}
		else {
			counts[s] = 1;
		}
	}

	std::copy (counts.begin (), counts.end (), std::back_inserter (out));
	std::sort (out.begin (), out.end (), [] (auto &e0, auto &e1) {	// NOTE auto &: this requires C++14
		return e0.second > e1.second; 
	});

	return out;
}

namespace {

	using ::operator<<;

	struct TestCase {
		std::list<std::string> browsingHistory;
		std::vector<entry> expOutput;

		friend std::ostream& operator << (std::ostream &os, TestCase const &tc) {
			os << "browsing history: " << tc.browsingHistory << " top URLs: " << tc.expOutput;
			return os;
		}
	};

	struct GetVisitedURLsByFreqTest : testing::Test, testing::WithParamInterface <TestCase> {};

	TEST_P (GetVisitedURLsByFreqTest, main) {
		auto const &test_case = GetParam ();
		auto out = get_visited_urls_by_freq (test_case.browsingHistory);
		EXPECT_EQ (test_case.expOutput, out);
	}

	INSTANTIATE_TEST_SUITE_P (Main, GetVisitedURLsByFreqTest,
		testing::Values (
			TestCase {
				{"amazon", "google", "apple", "amazon", "apple", "facebook"},
				{
					{"amazon", 2},
					{"apple", 2},
					{"google", 1},
					{"facebook", 1}
				}
			},
			TestCase {
				{"amazon"},
				{
					{"amazon", 1}
				}
			}
		)
	);
}
