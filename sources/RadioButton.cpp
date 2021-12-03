#include <VGUI_RadioButton.h>
#include <VGUI_Image.h>

namespace
{
  class FooRadioImage : public vgui::Image
  {
  private:
    vgui::RadioButton* _radioButton;
  public:
    FooRadioImage(vgui::RadioButton* radioButton) : _radioButton{ _radioButton }
    {
      setSize(20, 20);
    }

    void paint(vgui::Panel* panel)
    {
      drawSetTextFont(vgui::Scheme::SchemeFont::sf_secondary1);

      drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);
      drawPrintChar(0, 0, 'n');

      drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary2);
      drawPrintChar(0, 0, 'j');

      drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);
      drawPrintChar(0, 0, 'k');

      drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
      drawPrintChar(0, 0, 'l');

      drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary3);
      drawPrintChar(0, 0, 'm');

      if (_radioButton->isSelected())
      {
        drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
        drawPrintChar(0, 0, 'h');
      }
    }
  };
}
void vgui::RadioButton::paintBackground()
{
  int wide, tall;

  getPaintSize(wide, tall);
  drawSetColor(vgui::Scheme::sc_secondary3);
  drawFilledRect(0, 0, wide, tall);
}

vgui::RadioButton::RadioButton(const char* text, int x, int y, int wide, int tall)
  : vgui::ToggleButton{ text, x, y, wide, tall }
{
  setTextAlignment(vgui::Label::Alignment::a_east);
  setImage(new FooRadioImage{ this });

  getContentSize(wide, tall);
  setSize(wide, tall);
}

vgui::RadioButton::RadioButton(const char* text, int x, int y)
  : vgui::ToggleButton{ text, x, y }
{
  int wide, tall;

  setTextAlignment(vgui::Label::Alignment::a_east);
  setImage(new FooRadioImage{ this });

  getContentSize(wide, tall);
  setSize(wide, tall);
}

