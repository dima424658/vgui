#include <VGUI_TabPanel.h>

#include "handlers/FooClientBorder.hpp"
#include "handlers/FooTabAreaBorder.hpp"

void vgui::TabPanel::setSelectedTab(vgui::Panel* tab)
{
  if (tab == _selectedTab || tab == nullptr)
    return;

  for (auto i = 0; i < _tabArea->getChildCount(); ++i)
    if (tab == _tabArea->getChild(i))
    {
      _selectedPanel->setVisible(false);
      _selectedPanel = _clientArea->getChild(i);
      _selectedPanel->setVisible(true);
      _selectedTab = tab;
      break;
    }

  recomputeLayout();
}


void vgui::TabPanel::recomputeLayoutTop()
{
  int i, j, ja, jb, jc;
  int extra2;
  int maxx, miny;
  int x = 0, y = 0;
  int wide, tall;
  int paintWide, paintTall;
  int ww, tt;
  int xx, yy;

  (*((void(__cdecl**)(vgui::TabPanel* const, int*, int*))_vptr_Panel + 58))(this, &paintWide, &paintTall);
  v1 = paintWide;
  x[0] = 5;
  v2 = (*((int(__cdecl**)(vgui::Panel*))_tabArea->_vptr_Panel + 43))(_tabArea) - 1;
  if (v2 >= 0)
  {
    maxx = v1 - 5;
    v3 = 0;
    do
    {
      v5 = (*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(_tabArea, v2);
      (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v5 + 240))(v5, &wide, tall);
      v6 = (*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(_tabArea, v2);
      (*(void(__cdecl**)(int, int, int))(*(_DWORD*)v6 + 8))(v6, wide, tall[0]);
      if (x[0] + wide <= maxx)
      {
        ++v3;
      }
      else
      {
        if (v3)
        {
          extra2 = (maxx - x[0]) / v3;
          v7 = v3 * extra2;
          v8 = v2 + v3;
          v30 = v8;
          if (v8 > v2)
          {
            v9 = 0;
            i = v2;
            v33 = extra2 + maxx - x[0] - v7;
            do
            {
              v10 = extra2;
              if (v8 == v30)
                v10 = v33;
              v11 = (*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(_tabArea, v8);
              (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v11 + 240))(v11, &ww, &tt);
              v12 = (*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(_tabArea, v8);
              (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v12 + 4))(v12, &xx, &yy);
              ja = v8--;
              v13 = (*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(_tabArea, ja);
              v14 = v9 + xx;
              v9 += v10;
              (*(void(__cdecl**)(int, int, int, int, int))(*(_DWORD*)v13 + 16))(v13, v14, yy, v10 + ww, tt);
            } while (v8 != i);
            v2 = i;
          }
        }
        x[0] = 5;
        v3 = 1;
        maxx -= 5;
        y[0] += 4 - tall[0];
      }
      j = v2--;
      v4 = (void(__cdecl***)(_DWORD, int, int))(*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel
        + 44))(
          _tabArea,
          j);
      (**v4)(v4, x[0], y[0]);
      x[0] += wide - 1;
    } while (v2 != -1);
  }
  v15 = 0;
  v16 = (*((int(__cdecl**)(vgui::Panel*, _DWORD))_tabArea->_vptr_Panel + 44))(_tabArea, 0);
  (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v16 + 4))(v16, x, miny);
  while (1)
  {
    v19 = v15 < (*((int(__cdecl**)(vgui::Panel*))_tabArea->_vptr_Panel + 43))(_tabArea);
    v20 = _tabArea;
    v21 = v20->_vptr_Panel;
    if (!v19)
      break;
    v17 = v21[44](v20, v15);
    (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v17 + 4))(v17, x, y);
    jb = v15++;
    v18 = (void(__cdecl***)(_DWORD, int, int))(*((int(__cdecl**)(vgui::Panel*, int))_tabArea->_vptr_Panel + 44))(
      _tabArea,
      jb);
    (**v18)(v18, x[0], y[0] - miny[0]);
  }
  v22 = v21[44](v20, 0);
  (*(void(__cdecl**)(int, int*, int*))(*(_DWORD*)v22 + 12))(v22, &wide, tall);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD, int, int, int))_tabArea->_vptr_Panel + 4))(
    _tabArea,
    0,
    5,
    paintWide,
    tall[0] - miny[0]);
  (*((void(__cdecl**)(vgui::Panel*, int*, int*))_tabArea->_vptr_Panel + 3))(_tabArea, &wide, tall);
  (*((void(__cdecl**)(vgui::Panel*, _DWORD, int, int, int))_clientArea->_vptr_Panel + 4))(
    _clientArea,
    0,
    tall[0] + 4,
    paintWide,
    paintTall - tall[0] - 5);
  v23 = 0;
  (*((void(__cdecl**)(vgui::Panel*, int*, int*))_clientArea->_vptr_Panel + 3))(
    _clientArea,
    &wide,
    tall);
  while (v23 < (*((int(__cdecl**)(vgui::Panel*))_clientArea->_vptr_Panel + 43))(_clientArea))
  {
    v24 = (*((int(__cdecl**)(vgui::Panel*, int))_clientArea->_vptr_Panel + 44))(_clientArea, v23);
    (*(void(__cdecl**)(int, int, int, int, int))(*(_DWORD*)v24 + 16))(v24, 5, 5, wide - 10, tall[0] - 10);
    jc = v23++;
    v25 = (*((int(__cdecl**)(vgui::Panel*, int))_clientArea->_vptr_Panel + 44))(_clientArea, jc);
    (*(void(__cdecl**)(int, _DWORD))(*(_DWORD*)v25 + 184))(v25, 0);
  }
}

void vgui::TabPanel::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);
  recomputeLayout();
}

void vgui::TabPanel::recomputeLayout()
{
  if (_tabArea->getChildCount())
  {
    if (_tabPlacement == TabPlacement::tp_top)
      recomputeLayoutTop();
    repaint();
  }
}

void vgui::TabPanel::TabPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  _tabPlacement = TabPlacement::tp_top;

  _clientArea = new vgui::Panel{ 5, 5, wide - 10, tall - 10 };
  _clientArea->setParent(this);
  _clientArea->setBorder(new FooClientBorder);

  _tabArea = new vgui::Panel{ 5, 5, wide, 5 };
  _tabArea->setParent(this);
  _tabArea->setBorder(new FooTabAreaBorder);

  _selectedTab = nullptr;
  _selectedPanel = nullptr;
}