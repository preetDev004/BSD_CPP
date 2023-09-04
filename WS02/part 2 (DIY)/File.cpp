
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
			noOfRecs = 0;

			auto currentPosition = std::ftell(g_fptr);

			std::fseek(g_fptr, 0, SEEK_SET);

			char ch = {'\0'};
			while (std::fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}

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

	bool read(char *val,int& val1)
	{
		int result;
		result = std::fscanf(g_fptr, "%[^,],%d\n", val, &val1);
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
