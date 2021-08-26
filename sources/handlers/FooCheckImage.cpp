#include "FooCheckImage.h"

FooCheckImage::FooCheckImage(vgui::CheckButton* checkButton)
    : _checkButton{ checkButton }
{
    setSize(20, 20);
}

void FooCheckImage::paint(vgui::Panel* panel)
{
    drawSetTextFont(vgui::Scheme::SchemeFont::sf_secondary1);
    drawSetTextColor(vgui::Scheme::SchemeColor::sc_white);

    drawPrintChar(0, 0, 'g');
    drawPrintChar(0, 0, 'c');
    drawPrintChar(0, 0, 'd');
    drawPrintChar(0, 0, 'e');
    drawPrintChar(0, 0, 'f');

    if (_checkButton->isSelected())
    {
        drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
        drawPrintChar(0, 0, 'a');
    }
}