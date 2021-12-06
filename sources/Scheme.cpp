#include <VGUI_Scheme.h>

#include <VGUI_Font.h>
#include <VGUI_Cursor.h>

void vgui::Scheme::setColor(vgui::Scheme::SchemeColor sc, int r, int g, int b, int a)
{
  _color[sc][0] = r;
  _color[sc][1] = g;
  _color[sc][2] = b;
  _color[sc][3] = a;
}

void vgui::Scheme::getColor(vgui::Scheme::SchemeColor sc, int& r, int& g, int& b, int& a)
{
  r = _color[sc][0];
  g = _color[sc][1];
  b = _color[sc][2];
  a = _color[sc][3];
}

void vgui::Scheme::setFont(vgui::Scheme::SchemeFont sf_0, vgui::Font* font)
{
  if (font)
    _font[sf_0] = font;
}

vgui::Font* vgui::Scheme::getFont(vgui::Scheme::SchemeFont sf)
{
  return _font[sf];
}

void vgui::Scheme::setCursor(vgui::Scheme::SchemeCursor scu, vgui::Cursor* cursor)
{
  if (cursor)
    _cursor[scu] = cursor;
}

vgui::Cursor* vgui::Scheme::getCursor(vgui::Scheme::SchemeCursor sc)
{
  return _cursor[sc];
}

vgui::Scheme::Scheme()
{
  _color[0][0] = 0;
  _color[0][0] = 0;
  _color[0][2] = 0;
  _color[0][2] = 0;

  _color[1][0] = 0;
  _color[1][1] = 0;
  _color[1][2] = 0;
  _color[1][3] = 0;

  _color[2][0] = 255;
  _color[2][1] = 255;
  _color[2][2] = 255;
  _color[2][3] = 255;

  _color[3][0] = 102;
  _color[3][1] = 102;
  _color[3][2] = 153;
  _color[3][3] = 153;

  _color[4][0] = 153;
  _color[4][1] = 153;
  _color[4][2] = 204;
  _color[4][3] = 204;

  _color[5][0] = 204;
  _color[5][1] = 204;
  _color[5][2] = 255;
  _color[5][3] = 255;

  _color[6][0] = 102;
  _color[6][1] = 102;
  _color[6][2] = 102;
  _color[6][3] = 102;

  _color[7][0] = 153;
  _color[7][1] = 153;
  _color[7][2] = 153;
  _color[7][3] = 0;

  _color[8][0] = 204;
  _color[8][1] = 204;
  _color[8][2] = 204;
  _color[8][3] = 204;


  _font[0] = nullptr;
  _font[1] = new vgui::Font{ "Arial", 0, 0, 20, 0, 0.0, 400, 0, 0, 0, 0 };
  _font[2] = new vgui::Font{ "FixedSys", 0, 0, 18, 0, 0.0, 400, 0, 0, 0, 0 };
  _font[3] = new vgui::Font{ "Arial", 0, 0, 12, 0, 0.0, 400, 0, 0, 0, 0 };
  _font[4] = new vgui::Font{ "Marlett", 0, 0, 16, 0, 0.0, 0, 0, 0, 0, 1 };

  _cursor[1] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_none };
  _cursor[2] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_arrow };
  _cursor[3] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_ibeam };
  _cursor[4] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_hourglass };
  _cursor[5] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_crosshair };
  _cursor[6] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_up };
  _cursor[7] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenwse };
  _cursor[8] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizenesw };
  _cursor[9] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizewe };
  _cursor[10] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizens };
  _cursor[11] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_sizeall };
  _cursor[12] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_no };
  _cursor[13] = new vgui::Cursor{ vgui::Cursor::DefaultCursor::dc_hand };
}