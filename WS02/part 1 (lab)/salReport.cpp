
#include <iostream>
#include "Employee.h"
#include "File.h"

using namespace std;
using namespace sdds;
int main()
{
	// Test 1
	std::cout << "T1: Load Some Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (sdds::load("employees.csv"))
		sdds::display();

	// Test 2: Discard old data, load new data
	std::cout << "\nT2: Discard Old Data; Load New Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	sdds::deallocateMemory();
	if (sdds::load("simpsons.csv"))
		sdds::display(false);

	// Test 3: load some more, add to the existing collection
	std::cout << "\nT3: Load More Data; Add to the Existing Collection\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (sdds::load("employees.csv"))
		sdds::display(true);

	// clean-up
	sdds::deallocateMemory();
}
