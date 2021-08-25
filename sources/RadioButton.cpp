#include <VGUI_RadioButton.h>

#include "handlers/FooRadioImage.h"

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
  int wide, tall;

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

