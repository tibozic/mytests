#include "mytests.h"

void expect_equal(const char *function_name, int value1, int value2)
{
	if (value1 == value2)
	{
		fprintf(stdout,
				"[ " ANSI_COLOR_GREEN " Passed " ANSI_COLOR_RESET " ] %s\n",
				function_name);
	}
	else
	{
		fprintf(stderr,
				"[ " ANSI_COLOR_RED " Failed " ANSI_COLOR_RESET " ] %s\n",
				function_name);
	}
}
