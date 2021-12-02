#include <VGUI_LineBorder.h>
#include <VGUI_Panel.h>
#include <VGUI_Color.h>

void vgui::LineBorder::init(int thickness, vgui::Color color)
{
  setInset(thickness, thickness, thickness, thickness);
  _color = color;
}

void vgui::LineBorder::paint(vgui::Panel* panel)
{
  int wide, tall;
  int r, g, b, a;

  panel->getSize(wide, tall);
  _color.getColor(r, g, b, a);

  drawSetColor(r, g, b, a);
  drawFilledRect(0, 0, wide, _inset[1]);
  drawFilledRect(0, tall - _inset[3], wide, tall);
  drawFilledRect(0, _inset[1], _inset[0], tall - _inset[3]);
  drawFilledRect(wide - _inset[2], _inset[1], wide, tall - _inset[3]);
}

vgui::LineBorder::LineBorder()
{
  init(1, {});
}

vgui::LineBorder::LineBorder(int thickness)
{
  init(thickness, {});
}

vgui::LineBorder::LineBorder(vgui::Color color)
{
  init(1, color);
}

vgui::LineBorder::LineBorder(int thickness, vgui::Color color)
{
  init(thickness, color);
}

