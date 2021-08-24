#include <cmath>

#include "FooTabFolderVerticalLayout.h"

handlers::FooTabFolderVerticalLayout::FooTabFolderVerticalLayout(int hgap, int vgap)
    : _hgap{ hgap }, _vgap{ vgap }
{
}

void handlers::FooTabFolderVerticalLayout::performLayout(vgui::Panel* panel)
{
    int maxx = 0;
    int wide, tall;
    int y = 0;

    for (auto i = 0; i < panel->getChildCount(); ++i)
    {
        auto child = panel->getChild(i);
        auto tchild = dynamic_cast<vgui::TreeFolder*>(child);
        if (tchild)
            tchild->invalidateLayout(true);

        child->getSize(wide, tall);
        child->setPos(i ? _hgap : 0, y);

        maxx = std::max(maxx, wide + (i ? _hgap : 0));
        y += tall + _vgap;
    }

    auto tree_panel = dynamic_cast<vgui::TreeFolder*>(panel);
    if (tree_panel)
    {
        if (tree_panel->isOpened())
            tree_panel->setSize(maxx + 2, y);
        else if (tree_panel->getChild(0))
        {
            tree_panel->getChild(0)->getSize(wide, tall);
            tree_panel->setSize(wide, tall);
        }
    }
}