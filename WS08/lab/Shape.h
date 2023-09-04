
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>

namespace sdds{
    class Shape{
        public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& in) = 0;
        virtual ~Shape();

    };
    std::ostream& operator<<(std::ostream& os, const Shape& shape);
    std::istream& operator>>(std::istream& in, Shape& shape);
}

#endif