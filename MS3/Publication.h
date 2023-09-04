
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Streamable.h"
#include "Date.h"

namespace sdds
{
    class Publication : public Streamable
    {
    private:
        char* m_title;
        char m_shelfId[5];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        ~Publication();
        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char*() const;
        int getRef() const;
        bool conIO(std::ios& io) const;
        operator bool() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
    };
}

#endif
