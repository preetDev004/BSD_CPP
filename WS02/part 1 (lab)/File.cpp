
// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
	std::FILE *g_fptr = nullptr;

	bool openFile(const char *filename)
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = std::fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	int noOfRecordsInFile()
	{
		int noOfRecs = -1;
		if (g_fptr != nullptr)
		{
			// we have a file open; start counting from "0"
			noOfRecs = 0;

			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// read from file a character at a time, and count '\n'
			char ch = {'\0'};
			while (std::fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}

		// if no file was open, the counter will have "-1",
		//  otherwise will contain the number of lines
		return noOfRecs;
	}

	void closeFile()
	{
		if (g_fptr != nullptr)
		{
			std::fclose(g_fptr);
			g_fptr = nullptr;
		}
	}

	// TODO: implement the `read` functions here
	bool read(char *val)
	{
		int result;
		result = std::fscanf(g_fptr, "%[^\n]\n", val);
		if (result)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool read(int &val)
	{
		int result;
		result = std::fscanf(g_fptr, "%d,", &val);
		if (result)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool read(double &val)
	{
		int result;
		result = std::fscanf(g_fptr, "%lf,", &val);
		if (result)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}
