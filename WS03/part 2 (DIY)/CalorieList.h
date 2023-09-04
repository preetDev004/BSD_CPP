
#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds{
    class CalorieList{
    private:
        Food* m_items;
        int m_capacity;
        int m_cntItems;
        int getTotalCalories() const;
        void displayHeader() const;
        void displayFooter() const;
        bool isValid() const;

    public:
        void reset();
        void init(int capacity);
        bool add(const char* food_name, int calories, int when);
        void display() const;
};
}
#endif