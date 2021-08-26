#include "FooClock.h"

#include <ctime>

FooClock::FooClock(int x, int y, int wide, int tall)
    : vgui::Panel{ x, y, wide, tall }
{
    getApp()->addTickSignal(this);
}

void FooClock::paintBackground()
{
    char buf[50];

    if (_hour > 12)
        sprintf(buf, "%d:%.2d:%.2d PM", _hour - 12, _minute, _second);
    else
        sprintf(buf, "%d:%.2d:%.2d AM", _hour, _minute, _second);

    paintBackground();

    drawSetTextFont(vgui::Scheme::SchemeFont::sf_primary1);
    drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);
    drawPrintText(0, 0, buf, strlen(buf));
}

void FooClock::ticked()
{
    auto aclock = std::time(nullptr);

    auto lc = localtime(&aclock);
    if (_hour != lc->tm_hour || _minute != lc->tm_min || _second != lc->tm_sec)
    {
        _second = lc->tm_sec;
        _hour = lc->tm_hour;
        _minute = lc->tm_min;
        repaint();
    }
}