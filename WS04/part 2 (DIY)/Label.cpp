
#include <iostream>
#include <cstring>
#include "Label.h"

using namespace std;
namespace sdds
{
    Label::Label()
    {
        this->content = nullptr;
        strcpy(this->frame, "+-+|+-+|");
    }
    Label::Label(const char *frame) : Label()
    {
        strcpy(this->frame, frame);
    }
    Label::Label(const char *frame, const char *content) : Label(frame)
    {
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
    }
    Label::~Label()
    {
        delete[] this->content;
    }
    void Label::readLabel()
    {
        char read[MAX_LENGTH +1];
        cin.getline(read, MAX_LENGTH +1);
        this->content = new char[strlen(read) + 1];
        strcpy(this->content, read);
    }
    ostream &Label::print() const
    {
        if (this->content != nullptr && this->content[0] != '\0')
        {
            int width = (strlen(content) < MAX_LENGTH ) ? strlen(content) : MAX_LENGTH;
            char fillChar = cout.fill();

            // Top frame line
            cout << frame[0];
            cout.width(width + 2);
            cout.fill(frame[1]);
            cout << "";
            cout << frame[2] << endl;

            cout << frame[7];
            cout.width(width + 2);
            cout.fill(' ');
            cout << "";
            cout << frame[3] << endl;

            cout << frame[7];
            cout << " ";
            cout.width(width - 2);
            cout.fill(' ');
            cout << (this->content ? this->content : "");
            cout << " ";
            cout << frame[3] << endl;

            cout << frame[7];
            cout.width(width + 2);
            cout.fill(' ');
            cout << "";
            cout << frame[3] << endl;

            cout << frame[6];
            cout.width(width + 2);
            cout.fill(frame[5]);
            cout << "";
            cout << frame[4];

            cout.fill(fillChar);
        }

        return std::cout;
    }
}
