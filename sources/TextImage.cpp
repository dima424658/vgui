#include <cstring>

#include <VGUI_TextImage.h>
#include <VGUI_Font.h>

void vgui::TextImage::init(int textBufferLen, const char* text)
{
  int wide, tall;

  _text = nullptr;
  _textBufferLen = 0;
  _schemeFont = vgui::Scheme::SchemeFont::sf_primary1;
  _font = nullptr;

  setText(text);
  getTextSize(wide, tall);
  setSize(wide, tall);
}

void vgui::TextImage::setFont(vgui::Scheme::SchemeFont schemeFont)
{
  _schemeFont = schemeFont;
}

void vgui::TextImage::setFont(vgui::Font* font)
{
  _font = font;
}

vgui::Font* vgui::TextImage::getFont()
{
  return _font;
}

void vgui::TextImage::getTextSize(int& wide, int& tall)
{
  wide = 0;
  tall = 0;

  if (_text && getFont())
    getFont()->getTextSize(_text, wide, tall);
}

void vgui::TextImage::setSize(int wide, int tall)
{
  vgui::Image::setSize(wide, tall);
}

void vgui::TextImage::getTextSizeWrapped(int& wide, int& tall)
{}

void vgui::TextImage::setText(const char* text)
{
  setText(std::strlen(text) + 1, text);
}

void vgui::TextImage::setText(int textBufferLen, const char* text)
{
  int dstLen;
  char* dst;
  int wide, tall;

  dstLen = _textBufferLen;
  dst = _text;
  if (dstLen < textBufferLen)
  {
    delete[] _text;
    _textBufferLen = textBufferLen;
    dst = new char[textBufferLen];
    _text = dst;

    if (!dst)
      _textBufferLen = 0;

    dstLen = _textBufferLen;
  }

  if (dst)
    vgui::vgui_strcpy(dst, dstLen, text);

  getTextSize(wide, tall);
  setSize(wide, tall);
}

vgui::TextImage::TextImage(int textBufferLen, const char* text)
{
  init(textBufferLen, text);
}

vgui::TextImage::TextImage(const char* text)
{
  init(0, text);
}

void vgui::TextImage::paint(vgui::Panel* panel)
{
  vgui::Color color;

  int wide, tall;
  int x = 0, y = 0;
  int r, g, b, a, c;


  if (!_text)
    return;

  auto font = getFont();
  getSize(wide, tall);
  getColor(color);
  color.getColor(r, g, b, a);

  drawSetTextColor(r, g, b, a);
  drawSetTextFont(font);

  int yAdd = font->getTall();
  
  for (auto i = 0; _text[i] != '\0'; ++i)
  {
    if (_text[i] == '\r')
      continue;

    if (_text[i] == '\n')
    {
      y += yAdd;
      continue;
    }

    font->getCharABCwide(_text[i], a, b, c);
    if (_text[i] != ' ')
      drawPrintChar(_text[i], x, y);

    if ((x += a + b + c) > wide)
    {
      y += yAdd;
      x = 0;
    }
  }
}