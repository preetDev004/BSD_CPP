
#include <cstring>
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace sdds
{
    Publication::Publication()
    {
        // declare all the attributes to their default nll or empty state
        m_title = new char[1];
        m_title[0] = '\0';
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
    }
    Publication::Publication(const Publication &other) : Publication()
    {
        *this = other;
    }
    Publication &Publication::operator=(const Publication &other)
    {
        if (this != &other)
        {
            delete[] m_title; 
            m_shelfId[0] = '\0';

            if (other.m_title)
            {
                m_title = new char[strlen(other.m_title) + 1];
                std::strcpy(m_title, other.m_title);
            }
            else
            {
                m_title = new char[1];
                m_title[0] = '\0';
            }

            std::strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }
    Publication::~Publication()
    {
        delete[] m_title;
    }
    void Publication::set(int member_id)
    {
        if (member_id >= 10000 && member_id <= 99999)
        {
            m_membership = member_id;
        }
        else
        {
            m_membership = 0;
        }
    }
    void Publication::setRef(int value)
    {
        m_libRef = value;
    }
    void Publication::resetDate()
    {
        m_date = Date();
    }
    char Publication::type() const
    {
        return 'P';
    }
    bool Publication::onLoan() const
    {
        return (m_membership != 0);
    }
    Date Publication::checkoutDate() const
    {
        return m_date;
    }
    bool Publication::operator==(const char *title) const
    {
        if ((strstr(m_title, title)) != nullptr)
        {
            return true;
        }
        return false;
    }
    Publication::operator const char *() const
    {
        return m_title;
    }
    int Publication::getRef() const
    {
        return m_libRef;
    }
    bool Publication::conIO(ios &io) const
    {
        return (&io == &std::cout || &io == &std::cin);
    }
    Publication::operator bool() const
    {
        return (m_title != nullptr && m_title[0] != '\0');
    }
    ostream &Publication::write(ostream &os) const
    {
        if (m_title[0] != '\0')
        {
            if (conIO(os))
            {

                os << "| ";
                os.width(SDDS_SHELF_ID_LEN);
                os << m_shelfId << " | ";

                char fillChar = os.fill(' ');
                os.width(SDDS_TITLE_WIDTH);
                os.setf(ios::left);
                os.fill('.');

                os << m_title;

                os << " | ";
                os.unsetf(ios::left);
                os.fill(fillChar);
                if (m_membership == 0)
                {
                    os << " N/A ";
                }
                else
                {
                    os << m_membership;
                }

                os << " | ";
                os << m_date << " |";
            }
            else
            {
                os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t'
                   << m_title << '\t' << m_membership << '\t' << m_date;
            }
        }

        return os;
    }
    istream &Publication::read(istream &istr)
    {
        char localTitle[256]{};
        char localShelfId[SDDS_SHELF_ID_LEN + 1];
        int localMembership =0;
        int localLibRef=-1;
        Date localDate;

        delete[] m_title;
        m_title = new char[1];
        m_title[0] = '\0';
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        if (conIO(istr))
        {

            std::cout << "Shelf No: ";
            localShelfId[0] = '\0';
            istr.getline(localShelfId, SDDS_SHELF_ID_LEN+1,'\n');
            if (strlen(localShelfId) != SDDS_SHELF_ID_LEN)
            {
                istr.setstate(ios::failbit);
                return istr;
            }
            localShelfId[SDDS_SHELF_ID_LEN + 1] = '\0';

            std::cout << "Title: ";
            istr.getline(localTitle, 255,'\n');

            std::cout << "Date: ";
            istr >> localDate;

            m_libRef = -1;
        }
        else
        {
            istr >> localLibRef;
            // istr.ignore('\t');
            istr.ignore();
            istr.getline(localShelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            istr.getline(localTitle, 255, '\t');
            istr >> localMembership;
            istr.ignore();
            istr >> localDate;
        }

        if (!localDate)
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        delete[] m_title;
        m_title = new char[strlen(localTitle) + 1];
        std::strcpy(m_title, localTitle);
        m_membership = localMembership;
        m_date = localDate;
        std::strcpy(m_shelfId, localShelfId);
        m_libRef = localLibRef;

        return istr;
    }

}

