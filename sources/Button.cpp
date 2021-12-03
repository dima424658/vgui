#include <VGUI_Button.h>

#include <VGUI_ButtonGroup.h>
#include <VGUI_ButtonController.h>
#include <VGUI_ActionSignal.h>
#include <VGUI_InputSignal.h>

#include <bit>

namespace
{
  class FooDefaultButtonController : public vgui::ButtonController, public vgui::InputSignal
  {
  private:
    vgui::Button* _button;
  public:
    FooDefaultButtonController(vgui::Button* button) : _button{ button } {}

    void addSignals(vgui::Button* button) { button->addInputSignal(this); }
    void removeSignals(vgui::Button* button) { button->removeInputSignal(this); }

    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel)
    {
      if (_button->isEnabled() && _button->isMouseClickEnabled(code))
      {
        _button->setSelected(false);
        _button->fireActionSignal();
        _button->repaint();
      }
    }

    void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
    {
      if (_button->isEnabled() && _button->isMouseClickEnabled(code))
      {
        _button->setSelected(true);
        _button->repaint();
      }
    }

    void cursorMoved(int x, int y, vgui::Panel* panel) {}
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
}

vgui::Button::Button(const char* text, int x, int y, int wide, int tall)
  : vgui::Label{ text, x, y, wide, tall }
{
  init();
}

vgui::Button::Button(const char* text, int x, int y)
  : vgui::Label{ text, x, y }
{
  init();
}

void vgui::Button::setButtonBorderEnabled(bool state)
{
  _buttonBorderEnabled = state;
  repaint();
}

void vgui::Button::setSelectedDirect(bool state)
{
  _selected = state;
  repaint();
}

void vgui::Button::setArmed(bool state)
{
  _armed = state;
  repaint();
}

bool vgui::Button::isArmed()
{
  return _armed;
}

void vgui::Button::doClick()
{
  setSelected(true);
  fireActionSignal();
  setSelected(false);
}

bool vgui::Button::isSelected()
{
  return _selected;
}

void vgui::Button::paintBackground()
{
  int wide, tall;

  getPaintSize(wide, tall);
  if (!isSelected())
  {
    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary3);
    drawFilledRect(0, 0, wide, tall);

    if (_buttonBorderEnabled)
    {
      drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);
      drawFilledRect(0, 0, _size[0] - 1, 1);
      drawFilledRect(2, _size[1] - 2, _size[0] - 1, _size[1] - 1);
      drawFilledRect(0, 1, 1, _size[1] - 1);
      drawFilledRect(_size[0] - 2, 2, _size[0] - 1, _size[1] - 2);

      drawSetColor(vgui::Scheme::SchemeColor::sc_white);
      drawFilledRect(1, 1, _size[0] - 2, 2);
      drawFilledRect(1, _size[1] - 1, _size[0], _size[1]);
      drawFilledRect(1, 2, 2, _size[1] - 2);
      drawFilledRect(_size[0] - 1, 1, _size[0], _size[1] - 1);
    }
  }
  else
  {
    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);
    drawFilledRect(0, 0, wide, tall);
  }

  if (isArmed())
  {
    drawSetColor(vgui::Scheme::SchemeColor::sc_white);
    drawFilledRect(0, 0, wide, 2);
    drawFilledRect(0, 2, 2, tall);

    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);
    drawFilledRect(2, tall - 2, wide, tall);
    drawFilledRect(wide - 2, 2, wide, tall - 1);

    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);
    drawFilledRect(1, tall - 1, wide, tall);
    drawFilledRect(wide - 1, 1, wide, tall - 1);
  }
}

void vgui::Button::setButtonGroup(vgui::ButtonGroup* buttonGroup)
{
  _buttonGroup = buttonGroup;
  if (buttonGroup)
    buttonGroup->addButton(this);
}

bool vgui::Button::isMouseClickEnabled(vgui::MouseCode code)
{
  return (_mouseClickMask >> (code + 1)) & 1;
}

void vgui::Button::fireActionSignal()
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    _actionSignalDar[i]->actionPerformed(this);
}

void vgui::Button::setButtonController(vgui::ButtonController* buttonController)
{
  if (_buttonController)
    _buttonController->removeSignals(this);

  _buttonController = buttonController;
  if (_buttonController)
    _buttonController->addSignals(this);
}

void vgui::Button::setSelected(bool state)
{
  if (_buttonGroup)
    _buttonGroup->setSelected(this);
  else
    setSelectedDirect(state);
}

void vgui::Button::setMouseClickEnabled(vgui::MouseCode code, bool state)
{
  if (state)
    _mouseClickMask |= 2 << code;
  else
    _mouseClickMask &= std::rotl(-2, code + 1);
}

void vgui::Button::addActionSignal(vgui::ActionSignal* s)
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    if (_actionSignalDar[i] == s)
      return;

  _actionSignalDar.addElement(s);
}

void vgui::Button::init()
{
  _mouseClickMask = 0;
  _buttonController = nullptr;
  _buttonGroup = nullptr;

  _armed = false;
  _selected = false;
  _buttonBorderEnabled = true;

  setMouseClickEnabled(vgui::MouseCode::MOUSE_LEFT, true);
  setButtonController(new FooDefaultButtonController{ this });
}