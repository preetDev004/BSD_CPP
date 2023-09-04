
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{

    class Menu;

    class MenuItem
    {
    private:
        char *m_desc;
        friend class Menu;

        MenuItem(const char *desc = "");
        MenuItem(const MenuItem &other) = delete;
        MenuItem &operator=(const MenuItem &other) = delete;
        ~MenuItem();
        operator bool() const;
        operator const char *() const;
        void display(std::ostream &os = std::cout) const;
        friend std::ostream &operator<<(std::ostream &os, const Menu &menu);
    };

    class Menu
    {
    private:
        static const unsigned int MAX_MENU_ITEMS = 20;
        MenuItem *m_title;
        MenuItem *menuItems[MAX_MENU_ITEMS];
        int noOfItems;

    public:
        Menu(const char *title = "");
        Menu(const Menu &other) = delete;
        Menu &operator=(const Menu &other) = delete;
        ~Menu();
        void displayTitle(std::ostream &os = std::cout) const;
        void displayMenu(std::ostream &os = std::cout) const;
        unsigned int run();
        unsigned int operator~();
        Menu &operator<<(const char *menuItemContent);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        // std::ostream& operator<<(const Menu& menu);
        const char *operator[](int index) const;

        friend std::ostream &operator<<(std::ostream &os, const Menu &menu);
    };
}

#endif