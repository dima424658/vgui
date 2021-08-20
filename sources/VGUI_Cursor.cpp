#include <VGUI_Cursor.h>

#include <VGUI_Bitmap.h>

vgui::Cursor::Cursor(vgui::Bitmap* bitmap, int hotspotX, int hotspotY)
    : _bitmap{ bitmap },
    _dc{ vgui::Cursor::DefaultCursor::dc_user }
{
    _hotspot[0] = hotspotX;
    _hotspot[1] = hotspotY;
}

vgui::Cursor::Cursor(vgui::Cursor::DefaultCursor dc)
{
    int tall; // esi
    
    int hx; // [esp+28h] [ebp-14h] BYREF
    int hy; // [esp+2Ch] [ebp-10h] BYREF

    _dc = dc;
    auto cursor = new vgui::Bitmap;

    if (_dc != vgui::Cursor::DefaultCursor::dc_none)
    {
        cursor->setPos(8, 0); // ???
        cursor->setSize( 16, 16);

        for(auto tall = 0; tall < 16; ++tall)
        {
            cursor->setRGBA(0, tall, 0, 0, 0, 0);
            cursor->setRGBA(1, tall, 0, 0, 0, 0);
            cursor->setRGBA(2, tall, 0, 0, 0, 0);
            cursor->setRGBA(3, tall, 0, 0, 0, 0);
            cursor->setRGBA(4, tall, 0, 0, 0, 0);
            cursor->setRGBA(5, tall, 0, 0, 0, 0);
            cursor->setRGBA(6, tall, 0, 0, 0, 0);
            cursor->setRGBA(7, tall, 0, 0, 0, 0);
            cursor->setRGBA(8, tall, 0, 0, 0, 0);
            cursor->setRGBA(9, tall, 0, 0, 0, 0);
            cursor->setRGBA(10, tall, 0, 0, 0, 0);
            cursor->setRGBA(11, tall, 0, 0, 0, 0);
            cursor->setRGBA(12, tall, 0, 0, 0, 0);
            cursor->setRGBA(13, tall, 0, 0, 0, 0);
            cursor->setRGBA(14, tall, 0, 0, 0, 0);
            cursor->setRGBA(15, tall, 0, 0, 0, 0);
        }

        cursor->setRGBA(0, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(1, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(2, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(3, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(4, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(5, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(6, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(7, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(8, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(9, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(10, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(11, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(12, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(13, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(14, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(15, 8, 0, 0xFFu, 0, 0xFFu);
        cursor->setRGBA(8, 0, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 1, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 2, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 3, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 4, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 5, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 6, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 7, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 8, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 9, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 10, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 11, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 12, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 13, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 14, 0, 0, 0xFFu, 0xFFu);
        cursor->setRGBA(8, 15, 0, 0, 0xFFu, 0xFFu);
    }

    cursor->getPos(hx, hy); // ???

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