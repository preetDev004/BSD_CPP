
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Book.h"
#include "Streamable.h"
using namespace std;
namespace sdds
{
    LibApp::LibApp(const char *filename)
    {
        if (filename)
        {
            strcpy(m_fileName, filename);
        }

        m_changed = false;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";

        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";

        m_pubTypeMenu << "Book"
                      << "Publication";
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
        ifstream file(m_fileName);

        if (!file)
        {
            cout << "Error: Unable to open the data file." << endl;
            return;
        }
        char pubType;
        while (file >> pubType)
        {
            Publication *pub = nullptr;
            if (pubType == 'P') // Publication type
            {
                pub = new Publication;
                if (file >> *pub)
                {
                    m_ppa[m_nolp++] = pub;
                }
                else
                {
                    delete pub;
                }
            }
            else if (pubType == 'B') // Book type (Assuming you have a derived class Book from Publication)
            {
                pub = new Book;
                if (file >> *pub)
                {
                    m_ppa[m_nolp++] = pub;
                }
                else
                {
                    delete pub;
                }
            }
            else
            {
                cout << "Error: Invalid publication type encountered in the data file." << endl;
                delete pub;
            }
        }

        m_llrn = m_ppa[m_nolp - 1]->getRef();
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream file(m_fileName);
        if (!file)
        {
            cout << "Error: Unable to open the data file." << endl;
            return;
        }
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i]->getRef() != 0) // Skip deleted publications (ref number = 0)
            {
                file << *m_ppa[i]; // Insert publication details into the ofstream object
            }
        }
    }
    int LibApp::search(int searchMode)
    {
        // cout << "Searching for publication" << endl;
        PublicationSelector selector("Select one of the following found matches:");
        int type = m_pubTypeMenu.run();
        if (type == 0)
        {
            cout << "Aborted!" << endl;
            return 0;
        }

        char title[257] = {0};
        cin.ignore();
        cout << "Publication Title: ";
        cin.getline(title, 256, '\n');

        if (searchMode == 1)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                // Check for matching publication and type
                if (m_ppa[i] != nullptr && m_ppa[i]->type() == (type == 1 ? 'B' : 'P') && m_ppa[i]->operator==(title))
                {
                    selector << m_ppa[i];
                }
            }
        }
        else if (searchMode == 2)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                if (m_ppa[i] != nullptr && m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == (type == 1 ? 'B' : 'P') && m_ppa[i]->operator==(title) && m_ppa[i]->onLoan())
                {
                    selector << m_ppa[i];
                }
            }
        }
        else if (searchMode == 3)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                if (m_ppa[i] != nullptr && m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == (type == 1 ? 'B' : 'P') && m_ppa[i]->operator==(title) && !m_ppa[i]->onLoan())
                {
                    selector << m_ppa[i];
                }
            }
        }

        // Sort the results
        selector.sort();

        if (selector)
        {
            int libRef = selector.run();
            if (libRef)
            {
                for (int i = 0; i < m_nolp; i++)
                {
                    if (m_ppa[i]->getRef() == libRef)
                    {
                        m_ppa[i]->write(cout);
                        cout << endl;
                    }
                }
                return libRef;
            }
            else
            {
                cout << "Aborted!" << endl;
                return 0;
            }
        }
        else
        {
            cout << "No matches found!" << endl;
            return 0;
        }
    }
    Publication *LibApp::getPub(int libRef)
    {
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i] != nullptr && m_ppa[i]->getRef() == libRef)
            {
                return (m_ppa[i]);
            }
        }
        return nullptr;
    }
    void LibApp::returnPub()
    {
        cout << "Return publication to the library" << endl;
        int libRef = search(2);
        if (libRef)
        {
            if (confirm("Return Publication?"))
            {

                for (int i = 0; i < m_nolp; i++)
                {
                    if (m_ppa[i]->getRef() == libRef)
                    {
                        Date currentDate;
                        if ((currentDate - m_ppa[i]->checkoutDate()) > 15)
                        {
                            double penalty = ((currentDate - m_ppa[i]->checkoutDate()) - 15) * 0.50;

                            cout << "Please pay $";
                            cout.precision(2);
                            cout.setf(ios::fixed);
                            cout << penalty;
                            cout.unsetf(ios::fixed);
                            cout << " penalty for being " << (currentDate - m_ppa[i]->checkoutDate()) - 15 << " days late!" << endl;
                        }
                        m_ppa[i]->set(0);
                        cout << "Publication returned" << endl;
                        m_changed = true;
                    }
                }
            }
        }
        cout << endl;
    }
    void LibApp::newPublication()
    {
        if (m_nolp == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl
                 << endl;
            return;
        }

        cout << "Adding new publication to the library" << endl;
        int type = m_pubTypeMenu.run();
        if (type == 0)
        {
            cout << "Aborted!" << endl<< endl;
            return;
        }
        Publication *pub = nullptr;
        if (type == 1)
        {
            pub = new Book;
        }
        else if (type == 2)
        {
            pub = new Publication;
        }
        else
        {
            cout << "Invalid publication type selection!" << endl;
            delete pub;
            return;
        }

        if ((pub->read(cin)).fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            delete pub;
            cout << "Aborted!" << endl;
            return;
        }

        if (confirm("Add this publication to the library?"))
        {
            m_changed = true;
            m_nolp++;
            pub->setRef(++m_llrn);
            m_ppa[m_nolp - 1] = pub;
            m_changed = true;
            cout << "Publication added" << endl;
        }
        else
        {
            delete pub;
            cout << "Aborted!" << endl;
            return;
        }
        cout << endl;
    }
    LibApp::~LibApp()
    {
        for (int i = 0; i < m_nolp; i++)
        {
            delete m_ppa[i];
        }
    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int ref = search();
        if (ref)
        {

            if (confirm("Remove this publication from the library?"))
            {
                for (int i = 0; i < m_nolp; i++)
                {
                    if (m_ppa[i]->getRef() == ref)
                    {
                        m_ppa[i]->setRef(0);
                    }
                }
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
        cout << endl;
    }
    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int libRef = search(3);
        if (libRef)
        {

            if (confirm("Check out publication?"))
            {
                int localMembership = 0;
                cout << "Enter Membership number: ";
                do
                {
                    cin >> localMembership;
                    if (localMembership < 10000 || localMembership > 99999)
                    {
                        cout << "Invalid membership number, try again: ";
                    }

                } while (localMembership < 10000 || localMembership > 99999);

                for (int i = 0; i < m_nolp; i++)
                {
                    if (m_ppa[i]->getRef() == libRef)
                    {
                        m_ppa[i]->set(localMembership);
                    }
                }

                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
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
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }

}
