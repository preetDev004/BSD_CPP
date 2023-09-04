
#include "HtmlText.h"
#include "Text.h"
#include "cstring.h"
namespace sdds
{
    HtmlText::HtmlText(const char *filename, const char *title) : Text(filename)
    {
        m_title = nullptr;
        if (title)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
        
    }

    HtmlText::HtmlText(const HtmlText &other) : HtmlText(other.m_title) 
    {
        *this = other;
    }

    HtmlText &HtmlText::operator=(const HtmlText &other)
    {
        if (this != &other)
        {
            if (other.m_title!= nullptr)
            {
                Text::operator=(other);
                delete[] m_title;
                m_title = nullptr;
                int len = strLen(other.m_title);
                m_title = new char[len + 1];
                strCpy(m_title, other.m_title);
            }
        }
        return *this;
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
    }
    void HtmlText::write(std::ostream &os) const
    {
        os << "<html><head><title>";
        if (m_title)
        {
            os << m_title;
        }
        else
        {
            os << "No Title";
        }
        os << "</title></head>\n<body>\n";

        if (m_title)
        {
            os << "<h1>" << m_title << "</h1>\n";
        }

        bool MS = false;
        int i = 0;
        while(((*this)[i] != '\0'))
        {
            char c = (*this)[i];

            switch (c)
            {
            case ' ':
                if (MS)
                {
                    os << "&nbsp;";
                }
                else
                {
                    MS = true;
                    os << c;
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                MS = false;
                os << c;
                break;
            }
            i++;
        }

        os << "</body>\n</html>";
    }
}