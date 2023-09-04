
#include <iostream>
#include <cstring>
#include "Region.h"
#include "File.h"

using namespace std;
namespace sdds
{
    Region *g_areas = nullptr;
    int g_noOfAreas = 0;

    void sort()
	{
		for (int i = g_noOfAreas - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (g_areas[j].m_population > g_areas[j + 1].m_population)
				{
					Region temp = g_areas[j];
					g_areas[j] = g_areas[j + 1];
					g_areas[j + 1] = temp;
				}
	}

    bool load(const char *filename)
    {
        bool ok = true;
        if (openFile(filename))
        {
            int newAreas = g_noOfAreas + noOfRecordsInFile();
            Region *tmp = new Region[newAreas];

            for (int i = 0; i < g_noOfAreas; i++)
            {
                strcpy(tmp[i].m_code, g_areas[i].m_code);
                tmp[i].m_population = g_areas[i].m_population;
            }
            for (int i = g_noOfAreas; i < newAreas; i++)
            {
                load(tmp[i]);
            }
            cleanUp();
            g_areas = tmp;
            g_noOfAreas = newAreas;

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
            ok = false;
        }
        return ok;
    }
    bool load(Region &theRegion)
	{
		bool ok = false;
	
		if (
		read(theRegion.m_code, theRegion.m_population))
		{
			ok = true;
		}

		return ok;
	}
    void display(const char* areaName,bool shouldSort)
	{
        int totalPopulation = 0;
		cout << "#. Postal Code -> Population" << endl;
		cout << "------------------------------" << endl;
		if (shouldSort)
			sort();

		for (int i = 0; i < g_noOfAreas; i++)
		{
            totalPopulation += g_areas[i].m_population;
			cout << i + 1 << ". ";
			display(g_areas[i]);
		}
        cout << "------------------------------" << endl;
        cout << "Population of "<< areaName <<": "<< totalPopulation << endl;
	}
    void display(const Region &theRegion)
	{
		cout << theRegion.m_code << " -> " << theRegion.m_population << endl;
	}
    void cleanUp(){
		delete[] g_areas;
		g_areas = nullptr;
		g_noOfAreas = 0;
    }
}