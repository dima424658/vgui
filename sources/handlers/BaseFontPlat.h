#pragma once

#include <VGUI.h>

namespace vgui
{
    class SurfacePlat;

    class BaseFontPlat
    {
    public:
        virtual int equals(char const *, int, int, float, int, bool, bool, bool, bool);
        virtual void getCharRGBA(int ch, int rgbaX, int rgbaY, int rgbaWide, int rgbaTall, uchar *rgba);
        virtual void getCharABCwide(int ch, int &a, int &b, int &c);
        virtual int getTall();
        virtual int getWide();
        virtual void drawSetTextFont(vgui::SurfacePlat *);
    };
} // namespace vgui
