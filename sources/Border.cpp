#include <VGUI_Border.h>

vgui::Border::Border()
  : _panel{ nullptr }
{
  _inset[0] = 0;
  _inset[1] = 0;
  _inset[2] = 0;
  _inset[3] = 0;
}

vgui::Border::Border(int left, int top, int right, int bottom)
  : _panel{ nullptr }
{
  _inset[0] = left;
  _inset[1] = top;
  _inset[2] = right;
  _inset[3] = bottom;
}

void vgui::Border::setInset(int left, int top, int right, int bottom)
{
  _inset[0] = left;
  _inset[1] = top;
  _inset[2] = right;
  _inset[3] = bottom;
}

void vgui::Border::getInset(int& left, int& top, int& right, int& bottom)
{
  left = _inset[0];
  top = _inset[1];
  right = _inset[2];
  bottom = _inset[3];
}

void vgui::Border::drawFilledRect(int x0, int y0, int x1, int y1)
{
  drawFilledRect(
    x0 - _inset[0],
    y0 - _inset[1],
    x1 - _inset[0],
    y1 - _inset[1]);
}

void vgui::Border::drawOutlinedRect(int x0, int y0, int x1, int y1)
{
  vgui::Image::drawOutlinedRect(
    x0 - _inset[0],
    y0 - _inset[1],
    x1 - _inset[0],
    y1 - _inset[1]);
}

void vgui::Border::drawSetTextPos(int x, int y)
{
  vgui::Image::drawSetTextPos(x - _inset[0], y - _inset[1]);
}

void vgui::Border::drawPrintText(int x, int y, const char* str, int strlen)
{
  vgui::Image::drawPrintText(x - _inset[0], y - _inset[1], str, strlen);
}

void vgui::Border::drawPrintChar(int x, int y, char ch_0)
{
  vgui::Image::drawPrintChar(x - _inset[0], y - _inset[1], ch_0);
}