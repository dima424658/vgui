#include <VGUI_Cursor.h>
#include <VGUI_Bitmap.h>

namespace
{
    class CursorBitmap : public vgui::Bitmap
    {
    private:
        int _pos[2];
        int _hotspot[2];
        
    public:
        CursorBitmap(vgui::Cursor* cursor)
        {
            _pos[0] = 8;
            _pos[1] = 0;

            if (cursor->getDefaultCursor() != vgui::Cursor::DefaultCursor::dc_none)
            {
                setSize(16, 16);

                for (auto tall = 0; tall < 16; ++tall)
                {
                    setRGBA(0, tall, 0, 0, 0, 0);
                    setRGBA(1, tall, 0, 0, 0, 0);
                    setRGBA(2, tall, 0, 0, 0, 0);
                    setRGBA(3, tall, 0, 0, 0, 0);
                    setRGBA(4, tall, 0, 0, 0, 0);
                    setRGBA(5, tall, 0, 0, 0, 0);
                    setRGBA(6, tall, 0, 0, 0, 0);
                    setRGBA(7, tall, 0, 0, 0, 0);
                    setRGBA(8, tall, 0, 0, 0, 0);
                    setRGBA(9, tall, 0, 0, 0, 0);
                    setRGBA(10, tall, 0, 0, 0, 0);
                    setRGBA(11, tall, 0, 0, 0, 0);
                    setRGBA(12, tall, 0, 0, 0, 0);
                    setRGBA(13, tall, 0, 0, 0, 0);
                    setRGBA(14, tall, 0, 0, 0, 0);
                    setRGBA(15, tall, 0, 0, 0, 0);
                }

                setRGBA(0, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(1, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(2, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(3, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(4, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(5, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(6, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(7, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(8, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(9, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(10, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(11, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(12, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(13, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(14, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(15, 8, 0, 0xFFu, 0, 0xFFu);
                setRGBA(8, 0, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 1, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 2, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 3, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 4, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 5, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 6, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 7, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 8, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 9, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 10, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 11, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 12, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 13, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 14, 0, 0, 0xFFu, 0xFFu);
                setRGBA(8, 15, 0, 0, 0xFFu, 0xFFu);
            }
        }

        void getHotspot(int& x, int& y)
        {
            x = _hotspot[0];
            y = _hotspot[1];
        }
    };
}

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
    auto cursor = new CursorBitmap{ this };

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