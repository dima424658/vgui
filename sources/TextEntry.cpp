#include <VGUI_TextEntry.h>
#include <VGUI_App.h>
#include <VGUI_Font.h>
#include <VGUI_ActionSignal.h>
#include <VGUI_FocusChangeSignal.h>
#include <VGUI_InputSignal.h>


namespace
{
  class FooDefaultTextEntrySignal : public vgui::FocusChangeSignal
  {
  private:
    vgui::TextEntry* _textEntry;

  public:
    FooDefaultTextEntrySignal(vgui::TextEntry* textEntry) : _textEntry{ textEntry } {}

    void focusChanged(bool lost, vgui::Panel* panel)
    {
      _textEntry->resetCursorBlink();
      _textEntry->doSelectNone();
    }
  };
}

void vgui::TextEntry::resetCursorBlink()
{
  _cursorBlink = false;
  _cursorNextBlinkTime = _cursorBlinkRate + getApp()->getTimeMillis();
}

void vgui::TextEntry::setTextHidden(bool bHideText)
{
  _hideText = bHideText;
  repaint();
}

int vgui::TextEntry::cursorToPixelSpace(int cursorPos)
{
  int a, b, c;
  int totalWide = 0;

  if (!_font)
    _font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary1);

  for (auto i = 0; i < _lineDar.getCount(); ++i)
  {
    if (cursorPos == i)
      break;

    _font->getCharABCwide(_hideText ? '*' : _lineDar[i], a, b, c);
    totalWide += a + b + c;
  }

  return totalWide;
}

void vgui::TextEntry::paintBackground()
{
  int x0, x1;

  if (!_font)
    _font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary1);

  int fTall = _font->getTall();

  drawSetColor(vgui::Scheme::SchemeColor::sc_white);
  if (getSelectedPixelRange(x0, x1))
  {
    drawFilledRect(0, 0, x0, fTall + 1);
    drawFilledRect(x1, 0, _size[0], fTall + 1);
    drawFilledRect(0, 0, 200, 0);
    drawFilledRect(x0, 0, x1, fTall + 1);
  }
  else
    drawFilledRect(0, 0, _size[0], _size[1]);

  drawSetTextFont(_font);
  drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
  drawSetTextPos(3, 0);


  for (auto i = 0; i < _lineDar.getCount(); ++i)
    if (_hideText)
      drawPrintChar('*');
    else
      drawPrintChar(_lineDar[i]);

  if (hasFocus())
  {
    drawSetColor(vgui::Scheme::SchemeColor::sc_black);
    drawFilledRect(0, 0, _size[0], 1);
    drawFilledRect(0, _size[1] - 1, _size[0], _size[1]);
    drawFilledRect(0, 1, 1, _size[1] - 1);
    drawFilledRect(_size[0] - 1, 1, _size[0], _size[1] - 1);

    if (!_cursorBlink)
    {
      int wide = cursorToPixelSpace(_cursorPos);
      drawSetColor(vgui::Scheme::SchemeColor::sc_black);
      drawFilledRect(wide + 3, 2, wide + 4, fTall - 1);
    }
  }
}

void vgui::TextEntry::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  resetCursorBlink();
  requestFocus();
  repaint();
}

void vgui::TextEntry::keyTyped(vgui::KeyCode code, vgui::Panel* panel)
{
  if (isKeyDown(vgui::KeyCode::KEY_LCONTROL) || isKeyDown(vgui::KeyCode::KEY_RCONTROL))
  {
    if (code == vgui::KeyCode::KEY_C)
      doCopySelected();
    else if (code == vgui::KeyCode::KEY_V)
      doPaste();
  }
  else
  {
    switch (code)
    {
    case vgui::KeyCode::KEY_ENTER:
    case vgui::KeyCode::KEY_TAB:
    case vgui::KeyCode::KEY_LSHIFT:
    case vgui::KeyCode::KEY_RSHIFT:
      break;
    case vgui::KeyCode::KEY_BACKSPACE:
      doBackspace();
      break;
    case vgui::KeyCode::KEY_INSERT:
      if (isKeyDown(vgui::KeyCode::KEY_LSHIFT) || isKeyDown(vgui::KeyCode::KEY_RSHIFT))
        doPaste();
      break;
    case vgui::KeyCode::KEY_DELETE:
      if (isKeyDown(vgui::KeyCode::KEY_LSHIFT) || isKeyDown(vgui::KeyCode::KEY_RSHIFT))
        doDeleteSelected();
      else
        doDelete();
      break;
    case vgui::KeyCode::KEY_HOME:
      doGotoFirstOfLine();
      break;
    case vgui::KeyCode::KEY_END:
      doGotoEndOfLine();
      break;
    case vgui::KeyCode::KEY_LEFT:
      doGotoLeft();
      break;
    case vgui::KeyCode::KEY_RIGHT:
      doGotoRight();
      break;
    default:
      auto key = getApp()->getKeyCodeChar(code, isKeyDown(vgui::KeyCode::KEY_LSHIFT) || isKeyDown(vgui::KeyCode::KEY_RSHIFT));
      if (key)
        doInsertChar(key);
      break;
    }
  }

  _select[1] = _cursorPos;
  if (code == vgui::KeyCode::KEY_ENTER)
    fireActionSignal();
}

