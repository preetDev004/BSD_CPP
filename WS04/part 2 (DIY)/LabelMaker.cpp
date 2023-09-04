
#include <iostream>
#include <cstring>
#include "LabelMaker.h"
#include "Label.h"

using namespace std;
namespace sdds
{
    LabelMaker::LabelMaker()
    {
        this->labels = nullptr;
        this->size = 0;
    }
    LabelMaker::LabelMaker(int noOfLabels) : LabelMaker()
    {
        this->labels = new Label[noOfLabels];
        size = noOfLabels;
    }
    void LabelMaker::readLabels()
    {
        cout<<"Enter "<<this->size<<" labels:"<<endl;
        for (int i = 0; i < this->size; ++i) {
            std::cout << "Enter label number " << i + 1 << " > ";
            this->labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < this->size; ++i) {
            this->labels[i].print();
            cout<<endl;
        }
    }
    LabelMaker::~LabelMaker(){
        delete[] this->labels;
    }
}