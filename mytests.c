#include "mytests.h"

int FAILED = 0;
FILE *fp;

void expect_eq(const char *function_name, int line_number, int value1, int value2)
{
	if (value1 == value2)
	{
		fprintf(fp,
				"\t[ " ANSI_COLOR_GREEN " Passed " ANSI_COLOR_RESET " ] %s:%d\n",
				function_name,
				line_number);
	}
	else
	{
		FAILED++;
		fprintf(fp,
				"\t[ " ANSI_COLOR_RED " Failed " ANSI_COLOR_RESET " ] %s:%d\n",
				function_name,
				line_number);
		fprintf(fp,
				"\t\t\t\t Expected `%d` to match `%d`\n",
				value1,
				value2);
	}
}

void expect_neq(const char *function_name, int line_number, int value1, int value2)
{
	if (value1 != value2)
	{
		fprintf(fp,
				"\t[ " ANSI_COLOR_GREEN " Passed " ANSI_COLOR_RESET " ] %s:%d\n",
				function_name,
				line_number);
	}
	else
	{
		FAILED++;
		fprintf(fp,
				"\t[ " ANSI_COLOR_RED " Failed " ANSI_COLOR_RESET " ] %s:%d\n",
				function_name,
				line_number);
		fprintf(fp,
				"\t\t\t\t Expected `%d` not to match `%d`\n",
				value1,
				value2);
	}
}

void start_test(const char *function_name, const char *section_name)
{
	fprintf(stdout,
			"---- Staring tests for: %s:%s\n",
			function_name,
			section_name);

	fp = fopen("temp.txt", "w");
	if (fp == NULL)
	{
		fprintf(stderr,
				"Can't start test: %s - can't open file `temp.txt`\n",
				function_name);
		exit(1);
	}
}

void end_test(const char *function_name)
{
	fclose(fp);
	if (FAILED == 0)
	{
		fprintf(stdout,
				"[ " ANSI_COLOR_GREEN " Passed " ANSI_COLOR_RESET " ] %s\n",
				function_name);
		FAILED = 0;
	}
	else
	{
		FAILED = 0;
		fprintf(stderr,
				"[ " ANSI_COLOR_RED " Failed " ANSI_COLOR_RESET " ] %s\n",
				function_name);
		fp = fopen("temp.txt", "r");
		if (fp == NULL)
		{
			fprintf(stderr,
					"Can't open file with test reports: `temp.txt`\n");
			exit(1);
		}

		size_t max_line_length = 255;
		char *line = (char *) malloc(max_line_length * sizeof(char));

		if (line == NULL)
		{
			fprintf(stderr,
					"ERROR: Can't read file with test reports: `temp.txt`.\n");
			fclose(fp);
			exit(1);
		}

		while(fgets(line, max_line_length, fp) != NULL)
		{
			fprintf(stderr, "%s", line);
		}

		free(line);
		fclose(fp);
	}
	if (remove("temp.txt") != 0)
	{
		fprintf(stderr,
				"Failed to delete temporary file: `temp.txt` (file is part of the testing libarary)\n");
		exit(1);
	}
}
