#include <VGUI_TextPanel.h>

#include <VGUI_TextImage.h>

void vgui::TextPanel::setText(const char* text)
{
  _textImage->setText(text);
}

void vgui::TextPanel::setFont(vgui::Scheme::SchemeFont schemeFont)
{
  _textImage->setFont(schemeFont);
}

void vgui::TextPanel::setFont(vgui::Font* font)
{
  _textImage->setFont(font);
}

void vgui::TextPanel::paint()
{
  _textImage->doPaint(this);
}

void vgui::TextPanel::setFgColor(vgui::Scheme::SchemeColor sc)
{
  vgui::Panel::setFgColor(sc);
  _textImage->setColor(vgui::Color{sc});
}

void vgui::TextPanel::setFgColor(int r, int g, int b, int a)
{
  vgui::Color color = vgui::Color{ r, g, b, a };

  vgui::Panel::setFgColor(r, g, b, a);
  _textImage->setColor(color);
}

void vgui::TextPanel::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);

  getPaintSize(wide,tall);
  _textImage->setSize(wide, tall);
}

vgui::TextImage* vgui::TextPanel::getTextImage()
{
  return _textImage;
}

vgui::TextPanel::TextPanel(const char* text, int x, int y, int wide, int tall)
  : vgui::Panel{ x,y,wide,tall }
{
  _textImage = new vgui::TextImage{text};
  _textImage->setSize(wide, tall);
}