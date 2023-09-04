
#include "Streamable.h"

using namespace std;
namespace sdds
{
    
    ostream &operator<<(ostream &os, const Streamable &streamable)
    {
        if (!streamable)
        {
            return os;
        }else{
            streamable.write(os);
        }
        
        return os;
    }

    istream &operator>>(istream &is, Streamable &streamable)
    {
        streamable.read(is);
        return is;
    }
}