
// Best time to buy and sell bond: an array for which the ith element is the price of a given bond on day i. 
// If you were only permitted to complete at most one transaction (i.e. buy one //bond and sell one bond). 
// Design an algorithm to find the maximum profit.
// Note that you cannot sell a bond before you buy
// Input {107,101,105,106,98,99}

#include "pch.h"

#include <gtest/gtest.h>

// Complexity is > O(N) but < O(N^N);
int calc_profit_original (std::vector<int> const &v)
{
	int maxProfit = 0;
	for (auto i = v.begin (); i < v.end () - 2; ++i) {
		auto j = v.end () - 1;
		while (j > i) {
			int profit = *j - *i;
			maxProfit = std::max<int> (maxProfit, profit);
			--j;
		}
	}

	return maxProfit;
}

// complexity O(N)
int calc_profit_fast (std::vector<int> const &v)
{
	assert (v.size () > 1);

	int maxProfit = 0;
	int minBuyPrice = v[0];
	for (int price : v) {
		minBuyPrice = std::min (price, minBuyPrice);
		maxProfit = std::max (price - minBuyPrice, maxProfit);
	}

	return maxProfit;
}

TEST (CalcMaxProfit, Original) {
	auto prices = {107, 101, 105, 106, 98, 99};
	int profit = calc_profit_original (prices);
	EXPECT_EQ (profit, 106-101);
}

TEST (CalcMaxProfit, Fast) {
	auto prices = {107, 101, 105, 106, 98, 99};
	int profit = calc_profit_fast (prices);
	EXPECT_EQ (profit, 106 - 101);
}