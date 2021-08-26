#pragma once

#include <VGUI_Bitmap.h>

class vgui::Cursor;

class CursorBitmap : public vgui::Bitmap
{
private:
    int _pos[2];
    int _hotspot[2];
public:
    CursorBitmap(vgui::Cursor* cursor);
    void getHotspot(int& x, int& y);
};