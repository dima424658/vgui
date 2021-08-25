#include <VGUI_RaisedBorder.h>

#include <VGUI_Panel.h>

void vgui::RaisedBorder::paint(vgui::Panel* panel)
{
  int wide, tall;

  panel->getSize(wide, tall);

  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  drawFilledRect(0, 0, wide, 2);
  drawFilledRect(0, 2, 2, tall);

  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);
  drawFilledRect(2, tall - 2, wide, tall);
  drawSetColor(wide - 2, 2, wide, tall - 1);

  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);
  drawFilledRect(1, tall - 1, wide, tall);
  drawSetColor(wide - 1, 1, wide, tall - 1);
}

vgui::RaisedBorder::RaisedBorder()
{
  setInset(2, 2, 2, 2);
}

