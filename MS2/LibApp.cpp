
#include <iostream>
#include <cstring>
#include "LibApp.h"
using namespace std;
namespace sdds
{
    LibApp::LibApp()
    {
        m_changed = false;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";

        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        load();
    }
    bool LibApp::confirm(const char *message)
    {
        Menu confirmMenu(message);
        confirmMenu << "Yes";
        unsigned int selection = confirmMenu.run();
        return (selection == 1);
    }

    void LibApp::load()
    {
        cout << "Loading Data" << endl;
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
    }
    void LibApp::search()
    {
        cout << "Searching for publication" << endl;
    }
    void LibApp::returnPub()
    {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
        cout<<endl;
    }
    void LibApp::newPublication()
    {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?"))
        {
            m_changed = true;
            cout << "Publication added"<<endl;
        }
        cout<<endl;
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?"))
        {
            m_changed = true;
            cout << "Publication removed"<<endl;
        }
        cout<<endl;
    }
    void LibApp::checkOutPub()
    {
        search();
        if (confirm("Check out publication?"))
        {
            m_changed = true;
            cout << "Publication checked out"<<endl;

        }
        cout<<endl;
    }
    void LibApp::run()
    {
        
            bool flag = true;

            while (flag)
            {
                unsigned int selection = m_mainMenu.run();

                switch (selection)
                {
                case 1:
                    newPublication();
                    break;
                case 2:
                    removePublication();
                    break;
                case 3:
                    checkOutPub();
                    break;
                case 4:
                    returnPub();
                    break;
                case 0:
                    if (m_changed)
                    {
                        unsigned int exitSelection = m_exitMenu.run();
                        if (exitSelection == 1)
                        {
                            save();
                            flag = false;
                        }
                        else if (exitSelection == 2)
                        {
                            cout << endl;
                        }
                        else
                        {
                            int confirmSelection = confirm("This will discard all the changes are you sure?");
                            if (confirmSelection == 1)
                            {
                                flag = false;
                            }
                            else
                            {
                                cout << endl;
                            }
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                    break;
                 default:
                    cout << "Invalid selection. Please try again." << endl;
                    break;
                }
            }
            cout<<endl;
            cout << "-------------------------------------------" << endl;
            cout << "Thanks for using Seneca Library Application" << endl;
        }
    
}
