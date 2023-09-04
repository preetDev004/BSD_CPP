
#include "Shape.h"
using namespace std;
namespace sdds{
    Shape::~Shape(){
        // empty distructor.
    }
    ostream& operator<<(ostream& os, const Shape& shape){
        shape.draw(os);
        return os;
    }
    istream& operator>>(istream& in,  Shape& shape){
        shape.getSpecs(in);
        return in;
    }
}