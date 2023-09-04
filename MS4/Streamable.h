
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H
#include <iostream>
namespace sdds
{
    class Streamable
    {
    public:
        virtual ~Streamable(){};
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &io) const = 0;
        virtual operator bool() const = 0;
    };

    std::ostream &operator<<(std::ostream &os, const Streamable &streamable);
    std::istream &operator>>(std::istream &is, Streamable &streamable);

}

#endif