#pragma once
#include "main.h"
#include <gtest/gtest.h>

TEST(Test, testA){
	AAA A;
	ASSERT_EQ(A.aaa, 3);
}

TEST(Test, testB){
	BBB B;
	ASSERT_EQ(B.bbb, 5);
}
