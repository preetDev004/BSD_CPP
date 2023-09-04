
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
   int Text::getFileLength() const
   {
      int len = 0;
      ifstream fin(m_filename);
      while (fin)
      {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   const char &Text::operator[](int index) const
   {
      return m_content[index];
   }
   Text::Text(const char *filename)
   {
      if (filename)
      {
         m_filename = new char[strLen(filename) + 1];
         strCpy(m_filename, filename);
         m_content = nullptr;
         read();
      }
      else
      {
         m_content = nullptr;
         m_filename = nullptr;
      }
   }
   Text::~Text()
   {
      delete[] m_filename;
      delete[] m_content;
   }
   Text::Text(const Text &other) : Text(other.m_filename)
   {
      *this = other;
   }
   Text &Text::operator=(const Text &other)
   {
      if (this != &other)
      {
        
            delete[] m_filename;
            delete[] m_content;

            m_filename = nullptr;
            m_content = nullptr;

            if (other.m_filename)
            {
                m_filename = new char[strLen(other.m_filename) + 1];
                strCpy(m_filename, other.m_filename);
            }

            if (other.m_content)
            {
                int len = strLen(other.m_content);
                m_content = new char[len + 1];
                strnCpy(m_content, other.m_content, len + 1);
            }
        
      }
      return *this;
   }
   void Text::read()
   {
      int len = getFileLength();
      if (len == 0)
      {
         m_content = nullptr; // Set to empty state
         return;
      }
      m_content = new char[len + 1];
      ifstream file(m_filename);
      if (file.is_open())
      {
         char c;
         int i = 0;
         while (file.get(c))
         {
            m_content[i] = c;
            i++;
         }
         m_content[i] = '\0'; // Null-terminate the string
         file.close();
      }
      else
      {
         delete[] m_content;
         m_content = nullptr; // Set to empty state
      }
   }
   void Text::write(ostream &os) const
   {
      if (m_content != nullptr)
      {
         os << m_content;
      }
   }
   ostream &operator<<(ostream &os, const Text &text)
   {
      text.write(os);
      return os;
   }
}