#include <VGUI_EtchedBorder.h>

#include <VGUI_Panel.h>

vgui::EtchedBorder::EtchedBorder()
{
  setInset(2, 2, 2, 2);
}

void vgui::EtchedBorder::paint(vgui::Panel *panel)
{
  int wide, tall;
  panel->getSize(wide, tall);

  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  drawFilledRect(0, 0, wide, 2);
  drawFilledRect(0, tall - 2, wide, tall);
  drawFilledRect(0, 2, 2, tall - 2);
  drawFilledRect(wide - 2, 2, wide, tall - 2);
  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);

  drawFilledRect(0, 0, wide - 1, 1);
  drawFilledRect(0, tall - 2, wide - 1, tall - 1);
  drawFilledRect(0, 1, 1, tall - 2);
  drawFilledRect(wide - 2, 1, wide - 1, tall - 2);
}
