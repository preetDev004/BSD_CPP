
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include "MotorVehicle.h"

namespace sdds
{
    class Truck: public MotorVehicle{
        private:
        double m_capacity;
        double m_cargoLoad;

        public:
        Truck(const char* plateNum, int yearBuilt, double capacity,const char* currentAddress);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os, const Truck& truck);
    std::istream& operator>>(std::istream& in, Truck& truck);
}

#endif