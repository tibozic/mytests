#include "mytests.h"

void test1();
void test2();

int main(void)
{

	test1();
	test2();

	return 0;
}

void test1()
{
	START_TEST("Subsection 1");
	EXPECT_EQ(1, 1);
	EXPECT_NEQ(1, 1);
	END_TEST();

	START_TEST("Subsection 2");
	EXPECT_EQ(1, 1);
	EXPECT_NEQ(1, 2);
	END_TEST();
}

void test2()
{
	START_TEST("Subsection 1");
	EXPECT_EQ(1, 1);
	EXPECT_NEQ(1, 2);
	END_TEST();
}
