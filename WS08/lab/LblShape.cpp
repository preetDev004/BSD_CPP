
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds{
    

    LblShape::LblShape(const char* label) {
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
    LblShape::~LblShape(){
        delete[] m_label;
    }
    void LblShape::getSpecs(std::istream& in){
        char label[100];
        in.getline(label, 100, ',');
        delete[] m_label;
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
    const char *LblShape::label() const
    {
        return m_label;
    }

}