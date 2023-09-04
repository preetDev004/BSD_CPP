
#include <iostream>
#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H

namespace sdds{
    class Canister{
        private:
            double m_diameter;            
            double m_height;
            char* m_contentName;            
            double m_contentVolume;        
            bool m_usable;
            double getCapacity() const;  

        public:
            Canister();  
            Canister(double diameter, double hieght);  
            Canister(const char* contentName, double contentVolume);
            Canister(double diameter, double hieght, const char* contentName, double contentVolume); 
            ~Canister();  
            Canister& pour(const char* what, double howMuch);
            Canister& pour(Canister& src);
            void emptyAndWash();
            std::ostream& display(std::ostream& out = std::cout)const;


    };
}

#endif