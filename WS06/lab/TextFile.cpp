
#include <iostream>
#include <fstream>
#include "cstring.h"
#include "TextFile.h"

using namespace std;
namespace sdds
{

   Line::operator const char *() const
   {
      return (const char *)m_value;
   }
   Line &Line::operator=(const char *lineValue)
   {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line()
   {
      delete[] m_value;
   }

   void TextFile::setFilename(const char *fname, bool isCopy)
   {
      delete[] m_filename;
      if (isCopy)
      {
         m_filename = new char[strLen(fname) + 3];
         strCpy(m_filename, "C_");
         strCat(m_filename, fname);
      }
      else
      {
         m_filename = new char[strLen(fname) + 1];
         strCpy(m_filename, fname);
      }
   }
   void TextFile::setNoOfLines()
   {
      ifstream file(m_filename);
      if (file.is_open())
      {
         char fchar;
         m_noOfLines = 0;
         while (file.get(fchar))
         {
            if (fchar == '\n')
               m_noOfLines++;
         }
         if (m_noOfLines > 0 && fchar != '\n')
            m_noOfLines++;
         file.close();
      }
      else
      {
         setEmpty();
      }
   }
   void TextFile::loadText()
   {
      if (m_filename == nullptr)
         return;

      ifstream file(m_filename);
      if (file.is_open())
      {
         delete[] m_textLines;
         m_textLines = new Line[m_noOfLines];
         unsigned i;
         for (i = 0; i < m_noOfLines; i++)
         {
            string line;
            getline(file, line);
            m_textLines[i] = line.c_str();
         }
         m_noOfLines = i;
         file.close();
      }
      else
      {
         setEmpty();
      }
   }

   void TextFile::saveAs(const char *fileName) const
   {
      ofstream file(fileName);
      if (file.is_open())
      {
         for (unsigned i = 0; i < m_noOfLines; i++)
         {
            file << m_textLines[i] << endl;
         }
         file.close();
      }
   }
   void TextFile::setEmpty()
   {
      delete[] m_textLines;
      delete[] m_filename;
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
   }

   TextFile::TextFile(unsigned pageSize)
   {
      m_textLines = nullptr;
      m_filename = nullptr;
      m_noOfLines = 0;
      m_pageSize = pageSize;
   }

   TextFile::TextFile(const char *filename, unsigned pageSize) :  TextFile(pageSize)
   {
      
      if (filename != nullptr && filename[0] != '\0')
      {
         setFilename(filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile::TextFile(const TextFile &other) : TextFile(other.m_pageSize)
   {
      if (other.m_filename != nullptr)
      {
         setFilename(other.m_filename, true);
         other.saveAs(m_filename);
         setNoOfLines();
         loadText();
      }
   }

   TextFile &TextFile::operator=(const TextFile &other)
   {
      if (this != &other)
      {

         if (other.m_filename != nullptr)
         {
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
         }
      }
      return *this;
   }

   TextFile::~TextFile()
   {
      delete[] m_textLines;
      delete[] m_filename;
   }

   ostream &TextFile::view(ostream &ostr) const
   {
      if (m_filename != nullptr && m_filename[0] != '\0')
      {
         ostr << m_filename << endl;
         ostr << string(strLen(m_filename), '=') << endl;
         for (unsigned i = 0; i < m_noOfLines; i++)
         {
            ostr << m_textLines[i] << endl;
            if ((i + 1) % m_pageSize == 0)
            {
               char ch;
               ostr << "Hit ENTER to continue...";
               cin.get(ch);
            }
         }
      }
      return ostr;
   }

   istream &TextFile::getFile(istream &istr)
   {
      char fileName[256];
      istr.getline(fileName, 256, '\n');
      setFilename(fileName);
      setNoOfLines();
      loadText();
      return istr;
   }

   TextFile::operator bool() const
   {
      return m_filename != nullptr && m_filename[0] != '\0';
   }

   unsigned TextFile::lines() const
   {
      return m_noOfLines;
   }

   const char *TextFile::name() const
   {
      return m_filename;
   }

   const char *TextFile::operator[](unsigned index) const
   {
      if (m_textLines == nullptr || m_noOfLines == 0)
      {
         return nullptr;
      }
      index %= m_noOfLines;
      return m_textLines[index];
   }

   ostream &operator<<(ostream &ostr, const TextFile &text)
   {
      return text.view(ostr);
   }

   istream &operator>>(istream &istr, TextFile &text)
   {
      return text.getFile(istr);
   }
}
