#include <VGUI_ButtonGroup.h>

#include <VGUI_Button.h>

void vgui::ButtonGroup::addButton(vgui::Button* button)
{  
  for(auto i = 0; i < _buttonDar.getCount(); ++i)
    if(button == _buttonDar[i])
      return;
  
  _buttonDar.addElement(button);
}

void vgui::ButtonGroup::setSelected(vgui::Button* button)
{
  for (auto i = 0; i < _buttonDar.getCount(); ++i)
  {
    auto it = _buttonDar[i];
    if (it != button)
      it->setSelectedDirect(false);
  }

  button->setSelectedDirect(true);
}