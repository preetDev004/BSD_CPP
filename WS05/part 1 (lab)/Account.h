
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

namespace sdds
{
    const int NAME_LENGTH = 100;
    const int WIDTH_NAME = 10;
    const int WIDTH_NUM = 8;
    const int WIDTH_BAL = 10;
    class Account
    {
    private:
        char m_holderName[NAME_LENGTH + 1];
        int m_number;
        double m_balance;

    public:
        Account();
        Account(const char *name, int number, double balance = 0.0);
        void display() const;
        explicit operator const char *() const;
        explicit operator int() const;
        explicit operator double() const;
        explicit operator bool() const;
        bool operator!() const;
        Account &operator=(const char *name);
        Account &operator=(int number);
        Account &operator=(double balance);
        double operator+(const Account &acc) const;
        double operator+(double amount) const;
        Account &operator++();
        const Account operator++(int);
        Account &operator+=(double amount);
        bool operator==(int number) const;
        bool operator==(const char *name) const;
        Account &operator<<(Account &acc);
        Account &operator>>(Account &acc);
    };
    double operator+(double amount, const Account &acc);
    double& operator+=(double &amount, const Account &acc);
}

#endif