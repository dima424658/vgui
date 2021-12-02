#include <VGUI_Slider.h>
#include <VGUI_IntChangeSignal.h>
#include <VGUI_InputSignal.h>
#include <VGUI_App.h>

namespace
{
  class FooDefaultSliderSignal : public vgui::InputSignal
  {
  protected:
    vgui::Slider* _slider;

  public:
    FooDefaultSliderSignal(vgui::Slider* slider)
      : _slider{ slider }
    {}

    void cursorMoved(int x, int y, vgui::Panel* panel)
    {
      _slider->privateCursorMoved(x, y, panel);
    }
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
    {
      _slider->privateMousePressed(code, panel);
    }
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel)
    {
      _slider->privateMouseReleased(code, panel);
    }
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
};

bool vgui::Slider::isVertical()
{
  return _vertical;
}

int vgui::Slider::getValue()
{
  return _value;
}

void vgui::Slider::recomputeNobPosFromValue()
{
  int wide, tall, v5;

  getPaintSize(wide, tall);

  if (_rangeWindowEnabled)
    v5 = std::max(0, _rangeWindow);
  else
    v5 = _range[1] - _range[0];

  if (v5 > 0)
  {
    auto v6 = _vertical ? tall : wide;
    auto v7 = (_value - _range[0]) / (_range[1] - _range[0]);
    auto v9 = v6 * v6 / v5;

    _nobPos[0] = v7 * (v6 - v9);
    _nobPos[1] = _nobPos[0] + v9;

    if (v6 < _nobPos[1])
    {
      _nobPos[0] = v6 - v9;
      _nobPos[1] = v6;
    }
  }

  repaint();
}

void vgui::Slider::recomputeValueFromNobPos()
{
  int wide, tall, v5, v6;

  getPaintSize(wide, tall);

  if (_rangeWindowEnabled)
    v5 = std::max(0, _rangeWindow);
  else
    v5 = _range[1] - _range[0];

  if (v5 > 0)
  {
    v6 = _vertical ? tall : wide;
    v6 = (_range[1] - _range[0]) * (_nobPos[0] / (v6 - v6 * v6 / v5));
  }
  else
  {
    v6 = _value - _range[0];
  }

  _value = _range[1] = std::min(_range[1], v6 + _range[0] + 0.5);
}

bool vgui::Slider::hasFullRange()
{
  int wide, tall, v5, v6;

  getPaintSize(wide, tall);

  if (_rangeWindowEnabled)
    v5 = std::max(0, _rangeWindow);
  else
    v5 = _range[1] - _range[0];

  if (v5 > 0)
  {
    v6 = _vertical ? tall : wide;

    return (_buttonOffset + v6) >= v5;
  }
  else
    return false;
}

void vgui::Slider::fireIntChangeSignal()
{
  for (auto i = 0; i < _intChangeSignalDar.getCount(); ++i)
    _intChangeSignalDar[i]->intChanged(getValue(), this);
}

void vgui::Slider::paintBackground()
{
  int wide, tall;

  getSize(wide, tall);

  if (_vertical)
  {
    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary1);
    drawFilledRect(0, 0, wide, 1);
    drawFilledRect(0, tall - 1, wide, tall);
    drawFilledRect(0, 1, 1, tall - 1);
    drawFilledRect(wide - 1, 1, wide, tall - 1);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary2);
    drawFilledRect(1, 1, wide - 1, 2);
    drawFilledRect(1, 2, 3, tall - 1);
    drawFilledRect(2, _nobPos[1], wide - 1, _nobPos[1] + 1);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary3);
    drawFilledRect(2, 2, wide - 1, tall - 1);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_primary1);
    drawFilledRect(0, _nobPos[0], wide, _nobPos[0] + 1);
    drawFilledRect(0, _nobPos[1], wide, _nobPos[1] + 1);
    drawFilledRect(0, _nobPos[0] + 1, 1, _nobPos[1]);
    drawFilledRect(wide - 1, _nobPos[0] + 1, wide, _nobPos[1]);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_primary3);
    drawFilledRect(1, _nobPos[0] + 1, wide - 1, _nobPos[0] + 2);
    drawFilledRect(1, _nobPos[0] + 2, 2, _nobPos[1]);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_primary2);
    drawFilledRect(2, _nobPos[0] + 2, wide - 1, _nobPos[1]);
  }
  else
  {
    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary3);
    drawFilledRect(0, 0, wide, tall);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
    drawFilledRect(0, 0, wide, tall);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_primary2);
    drawFilledRect(_nobPos[0], 0, _nobPos[1], tall);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
    drawFilledRect(_nobPos[0], 0, _nobPos[1], tall);
  }
}

