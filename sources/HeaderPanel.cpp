#include <VGUI_HeaderPanel.h>

#include <VGUI_App.h>
#include <VGUI_ChangeSignal.h>

void vgui::HeaderPanel::setSliderPos(int sliderIndex, int pos)
{
  if (sliderIndex >= 0 && sliderIndex < _sliderPanelDar.getCount())
  {
    _sliderPanelDar[sliderIndex]->setPos(pos - _sliderWide / 2, 0);

    invalidateLayout(false);
    fireChangeSignal();
    repaint();
  }
}

int vgui::HeaderPanel::getSectionCount()
{
  return _sectionPanelDar.getCount();
}

void vgui::HeaderPanel::getSectionExtents(int sectionIndex, int& x0, int& x1)
{
  int x, y;
  int wide, tall;

  if (sectionIndex >= 0 && sectionIndex < _sectionPanelDar.getCount())
  {
    _sectionPanelDar[sectionIndex]->getBounds(x0, y, wide, tall);
    x0 = x;
    x1 = x + wide;
  }
}

void vgui::HeaderPanel::fireChangeSignal()
{
  invalidateLayout(true);

  for (auto i = 0; i < _changeSignalDar.getCount(); ++i)
    _changeSignalDar[i]->valueChanged(this);
}

void vgui::HeaderPanel::performLayout()
{
  int x, y;
  int wide, tall;

  getPaintSize(wide, tall);
  _sectionLayer->setBounds(0, 0, wide, tall);

  wide = 0;
  for (auto i = 0; i < _sectionPanelDar.getCount(); ++i)
  {
    _sliderPanelDar[i]->setPos(x, y);
    _sectionPanelDar[i]->setBounds(wide, 0, x + _sliderWide / 2 - wide, tall);
    wide = x + _sliderWide / 2;
  }
}

void vgui::HeaderPanel::privateCursorMoved(int x, int y, vgui::Panel* panel)
{
  if (_dragging)
  {
    getApp()->getCursorPos(x, y);
    screenToLocal(x, y);
    setSliderPos(_dragSliderIndex, _dragSliderStartPos + x - _dragSliderStartX);
    invalidateLayout(false);
    repaint();
  }
}

void vgui::HeaderPanel::privateMousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  int mx, my;
  int x, y;

  getApp()->getCursorPos(mx, my);
  screenToLocal(mx, my);

  for (auto i = 0; i < _sliderPanelDar.getCount(); ++i)
    if (panel == _sliderPanelDar[i])
    {
      panel->getPos(x, y);

      _dragging = true;
      _dragSliderIndex = i;
      _dragSliderStartPos = x + _sliderWide / 2;
      _dragSliderStartX = mx;

      panel->setAsMouseCapture(true);
      break;
    }

}

void vgui::HeaderPanel::privateMouseReleased(vgui::MouseCode code, vgui::Panel* panel)
{
  _dragging = false;
  panel->setAsMouseCapture(false);
}

void vgui::HeaderPanel::addChangeSignal(vgui::ChangeSignal* s)
{
  for (auto i = 0; i < _changeSignalDar.getCount(); ++i)
    if (s == _changeSignalDar[i])
      return;

  _changeSignalDar.addElement(s);
}

