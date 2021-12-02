#include <VGUI_ScrollBar.h>
#include <VGUI_Slider.h>
#include <VGUI_Button.h>

#include <VGUI_IntChangeSignal.h>
#include <VGUI_ActionSignal.h>

namespace
{
  class FooDefaultScrollBarIntChangeSignal : public vgui::IntChangeSignal
  {
  private:
    vgui::ScrollBar* _scrollBar;

  public:
    FooDefaultScrollBarIntChangeSignal(vgui::ScrollBar* scrollBar) : _scrollBar{ scrollBar } {}

    void intChanged(int value, vgui::Panel* panel)
    {
      _scrollBar->fireIntChangeSignal();
    }
  };

  class FooDefaultButtonSignal : public vgui::ActionSignal
  {
  private:
    vgui::ScrollBar* _scrollBar;
    int _buttonIndex;

  public:
    FooDefaultButtonSignal(vgui::ScrollBar* scrollBar, int buttonIndex) : _scrollBar{ scrollBar }, _buttonIndex{ buttonIndex } {}

    void actionPerformed(vgui::Panel* panel)
    {
      _scrollBar->doButtonPressed(_buttonIndex);
    }
  };
};


void vgui::ScrollBar::setValue(int value)
{
  _slider->setValue(value);
}

int vgui::ScrollBar::getValue()
{
  return _slider->getValue();
}

void vgui::ScrollBar::setRange(int min, int max)
{
  _slider->setRange(min, max);
}

void vgui::ScrollBar::fireIntChangeSignal()
{
  for (auto i = 0; i < _intChangeSignalDar.getCount(); ++i)
    _intChangeSignalDar[i]->intChanged(getValue(), this);
}

bool vgui::ScrollBar::isVertical()
{
  return _slider->isVertical();
}

bool vgui::ScrollBar::hasFullRange()
{
  return _slider->hasFullRange();
}

void vgui::ScrollBar::setButtonPressedScrollValue(int value)
{
  _buttonPressedScrollValue = value;
}

void vgui::ScrollBar::setRangeWindow(int rangeWindow)
{
  _slider->setRangeWindow(rangeWindow);
}

void vgui::ScrollBar::setRangeWindowEnabled(bool state)
{
  _slider->setRangeWindowEnabled(true);
}

void vgui::ScrollBar::validate()
{
  int wide, tall;
  int offset = 0;


  if (_slider)
  {
    if (_button[0] && _button[0]->isVisible())
      offset = isVertical() ? _button[1]->getTall() : _button[1]->getWide();

    if (_button[1] && _button[1]->isVisible())
      offset += isVertical() ? _button[1]->getTall() : _button[1]->getWide();

    _slider->setButtonOffset(offset);
  }

  getSize(wide, tall); // ???
  setSize(wide, tall);
}

void vgui::ScrollBar::setSlider(vgui::Slider* slider)
{
  if (_slider)
    removeChild(_slider);

  addChild(slider);
  _slider = slider;
  _slider->addIntChangeSignal(new FooDefaultScrollBarIntChangeSignal{ this });

  validate();
}

void vgui::ScrollBar::setButton(vgui::Button* button, int index)
{
  if (_button[index])
    removeChild(_button[index]);

  addChild(button);
  _button[index] = button;

  button->addActionSignal(new FooDefaultButtonSignal{ this, index });

  validate();
}

void vgui::ScrollBar::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);

  if (!_slider || !_button[0] || !_button[1])
    return;

  getPaintSize(wide, tall);

  if (isVertical())
  {
    _slider->setBounds(0, wide, wide, tall - 2 * wide);
    _button[0]->setBounds(0, 0, wide, wide);
    _button[1]->setBounds(0, tall - wide, wide, wide);
  }
  else
  {
    _slider->setBounds(tall, 0, wide - 2 * tall, tall);
    _button[0]->setBounds(0, 0, tall, tall);
    _button[1]->setBounds(wide - tall, 0, tall, tall);
  }
}

void vgui::ScrollBar::doButtonPressed(int buttonIndex)
{
  auto newValue = getValue();
  newValue += buttonIndex ? _buttonPressedScrollValue : -_buttonPressedScrollValue;
  setValue(newValue);
}

void vgui::ScrollBar::addIntChangeSignal(vgui::IntChangeSignal* s)
{
  for (auto i = 0; i < _intChangeSignalDar.getCount(); ++i)
    if (_intChangeSignalDar[i] == s)
      return;

  _intChangeSignalDar.addElement(s);
}

vgui::ScrollBar::ScrollBar(int x, int y, int wide, int tall, bool vertical)
  : vgui::Panel::Panel{ x, y, wide, tall },
  _button{ nullptr, nullptr },
  _slider{ nullptr },
  _buttonPressedScrollValue{ 15 }
{
  if (_slider)
    removeChild(_slider);

  if (vertical)
    _slider = new vgui::Slider{ 0, wide - 1, wide, tall - 2 * wide + 2, 1 };
  else
    _slider = new vgui::Slider{ tall, 0, wide - 2 * tall, tall, 0 };

  _slider->addIntChangeSignal(new FooDefaultScrollBarIntChangeSignal{ this });
  addChild(_slider);

  if (_button[0])
    removeChild(_button[0]);

  if (vertical)
    _button[0] = new vgui::Button{ "", 0, 0, wide, wide };
  else
    _button[0] = new vgui::Button{ "", 0, 0, tall + 1, tall + 1 };

  _button[0]->addActionSignal(new FooDefaultButtonSignal{ this, 0 });
  addChild(_button[0]);

  if (vertical)
    _button[1] = new vgui::Button{ "", 0, tall - wide, wide, wide };
  else
    _button[1] = new vgui::Button{ "", wide - tall, 0, tall + 1, tall + 1 };
  _button[1]->addActionSignal(new FooDefaultButtonSignal{ this, 1 });
  addChild(_button[1]);

  setPaintBorderEnabled(true);
  setPaintBackgroundEnabled(true);
  setPaintEnabled(true);
  validate();
}