
#include <iostream>
#include "Bill.h"

using namespace std;

namespace sdds
{
    double Bill::getTotalTax() const
    {
        double totalTax = 0.0;
        for (int i = 0; i < m_cntItems; i++)
        {
            totalTax += m_items[i].getTax();
        }
        return totalTax;
    }
    double Bill::getTotalPrice() const
    {
        double totalPrice = 0.0;
        for (int i = 0; i < m_cntItems; i++)
        {
            totalPrice += m_items[i].getPrice();
        }
        return totalPrice;
    }

    void Bill::displayHeader() const
    {
        char fillCharacter = cout.fill(' ');
        cout.fill(' ');
        cout << "+----------------------------------------------------+\n";
        cout << "| ";
        cout.width(WIDTH_NAME + WIDTH_PRICE + WIDTH_TAX + 6);
        cout.setf(ios::left);
        if (isValid())
            cout << m_title;
        else
            cout << "Invalid Bill";
        cout << " |\n";
        cout.unsetf(ios::left);
        cout << "+----------------------------------+----------+------+\n";
        cout << "| ";
        cout.setf(ios::left);
        cout.width(WIDTH_NAME);
        cout << "Item Name";
        cout << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::right);
        cout.width(WIDTH_PRICE);
        cout << "Price";
        cout << " | ";
        cout.width(WIDTH_TAX);
        cout << "Tax";
        cout.unsetf(ios::right);
        cout << " |\n";
        cout << "+----------------------------------+----------+------+\n";
        cout.fill(fillCharacter);
    }

    void Bill::displayFooter() const
    {
        char fillCharacter = cout.fill();
        int precisionNum = cout.precision();

        if (!isValid())
        {
            cout << "+----------------------------------+----------+------+\n";
            return;
        }
        double amountBeforeTax = getTotalPrice();
        double taxAmount = getTotalTax();
        double amountAfterTax = amountBeforeTax + taxAmount;

        cout << "+----------------------------------+----------+------+\n";
        cout << "|                        Price Before Tax : ";
        cout.width(WIDTH_PRICE);
        cout.setf(ios::fixed | ios::right);
        cout.precision(2);
        cout.fill(' ');
        cout << amountBeforeTax << " |\n";

        cout << "|                                     Tax : ";
        cout.width(WIDTH_PRICE);
        cout.setf(ios::fixed | ios::right);
        cout.precision(2);
        cout.fill(' ');
        cout << taxAmount << " |\n";

        cout << "|                         Price After Tax : ";
        cout.width(WIDTH_PRICE);
        cout.setf(ios::fixed | ios::right);
        cout.precision(2);
        cout.fill(' ');
        cout << amountAfterTax << " |\n";

        cout << "+----------------------------------------------------+\n";
        cout.precision(precisionNum);
        cout.fill(fillCharacter);
        cout.unsetf(ios::fixed | ios::right);
    }

    bool Bill::isValid() const
    {
        if (m_items == nullptr && m_title[0] == '\0')
        {
            return false;
        }
        for (int i = 0; i < m_capacity; i++)
        {
            if (m_items[i].isEmpty())
            {
                return false;
            }
        }
        return true;
    }

    void Bill::init(const char *title, int capacity)
    {
        if (title != nullptr && strlen(title) > 0 && capacity > 0)
        {
            strncpy(m_title, title, 50);
            m_capacity = capacity;
            m_items = new Item[m_capacity];

            for (int i = 0; i < m_capacity; i++)
            {
                m_items[i].init();
            }
            m_cntItems = 0;
        }
        else
        {
            strcpy(m_title, "");
            m_capacity = 0;
            m_items = nullptr;
            m_cntItems = 0;
        }
    }
    bool Bill::add(const char *item_name, double item_price, bool isTaxed)
    {
        if (m_cntItems < m_capacity)
        {
            bool isAdded = m_items[m_cntItems].set(item_name, item_price, isTaxed);
            m_cntItems++;
            return isAdded;
        }
        else
        {
            return false;
        }
    }
    void Bill::display() const
    {
        displayHeader();
        for (int i = 0; i < m_capacity; i++)
        {
            m_items[i].display();
        }
        displayFooter();
    }
    void Bill::cleanup()
    {

        delete[] m_items;
        m_items = nullptr;
        strcpy(m_title, "");
        m_capacity = 0;
        m_cntItems = 0;
    }
}
