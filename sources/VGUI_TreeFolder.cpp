#include <VGUI_TreeFolder.h>

bool vgui::TreeFolder::isOpened(vgui::TreeFolder *const this)
{
  return this->_opened;
}

void vgui::TreeFolder::setOpenedTraverse(vgui::TreeFolder *const this, bool state)
{
  int v2; // edi
  const void *lpsrc; // eax
  void *v4; // eax

  v2 = 0;
  (*((void (__cdecl **)(vgui::TreeFolder *const, int))this->_vptr_Panel + 129))(this, 1);
  if ( (*((int (__cdecl **)(vgui::TreeFolder *const))this->_vptr_Panel + 43))(this) > 0 )
  {
    do
    {
      lpsrc = (const void *)(*((int (__cdecl **)(vgui::TreeFolder *const, int))this->_vptr_Panel + 44))(this, v2);
      if ( lpsrc )
      {
        v4 = _dynamic_cast(
               lpsrc,
               (const struct __class_type_info *)&`typeinfo for'vgui::Panel,
               (const struct __class_type_info *)&`typeinfo for'vgui::TreeFolder,
               0);
        if ( v4 )
          (*(void (__cdecl **)(void *, bool))(*(_DWORD *)v4 + 512))(v4, state);
      }
      ++v2;
    }
    while ( v2 < (*((int (__cdecl **)(vgui::TreeFolder *const))this->_vptr_Panel + 43))(this) );
  }
}

void vgui::TreeFolder::paintBackground(vgui::TreeFolder *const this)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax
  bool v4; // cc
  int (**v5)(...); // eax
  const void *v6; // edi
  int v7; // esi
  const void *v8; // ebp
  void *v9; // ebp
  int (**v10)(...); // eax
  int tall[4]; // [esp+20h] [ebp-1Ch] BYREF
  int wide[2]; // [esp+30h] [ebp-Ch] BYREF
  int y_0; // [esp+38h] [ebp-4h] BYREF
  int x_0[7]; // [esp+3Ch] [ebp+0h] BYREF

  v1 = 10;
  v2 = 1;
  (*((void (__cdecl **)(vgui::TreeFolder *const, int))this->_vptr_Panel + 93))(this, 1);
  while ( 1 )
  {
    v4 = v2 < (*((int (__cdecl **)(vgui::TreeFolder *const))this->_vptr_Panel + 43))(this);
    v5 = this->_vptr_Panel;
    if ( !v4 )
      break;
    v6 = (const void *)v5[44](this, v2);
    (*(void (__cdecl **)(const void *, int *, int *, int *, int *))(*(_DWORD *)v6 + 20))(v6, &y_0, tall, x_0, wide);
    if ( _dynamic_cast(
           v6,
           (const struct __class_type_info *)&`typeinfo for'vgui::Panel,
           (const struct __class_type_info *)&`typeinfo for'vgui::TreeFolder,
           0) )
    {
      v3 = tall[0] + 10;
      tall[0] += 10;
    }
    else
    {
      v3 = tall[0] + wide[0] / 2;
      tall[0] = v3;
    }
    ++v2;
    (*((void (__cdecl **)(vgui::TreeFolder *const, int, int, int, int))this->_vptr_Panel + 95))(
      this,
      15,
      v3,
      30,
      v3 + 1);
    v1 = tall[0];
  }
  v7 = 1;
  v5[95](this, 15, 10, 16, v1);
  if ( (*((int (__cdecl **)(vgui::TreeFolder *const))this->_vptr_Panel + 43))(this) > 1 )
  {
    do
    {
      v8 = (const void *)(*((int (__cdecl **)(vgui::TreeFolder *const, int))this->_vptr_Panel + 44))(this, v7);
      (*(void (__cdecl **)(const void *, int *, int *, int *, int *))(*(_DWORD *)v8 + 20))(v8, x_0, &y_0, wide, tall);
      v9 = _dynamic_cast(
             v8,
             (const struct __class_type_info *)&`typeinfo for'vgui::Panel,
             (const struct __class_type_info *)&`typeinfo for'vgui::TreeFolder,
             0);
      if ( v9
        && (v10 = this->_vptr_Panel,
            y_0 += 10,
            v10[93](this, 2),
            (*((void (__cdecl **)(vgui::TreeFolder *const, int, int, int, int))this->_vptr_Panel + 95))(
              this,
              10,
              y_0 - 5,
              21,
              y_0 + 6),
            (*((void (__cdecl **)(vgui::TreeFolder *const, int))this->_vptr_Panel + 93))(this, 1),
            (*((void (__cdecl **)(vgui::TreeFolder *const, int, int, int, int))this->_vptr_Panel + 96))(
              this,
              10,
              y_0 - 5,
              21,
              y_0 + 6),
            (*((void (__cdecl **)(vgui::TreeFolder *const, int, int, int, int))this->_vptr_Panel + 95))(
              this,
              12,
              y_0,
              19,
              y_0 + 1),
            !(*(uint8_t (__cdecl **)(void *))(*(_DWORD *)v9 + 520))(v9)) )
      {
        ++v7;
        (*((void (__cdecl **)(vgui::TreeFolder *const, int, int, int, int))this->_vptr_Panel + 95))(
          this,
          15,
          y_0 - 3,
          16,
          y_0 + 4);
      }
      else
      {
        ++v7;
      }
    }
    while ( v7 < (*((int (__cdecl **)(vgui::TreeFolder *const))this->_vptr_Panel + 43))(this) );
  }
}

