#include <stdbool.h>

#include "mytests.h"

void test_equal();
void test_not_equal();
void test_true();
void test_false();

int main(void)
{

	test_equal();
	test_not_equal();
	test_true();
	test_false();
	report_print();

	return 0;
}

void test_equal()
{
	TEST_START("Test Equal");
	EXPECT_EQ(1, 1);
	TEST_END();

	TEST_START("Test Not Equal");
	EXPECT_EQ(1, 2);
	TEST_END();
}

void test_not_equal()
{
	TEST_START("Test not equal");
	EXPECT_NEQ(1, 2);
	TEST_END();

	TEST_START("Test equal");
	EXPECT_NEQ(1, 1);
	TEST_END();
}

void test_true()
{
	TEST_START("Test true");
	EXPECT_TRUE(true);
	TEST_END();

	TEST_START("Test false");
	EXPECT_TRUE(false);
	TEST_END();
}

void test_false()
{
	TEST_START("Test false");
	EXPECT_FALSE(false);
	TEST_END();

	TEST_START("Test true");
	EXPECT_FALSE(true);
	TEST_END();
}
