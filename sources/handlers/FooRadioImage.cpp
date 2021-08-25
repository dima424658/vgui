#include "FooRadioImage.h"

FooRadioImage::FooRadioImage(vgui::RadioButton* radioButton)
    : _radioButton{ _radioButton }
{
    setSize(20, 20);
}

void FooRadioImage::paint(vgui::Panel* panel)
{
    drawSetTextFont(vgui::Scheme::SchemeFont::sf_secondary1);

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);
    drawPrintChar(0, 0, 'n');

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary2);
    drawPrintChar(0, 0, 'j');

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);
    drawPrintChar(0, 0, 'k');

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
    drawPrintChar(0, 0, 'l');

    drawSetTextColor(vgui::Scheme::SchemeColor::sc_secondary3);
    drawPrintChar(0, 0, 'm');

    if (_radioButton->isSelected())
    {
        drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
        drawPrintChar(0, 0, 'h');
    }
}