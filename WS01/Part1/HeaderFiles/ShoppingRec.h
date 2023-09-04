
#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H
#include "File.h"
// Your header file content goes here
namespace sdds
{
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec *shp);
    void toggleBoughtFlag(ShoppingRec *rec);
    bool isShoppingRecEmpty(const ShoppingRec *shp);
}
#endif