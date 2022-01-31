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
	print_report();

	return 0;
}

void test_equal()
{
	START_TEST("Test Equal");
	EXPECT_EQ(1, 1);
	END_TEST();

	START_TEST("Test Not Equal");
	EXPECT_EQ(1, 2);
	END_TEST();
}

void test_not_equal()
{
	START_TEST("Test not equal");
	EXPECT_NEQ(1, 2);
	END_TEST();

	START_TEST("Test equal");
	EXPECT_NEQ(1, 1);
	END_TEST();
}

void test_true()
{
	START_TEST("Test true");
	EXPECT_TRUE(true);
	END_TEST();

	START_TEST("Test false");
	EXPECT_TRUE(false);
	END_TEST();
}

void test_false()
{
	START_TEST("Test false");
	EXPECT_FALSE(false);
	END_TEST();

	START_TEST("Test true");
	EXPECT_FALSE(true);
	END_TEST();
}
