
#include <cstring>
#include <iostream>
#include "Item.h"

using namespace std;
namespace sdds{
void Item::init()
{
    strcpy(m_name, "");
    m_price = 0.0;
    m_isTaxed = true;
}

bool Item::set(const char *name, double price, bool isTaxed)
{
    if ((name != nullptr && (strlen(name) > 0)) && (price > 0))
    {
        strcpy(m_name, name);
        m_name[WIDTH_NAME] = '\0';
        m_price = price;
        m_isTaxed = isTaxed;

        return true;
    }
    else
    {
        init();
        return false;
    }
}

void Item::display() const
{
    // to store the current fillCharacter
    char fillCharacter = cout.fill();
    // to store the current precision 
    int precisionNum = cout.precision();
    cout.precision(2);

    if (!isEmpty())
    {
        cout << "| ";
        cout.width(WIDTH_NAME);
        cout.fill('.');
        cout.setf(ios::left);
        cout << m_name;
        cout << " | ";
        cout.width(WIDTH_PRICE);
        cout.setf(ios::right | ios::fixed);
        cout.fill(' ');
        cout << m_price;
        cout << " | ";
        cout.width(WIDTH_TAX);
        cout.setf(ios::right);
        cout.fill(' ');
        cout << (m_isTaxed ? "Yes" : "No");
        cout << " |" << endl;
        cout.unsetf(ios::right | ios::left | ios::fixed);
    }
    else
    {
        cout << "| ";
        cout.width(WIDTH_NAME);
        cout.fill('x');
        cout << "xxx";
        cout << " | ";
        cout.width(WIDTH_PRICE);
        cout.fill('x');
        cout << "xxx";
        cout << " | ";
        cout.width(WIDTH_TAX);
        cout.fill('x');
        cout << "xxx";
        cout << " |" << endl;
    }

    cout.fill(fillCharacter);
    cout.precision(precisionNum);
}

bool Item::isEmpty() const
{
    return (strlen(m_name) == 0);
}

double Item::getPrice() const
{
    return m_price;
}

double Item::getTax() const
{
    if (m_isTaxed)
    {
        return m_price * 0.13;
    }
    else
        return 0;
}
}