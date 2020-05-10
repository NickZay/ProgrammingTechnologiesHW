//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include "Functions.h"

class LeapTestCase : public ::testing::Test {
public:
	LeapTestCase() = default;
};


TEST_F(LeapTestCase, ZeroTestOnLeap){
	//testing exceptions
	EXPECT_THROW(IsLeap(-1), std::invalid_argument);
}

TEST_F(LeapTestCase, FirstTestOnLeap){
	//testing not leap year
	EXPECT_FALSE(IsLeap(1));
}

TEST_F(LeapTestCase, SecondTestOnLeap){
	//testing  year % 4(not 100)
	EXPECT_TRUE(IsLeap(20));
}

TEST_F(LeapTestCase, ThirdTestOnLeap){
	//testing  year % 100(not 400)
	EXPECT_FALSE(IsLeap(100));
}

TEST_F(LeapTestCase, FourthTestOnLeap){
	//testing  year % 400
	EXPECT_TRUE(IsLeap(400));
}