void vgui::HeaderPanel::addSectionPanel(vgui::Panel* panel)
{
  int x, y;
  int wide, tall;

  invalidateLayout(true);

  for(auto i = 0; i < _sectionPanelDar.getCount(); ++i)
  {
    _sectionPanelDar[i]->getBounds(x, y, wide, tall);
    x += wide + _sliderWide;
  }

  v6 = _sectionPanelDar._capacity;
  v7 = v2 + 1;
  v8 = &_sectionPanelDar;
  if (v7 <= v6)
  {
    v9 = _sectionPanelDar._data;
    goto LABEL_7;
  }
  if (v6 || (v6 = 1, v24 = 4, v7 > 1))
  {
    do
      v6 *= 2;
    while (v7 > v6);
    v24 = 4 * v6;
  }
  v25 = (_BYTE*)operator new[](v24);
  v9 = (vgui::Panel**)v25;
  if (!v25)
    goto LABEL_64;
  v36 = v24;
  v26 = v25;
  if (v36 >= 8)
  {
    if (((uint8_t)v25 & 1) != 0)
    {
      *v25 = 0;
      v26 = v25 + 1;
      --v36;
    }
    if (((uint8_t)v26 & 2) != 0)
    {
      *v26++ = 0;
      v36 -= 2;
    }
    if (((uint8_t)v26 & 4) != 0)
    {
      *(_DWORD*)v26 = 0;
      v26 += 2;
      v36 -= 4;
    }
    memset(v26, 0, 4 * (v36 >> 2));
    v26 += 2 * (v36 >> 2);
    LOBYTE(v36) = v36 & 3;
  }
  if ((v36 & 4) == 0)
  {
    if ((v36 & 2) == 0)
      goto LABEL_18;
  LABEL_46:
    *v26++ = 0;
    if ((v36 & 1) == 0)
      goto LABEL_19;
    goto LABEL_45;
  }
  *(_DWORD*)v26 = 0;
  v26 += 2;
  if ((v36 & 2) != 0)
    goto LABEL_46;
LABEL_18:
  if ((v36 & 1) != 0)
    LABEL_45 :
    *(_BYTE*)v26 = 0;
LABEL_19:
  v3 = _sectionPanelDar._count;
  _sectionPanelDar._capacity = v6;
  if (v3 > 0)
  {
    v27 = 0;
    do
    {
      v9[v27] = _sectionPanelDar._data[v27];
      ++v27;
      v3 = v8->_count;
    } while (v27 < v8->_count);
  }
  v28 = _sectionPanelDar._data;
  if (v28)
  {
    v33 = v9;
    operator delete[]((VFontData* const)v28);
    v3 = _sectionPanelDar._count;
    v9 = v33;
  }
  _sectionPanelDar._data = v9;
LABEL_7:
  v9[v3] = panel;
  v10 = x;
  ++_sectionPanelDar._count;
  (*panel->_vptr_Panel)(panel, v10, 0);
  (*((void(__cdecl**)(vgui::Panel*, vgui::Panel*))panel->_vptr_Panel + 16))(panel, _sectionLayer);
  (*((void(__cdecl**)(vgui::Panel*, int, int, int, int))panel->_vptr_Panel + 4))(panel, x, y, wide, tall[0]);
  (*((void(__cdecl**)(vgui::HeaderPanel* const, int*, int*))_vptr_Panel + 58))(this, &wide, tall);
  v11 = (vgui::Panel*)operator new(0xBCu);
  vgui::Panel::Panel(v11, 0, 0, _sliderWide, tall[0]);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))v11->_vptr_Panel + 54))(v11, 0);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))v11->_vptr_Panel + 55))(v11, 0);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))v11->_vptr_Panel + 56))(v11, 0);
  (*v11->_vptr_Panel)(v11, wide + x, 0);
  v12 = (void(__cdecl*)(vgui::Panel*, _DWORD*)) * ((_DWORD*)v11->_vptr_Panel + 28);
  v13 = operator new(8u);
  *v13 = &off_449A8;
  v13[1] = this;
  v12(v11, v13);
  v14 = (void(__cdecl*)(vgui::Panel*, int)) * ((_DWORD*)v11->_vptr_Panel + 36);
  v15 = (*((int(__cdecl**)(vgui::HeaderPanel* const))_vptr_Panel + 83))(this);
  v16 = (*(int(__cdecl**)(int))(*(_DWORD*)v15 + 84))(v15);
  v17 = &_sliderPanelDar;
  v18 = (*(int(__cdecl**)(int, int))(*(_DWORD*)v16 + 20))(v16, 9);
  v14(v11, v18);
  (*((void(__cdecl**)(vgui::Panel*, vgui::HeaderPanel* const))v11->_vptr_Panel + 16))(v11, this);
  v19 = _sliderPanelDar._count;
  v20 = _sliderPanelDar._capacity;
  v21 = v19 + 1;
  if (v19 + 1 <= v20)
  {
    v22 = _sliderPanelDar._data;
    goto LABEL_9;
  }
  if (v20 || (v20 = 1, v29 = 4, v21 > 1))
  {
    do
      v20 *= 2;
    while (v21 > v20);
    v29 = 4 * v20;
  }
  v34 = v20;
  v30 = (_BYTE*)operator new[](v29);
  v35 = (vgui::Panel**)v30;
  if (!v30)
    LABEL_64:
  exit(0);
  v37 = v29;
  v31 = v30;
  if (v37 >= 8)
  {
    if (((uint8_t)v30 & 1) != 0)
    {
      *v30 = 0;
      --v37;
      v31 = v30 + 1;
    }
    if (((uint8_t)v31 & 2) != 0)
    {
      *v31++ = 0;
      v37 -= 2;
    }
    if (((uint8_t)v31 & 4) != 0)
    {
      *(_DWORD*)v31 = 0;
      v31 += 2;
      v37 -= 4;
    }
    memset(v31, 0, 4 * (v37 >> 2));
    v31 += 2 * (v37 >> 2);
    LOBYTE(v37) = v37 & 3;
  }
  if ((v37 & 4) == 0)
  {
    if ((v37 & 2) == 0)
      goto LABEL_33;
  LABEL_41:
    *v31++ = 0;
    if ((v37 & 1) == 0)
      goto LABEL_34;
    goto LABEL_40;
  }
  *(_DWORD*)v31 = 0;
  v31 += 2;
  if ((v37 & 2) != 0)
    goto LABEL_41;
LABEL_33:
  if ((v37 & 1) != 0)
    LABEL_40 :
    *(_BYTE*)v31 = 0;
