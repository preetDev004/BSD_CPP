
#include "Line.h"

using namespace std;
namespace sdds
{
    Line::Line() : LblShape()
    {
        m_length = 0;
    }
    Line::Line(const char *label, int length) : LblShape(label)
    {
        m_length = length;
    }
    void Line::getSpecs(std::istream &in)
    {
        LblShape::getSpecs(in);
        in >> m_length;
        in.ignore();
    }
    void Line::draw(std::ostream &os) const
    {
        if (m_length > 0 && label() != nullptr)
        {
            os << label() << endl;
            for (int i = 0; i < m_length; ++i)
            {
                os << '=';
            }
        }
    }
}