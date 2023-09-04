
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
    private:
        int m_width = 0;
        int m_height = 0;

    public:
    Rectangle();
    Rectangle(const char* label, int width, int height);
    void getSpecs(std::istream& in)override;
    void draw(std::ostream& os) const override;

    };
}

#endif