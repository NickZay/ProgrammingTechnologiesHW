//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST_F(AddTestCase, AddTest) {
	ASSERT_EQ(Add(10, 11), 21);
}

