#include <VGUI_Cursor.h>

#include "handlers/CursorBitmap.h"

vgui::Cursor::Cursor(vgui::Bitmap* bitmap, int hotspotX, int hotspotY)
    : _bitmap{ bitmap },
    _dc{ vgui::Cursor::DefaultCursor::dc_user }
{
    _hotspot[0] = hotspotX;
    _hotspot[1] = hotspotY;
}

vgui::Cursor::Cursor(vgui::Cursor::DefaultCursor dc)
    : _dc{ dc }
{
    int hx, hy;
    auto cursor = new CursorBitmap{this};
    
    privateInit(cursor, hx, hy);
}

void vgui::Cursor::getHotspot(int& x, int& y)
{
    x = _hotspot[0];
    y = _hotspot[1];
}

void vgui::Cursor::privateInit(vgui::Bitmap* bitmap, int hotspotX, int hotspotY)
{
    _bitmap = bitmap;
    _hotspot[0] = hotspotX;
    _hotspot[1] = hotspotY;
}

vgui::Bitmap* vgui::Cursor::getBitmap()
{
    return _bitmap;
}

vgui::Cursor::DefaultCursor vgui::Cursor::getDefaultCursor()
{
    return _dc;
}