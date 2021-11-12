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

  _sectionPanelDar.addElement(panel);
  panel->setParent(_sectionLayer);
  panel->setBounds(x, y, wide, tall);

  getPaintSize(wide, tall);

  auto v11 = new vgui::Panel{0, 0, _sliderWide, tall};
  v11->setPaintBorderEnabled(false);
  v11->setPaintBackgroundEnabled(false);
  v11->setPaintEnabled(false);
  v11->setPos(wide + x, 0);
  
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

vgui::HeaderPanel::HeaderPanel(int x, int y, int wide, int tall)
  : vgui::Panel{x, y, wide, tall},
    _sliderWide{11},
    _dragging{false},
    _sectionLayer{new vgui::Panel{0, 0, wide, tall}}
{
  _sectionLayer->setPaintBorderEnabled(false);
  _sectionLayer->setPaintBackgroundEnabled(false);
  _sectionLayer->setPaintEnabled(false);
  _sectionLayer->setParent(this);
}