#include <VGUI_FocusNavGroup.h>

#include <VGUI_Panel.h>

void vgui::FocusNavGroup::setCurrentPanel(vgui::Panel *panel)
{
  for(auto i = 0; i < _panelDar.getCount(); ++i)
    if(_panelDar[i] == panel)
    {
      _currentIndex = i;
      break;
    }
}

void vgui::FocusNavGroup::requestFocusNext()
{
  if(++_currentIndex < _panelDar.getCount())
    _panelDar[_currentIndex]->requestFocus();
}

void vgui::FocusNavGroup::requestFocusPrev()
{
  if (--_currentIndex >= 0)
    _panelDar[_currentIndex]->requestFocus();
}

void vgui::FocusNavGroup::addPanel(vgui::Panel *panel)
{
  for (auto i = 0; i < _panelDar.getCount(); ++i)
    if (_panelDar[i] == panel)
      return;

  _panelDar.addElement(panel);
}

vgui::FocusNavGroup::FocusNavGroup()
{
  _currentIndex = 0;
}
