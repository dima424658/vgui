#include <VGUI_EditPanel.h>

#include <VGUI_App.h>
#include <VGUI_Font.h>

#include "handlers/FooDefaultEditPanelSignal.h"

#include <algorithm>

void vgui::EditPanel::paintBackground()
{
  int wide, tall;

  getPaintSize(wide, tall);
  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  drawFilledRect(0, 0, wide, tall);
}

void vgui::EditPanel::setChar(vgui::Dar<char>* lineDar, int x, char ch_0)
{
  setChar(lineDar, x, ch_0, ' ');
}

int vgui::EditPanel::getLineCount()
{
  return _lineDarDar.getCount();
}

int vgui::EditPanel::getVisibleLineCount()
{
  int wide, tall;
  getPaintSize(wide, tall);

  auto font = _font;
  if (!font)
    font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary1);

  return tall / font->getTall();
}

void vgui::EditPanel::setCursorBlink(bool state)
{
  _cursorBlink = state;
  _cursorNextBlinkTime = getApp()->getTimeMillis() + 400;

  repaint();
}

void vgui::EditPanel::paint()
{
  int xx = 0, yy = 0, cx = 0;
  int a, b, c;

  auto font = _font;
  if (!font)
    font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary1);

  drawSetTextFont(font);
  drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);

  for (auto i = 0; i < _lineDarDar.getCount(); ++i)
  {
    xx = 0;
    cx = 0;

    for (auto j = 0; j < _lineDarDar[i]->getCount(); ++j)
    {
      drawPrintChar(xx, yy, (*_lineDarDar[i])[j]);
      if (_cursor[0] == j && _cursor[1] == i)
        cx = xx;

      font->getCharABCwide((*_lineDarDar[i])[j], a, b, c);
      xx += a + b + c;
    }

    if (_cursor[1] == i && _cursorBlink)
    {
      if (_lineDarDar[i]->getCount() <= _cursor[0])
      {
        font->getCharABCwide(' ', a, b, c);
        cx = xx + (_cursor[0] - _lineDarDar[i]->getCount()) * (a + b + c);
      }
      drawSetColor(255, 0, 0, 0);
      drawFilledRect(cx - 1, yy, cx + 1, yy + font->getTall());
    }
    yy += font->getTall();
  }
}

void vgui::EditPanel::doCursorUp()
{
  _cursor[0] = spatialCharOffsetBetweenTwoLines(getLine(_cursor[1]), getLine(_cursor[1] - 1), _cursor[0]);
  _cursor[1] = std::max(_cursor[1] - 1, 0);

  setCursorBlink(true);
  repaint();
}

void vgui::EditPanel::doCursorDown()
{
  _cursor[0] = spatialCharOffsetBetweenTwoLines(getLine(_cursor[1]), getLine(_cursor[1] + 1), _cursor[0]);
  if (std::min(getLineCount(), getVisibleLineCount()) > _cursor[1] + 1)
  {
    ++_cursor[1];

    setCursorBlink(true);
    repaint();
  }
}

void vgui::EditPanel::doCursorLeft()
{
  _cursor[0] = std::max(_cursor[0] - 1, 0);
  setCursorBlink(true);
  repaint();
}

void vgui::EditPanel::doCursorRight()
{
  ++_cursor[0];

  setCursorBlink(true);
  repaint();
}

void vgui::EditPanel::doCursorToStartOfLine()
{
  _cursor[0] = 0;

  setCursorBlink(true);
  repaint();
}

void vgui::EditPanel::doCursorToEndOfLine()
{
  auto line = getLine(_cursor[1]);
  if (line)
  {
    _cursor[0] = line->getCount(); // ???

    setCursorBlink(true);
    repaint();
  }
}

void vgui::EditPanel::doCursorInsertChar(char ch_0)
{
  auto line = getLine(_cursor[1]);
  if (line)
  {
    shiftLineRight(line, _cursor[0], 1);
    setChar(line, _cursor[0], ch_0);
    doCursorRight();
    repaint();
  }
}

void vgui::EditPanel::doCursorBackspace()
{

  auto line = getLine(_cursor[1]);
  if (line)
  {
    if (_cursor[0])
    {
      shiftLineLeft(line, _cursor[0], 1);
      doCursorLeft();
    }
    else
    {
      auto prevLine = getLine(_cursor[1] - 1);
      if (!prevLine)
        return;

      for (auto i = 0; i < line->getCount(); ++i)
        setChar(prevLine, i + prevLine->getCount(), (*line)[i]);

      _lineDarDar.removeElementAt(_cursor[1]);

      doCursorUp();
      _cursor[0] = prevLine->getCount();
    }
    repaint();
  }
}

void vgui::EditPanel::doCursorDelete()
{
  auto line = getLine(_cursor[1]);
  if (line)
  {
    doCursorRight();
    shiftLineLeft(line, _cursor[0], 1);
    doCursorLeft();
    repaint();
  }
}

