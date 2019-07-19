
#include "pch.h"

#include <gtest/gtest.h>

/*
	
	Igor,
	Do you know how I can replicate Excel’s MROUND function (number rounded to a given multiple)  in C++?

	I need to replicate the following Excel’s formulas in CFE
	For monthly
	(MROUND(WAL,1/12))

	For quarterly
	MROUND(WAL,0.25)

	For semi
	(0.125+MROUND(I4-0.125,0.5))

	For annual:
	(0.38+MROUND(I4-0.38,1))


 */
double mround (double d, double multiple)
{
	double m = d / multiple;
	int rm = int (m + 0.5);
	return rm * multiple;
}

TEST (MRoundTest, Basic) {

	EXPECT_EQ (mround (1.12, 0.25), 1.0);
	EXPECT_EQ (mround (1.13, 0.25), 1.25);

	// quarterly
	EXPECT_DOUBLE_EQ (mround (4.1, 0.25), 4.00);
	EXPECT_DOUBLE_EQ (mround (4.2, 0.25), 4.25);

	// monthly
	EXPECT_NEAR (mround (4.1, 0.08333333), 4.08333333, 0.000001);
	EXPECT_NEAR (mround (4.2, 0.08333333), 4.16666667, 0.000001);

	// semiannually;
	EXPECT_NEAR (0.125 + mround (4.3 - 0.125, 0.5), 4.125, 0.000001);
	EXPECT_NEAR (0.125 + mround (4.4 - 0.125, 0.5), 4.625, 0.000001);
}