# mytests
A simple library for testing.

## Supported commands
TEST_START("Name of test"); <br>
TEST_END(); <br>
EXPECT_EQ(int1, int2); <br>
EXPECT_NEQ(int1, int2); <br>
EXPECT_TRUE(boolean); <br>
EXPECT_FALSE(boolean); <br>
report_print();

## Usage
A group of tests is marked by TEST_START("Group name");. Every TEST_START() should be closed with TEST_END(). <br>
If all tests within a group pass, it will be printed that the group passed. If any of the tests in a group failed,
it will print that the group failed and which tests within group passed and which failed. <br>
report_print() prints how many tests were ran, how many failed and how many passed. <br>
