#include <VGUI_MenuSeparator.h>

void vgui::MenuSeparator::paintBackground()
{
  int wide, tall;
  int textWide, textTall;

  getPaintSize(wide, tall);
  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary3);
  drawFilledRect(0, 0, wide, tall);
  getTextSize(textWide, textTall);

  if (textWide > 0)
    textWide += 4;

  int x0 = (wide + textWide) / 2;
  int x1 = (wide - textWide) / 2;
  int y = textTall / 2;
  
  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);
  drawFilledRect(2, y - 1, x1, y);
  drawFilledRect(x0, y - 1, wide - 2, y);

  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  drawFilledRect(2, y, x1, y + 1);
  drawFilledRect(x0, y, wide - 2, y + 1);
}

vgui::MenuSeparator::MenuSeparator(const char* text)
  : vgui::Label{ text }
{
  setFont(vgui::Scheme::SchemeFont::sf_primary3);
}

