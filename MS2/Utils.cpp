
#include "Utils.h"
using namespace std;
namespace sdds {
    int getIntegerInput(int minVal, int maxVal) {
    int selection;
    while (true) {
        if (cin >> selection && selection >= minVal && selection <= maxVal) {
            break; // Valid input, break the loop
        }
        else {
            cout << "Invalid Selection, try again: ";
            cin.clear(); // Clear error flags
            cin.ignore(100, '\n'); // Discard invalid input
            
        }
    }
    return selection;
}

}