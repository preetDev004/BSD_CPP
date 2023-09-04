
#ifndef SDDS_REGION_H
#define SDDS_REGION_H
#define POSTAL_CODE 3

namespace sdds{

	struct Region
	{
		char m_code[POSTAL_CODE+1];
		int m_population;
	};

	void sort();

	bool load(const char* filename);

	bool load(Region &theRegion);

	void display(const char* areaName,bool shouldSort = false);

	void display(const Region& theRegion);

	void cleanUp();
}


#endif