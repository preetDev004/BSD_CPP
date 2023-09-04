
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds
{
    const int MAX_LENGTH = 70;
    const int FRAME_LENGTH = 8;

    class Label
    {
    private:
        char *content;
        char frame[FRAME_LENGTH + 1];

    public:
        Label();
        Label(const char *frame);
        Label(const char *frame, const char *content);
        ~Label();
        void readLabel();
        std::ostream& print() const;
    };

}

#endif