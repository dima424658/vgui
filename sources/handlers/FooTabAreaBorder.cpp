#include "FooTabAreaBorder.hpp"

#include <VGUI_Panel.h>

void FooTabAreaBorder::paintBorder(vgui::Panel* panel)
{
    int wide, tall;
    panel->getSize(wide, tall);

    drawSetColor(vgui::Scheme::SchemeColor::sc_white);
    drawFilledRect(0, tall - 1, wide, tall);
}