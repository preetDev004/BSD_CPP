
#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;
namespace sdds
{
    Account::Account()
    {
        this->m_holderName[0] = '\0';
        this->m_number = 0;
        this->m_balance = 0.0;
    }
    Account::Account(const char *name, int number, double balance) : Account()
    {
        if (name != nullptr && name[0] != '\0')
        {
            strcpy(this->m_holderName, name);
            if (number >= 100000 && number <= 999999)
            {
                this->m_number = number;
                this->m_balance = balance;
            }
        }
    }
    void Account::display() const
    {
        auto oldFill = cout.fill();
        auto oldPrec = cout.precision();
        if (m_holderName[0] != '\0')
        {
            // there is account
            cout << "| ";
            cout.width(WIDTH_NAME);
            cout.fill(' ');
            cout.setf(std::ios::left);
            cout << this->m_holderName << " | ";
            cout.unsetf(std::ios::left);
            cout.width(WIDTH_NUM);
            if (*this)
                cout.fill('0');
            else
                cout.fill(' ');
            cout.setf(std::ios::right);
            cout << this->m_number << " | ";
            cout.setf(std::ios::fixed);
            cout.width(WIDTH_BAL);
            cout.precision(2);
            cout.fill(' ');
            cout << this->m_balance << " |\n";
            cout.unsetf(std::ios::fixed);
            cout.unsetf(std::ios::right);
        }
        else
        {
            cout.fill('x');
            cout << "| ";
            cout.width(WIDTH_NAME);
            cout << ""
                 << " | ";
            cout.width(WIDTH_NUM);
            cout << ""
                 << " | ";
            cout.width(WIDTH_BAL);
            cout << ""
                 << " |\n";
        }
        cout.fill(oldFill);
        cout.precision(oldPrec);
    }

    Account::operator const char *() const
    {
        return this->m_holderName;
    }
    Account::operator int() const
    {
        return this->m_number;
    }
    Account::operator double() const
    {
        return this->m_balance;
    }
    Account::operator bool() const
    {
        if ((this->m_holderName[0] != '\0') &&
            (this->m_number >= 100000 && this->m_number <= 999999))
            return true;

        return false;
    }
    bool Account::operator!() const
    {
        return (!((bool)*this));
    }
    Account &Account::operator=(const char *name)
    {
        if (name != nullptr && name[0] != '\0')
            strcpy(this->m_holderName, name);

        return *this;
    }
    Account &Account::operator=(int number)
    {
        if (number >= 100000 && number <= 999999)
        {
            if (this->m_number == 0 && this->m_holderName[0] != '\0')
                this->m_number = number;
        }
        return *this;
    }
    Account &Account::operator=(double balance)
    {
        if ((bool)(*this))
            this->m_balance = balance;

        return *this;
    }
    double Account::operator+(const Account &acc) const
    {
        if (((bool)*this) && (bool)acc)
            return (this->m_balance + acc.m_balance);

        return 0.0;
    }
    double Account::operator+(double amount) const
    {
        if ((bool)*this)
            return amount += this->m_balance;

        return 0.0;
    }
    Account &Account::operator++()
    {
        if ((bool)*this)
            this->m_balance += 1000.0;

        return *this;
    }
    const Account Account::operator++(int)
    {
        Account localObj = *this;
        ++(*this);
        return localObj;
    }
    Account &Account::operator+=(double amount)
    {
        if ((bool)*this)
            this->m_balance += amount;

        return *this;
    }
    bool Account::operator==(int number) const
    {
        if ((bool)*this && this->m_number == number)
            return true;

        return false;
    }
    bool Account::operator==(const char *name) const
    {
        if ((bool)*this && (strcmp(this->m_holderName, name) == 0))
            return true;

        return false;
    }
    Account &Account::operator<<(Account &acc)
    {
        if ((bool)*this && (bool)acc && this->m_number != acc.m_number)
        {
            
            this->m_balance += acc.m_balance;
            
            acc.m_balance = 0.0;
        }
        return *this;
    }
    Account &Account::operator>>(Account &acc)
    {
        acc << *this;
        return *this;
    }
    double operator+(double amount, const Account &acc)
    {
        if ((bool)acc)
            return amount + (double)acc;

        return 0.0;
    }
    double &operator+=(double &amount, const Account &acc)
    {
        if ((bool)acc)
            amount += (double)acc;
        else
            amount = 0.0;

        return amount;
    }

}