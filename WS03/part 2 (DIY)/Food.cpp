
#include <cstring>
#include <iostream>
#include "Food.h"

using namespace std;
namespace sdds{
void Food::init()
{
    strcpy(m_foodName, "");
    m_cal = 0;
    m_when = 0;
}

bool Food::set(const char *food_name, int calories, int when)
{
    if ((food_name != nullptr && (strlen(food_name) > 0)) &&
        (calories > 0 && calories <= 3000) && 
        (when >=1 && when <= 4))
    {
        strcpy(m_foodName, food_name);
        m_foodName[FOOD_NAME] = '\0';
        m_cal = calories;
        m_when  = when;

        return true;
    }
    else
    {
        init();
        return false;
    }
}

void Food::display() const
{
    // to store the current fillCharacter
    char fillCharacter = cout.fill();

    if (!isEmpty())
    {
        cout << "| ";
        cout.width(FOOD_NAME);
        cout.fill('.');
        cout.setf(ios::left);
        cout << m_foodName;
        cout << " | ";
        cout.unsetf(ios::left);
        cout.width(CALORIES);
        cout.setf(ios::right | ios::fixed);
        cout.fill(' ');
        cout << m_cal;
        cout << " | ";
        cout.unsetf(ios::right | ios::fixed);
        cout.width(WHEN);
        cout.setf(ios::left);
        cout.fill(' ');
        switch (m_when)
        {
        case 1:
            cout << "Breakfast";
            break;
        case 2:
            cout << "Lunch";
            break;
        case 3:
            cout << "Dinner";
            break;
        case 4:
            cout << "Snack";
            break;
        
        default:
            break;
        }
        cout << " |" << endl;
        cout.unsetf(ios::left);
    }
    else
    {
        cout << "| ";
        cout.width(FOOD_NAME);
        cout.fill('x');
        cout << "xxx";
        cout << " | ";
        cout.width(CALORIES);
        cout.fill('x');
        cout << "xxx";
        cout << " | ";
        cout.width(WHEN);
        cout.fill('x');
        cout << "xxx";
        cout << " |" << endl;
    }

    cout.fill(fillCharacter);
}

bool Food::isEmpty() const
{
    return (strlen(m_foodName) == 0);
}

int Food::getCalories() const
{
    return m_cal;
}

}