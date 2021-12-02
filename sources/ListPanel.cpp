#include <VGUI_ListPanel.h>
#include <VGUI_ScrollBar.h>
#include <VGUI_Label.h>
#include <VGUI_StackLayout.h>
#include <VGUI_IntChangeSignal.h>

namespace
{
  class FooDefaultListPanelSignal : public vgui::IntChangeSignal
  {
  private:
    vgui::ListPanel* _listPanel;
  public:
    FooDefaultListPanelSignal(vgui::ListPanel* listPanel) : _listPanel{ listPanel } {}

    void intChanged(int value, vgui::Panel* panel)
    {
      _listPanel->setPixelScroll(-value);
    }
  };
}

void vgui::ListPanel::addItem(vgui::Panel* panel)
{
  int x, y;
  int wide, tall;
  int vwide, vtall;

  panel->setParent(_vpanel);
  _vpanel->invalidateLayout(true);

  auto child = _vpanel->getChild(_vpanel->getChildCount() - 1);
  child->getBounds(x, y, wide, tall);

  _vpanel->getSize(vwide, vtall);
  _vpanel->setSize(vwide, tall + y);

  _scroll->setRange(0, tall + y - _size[1]);
}

void vgui::ListPanel::performLayout()
{
  auto child = _vpanel->getChild(_vpanel->getChildCount() - 1);
  if (child)
  {
    int x, y;
    int wide, tall;
    int vwide, vtall;

    child->getBounds(x, y, wide, tall);
    _vpanel->getSize(vwide, vtall);
    _vpanel->setSize(_size[0] - 15, vtall);

    _scroll->setBounds(_size[0] - 15, 0, 15, _size[1]);
    _scroll->setRange(0, tall + y - _size[1]);
  }
}

void vgui::ListPanel::setPixelScroll(int value)
{
  _vpanel->setPos(0, value);
  repaint();
  _vpanel->repaint();
}

void vgui::ListPanel::translatePixelScroll(int delta)
{
  int x, y;
  _vpanel->getPos(x, y);
  _vpanel->setPos(0, y + delta);

  repaint();
  _vpanel->repaint();
}

void vgui::ListPanel::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);
  invalidateLayout(false);
}

void vgui::ListPanel::addString(const char* str)
{
  addItem(new vgui::Label{ str, 0, 0, 80, 20 });
}

vgui::ListPanel::ListPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _vpanel{ new vgui::Panel{ 0, 0, wide - 15, 2 * tall } },
  _scroll{ new vgui::ScrollBar{ wide - 15, 0, 15, tall, true } }
{

  _vpanel->setParent(this);
  _vpanel->setLayout(new vgui::StackLayout{ 1, false });
  _vpanel->setBgColor(0, 0, 100, 0);

  _scroll->setParent(this);
  _scroll->addIntChangeSignal(new FooDefaultListPanelSignal{ this });
}