void vgui::TreeFolder::setOpened(vgui::TreeFolder *const this, bool state)
{
  vgui::TreeFolder *lpsrc; // ebx
  void *v3; // esi
  void *v4; // eax

  lpsrc = this;
  if ( this->_opened != state )
  {
    this->_opened = state;
    v3 = 0;
    do
    {
      v4 = _dynamic_cast(
             lpsrc,
             (const struct __class_type_info *)&`typeinfo for'vgui::Panel,
             (const struct __class_type_info *)&`typeinfo for'vgui::TreeFolder,
             0);
      if ( v4 )
      {
        v3 = v4;
        (*(void (__cdecl **)(void *, int))(*(_DWORD *)v4 + 184))(v4, 1);
      }
      lpsrc = (vgui::TreeFolder *)(*((int (__cdecl **)(vgui::TreeFolder *))lpsrc->_vptr_Panel + 8))(lpsrc);
    }
    while ( lpsrc );
    if ( v3 )
      (*(void (__cdecl **)(void *))(*(_DWORD *)v3 + 268))(v3);
  }
}

void vgui::TreeFolder::init(vgui::TreeFolder *const this, const char *name)
{
  vgui::Label *v2; // esi
  void (__cdecl *v3)(vgui::Label *, _DWORD *); // edi
  _DWORD *v4; // eax
  void (__cdecl *v5)(vgui::TreeFolder *const, vgui::Layout *); // esi
  vgui::Layout *v6; // edi

  this->_opened = 0;
  v2 = (vgui::Label *)operator new(0xD0u);
  vgui::Label::Label(v2, name, 0, 0);
  v3 = *(void (__cdecl **)(vgui::Label *, _DWORD *))(*(_DWORD *)v2->baseclass_0 + 112);
  v4 = operator new(8u);
  v4[1] = this;
  *v4 = &off_499A8;
  v3(v2, v4);
  (*(void (__cdecl **)(vgui::Label *, vgui::TreeFolder *const))(*(_DWORD *)v2->baseclass_0 + 64))(v2, this);
  v5 = (void (__cdecl *)(vgui::TreeFolder *const, vgui::Layout *))*((_DWORD *)this->_vptr_Panel + 45);
  v6 = (vgui::Layout *)operator new(0xCu);
  vgui::Layout::Layout(v6);
  v6->_vptr_Layout = (int (**)(...))&off_499E0;
  v6[1]._vptr_Layout = (int (**)(...))(&dword_1C + 2);
  v6[2]._vptr_Layout = (int (**)(...))(dword_0 + 3);
  v5(this, v6);
}

void vgui::TreeFolder::TreeFolder(vgui::TreeFolder *const this, const char *name)
{
  vgui::Panel::Panel((vgui::Panel *const)this, 0, 0, 500, 500);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TreeFolder + 2);
  vgui::TreeFolder::init(this, name);
}

void vgui::TreeFolder::TreeFolder(vgui::TreeFolder *const this, const char *name, int x, int y)
{
  vgui::Panel::Panel((vgui::Panel *const)this, x, y, 500, 500);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::TreeFolder + 2);
  vgui::TreeFolder::init(this, name);
}

