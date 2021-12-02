#pragma once

#include <VGUI_Bitmap.h>

struct VFontData
{
    int m_BitmapCharHeight = 0;
    int m_BitmapCharWidth = 0;
    vgui::Bitmap* m_pBitmap = nullptr;
};