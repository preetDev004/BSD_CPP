//*******************************************************************
//                        Workshop-7 part-1
// Name: Preet Dineshkumar Patel
// Email: pdpatel51@myseneca.ca
// Student ID: 123845224
// Date of Completion: 07/10/2023
//
// Declaration: I have done all the coding by myself and only copied 
//              the code that my professor provided to complete my 
//              workshops and assignments.
//*******************************************************************


#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>
namespace sdds
{
    class MotorVehicle
    {
    private:
        static const int MAX_LP_SIZE = 9;
        static const int MAX_ADD_SIZE = 64;
        char m_plateNum[MAX_LP_SIZE + 1];
        char m_currentAdd[MAX_ADD_SIZE + 1];
        int m_yearBuilt;

    public:
        MotorVehicle(const char *plateNum, int yearBuilt);
        void moveTo(const char *address);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &in);
    };
    std::ostream &operator<<(std::ostream &os,const MotorVehicle &vehicle);
    std::istream &operator>>(std::istream &in, MotorVehicle &vehicle);
}

#endif