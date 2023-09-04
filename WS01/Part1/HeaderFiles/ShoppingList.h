
#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H
// Your header file content goes here
namespace sdds
{
    const int MAX_NO_OF_RECS = 15;
    bool loadList();
    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    bool saveList();
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
    bool listIsEmpty();
}
#endif