void vgui::Slider::setRange(int min, int max)
{
  _range[0] = min;
  _range[1] = std::max(min, max);
}

void vgui::Slider::getRange(int& min, int& max)
{
  min = _range[0];
  max = _range[1];
}

void vgui::Slider::privateCursorMoved(int x, int y, vgui::Panel* panel)
{
  int wide, tall;
  int v6, v7, v8;

  if (!_dragging)
    return;

  getApp()->getCursorPos(x, y);
  screenToLocal(x, y);
  getPaintSize(wide, tall);

  if (_vertical)
  {
    v8 = tall;
    v6 = y - _dragStartPos[1] + _nobDragStartPos[0];
    v7 = _nobDragStartPos[1] + y - _dragStartPos[1];
  }
  else
  {
    v8 = wide;
    v6 = x - _dragStartPos[0] + _nobDragStartPos[0];
    v7 = _nobDragStartPos[1] + x - _dragStartPos[0];
  }

  _nobPos[0] = v6;
  _nobPos[1] = v7;

  if (v7 > v8)
  {
    v7 = v8;

    _nobPos[0] = v8 + v6 - v7;
    _nobPos[1] = v8;
  }

  if (_nobPos[0] < 0)
  {
    _nobPos[1] = v7 - _nobPos[0];
    _nobPos[0] = 0;
  }

  recomputeNobPosFromValue();
  repaint();
  fireIntChangeSignal();
}

void vgui::Slider::privateMousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  int x, y;

  getApp()->getCursorPos(x, y);
  screenToLocal(x, y);

  auto pos = _vertical ? y : x;
  if (_nobPos[0] > pos || pos >= _nobPos[1])
    return;

  _dragging = true;

  _nobDragStartPos[0] = _nobPos[0];
  _nobDragStartPos[1] = _nobPos[1];

  _dragStartPos[0] = x;
  _dragStartPos[1] = y;

  getApp()->setMouseCapture(this);
}

void vgui::Slider::privateMouseReleased(vgui::MouseCode code, vgui::Panel* panel)
{
  _dragging = false;
  getApp()->setMouseCapture(nullptr);
}

void vgui::Slider::getNobPos(int& min, int& max)
{
  min = _nobPos[0];
  max = _nobPos[1];
}

void vgui::Slider::setRangeWindow(int rangeWindow)
{
  _rangeWindow = rangeWindow;
}

void vgui::Slider::setRangeWindowEnabled(bool state)
{
  _rangeWindowEnabled = state;
}

void vgui::Slider::setButtonOffset(int buttonOffset)
{
  _buttonOffset = buttonOffset;
}

void vgui::Slider::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);

  recomputeNobPosFromValue();
}

void vgui::Slider::setValue(int value)
{
  auto oldValue = _value;
  _value = std::min(_range[1], std::max(value, _range[0]));

  recomputeNobPosFromValue();
  if (_value != oldValue)
    fireIntChangeSignal();
}

void vgui::Slider::addIntChangeSignal(vgui::IntChangeSignal* s)
{
  for (auto i = 0; i < _intChangeSignalDar.getCount(); ++i)
    if (_intChangeSignalDar[i] == s)
      return;

  _intChangeSignalDar.addElement(s);
}

vgui::Slider::Slider(int x, int y, int wide, int tall, bool vertical)
  : vgui::Panel{ x, y, wide, tall }, _vertical{ vertical }, _dragging{ false }, _range{ 0, 299 }, _value{ 0 }, _rangeWindow{ 0 }, _rangeWindowEnabled{ false }, _buttonOffset{ 0 }
{
  recomputeNobPosFromValue();
  vgui::Panel::addInputSignal(new FooDefaultSliderSignal{this});
}