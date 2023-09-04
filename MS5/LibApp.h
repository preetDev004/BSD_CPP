
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace sdds
{
   class LibApp
   {
   private:
      bool m_changed;
      char m_fileName[256]{};
      Publication* m_ppa[SDDS_LIBRARY_CAPACITY];
      int m_nolp=0;
      int m_llrn;
      Menu m_pubTypeMenu{"Choose the type of publication:"};
      Menu m_mainMenu{"Seneca Library Application"};
      Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};
      bool confirm(const char *message);
      void load();
      void save();
      int search(int searchMode = 1);
      Publication* getPub(int libRef);
      void returnPub();
      void newPublication();
      void removePublication();
      void checkOutPub();

   public:
      LibApp(const char* filename);
      ~LibApp();
      void run();

   };
}
#endif // !SDDS_LIBAPP_H
