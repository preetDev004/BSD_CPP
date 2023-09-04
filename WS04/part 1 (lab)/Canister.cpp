
#include <cstring>
#include <cmath>
#include "Canister.h"

using namespace std;
namespace sdds
{

    double Canister::getCapacity() const
    {
        // as we have to leave the space of 0.267cm on top we subtract that from hieght.
        // Formula : pi*(h)*(radius^2)
        // cout<< (3.14159265 * (this->m_height - 0.267) * pow((this->m_diameter / 2) ,2));
        return (3.14159265 * (this->m_height - 0.267) * pow((this->m_diameter / 2) ,2));
    }

    Canister::Canister()
    {
        this->m_contentName = nullptr;
        this->m_height = 13.0;
        this->m_diameter = 10.0;
        this->m_contentVolume = 0.0;
        this->m_usable = true;
    }
    // first the default constructor is called to set all the values to default and delegating constructor
    // perform checks to update the values of the members of the current object.
    Canister::Canister(double diameter, double hieght) : Canister()
    {
        if ((hieght >= 10 && hieght <= 40) && (diameter >= 10 && diameter <= 30))
        {
            this->m_height = hieght;
            this->m_diameter = diameter;
        }
    }

    Canister::Canister(const char *contentName, double contentVolume) : Canister()
    {
        pour(contentName, contentVolume);
    }
    // used delegating constructor to set the values and 
    Canister::Canister(double diameter, double hieght,
                       const char *contentName, double contentVolume) : Canister(diameter, hieght)
    {

        pour(contentName, contentVolume);
    }
    // Destructor to deallocate the memory that we allocated before the object goes out of scope.
    Canister::~Canister()
    {
        delete[] this->m_contentName;
    }
    Canister &Canister::pour(const char *what, double howMuch)
    {
        if (this->m_usable && what != nullptr && what[0] != '\0' && howMuch > 0)
        {
            if (this->m_contentName == nullptr)
            {
                this->m_contentName = new char[strlen(what) + 1];
                strcpy(this->m_contentName, what);
            }
            if (howMuch <= this->getCapacity())
            {
                this->m_contentVolume += howMuch;
            }
            else
            {
                this->m_contentVolume = this->getCapacity();
            }
            if (strcmp(this->m_contentName, what) != 0)
            {
                char *newStr = new char[strlen(m_contentName) + strlen(what) + 17];
                strcpy(newStr, "Mix of [");
                strcat(newStr, this->m_contentName);
                strcat(newStr, "] and [");
                strcat(newStr, what);
                strcat(newStr, "]");

                delete[] this->m_contentName;
                this->m_contentName = newStr;
                this->m_usable = false;
            }
        }
        return *this;
    }

    Canister& Canister::pour(Canister &src)
    {
        if (this->m_usable && src.m_usable)
        {
            double spaceInCurrent = (this->getCapacity() - this->m_contentVolume);
            double volumeToAdd = src.m_contentVolume;
            double howMuch = (spaceInCurrent < volumeToAdd) ? spaceInCurrent : volumeToAdd;
            this->pour(src.m_contentName, howMuch);
            src.m_contentVolume -= howMuch;
            if (!(src.m_contentVolume))
                src.emptyAndWash();
        }
            return *this;
    }

    void Canister::emptyAndWash()
    {
        delete[] this->m_contentName;
        this->m_contentName = nullptr;
        this->m_contentVolume = 0.0;
        this->m_usable = true;
    }

    ostream& Canister::display(ostream& out) const{
        char fillCharacter = out.fill();
        int precisionNum = out.precision();
        if (this->m_usable)
        {
            out.precision(1);
            out.setf(ios::right | ios::fixed);
            out.fill(' ');
            out.width(8);
            out << this->getCapacity() <<"cc" ;
            out << " (" << this->m_height << "x" << this->m_diameter <<")"
                << " canister of ";
            out.precision(1);    
            out.width(8);
            out<< this->m_contentVolume<<"cc";
            out.unsetf(ios::right | ios::fixed);

            if (this->m_contentName != nullptr)
            {
                out << "  ";
                out.setf(ios::left);
                out<< this->m_contentName;
                out.unsetf(ios::left);
            }
            
        }
        else{
            out.precision(1);
            out.setf(ios::right | ios::fixed);
            out.fill(' ');
            out.width(8);
            out << this->getCapacity() <<"cc" ;
            out << " (" << this->m_height << "x" << this->m_diameter <<")"
                << " canister of ";
            out.precision(1);    
            out.width(8);
            out<< this->m_contentVolume<<"cc";
            out.unsetf(ios::right | ios::fixed);

            out << "  ";
                out.setf(ios::left);
                out<< this->m_contentName << " -> unusable content. Discard and wash!";
                out.unsetf(ios::left);
        }
        out.fill(fillCharacter);
        out.precision(precisionNum);
        return out;
        
    }

}