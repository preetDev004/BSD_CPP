
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds{
    class LblShape: public Shape{
        private:
        char* m_label=nullptr;
        
        protected:
        const char * label() const;

        public:
        LblShape() = default;
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape& other) = delete;
        LblShape& operator=(const LblShape& other) = delete;
        void getSpecs(std::istream& in) override;

    };
}

#endif