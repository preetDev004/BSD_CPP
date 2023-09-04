
#include <iostream>
#include "CalorieList.h"

using namespace std;

namespace sdds
{

    int CalorieList::getTotalCalories() const
    {
        double totalCalories = 0;
        for (int i = 0; i < m_cntItems; i++)
        {
            totalCalories += m_items[i].getCalories();
        }
        return totalCalories;
    }

    void CalorieList::displayHeader() const
    {
        char fillCharacter = cout.fill(' ');
        cout.fill(' ');
        cout << "+----------------------------------------------------+\n";
        cout << "|";
        cout.width(FOOD_NAME + CALORIES + WHEN + 6);
        cout.setf(ios::left);
        if (isValid())
            cout << "  Daily Calorie Consumption";
        else
            cout << " Invalid Calorie Consumption list";
        cout << "  |\n";
        cout.unsetf(ios::left);
        cout << "+--------------------------------+------+------------+\n";
        cout << "| ";
        cout.setf(ios::left);
        cout.width(FOOD_NAME);
        cout << "Food name";
        cout << " | ";
        cout.unsetf(ios::left);
        cout.setf(ios::left);
        cout.width(CALORIES);
        cout << "Cals";
        cout << " | ";
        cout.width(WHEN);
        cout << "When";
        cout.unsetf(ios::left);
        cout << " |\n";
        cout << "+--------------------------------+------+------------+\n";
        cout.fill(fillCharacter);
    }

    void CalorieList::displayFooter() const
    {
        char fillCharacter = cout.fill();

        if (!isValid())
        {
            cout << "+--------------------------------+------+------------+\n";
            // cout << "|    Invalid Calorie Consumption list                |\n";
            cout << "|";
            cout.width(FOOD_NAME + CALORIES + WHEN + 6);
            cout.setf(ios::left);
            cout.fill(' ');
            cout << "    Invalid Calorie Consumption list";
            cout << "  |\n";
            cout << "+----------------------------------------------------+\n";
            cout.fill(fillCharacter);
            cout.unsetf(ios::left);
            return;
        }
        else
        {
            int totalCalories = getTotalCalories();
            cout << "+--------------------------------+------+------------+\n";
            cout << "|    Total Calories for today:     ";

            cout.width(CALORIES);
            cout.setf(ios::right);
            cout.fill(' ');
            cout << totalCalories;
            cout << " | ";

            cout.width(WHEN + 3);
            cout.fill(' ');
            cout << " |\n";
            cout << "+----------------------------------------------------+\n";
            cout.fill(fillCharacter);
        }

        
        cout.unsetf(ios::right);
    }

    bool CalorieList::isValid() const
    {
        if (m_items == nullptr)
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

    void CalorieList::init(int capacity)
    {
        if (capacity > 0)
        {
            m_capacity = capacity;
            m_items = new Food[m_capacity];

            for (int i = 0; i < m_capacity; i++)
            {
                m_items[i].init();
            }
            m_cntItems = 0;
        }
        else
        {
            m_capacity = 0;
            m_items = nullptr;
            m_cntItems = 0;
        }
    }
    bool CalorieList::add(const char *food_name, int calories, int when)
    {
        if (m_cntItems < m_capacity)
        {
            bool isAdded = m_items[m_cntItems].set(food_name, calories, when);
            m_cntItems++;
            return isAdded;
        }
        else
        {
            return false;
        }
    }
    void CalorieList::display() const
    {
        displayHeader();
        for (int i = 0; i < m_capacity; i++)
        {
            m_items[i].display();
        }
        displayFooter();
    }
    void CalorieList::reset()
    {

        delete[] m_items;
        m_items = nullptr;
        m_capacity = 0;
        m_cntItems = 0;
    }
}
