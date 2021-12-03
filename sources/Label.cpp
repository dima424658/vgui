#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdarg>

#include <VGUI_Label.h>
#include <VGUI_TextImage.h>

void vgui::Label::getTextSize(int& wide, int& tall)
{
  _textImage->getSize(wide, tall);
}

void vgui::Label::getContentSize(int& wide, int& tall)
{
  int tx0, ty0;
  int tx1, ty1;
  int ix0, iy0;
  int ix1, iy1;
  int minX, minY;
  int maxX, maxY;

  computeAlignment(tx0, ty0, tx1, ty1, ix0, iy0, ix1, iy1, minX, minY, maxX, maxY);

  wide = maxX - minX;
  tall = maxY - minY;
}

void vgui::Label::setFont(vgui::Scheme::SchemeFont schemeFont)
{
  _textImage->setFont(schemeFont);
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::setImage(vgui::Image* image)
{
  _image = image;
  recomputeMinimumSize();
  if (image)
    repaint();
}

void vgui::Label::setText(int textBufferLen, const char* text)
{
  _textImage->setText(textBufferLen, text);
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::computeAlignment(int& tx0, int& ty0, int& tx1, int& ty1, int& ix0, int& iy0, int& ix1, int& iy1, int& minX, int& minY, int& maxX, int& maxY)
{
  int offX, offY;
  int wide, tall;
  int tWide, tTall;
  int iWide = 0, iTall = 0;

  getPaintSize(wide, tall);
  getTextSize(tWide, tTall);

  if (_image)
    _image->getSize(iWide, iTall);

  ix0 = 0, iy0 = 0;
  ix1 = iWide, iy1 = iTall;
  tx0 = 0, ty0 = 0;
  tx1 = tWide, ty1 = tTall;

  switch (_textAlignment)
  {
  case Alignment::a_northeast:
  case Alignment::a_east:
  case Alignment::a_southeast:
    tx0 = ix1;
    break;
  case Alignment::a_north:
  case Alignment::a_center:
  case Alignment::a_south:
    tx0 = (ix1 - ix0) / 2 - (tx1 - tx0) / 2;
    break;
  case Alignment::a_northwest:
  case Alignment::a_west:
  case Alignment::a_southwest:
    tx0 = ix0 - tWide;
    break;
  }

  switch (_textAlignment)
  {
  case Alignment::a_southwest:
  case Alignment::a_south:
  case Alignment::a_southeast:
    ty0 = iy1;
    break;
  case Alignment::a_west:
  case Alignment::a_center:
  case Alignment::a_east:
    ty0 = (iy1 - iy0) / 2 - (ty1 - ty0) / 2;
    break;
  case Alignment::a_northwest:
  case Alignment::a_north:
  case Alignment::a_northeast:
    ty0 = iy0 - tTall;
    break;
  }

  tx1 = tx0 + tWide;
  ty1 = ty0 + tTall;
  minX = std::min(tx0, ix0);
  minY = std::min(ty0, iy0);

  maxX = std::max(tx1, ix1);
  maxY = std::max(ty1, iy1);

  tx0 -= minX, ty0 -= minY;
  tx1 -= minX, ty1 -= minY;
  ix0 -= minX, iy0 -= minY;
  ix1 -= minX, iy1 -= minY;

  maxX -= minX;
  maxY -= minY;
  minX = 0;
  minY = 0;

  switch (_textAlignment)
  {
  case Alignment::a_northeast:
  case Alignment::a_east:
  case Alignment::a_southeast:
    offX = wide + minX - maxX;
    break;
  case Alignment::a_north:
  case Alignment::a_center:
  case Alignment::a_south:
    offX = wide / 2 - (maxX - minX) / 2;
    break;
  case Alignment::a_northwest:
  case Alignment::a_west:
  case Alignment::a_southwest:
    offX = 0;
    break;
  }

  switch (_textAlignment)
  {
  case Alignment::a_southwest:
  case Alignment::a_south:
  case Alignment::a_southeast:
    offY = tall - maxY;
    break;
  case Alignment::a_west:
  case Alignment::a_center:
  case Alignment::a_east:
    offY = tall / 2 - maxY / 2;
    break;
  case Alignment::a_northwest:
  case Alignment::a_north:
  case Alignment::a_northeast:
    offY = 0;
    break;
  }

  tx0 += offX, ty0 += offY;
  tx1 += offX, ty1 += offY;
  ix0 += offX, iy0 += offY;
  ix1 += offX, iy1 += offY;
  minX += offX, minY += offY;
  maxX += offX, maxY += offY;
  minX -= 4, minY -= 4;
  maxX += 4, maxY += 4;
}

void vgui::Label::paint()
{
  int tx0, ty0;
  int tx1, ty1;
  int ix0, iy0;
  int ix1, iy1;
  int minX, minY;
  int maxX, maxY;

  computeAlignment(tx0, ty0, tx1, ty1, ix0, iy0, ix1, iy1, minX, minY, maxX, maxY);

  if (_image)
  {
    _image->setPos(ix0, iy0);
    _image->doPaint(this);
  }

  if (_textImage)
  {
    _textImage->setPos(tx0, ty0);
    _textImage->doPaint(this);
  }

  if (hasFocus())
  {
    drawSetColor(vgui::Scheme::SchemeColor::sc_primary2);
    drawOutlinedRect(tx0, ty0, tx1, ty1);
  }
}

void vgui::Label::setTextAlignment(Alignment alignment)
{
  _textAlignment = alignment;
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::setContentAlignment(Alignment alignment)
{
  _contentAlignment = alignment;
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::recomputeMinimumSize()
{
  int wide, tall;
  getContentSize(wide, tall);
  setPreferredSize(wide, tall);
  if (_contentFitted)
    setSize(wide, tall);
}

void vgui::Label::setFont(vgui::Font* font)
{
  _textImage->setFont(font);
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::setContentFitted(bool state)
{
  _contentFitted = state;
  recomputeMinimumSize();
  repaint();
}

void vgui::Label::setFgColor(vgui::Scheme::SchemeColor sc)
{
  vgui::Panel::setFgColor(sc);
  _textImage->setColor(sc);
  repaint();
}

void vgui::Label::setFgColor(int r, int g, int b, int a)
{
  vgui::Panel::setFgColor(r, g, b, a);
  _textImage->setColor({ r, g, b, a });
  repaint();
}

void vgui::Label::setText(const char* format, ...)
{
  constexpr int bufSz = 4096;
  char buf[bufSz];
  std::va_list __varargs;

  va_start(__varargs, format);
  std::vsnprintf(buf, bufSz, format, __varargs);
  buf[bufSz - 1] = '\0';

  setText(std::strlen(buf) + 1, buf);
}

void vgui::Label::init(int textBufferLen, const char* text, bool textFitted)
{
  _contentFitted = textFitted;
  _textAlignment = Alignment::a_center;
  _contentAlignment = Alignment::a_center;

  _textImage = new vgui::TextImage{ textBufferLen, text };
  _textImage->setColor(vgui::Scheme::SchemeColor::sc_black);

  _image = nullptr;

  setText(textBufferLen, text);
}

vgui::Label::Label(int textBufferLen, const char* text, int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  init(textBufferLen, text, false);
}

vgui::Label::Label(const char* text, int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  init(std::strlen(text) + 1, text, false);
}

vgui::Label::Label(const char* text, int x, int y)
  : vgui::Panel{ x, y, 10, 10 }
{
  init(std::strlen(text) + 1, text, false);
}

vgui::Label::Label(const char* text)
  : vgui::Panel{ 0, 0, 10, 10 }
{
  init(std::strlen(text) + 1, text, false);
}