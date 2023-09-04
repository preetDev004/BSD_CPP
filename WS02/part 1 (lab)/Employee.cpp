
// This prevents VS compiler from issuing warnings/errors related to utilization
//   of unsafe string functions.  Has no effect in g++.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds
{

	Employee *g_employees = nullptr;
	int g_noOfEmployees = 0;

	void sort()
	{
		for (int i = g_noOfEmployees - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (g_employees[j].m_empNo > g_employees[j + 1].m_empNo)
				{
					Employee temp = g_employees[j];
					g_employees[j] = g_employees[j + 1];
					g_employees[j + 1] = temp;
				}
	}

	bool load(const char *filename)
	{
		bool ok = true;
		if (openFile(filename))
		{

			int nRecords = noOfRecordsInFile();
			int newSize = g_noOfEmployees + nRecords;

			Employee *tmp = new Employee[newSize];

			for (int i = 0; i < g_noOfEmployees; i++)
			{

				tmp[i].m_name = new char[strlen(g_employees[i].m_name) + 1];
				strcpy(tmp[i].m_name, g_employees[i].m_name);
				tmp[i].m_empNo = g_employees[i].m_empNo;
				tmp[i].m_salary = g_employees[i].m_salary;
			}
			for (int i = g_noOfEmployees; i < newSize; i++)
			{
				load(tmp[i]);
			}
			deallocateMemory();
			g_employees = tmp;
			g_noOfEmployees = newSize;

			closeFile();
		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
			ok = false;
		}
		return ok;
	}

	bool load(Employee &theEmployee)
	{
		bool ok = false;
		char name[128];

		if (read(theEmployee.m_empNo) &&
			read(theEmployee.m_salary) &&
			read(name))
		{
			theEmployee.m_name = new char[strlen(name) + 1];
			strcpy(theEmployee.m_name, name);
			ok = true;
		}

		return ok;
	}

	void display(bool shouldSort)
	{

		cout << "Employee Salary Report" << endl;
		cout << "no- Empno, Name, Salary" << endl;
		cout << "-----------------------" << endl;
		if (shouldSort)
			sort();

		for (int i = 0; i < g_noOfEmployees; i++)
		{
			cout << i + 1 << "- ";
			display(g_employees[i]);
		}
	}

	void display(const Employee &theEmployee)
	{
		cout << theEmployee.m_empNo << ": " << theEmployee.m_name << ", " << theEmployee.m_salary << endl;
	}

	void deallocateMemory()
	{
		for (int i = 0; i < g_noOfEmployees; i++)
		{
			delete[] g_employees[i].m_name;
		}
		delete[] g_employees;
		g_employees = nullptr;
		g_noOfEmployees = 0;
	}

}
