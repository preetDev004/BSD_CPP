
#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds
{
    Mark::Mark(int value)
    {
        this->mark = value;
    }
    Mark &Mark::operator+=(int value)
    {
        if (this->mark >= 0 && this->mark <= 100)
        {
            this->mark += value;
        }
        return *this;
    }
    Mark &Mark::operator=(int name)
    {
        this->mark = name;
        return *this;
    }
    Mark::operator int() const
    {
        if (this->mark >= 0 && this->mark <= 100)
            return this->mark;
        return 0;
    }
    Mark::operator char() const
    {
        if (this->mark >= 0 && this->mark < 50)
        {
            return 'F';
        }
        else if (this->mark >= 50 && this->mark < 60)
        {
            return 'D';
        }
        else if (this->mark >= 60 && this->mark < 70)
        {
            return 'C';
        }
        else if (this->mark >= 70 && this->mark < 80)
        {
            return 'B';
        }
        else if (this->mark >= 80 && this->mark <= 100)
        {
            return 'A';
        }
        return 'X';
    }
    Mark::operator double() const
    {
        if (this->mark >= 0 && this->mark < 50)
        {
            return 0.0;
        }
        else if (this->mark >= 50 && this->mark < 60)
        {
            return 1.0;
        }
        else if (this->mark >= 60 && this->mark < 70)
        {
            return 2.0;
        }
        else if (this->mark >= 70 && this->mark < 80)
        {
            return 3.0;
        }
        else if (this->mark >= 80 && this->mark <= 100)
        {
            return 4.0;
        }
        return 0.0;
    }
    int &operator+=(int &val, const Mark &theMark)
    {
        val += ((int)theMark);
        return val;
    }
}