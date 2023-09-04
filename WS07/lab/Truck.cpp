
#include "Truck.h"

using namespace std;
namespace sdds{
    Truck::Truck(const char* plateNum, int yearBuilt, double capacity,const char* currentAddress)
    : MotorVehicle(plateNum,yearBuilt){
        m_capacity = capacity;
        m_cargoLoad = 0.0;
        moveTo(currentAddress);
    }
    bool Truck::addCargo(double cargo){
        if(m_cargoLoad < m_capacity){
            if ((m_cargoLoad + cargo) <= m_capacity)
            {
                m_cargoLoad += cargo;
            }
            else{
                m_cargoLoad = m_capacity;
            }
            return true;   
        }
        return false;
    }
    bool Truck::unloadCargo()
    {
        if (m_cargoLoad > 0.0) {
            m_cargoLoad = 0.0;
            return true;
        }
        return false;
    }
    ostream& Truck::write(ostream& os) const{
        MotorVehicle::write(os);
        os << " | " << m_cargoLoad <<"/"<<m_capacity;
        return os;
    }

    istream &Truck::read(istream &in)
    {
        MotorVehicle::read(in);
        cout << "Capacity: ";
        in >> m_capacity; 
        cout << "Cargo: ";
        in >> m_cargoLoad;   
        return in;
    }
    ostream& operator<<(ostream& os, const Truck& truck) {
        return truck.write(os);
    }

    istream& operator>>(istream& in, Truck& truck) {
        return truck.read(in);
    }
}
