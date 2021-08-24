#pragma once

#include <VGUI_Layout.h>
#include <VGUI_TreeFolder.h>

namespace handlers
{
    class FooTabFolderVerticalLayout : public vgui::Layout
    {
    private:
        int _hgap, _vgap;
    public:
        FooTabFolderVerticalLayout(int hgap, int vgap);
        virtual void performLayout(vgui::Panel* panel);
    };
};