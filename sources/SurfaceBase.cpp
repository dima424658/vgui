#include <cstdio>
#include <cstring>

#include <VGUI_SurfaceBase.h>
#include <VGUI_ImagePanel.h>
#include <VGUI_Cursor.h>
#include <VGUI_App.h>

namespace
{
  class FakeImagePanel : public vgui::ImagePanel
  {
    bool isWithin(int x, int y)
    {
      return false;
    }
  };
}

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

  if (_currentCursor && !_emulatedCursor->isVisible())
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

  if (index >= 0 && index < _modeInfoDar.getCount())
  {
    std::sscanf(_modeInfoDar[index], "%dx%dx%d", wide, tall, bpp);
    result = true;
  }

  return result;
}

void vgui::SurfaceBase::addModeInfo(int wide, int tall, int bpp)
{
  char* buf2, buf[256];

  std::sprintf(buf, "%dx%dx%d", wide, tall, bpp);
  buf2 = new char[std::strlen(buf)];
  std::strncpy(buf2, buf, 256);

  _modeInfoDar.addElement(buf2);
}

vgui::SurfaceBase::SurfaceBase(vgui::Panel* embeddedPanel)
  : _needsSwap{ true }, _embeddedPanel{ embeddedPanel }, _emulatedCursor{ new FakeImagePanel }, _currentCursor{ nullptr }
{
  _embeddedPanel->setSurfaceBaseTraverse(this);
  vgui::App::getInstance()->surfaceBaseCreated(this);

  _emulatedCursor->setImage(nullptr);
  _emulatedCursor->setParent(_embeddedPanel);
}

vgui::SurfaceBase::~SurfaceBase()
{
  vgui::App::getInstance()->surfaceBaseDeleted(this);
}

vgui::Panel* vgui::SurfaceBase::getPanel()
{
  return _embeddedPanel;
}

vgui::App* vgui::SurfaceBase::getApp()
{
  return vgui::App::getInstance();
}