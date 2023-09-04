
#ifndef SDDS_BILL_H
#define SDDS_BILL_H
#include "Item.h"

namespace sdds{
    class Bill{
    private:
        char m_title[51];
        Item* m_items;
        int m_capacity;
        int m_cntItems;
        double getTotalTax() const;
        double getTotalPrice() const;
        void displayHeader() const;
        void displayFooter() const;
        bool isValid() const;

    public:
        void init(const char* title, int capacity);
        bool add(const char* item_name, double item_price, bool isTaxed);
        void display() const;
        void cleanup();
};
}
#endif