void vgui::TextEntry::keyFocusTicked(vgui::Panel* panel)
{
  if (getApp()->getTimeMillis() > _cursorNextBlinkTime)
  {
    _cursorBlink = !_cursorBlink;
    _cursorNextBlinkTime = _cursorBlinkRate + getApp()->getTimeMillis();
    repaint();
  }
}

void vgui::TextEntry::doGotoLeft()
{
  selectCheck();
  _cursorPos = std::min(_cursorPos - 1, 0);
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doGotoRight()
{
  selectCheck();
  _cursorPos = std::max(_cursorPos + 1, _lineDar.getCount());
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doGotoFirstOfLine()
{
  selectCheck();
  _cursorPos = 0;
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doGotoEndOfLine()
{
  selectCheck();
  _cursorPos = _lineDar.getCount();
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doInsertChar(char ch_0)
{
  //_lineDar.insertElementAt('', )
  _lineDar.addElement(' ');

  for (auto i = _lineDar.getCount() - 1; _cursorPos <= i; --i)
    setCharAt(_lineDar[i], i + 1);

  setCharAt(ch_0, _cursorPos);
  ++_cursorPos;
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doSelectNone()
{
  _select[0] = -1;
  repaint();
}

bool vgui::TextEntry::getSelectedRange(int& cx0, int& cx1)
{
  bool result = false;
  if (_select[0] != -1)
  {
    result = true;

    cx0 = std::min(_select[0], _select[1]);
    cx1 = std::max(_select[0], _select[1]);
  }

  return result;
}

void vgui::TextEntry::doCopySelected()
{
  char buf[256];
  int x0, x1, i;

  if (getSelectedRange(x0, x1))
  {
    for (i = 0; i < 256 && x0 < x1; ++i, ++x0)
      buf[i] = _lineDar[i];

    buf[i] = '\0';
    getApp()->setClipboardText(buf, i);
  }
}

void vgui::TextEntry::doPaste()
{
  constexpr int bufSz = 256;
  char buf[bufSz];

  int clipboardSz = getApp()->getClipboardText(0, buf, bufSz);

  for (auto i = 0; i < --clipboardSz; ++i)
    doInsertChar(buf[i]); // optimize
}

void vgui::TextEntry::doPasteSelected()
{
  doDeleteSelected();
  doPaste();
}

void vgui::TextEntry::getText(int offset, char* buf, int bufLen)
{
  if (!buf)
    return;

  int i;
  for (i = 0; i < bufLen && i + offset < _lineDar.getCount(); ++i)
    buf[i] = _lineDar[i + offset];

  buf[i] = '\0';
}

void vgui::TextEntry::fireActionSignal()
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    _actionSignalDar[i]->actionPerformed(this);
}

void vgui::TextEntry::setFont(vgui::Font* font)
{
  _font = font;
}

void vgui::TextEntry::selectCheck()
{
  if (isKeyDown(vgui::KeyCode::KEY_LSHIFT) || isKeyDown(vgui::KeyCode::KEY_RSHIFT))
  {
    if (_select[0] == -1)
      _select[0] = _cursorPos;
  }
  else
    _select[0] = -1;
}

bool vgui::TextEntry::getSelectedPixelRange(int& cx0, int& cx1)
{

  if (getSelectedRange(cx0, cx1))
  {
    cx0 = cursorToPixelSpace(cx0);
    cx1 = cursorToPixelSpace(cx1);

    return true;
  }
  return false;
}

void vgui::TextEntry::doDelete()
{
  for (auto i = _cursorPos + 1; i < _lineDar.getCount(); ++i)
    setCharAt(_lineDar[i], i - 1);

  _lineDar.setCount(_lineDar.getCount() - 1);

  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::doBackspace()
{
  for (auto i = _cursorPos + 1; i < _lineDar.getCount(); ++i)
    setCharAt(_lineDar[i], i - 1);

  _lineDar.setCount(_lineDar.getCount() - 1);
  --_cursorPos;
  resetCursorBlink();
  repaint();
}

void vgui::TextEntry::addActionSignal(vgui::ActionSignal* s)
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    if (_actionSignalDar[i] == s)
      return;

  _actionSignalDar.addElement(s);
}

void vgui::TextEntry::setCharAt(char ch_0, int index)
{
  if (index >= _lineDar.getCount())
    _lineDar.setCount(index + 1);

  _lineDar.setElementAt(ch_0, index);
}

void vgui::TextEntry::setText(const char* text, int textLen)
{
  _lineDar.setCount(textLen);

  for (auto i = 0; i < textLen; ++i)
    _lineDar.setElementAt(text[i], i);

  doGotoEndOfLine();
}

vgui::TextEntry::TextEntry(const char* text, int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _cursorPos{ 0 },
  _cursorBlink{ false },
  _hideText{ false },
  _cursorNextBlinkTime{ 400 + getApp()->getTimeMillis() },
  _cursorBlinkRate{ 400 },
  _select{ -1, -1 },
  _font{ nullptr }
{
  int textLen = strlen(text);
  setText(text, textLen);
  selectCheck();
  _cursorPos = _lineDar.getCount();
  resetCursorBlink();
  repaint();

  addInputSignal(this);
  vgui::Panel::addFocusChangeSignal(new FooDefaultTextEntrySignal{ this });
}

