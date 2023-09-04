
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds
{

	bool openFile(const char* filename);

	void closeFile();

	int noOfRecordsInFile();

	bool read(char* val, int& val1);

}
#endif 