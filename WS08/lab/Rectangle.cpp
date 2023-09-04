
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds
{
    Rectangle::Rectangle() : LblShape()
    {
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char *label, int width, int height) : LblShape(label)
    {
        if (height < 3 || width < (int)strlen(label) + 2)
        {
            m_width = 0;
            m_height = 0;
        }
        else
        {
            m_width = width;
            m_height = height;
        }
    }
    void Rectangle::getSpecs(std::istream &in)
    {
        LblShape::getSpecs(in);
        char comma;
        in >> m_width >> comma >> m_height;
        in.ignore();
    }
    void Rectangle::draw(std::ostream &os) const
    {
        if (m_width > 0 && m_height > 0)
        {
            char fillChar = os.fill();
            os << '+';
            os.width(m_width - 1);
            os.fill('-');
            os << '+' << endl;

            os << "|" << label();
            os.width(m_width - 1 - (int)strlen(label()));
            os.fill(' ');
            os << '|' << endl;

            for (int i = 0; i < m_height - 3; ++i)
            {
                os << '|';
                os.width(m_width - 1);
                os.fill(' ');
                os << '|' << endl;
            }

            os << '+';
            os.width(m_width - 1);
            os.fill('-');
            os << '+';

            os.fill(fillChar);
        }
    }
}