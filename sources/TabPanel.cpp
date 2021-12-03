#include <VGUI_TabPanel.h>
#include <VGUI_Border.h>
#include <VGUI_Panel.h>

namespace
{
  class FooTabAreaBorder : public vgui::Border
  {
  public:
    void paintBorder(vgui::Panel* panel)
    {
      int wide, tall;
      panel->getSize(wide, tall);

      drawSetColor(vgui::Scheme::SchemeColor::sc_white);
      drawFilledRect(0, tall - 1, wide, tall);
    }
  };

  class FooClientBorder : public vgui::Border
  {
  public:
    void paintBorder(vgui::Panel* panel)
    {
      int wide, tall;
      panel->getSize(wide, tall);

      drawSetColor(vgui::Scheme::SchemeColor::sc_white);
      drawFilledRect(0, 0, wide - 1, 1);
      drawFilledRect(0, 1, 1, tall - 1);

      drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);
      drawFilledRect(0, tall - 1, wide, tall);
      drawFilledRect(wide - 1, 0, wide, tall - 1);
    }
  };
}

void vgui::TabPanel::setSelectedTab(vgui::Panel* tab)
{
  if (tab == _selectedTab || tab == nullptr)
    return;

  for (auto i = 0; i < _tabArea->getChildCount(); ++i)
    if (tab == _tabArea->getChild(i))
    {
      _selectedPanel->setVisible(false);
      _selectedPanel = _clientArea->getChild(i);
      _selectedPanel->setVisible(true);
      _selectedTab = tab;
      break;
    }

  recomputeLayout();
}


void vgui::TabPanel::recomputeLayoutTop()
{
  int extra2;
  int maxx, miny;
  int x = 5, y = 0;
  int wide, tall;
  int paintWide, paintTall;
  int ww, tt;
  int xx, yy;

  getPaintSize(paintWide, paintTall);
  maxx = paintWide - 5;

  auto j = 0;
  for (auto i = _tabArea->getChildCount(); i > 0; --i)
  {
    auto child = _tabArea->getChild(i);
    child->getPreferredSize(wide, tall);
    child->setSize(wide, tall);

    if (x + wide <= maxx)
      ++j;
    else
    {
      if (j)
      {
        extra2 = (maxx - x) / j;

        for (j += i; j != i; --j)
        {
          _tabArea->getChild(j)->getPreferredSize(ww, tt);
          _tabArea->getChild(j)->getPos(xx, yy);
          _tabArea->getChild(j)->setBounds(i * extra2 + xx, yy, extra2 + ww, tt);
        }
      }
      y += 4 - tall;
      j = 1;
      maxx -= 5;
    }

    child->setPos(x, y);
    x += wide - 1;
  }

  _tabArea->getChild(0)->getPos(x, miny);
  for (auto i = 0; i < _tabArea->getChildCount(); ++i)
  {
    _tabArea->getChild(i)->getPos(x, y);
    _tabArea->getChild(i)->setPos(x, y - miny);
  }

  _tabArea->getChild(0)->getSize(wide, tall);
  _tabArea->setBounds(0, 5, paintWide, tall - miny);
  _tabArea->getSize(wide, tall);

  _clientArea->setBounds(0, tall + 4, paintWide, paintTall - tall - 5);
  _clientArea->getSize(wide, tall);
  for (auto i = 0; i < _clientArea->getChildCount(); ++i)
  {
    _clientArea->getChild(i)->setBounds(5, 5, wide - 10, tall - 10);
    _clientArea->getChild(i)->invalidateLayout(false);
  }
}

void vgui::TabPanel::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);
  recomputeLayout();
}

void vgui::TabPanel::recomputeLayout()
{
  if (_tabArea->getChildCount())
  {
    if (_tabPlacement == TabPlacement::tp_top)
      recomputeLayoutTop();
    repaint();
  }
}

vgui::TabPanel::TabPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  _tabPlacement = TabPlacement::tp_top;

  _clientArea = new vgui::Panel{ 5, 5, wide - 10, tall - 10 };
  _clientArea->setParent(this);
  _clientArea->setBorder(new FooClientBorder);

  _tabArea = new vgui::Panel{ 5, 5, wide, 5 };
  _tabArea->setParent(this);
  _tabArea->setBorder(new FooTabAreaBorder);

  _selectedTab = nullptr;
  _selectedPanel = nullptr;
}