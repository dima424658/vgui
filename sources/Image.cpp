#include <VGUI_Image.h>
#include <VGUI_Panel.h>

void vgui::Image::setPos(int x, int y)
{
  _pos[0] = x;
  _pos[1] = y;
}

void vgui::Image::setSize(int wide, int tall)
{
  _size[0] = wide;
  _size[1] = tall;
}

void vgui::Image::getPos(int& x, int& y)
{
  x = _pos[0];
  y = _pos[1];
}

void vgui::Image::getSize(int& wide, int& tall)
{
  wide = _size[0];
  tall = _size[1];
}

void vgui::Image::drawSetColor(vgui::Scheme::SchemeColor sc)
{
  _panel->drawSetColor(sc);
}

void vgui::Image::drawSetColor(int r, int g, int b, int a)
{
  _panel->drawSetColor(r, g, b, a);
}

void vgui::Image::drawFilledRect(int x0, int y0, int x1, int y1)
{
  _panel->drawFilledRect(
    x0 + _pos[0],
    y0 + _pos[1],
    _pos[0] + x1,
    _pos[1] + y1);
}

void vgui::Image::drawOutlinedRect(int x0, int y0, int x1, int y1)
{
  _panel->drawOutlinedRect(
    x0 + _pos[0],
    y0 + _pos[1],
    _pos[0] + x1,
    _pos[1] + y1);
}

void vgui::Image::drawSetTextFont(vgui::Scheme::SchemeFont sf)
{
  _panel->drawSetTextFont(sf);
}

void vgui::Image::drawSetTextFont(vgui::Font* font)
{
  _panel->drawSetTextFont(font);
}

void vgui::Image::drawSetTextColor(vgui::Scheme::SchemeColor sc)
{
  _panel->drawSetTextColor(sc);
}

void vgui::Image::drawSetTextColor(int r, int g, int b, int a)
{
  _panel->drawSetTextColor(r, g, b, a);
}

void vgui::Image::drawSetTextPos(int x, int y)
{
  _panel->drawSetTextPos(
    _pos[0] + x,
    _pos[1] + y);
}

void vgui::Image::drawPrintText(const char* str, int strlen)
{
  _panel->drawPrintText(str, strlen);
}

void vgui::Image::drawPrintText(int x, int y, const char* str, int strlen)
{
  _panel->drawPrintText(
    _pos[0] + x,
    _pos[1] + y,
    str, strlen);
}

void vgui::Image::drawPrintChar(char ch)
{
  _panel->drawPrintChar(ch);
}

void vgui::Image::drawPrintChar(int x, int y, char ch_0)
{
  _panel->drawPrintChar(
    _pos[0] + x,
    _pos[1] + y,
    ch_0);
}

void vgui::Image::drawSetTextureRGBA(int id, const char* rgba, int wide, int tall)
{
  _panel->drawSetTextureRGBA(id, rgba, wide, tall);
}

void vgui::Image::drawSetTexture(int id)
{
  _panel->drawSetTexture(id);
}

void vgui::Image::drawTexturedRect(int x0, int y0, int x1, int y1)
{
  _panel->drawTexturedRect(x0, y0, x1, y1);
}

void vgui::Image::paint(Panel* panel)
{

}

void vgui::Image::doPaint(vgui::Panel* panel)
{
  _panel = panel;
  paint(panel);
  _panel = nullptr;
}

void vgui::Image::setColor(vgui::Color p_color)
{
  _color = p_color;
}

void vgui::Image::getColor(vgui::Color& color)
{
  color = _color;
}

vgui::Image::Image() : _pos{ 0, 0 }, _size{ 0, 0 }, _panel{ nullptr }, _color{ 255, 255, 255, 0 }
{

}