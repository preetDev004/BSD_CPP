
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    MenuItem::MenuItem(const char *desc)
    {
        m_desc = new char[strlen(desc) + 1];
        strcpy(m_desc, desc);
    }
    MenuItem::~MenuItem()
    {
        delete[] m_desc;
    }
    MenuItem::operator bool() const
    {
        return (m_desc[0] != '\0');
    }
    MenuItem::operator const char *() const
    {
        return m_desc;
    }
    void MenuItem::display(ostream &os) const
    {
        if (m_desc[0] != '\0')
        {
            os << m_desc;
        }
    }

    Menu::Menu(const char *title)
    {
        m_title = nullptr;
        m_title = new MenuItem(title);

        for (unsigned i = 0; i < MAX_MENU_ITEMS; i++)
        {
            menuItems[i] = nullptr;
        }
        noOfItems = 0;
    }
    Menu::~Menu()
    {
        delete m_title;
        for (int i = 0; i < noOfItems; i++)
        {
            delete menuItems[i];
            menuItems[i] = nullptr;
        }
    }
    void Menu::displayTitle(ostream &os) const
    {
        if (m_title != nullptr && m_title[0] != '\0')
        {
            m_title->display(os);
            os<< endl;
        }
    }
    void Menu::displayMenu(ostream &os) const
    {
        displayTitle(os);

        for (int i = 0; i < noOfItems; i++)
        {
            os << " " << i + 1 << "- ";
            menuItems[i]->display(os) ;
            os<< endl;
        }

        os << " 0- Exit" << endl;
        os << "> ";
    }
    unsigned int Menu::run()
    {
        displayMenu();
        unsigned int selection = getIntegerInput(0, noOfItems);
        return selection;
    }
    unsigned int Menu::operator~()
    {
        return run();
    }
    Menu &Menu::operator<<(const char *menuItemContent)
    {
        if ((unsigned int)noOfItems < MAX_MENU_ITEMS)
        {
            menuItems[noOfItems] = new MenuItem(menuItemContent);
            noOfItems++;
        }
        return *this;
    }
    Menu::operator int() const
    {
        return noOfItems;
    }

    Menu::operator unsigned int() const
    {
        return (unsigned int)(noOfItems);
    }
    Menu::operator bool() const
    {
        return (noOfItems > 0);
    }
    const char *Menu::operator[](int index) const
    {
        if (noOfItems > 0)
        {
            return *menuItems[index % noOfItems];
        }
        else
        {
            return nullptr;
        }
    }
    ostream& operator<<(ostream& os, const Menu& menu)
    {
        menu.m_title->display(os);
        return os;
    }

}

