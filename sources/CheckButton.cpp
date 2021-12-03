#include <VGUI_CheckButton.h>
#include <VGUI_Image.h>

namespace
{
  class FooCheckImage : public vgui::Image
  {
  private:
    vgui::CheckButton* _checkButton;
  public:
    FooCheckImage(vgui::CheckButton* checkButton) : _checkButton{ checkButton }
    {
      setSize(20, 20);
    }

    void paint(vgui::Panel* panel)
    {
      drawSetTextFont(vgui::Scheme::SchemeFont::sf_secondary1);
      drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);

      drawPrintChar(0, 0, 'g');
      drawPrintChar(0, 0, 'c');
      drawPrintChar(0, 0, 'd');
      drawPrintChar(0, 0, 'e');
      drawPrintChar(0, 0, 'f');

      if (_checkButton->isSelected())
      {
        drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
        drawPrintChar(0, 0, 'a');
      }
    }
  };
}

vgui::CheckButton::CheckButton(const char* text, int x, int y)
  : vgui::ToggleButton{ text, x, y }
{
  int wide, tall;

  setTextAlignment(vgui::Label::Alignment::a_east);

  auto image = new FooCheckImage{ this };
  setImage(image);

  getContentSize(wide, tall);
  setSize(wide, tall);
}

vgui::CheckButton::CheckButton(const char* text, int x, int y, int wide, int tall)
  : vgui::ToggleButton{ text, x, y, wide, tall }
{
  setTextAlignment(vgui::Label::Alignment::a_east);

  auto image = new FooCheckImage{ this };
  setImage(image);
}

void vgui::CheckButton::paintBackground()
{
  int wide, tall;

  getPaintSize(wide, tall);
  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary3);
  drawFilledRect(0, 0, wide, tall);
}

