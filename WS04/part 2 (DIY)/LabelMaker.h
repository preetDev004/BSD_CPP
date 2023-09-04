
#ifndef SDDS_LABEMAKERL_H
#define SDDS_LABEMAKERL_H

#include "Label.h"

namespace sdds
{
    class LabelMaker
    {
        private:
            Label* labels;
            int size;
        
        public:
            LabelMaker();
            LabelMaker(int noOfLabels);
            void readLabels();
            void printLabels();
            ~LabelMaker();
    };
}

#endif