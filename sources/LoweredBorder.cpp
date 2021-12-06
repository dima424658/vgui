#include <VGUI_LoweredBorder.h>
#include <VGUI_Panel.h>

vgui::LoweredBorder::LoweredBorder()
{
    setInset(2, 2, 2, 2);
}

void vgui::LoweredBorder::paint(vgui::Panel* panel)
{
    int wide, tall;
    panel->getSize(wide, tall);

    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);
    drawFilledRect(0, 0, wide, 2);
    drawFilledRect(0, 2, 2, tall);

    drawSetColor(vgui::Scheme::SchemeColor::sc_white);
    drawFilledRect(1, tall - 2, wide, tall);
    drawFilledRect(wide - 2, 1, wide, tall - 1);

    drawSetColor(vgui::Scheme::SchemeColor::sc_secondary1);

    drawFilledRect(1, 1, wide - 1, 2);
    drawFilledRect(1, 2, 2, tall - 1);
}