#include <VGUI_BorderLayout.h>

void vgui::BorderLayout::performLayout(vgui::BorderLayout *const this, vgui::Panel *panel)
{
  int v2; // esi
  int v3; // eax
  const void *lpsrc; // eax
  _DWORD *v5; // edi
  int v6; // ebp
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // ebp
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  const void *v16; // eax
  _DWORD *v17; // eax
  int v18; // edi
  int v19; // eax
  int x1; // [esp+2Ch] [ebp-50h]
  int x1a; // [esp+2Ch] [ebp-50h]
  int y0; // [esp+30h] [ebp-4Ch]
  int y0a; // [esp+30h] [ebp-4Ch]
  int i; // [esp+34h] [ebp-48h]
  int ia; // [esp+34h] [ebp-48h]
  int y1; // [esp+38h] [ebp-44h]
  int y1a; // [esp+38h] [ebp-44h]
  int v28; // [esp+3Ch] [ebp-40h]
  int wide[4]; // [esp+40h] [ebp-3Ch] BYREF
  int tall[11]; // [esp+50h] [ebp-2Ch] BYREF

  v2 = 0;
  (*((void (__cdecl **)(vgui::Panel *, int *, int *))panel->_vptr_Panel + 3))(panel, wide, tall);
  i = 0;
  y0 = 0;
  y1 = 0;
  x1 = 0;
  if ( (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 43))(panel) > 0 )
  {
    do
    {
      v3 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, v2);
      lpsrc = (const void *)(*(int (__cdecl **)(int))(*(_DWORD *)v3 + 344))(v3);
      if ( lpsrc )
      {
        v5 = _dynamic_cast(
               lpsrc,
               (const struct __class_type_info *)&`typeinfo for'vgui::LayoutInfo,
               (const struct __class_type_info *)&`typeinfo for'vgui::BorderLayoutInfo,
               0);
        if ( v5 )
        {
          v6 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, v2);
          v7 = v5[1];
          if ( v7 == 2 )
          {
            if ( i < (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 28))(v6) )
            {
              ++v2;
              i = (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 28))(v6);
              continue;
            }
          }
          else if ( v7 > 2 )
          {
            if ( v7 == 3 )
            {
              if ( x1 < (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 28))(v6) )
              {
                ++v2;
                x1 = (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 24))(v6);
                continue;
              }
            }
            else if ( v7 == 4 && y1 < (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 24))(v6) )
            {
              ++v2;
              y1 = (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 24))(v6);
              continue;
            }
          }
          else if ( v7 == 1 && y0 < (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 28))(v6) )
          {
            ++v2;
            y0 = (*(int (__cdecl **)(int))(*(_DWORD *)v6 + 28))(v6);
            continue;
          }
        }
      }
      ++v2;
    }
    while ( v2 < (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 43))(panel) );
  }
  v8 = 0;
  v9 = this->_inset;
  x1a = wide[0] - x1 - v9;
  v10 = tall[0] - i - v9;
  v11 = v9 + y0;
  ia = v9 + y1;
  v12 = v10 - (v9 + y0);
  v13 = v9 + y1;
  y0a = v12;
  y1a = v10;
  v14 = v11;
  v28 = x1a - v13;
  while ( v8 < (*((int (__cdecl **)(vgui::Panel *))panel->_vptr_Panel + 43))(panel) )
  {
    v15 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, v8);
    v16 = (const void *)(*(int (__cdecl **)(int))(*(_DWORD *)v15 + 344))(v15);
    if ( v16
      && (v17 = _dynamic_cast(
                  v16,
                  (const struct __class_type_info *)&`typeinfo for'vgui::LayoutInfo,
                  (const struct __class_type_info *)&`typeinfo for'vgui::BorderLayoutInfo,
                  0)) != 0 )
    {
      v18 = v17[1];
      v19 = (*((int (__cdecl **)(vgui::Panel *, int))panel->_vptr_Panel + 44))(panel, v8);
      switch ( v18 )
      {
        case 0:
          ++v8;
          (*(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)v19 + 16))(v19, ia, v14, v28, y0a);
          break;
        case 1:
          ++v8;
          (*(void (__cdecl **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v19 + 16))(v19, 0, 0, wide[0], v14);
          break;
        case 2:
          ++v8;
          (*(void (__cdecl **)(int, _DWORD, int, int, int))(*(_DWORD *)v19 + 16))(v19, 0, y1a, wide[0], tall[0] - y1a);
          break;
        case 3:
          (*(void (__cdecl **)(int, int, int, int, int))(*(_DWORD *)v19 + 16))(v19, x1a, v14, wide[0] - x1a, y0a);
          goto LABEL_24;
        case 4:
          ++v8;
          (*(void (__cdecl **)(int, _DWORD, int, int, int))(*(_DWORD *)v19 + 16))(v19, 0, v14, ia, y0a);
          break;
        default:
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      ++v8;
    }
  }
}

void vgui::BorderLayout::BorderLayout(vgui::BorderLayout *const this, int inset)
{
  vgui::Layout::Layout(this);
  this->_vptr_Layout = (int (**)(...))(&`vtable for'vgui::BorderLayout + 2);
  this->_inset = inset;
}

