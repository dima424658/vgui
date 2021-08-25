#include <VGUI_Scheme.h>

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

void vgui::Scheme::setCursor(vgui::Scheme::SchemeCursor scu, vgui::Cursor* cursor)
{
  if (cursor)
    _cursor[scu] = cursor;
}

void vgui::Scheme::Scheme()
{
  vgui::Font* v1; // esi
  vgui::Font* v2; // esi
  vgui::Font* v3; // esi
  vgui::Font* v4; // esi
  vgui::Cursor* v5; // esi
  vgui::Cursor* v6; // esi
  vgui::Cursor* v7; // esi
  vgui::Cursor* v8; // esi
  vgui::Cursor* v9; // esi
  vgui::Cursor* v10; // esi
  vgui::Cursor* v11; // esi
  vgui::Cursor* v12; // esi
  vgui::Cursor* v13; // esi
  vgui::Cursor* v14; // esi
  vgui::Cursor* v15; // esi
  vgui::Cursor* v16; // esi
  vgui::Cursor* v17; // esi

  this->_color[7][3] = 0;
  this->_vptr_Scheme = (int (**)(...))(&`vtable for'vgui::Scheme + 2);
    * (_QWORD*)&this->_color[1][0] = 0LL;
  *(_QWORD*)&this->_color[1][2] = 0LL;
  this->_color[2][0] = 255;
  this->_color[2][1] = 255;
  *(_QWORD*)&this->_color[2][2] = 255LL;
  this->_color[3][0] = 102;
  this->_color[3][1] = 102;
  *(_QWORD*)&this->_color[3][2] = 153LL;
  this->_color[4][0] = 153;
  this->_color[4][1] = 153;
  *(_QWORD*)&this->_color[4][2] = 204LL;
  this->_color[5][0] = 204;
  this->_color[5][1] = 204;
  *(_QWORD*)&this->_color[5][2] = 255LL;
  this->_color[6][0] = 102;
  this->_color[6][1] = 102;
  *(_QWORD*)&this->_color[6][2] = 102LL;
  this->_color[7][0] = 153;
  this->_color[7][1] = 153;
  this->_color[7][2] = 153;
  this->_color[8][0] = 204;
  *(_QWORD*)&this->_color[8][2] = 204LL;
  this->_color[8][1] = 204;
  *(_QWORD*)&this->_color[0][0] = 0LL;
  *(_QWORD*)&this->_color[0][2] = 0LL;
  v1 = (vgui::Font*)operator new(0x10u);
  vgui::Font::Font(v1, "Arial", 0, 0, 20, 0, 0.0, 400, 0, 0, 0, 0);
  if (v1)
    this->_font[1] = v1;
  v2 = (vgui::Font*)operator new(0x10u);
  vgui::Font::Font(v2, "FixedSys", 0, 0, 18, 0, 0.0, 400, 0, 0, 0, 0);
  if (v2)
    this->_font[2] = v2;
  v3 = (vgui::Font*)operator new(0x10u);
  vgui::Font::Font(v3, "Arial", 0, 0, 12, 0, 0.0, 400, 0, 0, 0, 0);
  if (v3)
    this->_font[3] = v3;
  v4 = (vgui::Font*)operator new(0x10u);
  vgui::Font::Font(v4, "Marlett", 0, 0, 16, 0, 0.0, 0, 0, 0, 0, 1);
  if (v4)
    this->_font[4] = v4;
  v5 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v5, dc_none);
  if (v5)
    this->_cursor[1] = v5;
  v6 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v6, dc_arrow);
  if (v6)
    this->_cursor[2] = v6;
  v7 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v7, dc_ibeam);
  if (v7)
    this->_cursor[3] = v7;
  v8 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v8, dc_hourglass);
  if (v8)
    this->_cursor[4] = v8;
  v9 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v9, dc_crosshair);
  if (v9)
    this->_cursor[5] = v9;
  v10 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v10, dc_up);
  if (v10)
    this->_cursor[6] = v10;
  v11 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v11, dc_sizenwse);
  if (v11)
    this->_cursor[7] = v11;
  v12 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v12, dc_sizenesw);
  if (v12)
    this->_cursor[8] = v12;
  v13 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v13, dc_sizewe);
  if (v13)
    this->_cursor[9] = v13;
  v14 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v14, dc_sizens);
  if (v14)
    this->_cursor[10] = v14;
  v15 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v15, dc_sizeall);
  if (v15)
    this->_cursor[11] = v15;
  v16 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v16, dc_no);
  if (v16)
    this->_cursor[12] = v16;
  v17 = (vgui::Cursor*)operator new(0x14u);
  vgui::Cursor::Cursor(v17, dc_hand);
  if (v17)
    this->_cursor[13] = v17;
}

