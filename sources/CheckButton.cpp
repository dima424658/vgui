#include <VGUI_CheckButton.h>

#include "handlers/FooCheckImage.h"

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

