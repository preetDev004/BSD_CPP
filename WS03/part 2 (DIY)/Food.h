
#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

const int FOOD_NAME = 30;
const int CALORIES = 4;
const int WHEN = 10;

namespace sdds
{

    class Food
    {
    private:
        char m_foodName[FOOD_NAME + 1];
        int m_cal;
        int m_when;

    public:
        void init();
        
        bool isEmpty() const;

        bool set(const char *food_name, int calories, int when);

        void display() const;

        int getCalories() const;
    };
}
#endif