LABEL_34:
  v19 = _sliderPanelDar._count;
  _sliderPanelDar._capacity = v34;
  if (v19 > 0)
  {
    v32 = 0;
    do
    {
      v35[v32] = _sliderPanelDar._data[v32];
      ++v32;
      v19 = v17->_count;
    } while (v32 < v17->_count);
  }
  if (_sliderPanelDar._data)
  {
    operator delete[]((VFontData* const)_sliderPanelDar._data);
    v19 = _sliderPanelDar._count;
  }
  v22 = v35;
  _sliderPanelDar._data = v35;
LABEL_9:
  v22[v19] = v11;
  v23 = _vptr_Panel;
  ++_sliderPanelDar._count;
  v23[46](this, 0);
  (*((void(__cdecl**)(vgui::HeaderPanel* const))_vptr_Panel + 132))(this);
  (*((void(__cdecl**)(vgui::HeaderPanel* const))_vptr_Panel + 12))(this);
}

void vgui::HeaderPanel::HeaderPanel(int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::Panel** v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  vgui::Panel** v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  vgui::ChangeSignal** v16; // edx
  vgui::Panel* v17; // esi
  int v18; // [esp+2Ch] [ebp-20h]
  int v19; // [esp+2Ch] [ebp-20h]
  int v20; // [esp+2Ch] [ebp-20h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  _sliderPanelDar._count = 0;
  _sliderPanelDar._capacity = 0;
  _vptr_Panel = (int (**)(...))(&`vtable for'vgui::HeaderPanel + 2);
    _sliderPanelDar._data = 0;
  v5 = operator new[](0x10u);
  if (!v5)
    goto LABEL_20;
  *(_DWORD*)v5 = 0;
  *(_DWORD*)(v5 + 4) = 0;
  *(_DWORD*)(v5 + 8) = 0;
  *(_DWORD*)(v5 + 12) = 0;
  v6 = _sliderPanelDar._count;
  _sliderPanelDar._capacity = 4;
  if (v6 > 0)
  {
    v7 = 0;
    do
    {
      *(_DWORD*)(v5 + 4 * v7) = _sliderPanelDar._data[v7];
      ++v7;
    } while (v7 < _sliderPanelDar._count);
  }
  v8 = _sliderPanelDar._data;
  if (v8)
  {
    v18 = v5;
    operator delete[]((VFontData* const)v8);
    v5 = v18;
  }
  _sliderPanelDar._data = (vgui::Panel**)v5;
  _sectionPanelDar._count = 0;
  _sectionPanelDar._capacity = 0;
  _sectionPanelDar._data = 0;
  v9 = operator new[](0x10u);
  if (!v9)
    goto LABEL_20;
  *(_DWORD*)v9 = 0;
  *(_DWORD*)(v9 + 4) = 0;
  *(_DWORD*)(v9 + 8) = 0;
  *(_DWORD*)(v9 + 12) = 0;
  v10 = _sectionPanelDar._count;
  _sectionPanelDar._capacity = 4;
  if (v10 > 0)
  {
    v11 = 0;
    do
    {
      *(_DWORD*)(v9 + 4 * v11) = _sectionPanelDar._data[v11];
      ++v11;
    } while (v11 < _sectionPanelDar._count);
  }
  v12 = _sectionPanelDar._data;
  if (v12)
  {
    v19 = v9;
    operator delete[]((VFontData* const)v12);
    v9 = v19;
  }
  _sectionPanelDar._data = (vgui::Panel**)v9;
  _changeSignalDar._count = 0;
  _changeSignalDar._capacity = 0;
  _changeSignalDar._data = 0;
  v13 = operator new[](0x10u);
  if (!v13)
    LABEL_20:
  exit(0);
  *(_DWORD*)v13 = 0;
  *(_DWORD*)(v13 + 4) = 0;
  *(_DWORD*)(v13 + 8) = 0;
  *(_DWORD*)(v13 + 12) = 0;
  v14 = _changeSignalDar._count;
  _changeSignalDar._capacity = 4;
  if (v14 > 0)
  {
    v15 = 0;
    do
    {
      *(_DWORD*)(v13 + 4 * v15) = _changeSignalDar._data[v15];
      ++v15;
    } while (v15 < _changeSignalDar._count);
  }
  v16 = _changeSignalDar._data;
  if (v16)
  {
    v20 = v13;
    operator delete[]((VFontData* const)v16);
    v13 = v20;
  }
  _changeSignalDar._data = (vgui::ChangeSignal**)v13;
  _sliderWide = 11;
  _dragging = 0;
  v17 = (vgui::Panel*)operator new(0xBCu);
  vgui::Panel::Panel(v17, 0, 0, wide, tall);
  _sectionLayer = v17;
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))v17->_vptr_Panel + 54))(v17, 0);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))_sectionLayer->_vptr_Panel + 55))(_sectionLayer, 0);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD))_sectionLayer->_vptr_Panel + 56))(_sectionLayer, 0);
  (*((void(__cdecl**)(vgui::Panel*, vgui::HeaderPanel* const))_sectionLayer->_vptr_Panel + 16))(
    _sectionLayer,
    this);
}

