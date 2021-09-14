#include "FooClientBorder.hpp"

#include <VGUI_Border.h>
#include <VGUI_Panel.h>

void FooClientBorder::paintBorder(vgui::Panel* panel)
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