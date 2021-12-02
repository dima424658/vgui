#include <VGUI_MessageBox.h>
#include <VGUI_ActionSignal.h>
#include <VGUI_Label.h>
#include <VGUI_Button.h>

namespace
{
  class FooButtonHandler : public vgui::ActionSignal
  {
  private:
    vgui::MessageBox* _messageBox;

  public:
    FooButtonHandler(vgui::MessageBox* messageBox) : _messageBox{ messageBox } {}
    
    void actionPerformed(vgui::Panel* panel)
    {
      _messageBox->fireActionSignal();
    }
  };
}


void vgui::MessageBox::performLayout()
{
  int wide, tall;
  getClient()->getSize(wide, tall);

  _messageLabel->setPos((wide - _messageLabel->getWide()) / 2, (tall - _messageLabel->getTall() - 10) / 2);
  _okButton->setPos((wide - _okButton->getWide()) / 2, tall - _okButton->getTall() - 10);
}

void vgui::MessageBox::addActionSignal(vgui::ActionSignal* s)
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    if (_actionSignalDar[i] == s)
      return;

  _actionSignalDar.addElement(s);
}

void vgui::MessageBox::fireActionSignal()
{
  for (auto i = 0; i < _actionSignalDar.getCount(); ++i)
    _actionSignalDar[i]->actionPerformed(this);
}

vgui::MessageBox::MessageBox(const char* title, const char* text, int x, int y)
  : vgui::Frame{ x, y, 64, 64 }
{
  int wide, tall;

  setTitle(title);
  setMenuButtonVisible(false);
  setTrayButtonVisible(false);
  setMinimizeButtonVisible(false);
  setMaximizeButtonVisible(false);
  setCloseButtonVisible(false);
  setSizeable(false);

  _messageLabel = new vgui::Label{ text };
  _messageLabel->setParent(getClient());
  _messageLabel->getSize(wide, tall);

  _okButton = new vgui::Button{ "Ok", 10, 10 };
  _okButton->setParent(getClient());
  _okButton->addActionSignal(new FooButtonHandler{this});
  
  setSize(wide + 100, tall + 100);
}

