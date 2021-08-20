#include <VGUI_ProgressBar.h>

void vgui::ProgressBar::paintBackground(vgui::ProgressBar *const this)
{
  int v2; // esi
  int v4; // ebp
  int v5; // edi
  long double v6; // fst7
  float v8; // [esp+2Ch] [ebp-40h]
  int segmentWide; // [esp+30h] [ebp-3Ch]
  float v10; // [esp+34h] [ebp-38h]
  int wide; // [esp+44h] [ebp-28h] BYREF
  int tall; // [esp+48h] [ebp-24h] BYREF
  __int16 v13; // [esp+4Ch] [ebp-20h]
  __int16 v14; // [esp+4Eh] [ebp-1Eh]

  (*((void (__cdecl **)(vgui::ProgressBar *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::ProgressBar *const, int))this->_vptr_Panel + 93))(this, 7);
  (*((void (__cdecl **)(vgui::ProgressBar *const, _DWORD, _DWORD, int, int))this->_vptr_Panel + 95))(
    this,
    0,
    0,
    wide,
    tall);
  _FST7 = this->_progress;
  v2 = wide / this->_segmentCount;
  segmentWide = v2 - 2;
  v14 = v13 & 0xF3FF | 0x400;
  __asm { frndint }
  v4 = 0;
  if ( (int)(double)_FST7 > 0 )
  {
    v5 = 0;
    do
    {
      ++v4;
      (*((void (__cdecl **)(vgui::ProgressBar *const, _DWORD, _DWORD, int, _DWORD))this->_vptr_Panel + 94))(
        this,
        0,
        0,
        100,
        0);
      (*((void (__cdecl **)(vgui::ProgressBar *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
        this,
        v5,
        0,
        v5 + segmentWide,
        tall);
      v5 += v2;
    }
    while ( v4 != (int)(double)_FST7 );
    v4 *= v2;
  }
  v6 = this->_progress;
  if ( (long double)this->_segmentCount > v6 )
  {
    _FST6 = this->_progress;
    v13 = v14 & 0xF3FF | 0x400;
    __asm { frndint }
    v10 = _FST6;
    v8 = 255.0 - (v6 - v10) * 155.0;
    (*((void (__cdecl **)(vgui::ProgressBar *const, _DWORD, _DWORD, int, _DWORD))this->_vptr_Panel + 94))(
      this,
      0,
      0,
      (int)v8,
      0);
    (*((void (__cdecl **)(vgui::ProgressBar *const, int, _DWORD, int, int))this->_vptr_Panel + 95))(
      this,
      v4,
      0,
      v4 + segmentWide,
      tall);
  }
}

int vgui::ProgressBar::getSegmentCount(vgui::ProgressBar *const this)
{
  return this->_segmentCount;
}

void vgui::ProgressBar::setProgress(vgui::ProgressBar *const this, float progress)
{
  int (**v2)(...); // edx

  if ( this->_progress != progress )
  {
    v2 = this->_vptr_Panel;
    this->_progress = progress;
    v2[12](this);
  }
}

void vgui::ProgressBar::ProgressBar(vgui::ProgressBar *const this, int segmentCount)
{
  vgui::Panel::Panel(this, 0, 0, 10, 110);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ProgressBar + 2);
  this->_progress = 0.0;
  this->_segmentCount = segmentCount;
}

