#include <VGUI_LineBorder.h>

vgui::LineBorder::LineBorder()
{
  init(1, { 0, 0, 0, 0 });
}

vgui::LineBorder::LineBorder(int thickness)
{
  init(thickness, { 0, 0, 0, 0 });
}

vgui::LineBorder::LineBorder(vgui::Color color)
{
  init(1, color);
}

vgui::LineBorder::LineBorder(int thickness, vgui::Color color)
{
  init(thickness, color);
}

void vgui::LineBorder::init(int thickness, vgui::Color color)
{
  setInset(thickness, thickness, thickness, thickness);
  _color = color;
}

void vgui::LineBorder::paint(vgui::Panel* panel)
{
  int wide, tall;
  int r, g, b, a;

  getSize(wide, tall);
  _color.getColor(r, g, b, a);

  drawSetColor(r, g, b, a);
  drawFilledRect(0, 0, wide, _inset[1]);
  drawFilledRect(0, tall - _inset[3], wide, tall);
  drawFilledRect(0, _inset[1], _inset[0], tall - _inset[3]);
  drawFilledRect(wide - _inset[2], _inset[1], wide, tall - _inset[3]);
}