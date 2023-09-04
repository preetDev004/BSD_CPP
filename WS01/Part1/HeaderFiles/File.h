
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
// Your header file content goes here
namespace sdds
{
    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };
    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec *rec);
    void fwriteShoppintRec(const ShoppingRec *rec);
}
#endif