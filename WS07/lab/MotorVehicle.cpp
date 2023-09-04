
#include <iostream>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds{
    MotorVehicle::MotorVehicle(const char* plateNum, int yearBuilt){
        strCpy(m_plateNum, plateNum); // so it only copies the 9 characters and do not cross the limit
        strCpy(m_currentAdd, "Factory");
        m_yearBuilt = yearBuilt;
    }

     void MotorVehicle::moveTo(const char* address){
        cout<<"|";
        cout.width(8);
        cout.setf(ios::right);
        cout<<m_plateNum << "| ";
        cout.unsetf(ios::right);

        cout<<"|";
        cout.width(20);
        cout.setf(ios::right);
        cout<<m_currentAdd << " ---> ";
        cout.unsetf(ios::right);

        cout.width(20);
        cout.setf(ios::left);
        cout<<address << "|"<<endl;
        cout.unsetf(ios::left);

        if (strCmp(address, m_currentAdd) !=0)
        {
            strCpy(m_currentAdd, address);
        }
        
    
     }
     ostream& MotorVehicle::write(ostream& os) const{
        os<< "| "<<m_yearBuilt<< " | "<<m_plateNum <<" | "<< m_currentAdd;
        return os;
     }
     istream& MotorVehicle::read(istream& in){
        cout << "Built year: ";
        in >> m_yearBuilt;
        cout << "License plate: ";
        in.ignore();
        in.getline(m_plateNum, MAX_LP_SIZE);
        cout << "Current location: ";
        in.getline(m_currentAdd, MAX_ADD_SIZE);
        return in;
     }

    ostream& operator<<(ostream& os, const MotorVehicle& vehicle) {
        return vehicle.write(os);
    }

    istream& operator>>(istream& in, MotorVehicle& vehicle) {
        return vehicle.read(in);
    }


}