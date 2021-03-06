#include <VGUI_BorderLayout.h>

#include <VGUI_Panel.h>
#include <VGUI_LayoutInfo.h>

namespace vgui
{
  class BorderLayoutInfo : public LayoutInfo
  {
  public:
    virtual LayoutInfo* getThis() { return this; }

    vgui::BorderLayout::Alignment _alignment;
  };
};

vgui::BorderLayout::BorderLayout(int inset)
  : _inset{ inset }
{}

void vgui::BorderLayout::performLayout(vgui::Panel* panel)
{
  int x1 = 0, x1a;
  int y0 = 0, y0a;
  int i = 0, ia;
  int y1 = 0, y1a;

  int wide, tall;

  panel->getSize(wide, tall);

  for (auto j = 0; j < panel->getChildCount(); ++j)
  {
    auto child = panel->getChild(j);
    auto lpsrc = dynamic_cast<vgui::BorderLayoutInfo*>(child->getLayoutInfo());
    if (lpsrc)
    {
      auto tall = child->getTall();
      auto wide = child->getWide();

      switch (lpsrc->_alignment)
      {
      case vgui::BorderLayout::Alignment::a_north:
        if (y0 < tall)
        {
          y0 = tall;
          continue;
        }
        break;
      case vgui::BorderLayout::Alignment::a_south:
        if (i < tall)
        {
          i = tall;
          continue;
        }
        break;
      case vgui::BorderLayout::Alignment::a_east:
        if (x1 < tall)
        {
          x1 = wide;
          continue;
        }
        break;
      case vgui::BorderLayout::Alignment::a_west:
        if (y1 < wide)
        {
          y1 = wide;
          continue;
        }
        break;
      default:
        break;
      }
    }
  }

  x1a = wide - x1 - _inset;
  ia = _inset + y1;
  y0a = tall - i - _inset - (_inset + y0);
  y1a = tall - i - _inset;

  for (auto j = 0; j < panel->getChildCount(); ++j)
  {
    auto lpsrc = dynamic_cast<vgui::BorderLayoutInfo*>(panel->getChild(j)->getLayoutInfo());

    if (lpsrc)
    {
      switch (lpsrc->_alignment)
      {
      case vgui::BorderLayout::Alignment::a_center:
        panel->getChild(j)->setBounds(ia, _inset + y0, x1a - (_inset + y1), y0a);
        break;
      case vgui::BorderLayout::Alignment::a_north:
        panel->getChild(j)->setBounds(0, 0, wide, _inset + y0);
        break;
      case vgui::BorderLayout::Alignment::a_south:
        panel->getChild(j)->setBounds(0, y1a, wide, tall - y1a);
        break;
      case vgui::BorderLayout::Alignment::a_east:
        panel->getChild(j)->setBounds(x1a, _inset + y0, wide - x1a, y0a);
        break;
      case vgui::BorderLayout::Alignment::a_west:
        panel->getChild(j)->setBounds(0, _inset + y0, ia, y0a);
        break;
      default:
        break;
      }
    }
  }
}

vgui::LayoutInfo * vgui::BorderLayout::createLayoutInfo(vgui::BorderLayout::Alignment alignment)
{
  auto result = new BorderLayoutInfo;
  result->_alignment = alignment;
  
  return result;
}