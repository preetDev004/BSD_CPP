
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"

namespace sdds{
    class Book : public Publication {
        private:
        char* m_author;

        public:
        Book();
        Book(const Book& other);
        Book& operator=(const Book other);
        ~Book();
        char type()const override;
        std::ostream& write(std::ostream &os) const override;
        std::istream& read(std::istream& istr) override;
        void set(int member_id) override;
        operator bool() const override;

    };
}

#endif