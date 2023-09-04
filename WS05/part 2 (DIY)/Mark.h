
#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds{
    class Mark{
        private:
            int mark;
        
        public:
            Mark(int value = 0);
            Mark& operator+=(int value);
            Mark& operator=(int name);
            explicit operator int() const;
            explicit operator char() const;
            explicit operator double() const;
    };

        int& operator+=(int& val, const Mark& theMark);
}

#endif