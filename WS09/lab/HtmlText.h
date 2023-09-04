
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds
{
   class HtmlText : public Text
   {
      char *m_title;

   public:
      HtmlText(const char *filename = nullptr, const char *title = nullptr);
      HtmlText(const HtmlText &other);
      HtmlText &operator=(const HtmlText &other);
      ~HtmlText();
      virtual void write(std::ostream &os) const override;
   };
}
#endif // !SDDS_HTMLTEXT_H__
