
#include <iostream>
#include <cstring>
#include "Book.h"
#include "Lib.h"

using namespace std;
namespace sdds
{

    Book::Book() : Publication()
    {
        m_author = nullptr;
    }

    Book::Book(const Book &other) : Publication(other)
    {
        m_author = nullptr;
        *this = other;
    }
    Book &Book::operator=(const Book other)
    {
        if (this != &other)
        {
            Publication::operator=(other);
            delete[] m_author;
            if (other.m_author)
            {
                m_author = new char[strlen(other.m_author) + 1];
                strcpy(m_author, other.m_author);
            }
            else
            {
                m_author = nullptr;
            }
        }
        return *this;
    }
    Book::~Book()
    {
        delete[] m_author;
    }
    char Book::type() const
    {
        return 'B';
    }
    ostream &Book::write(ostream &os) const
    {
        this->Publication::write(os);
    
        if (m_author)
        {
            char localAuthor[255]{};
            if (conIO(os))
            {
                os << ' ';
                os.setf(ios::left | ios::fixed);
                if (strlen(m_author) > SDDS_AUTHOR_WIDTH)
                {
                    strcpy(localAuthor, m_author);
                    m_author[SDDS_AUTHOR_WIDTH] = '\0';
                }
                os.width(SDDS_AUTHOR_WIDTH);
                os << m_author;
                if (localAuthor[0] != '\0')
                {
                    strcpy(m_author, localAuthor); 
                }
                
                os.unsetf(ios::left | ios::fixed);
                os << " |";
                
            }
            else
            {
                os << '\t';
                os << m_author;
            }
        }

        return os;
    }
    istream &Book::read(istream &istr)
    {
        Publication::read(istr);
        delete[] m_author;
        m_author = nullptr;
        char localAuthor[256]{};
        if (conIO(istr))
        {
            istr.ignore();
            cout << "Author: ";
            istr.get(localAuthor, 256);
        }
        else
        {
            istr.ignore(1024, '\t');
            istr.get(localAuthor, 256);
        }
        if (!istr.fail())
        {
            if (strlen(localAuthor) > 1)
            {
                m_author = new char[strlen(localAuthor) + 1];
                strcpy(m_author, localAuthor);
            }
        }

        return istr;
    }
    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }
    Book::operator bool() const
    {
        return (m_author != nullptr && m_author[0] != '\0' && Publication::operator bool());
    }
}