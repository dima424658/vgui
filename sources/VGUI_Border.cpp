#include <VGUI_Border.h>

void vgui::Border::setInset(vgui::Border *const this, int left, int top, int right, int bottom)
{
  *(__m128i *)this->_inset = _mm_unpacklo_epi64(
                               _mm_move_epi64(_mm_unpacklo_epi32(_mm_cvtsi32_si128(left), _mm_cvtsi32_si128(top))),
                               _mm_move_epi64(_mm_unpacklo_epi32(_mm_cvtsi32_si128(right), _mm_cvtsi32_si128(bottom))));
}

void vgui::Border::getInset(vgui::Border *const this, int *const left, int *const top, int *const right, int *const bottom)
{
  *left = this->_inset[0];
  *top = this->_inset[1];
  *right = this->_inset[2];
  *bottom = this->_inset[3];
}

void vgui::Border::drawPrintChar(vgui::Border *const this, int x, int y, char ch_0)
{
  vgui::Image::drawPrintChar(this, x - this->_inset[0], y - this->_inset[1], ch_0);
}

void vgui::Border::drawPrintText(vgui::Border *const this, int x, int y, const char *str, int strlen)
{
  vgui::Image::drawPrintText(this, x - this->_inset[0], y - this->_inset[1], str, strlen);
}

void vgui::Border::drawSetTextPos(vgui::Border *const this, int x, int y)
{
  vgui::Image::drawSetTextPos(this, x - this->_inset[0], y - this->_inset[1]);
}

void vgui::Border::drawOutlinedRect(vgui::Border *const this, int x0, int y0, int x1, int y1)
{
  vgui::Image::drawOutlinedRect(
    this,
    x0 - this->_inset[0],
    y0 - this->_inset[1],
    x1 - this->_inset[0],
    y1 - this->_inset[1]);
}

void vgui::Border::drawFilledRect(vgui::Border *const this, int x0, int y0, int x1, int y1)
{
  vgui::Image::drawFilledRect(
    this,
    x0 - this->_inset[0],
    y0 - this->_inset[1],
    x1 - this->_inset[0],
    y1 - this->_inset[1]);
}

void vgui::Border::Border(vgui::Border *const this)
{
  vgui::Image::Image(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::Border + 2);
  this->_inset[0] = 0;
  this->_inset[1] = 0;
  this->_inset[2] = 0;
  this->_inset[3] = 0;
  this->_panel = 0;
}

void vgui::Border::Border(vgui::Border *const this, int left, int top, int right, int bottom)
{
  vgui::Image::Image(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::Border + 2);
  this->_panel = 0;
  this->_inset[0] = left;
  this->_inset[1] = top;
  this->_inset[2] = right;
  this->_inset[3] = bottom;
}

