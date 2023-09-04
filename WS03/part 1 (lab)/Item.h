
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

const int  WIDTH_NAME = 32;
const int  WIDTH_PRICE = 8;
const int WIDTH_TAX = 4;

namespace sdds{

class Item
{
private:
    char m_name[WIDTH_NAME + 1];
    double m_price;
    bool m_isTaxed;

public:
    void init();

    bool set(const char* name, double price, bool isTaxed);

    void display() const;

    bool isEmpty() const;

    double getPrice() const;

    double getTax() const;
};
}
#endif