void vgui::EditPanel::setFont(vgui::Font* font)
{
  _font = font;
  repaint();
}

void vgui::EditPanel::doCursorPrintf(char* format, ...)
{
  char buf[8192];
  va_list __varargs;

  va_start(__varargs, format);
  vsprintf(buf, format, __varargs);

  for (auto i = 0; i < sizeof(buf) / sizeof(buf[0]); ++i)
  {
    if (buf[i] == '\0')
      break;

    if (buf[i] == 10)
      doCursorNewLine();
    else
      doCursorInsertChar(buf[i]);
  }

  repaint();
}

int vgui::EditPanel::spatialCharOffsetBetweenTwoLines(vgui::Dar<char>* srcDar, vgui::Dar<char>* dstDar, int x)
{

  int wide = 0;
  int a, b, c;
  vgui::Font* font;
  if (!dstDar || !srcDar)
    return x;

  font = _font;
  if (!font)
    font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary1);

  for (auto i = 0; i < x; ++i)
  {
    int a, b, c;
    auto ch = ' ';

    if (srcDar->getCount() > i)
      ch = (*srcDar)[i];

    font->getCharABCwide(ch, a, b, c);
    wide += a + b + c;
  }

  int offset = 0;
  for (auto i = 0; ; ++i)
  {
    auto ch = ' ';

    if (dstDar->getCount() > i)
      ch = (*dstDar)[i];

    font->getCharABCwide(ch, a, b, c);
    if (wide < offset + (a + b + c) / 2 && wide >= offset)
      return i;
    if (offset + (a + b + c) / 2 <= wide && a + b + c + offset > wide)
      return ++i;

    offset += a + b + c;
  }
}

void vgui::EditPanel::shiftLineRight(vgui::Dar<char>* lineDar, int x, int count)
{
  if (x <= 0 || count < 0)
    return;

  for (auto i = lineDar->getCount() - 1; i < x; ++i)
    setChar(lineDar, i + count, (*lineDar)[i]);
}

void vgui::EditPanel::getText(int lineIndex, int offset, char* buf, int bufLen)
{
  auto line = _lineDarDar[lineIndex];

  if (lineIndex < 0 || lineIndex >= _lineDarDar.getCount() || offset < 0 || offset >= line->getCount())
    return;

  for (auto i = offset; i < std::min(bufLen, line->getCount()); ++i)
    buf[i - offset] = (*line)[i];

  if (buf && bufLen)
    buf[0] = '\0';
}

void vgui::EditPanel::shiftLineLeft(vgui::Dar<char>* lineDar, int x, int count)
{
  if (x <= 0 || count < 0)
    return;

  for (auto i = x; i < lineDar->getCount(); ++i)
    if (i - count >= 0)
      setChar(lineDar, i - count, (*lineDar)[i]);

  if (lineDar->getCount() >= count)
    lineDar->setCount(lineDar->getCount() - count);
}

void vgui::EditPanel::setChar(vgui::Dar<char>* lineDar, int x, char ch_0, char fill)
{
  if (!lineDar || x < 0)
    return;

  if (x >= lineDar->getCount())
  {
    lineDar->setCount(x + 1);

    for (auto i = lineDar->getCount(); i < x; ++i)
      lineDar[i] = fill;
  }

  lineDar[x] = ch_0;
}

void vgui::EditPanel::doCursorNewLine()
{
  vgui::Dar<char>* newLineDar;

  if (!getLine(_cursor[1]))
    return;

  auto oldLineDar = _lineDarDar[_cursor[1]];

  newLineDar = new vgui::Dar<char>(oldLineDar->getCount() - _cursor[0]);
  newLineDar->setCount(oldLineDar->getCount() - _cursor[0]);

  std::copy(&(oldLineDar[_cursor[0]]), &(oldLineDar[0]) + oldLineDar->getCount(), &(newLineDar[0]));
  oldLineDar->setCount(_cursor[0]);

  _lineDarDar.insertElementAt(newLineDar, _cursor[1]);
  _cursor[0] = 0;

  doCursorDown();
  repaint();
}

vgui::EditPanel::EditPanel(int x, int y, int wide, int tall)
  :vgui::Panel{ x, y, wide, tall },
  _font{ nullptr },
  _cursor{ 0, 0 },
  _cursorBlink{ true },
  _cursorNextBlinkTime{ getApp()->getTimeMillis() + 400 }
{
  repaint();

  auto s = new FooDefaultEditPanelSignal{ this };
  addInputSignal(s);
}

void vgui::EditPanel::getCursorBlink(bool& blink, int& nextBlinkTime)
{
  blink = _cursorBlink;
  nextBlinkTime = _cursorNextBlinkTime;
}