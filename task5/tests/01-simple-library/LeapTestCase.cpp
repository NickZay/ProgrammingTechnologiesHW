//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST_F(LeapTestCase, TestLessZero) {
	ASSERT_THROW(IsLeap(-1), std::invalid_argument);	
}

TEST_F(LeapTestCase, Test400) {
	ASSERT_TRUE(IsLeap(400));
}

TEST_F(LeapTestCase, Test100) {
	ASSERT_FALSE(IsLeap(100));
}

TEST_F(LeapTestCase, Test4) {
	ASSERT_TRUE(IsLeap(4));
}

TEST_F(LeapTestCase, Test1) {
	ASSERT_FALSE(IsLeap(1));
}
