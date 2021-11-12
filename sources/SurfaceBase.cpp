#include <VGUI_SurfaceBase.h>
#include <VGUI_ImagePanel.h>
#include <VGUI_Cursor.h>

void vgui::SurfaceBase::requestSwap()
{
  _needsSwap = true;
}

void vgui::SurfaceBase::resetModeInfo()
{
  _modeInfoDar.removeAll();
}

int vgui::SurfaceBase::getModeInfoCount()
{
  return _modeInfoDar.getCount();
}

void vgui::SurfaceBase::setEmulatedCursorVisible(bool state)
{
  _emulatedCursor->setVisible(state);
}

void vgui::SurfaceBase::setEmulatedCursorPos(int x, int y)
{
  int hx, hy;

  //v4 = (*_vptr_SurfaceBase)(this);
  //(*(void (__cdecl **)(int, vgui::ImagePanel *))(*(_DWORD *)v4 + 76))(v4, _emulatedCursor);
  //v5 = (*_vptr_SurfaceBase)(this);
  //(*(void (__cdecl **)(int, vgui::ImagePanel *))(*(_DWORD *)v5 + 68))(v5, _emulatedCursor);
  //v6 = (*_vptr_SurfaceBase)(this);

  //(*(void (__cdecl **)(int, int *, int *))(*(_DWORD *)v6 + 140))(v6, &x, &y);
  if ( _currentCursor && !_emulatedCursor->isVisible())
  {
    _currentCursor->getHotspot(hx, hy);

    x -= hx;
    y -= hy;
  }
  
  _emulatedCursor->setPos(x, y);
}

bool vgui::SurfaceBase::getModeInfo(int index, int& wide, int& tall, int& bpp)
{
  bool result = false;

  if ( index >= 0 && index < _modeInfoDar.getCount() )
  {
    sscanf(_modeInfoDar[index], "%dx%dx%d", wide, tall, bpp);
    result = true;
  }

  return result;
}

void vgui::SurfaceBase::addModeInfo(int wide, int tall, int bpp)
{
  char *buf2, buf[256];

  sprintf(buf, "%dx%dx%d", wide, tall, bpp);
  buf2 = strdup(buf);
  
  _modeInfoDar.addElement(buf2);
}

vgui::SurfaceBase::SurfaceBase(vgui::Panel *embeddedPanel)
{
  _embeddedPanel = embeddedPanel;
  _needsSwap = true;
  
  v6 = (vgui::ImagePanel *)operator new(0xC0u);
  vgui::ImagePanel::ImagePanel(v6, 0);
  v6->_vptr_Panel = (int (**)(...))&off_477C8;
  _emulatedCursor = v6;
  (*((void (__cdecl **)(vgui::ImagePanel *, _DWORD))v6->_vptr_Panel + 9))(v6, 0);
  v7 = _embeddedPanel;
  _currentCursor = 0;
  (*((void (__cdecl **)(vgui::Panel *, vgui::SurfaceBase *const))v7->_vptr_Panel + 90))(v7, this);
  v8 = vgui::App::getInstance();
  (*((void (__cdecl **)(vgui::App *, vgui::SurfaceBase *const))v8->_vptr_App + 51))(v8, this);
  (*((void (__cdecl **)(vgui::ImagePanel *, vgui::Panel *))_emulatedCursor->_vptr_Panel + 16))(
    _emulatedCursor,
    _embeddedPanel);
}

void vgui::SurfaceBase::~SurfaceBase()
{
  vgui::App *v1; // eax

  _vptr_SurfaceBase = (int (**)(...))(&`vtable for'vgui::SurfaceBase + 2);
  v1 = vgui::App::getInstance();
  (*((void (__cdecl **)(vgui::App *, vgui::SurfaceBase *const))v1->_vptr_App + 52))(v1, this);
}

