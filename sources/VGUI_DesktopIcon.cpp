#include <VGUI_DesktopIcon.h>

void vgui::DesktopIcon::setDesktop(vgui::DesktopIcon *const this, vgui::Desktop *desktop)
{
  this->_desktop = desktop;
}

void vgui::DesktopIcon::doActivate(vgui::DesktopIcon *const this)
{
  vgui::Desktop *v1; // eax

  v1 = this->_desktop;
  if ( v1 )
    (*((void (__cdecl **)(vgui::Desktop *, vgui::DesktopIcon *const))v1->_vptr_Panel + 127))(v1, this);
}

void vgui::DesktopIcon::setImage(vgui::DesktopIcon *const this, vgui::Image *image)
{
  int wide; // [esp+18h] [ebp-14h] BYREF
  int tall[4]; // [esp+1Ch] [ebp-10h] BYREF

  this->_image = image;
  if ( image )
  {
    (*((void (__cdecl **)(vgui::Image *, int *, int *))image->_vptr_Image + 2))(image, &wide, tall);
    (*((void (__cdecl **)(vgui::DesktopIcon *const, int, int))this->_vptr_Panel + 2))(this, wide, tall[0]);
  }
}

void vgui::DesktopIcon::paintBackground(vgui::DesktopIcon *const this)
{
  vgui::Image *v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // edi
  vgui::MiniApp *v5; // edx
  char buf[256]; // [esp+20h] [ebp-11Ch] BYREF
  int wide; // [esp+120h] [ebp-1Ch] BYREF
  int tall; // [esp+124h] [ebp-18h] BYREF
  int tWide; // [esp+128h] [ebp-14h] BYREF
  int tTall[4]; // [esp+12Ch] [ebp-10h] BYREF

  vgui::Panel::paintBackground(this);
  (*((void (__cdecl **)(vgui::DesktopIcon *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  v1 = this->_image;
  if ( v1 )
    (*((void (__cdecl **)(vgui::Image *, vgui::DesktopIcon *const))v1->_vptr_Image + 23))(v1, this);
  v2 = (*((int (__cdecl **)(vgui::DesktopIcon *const))this->_vptr_Panel + 83))(this);
  v3 = (*(int (__cdecl **)(int))(*(_DWORD *)v2 + 84))(v2);
  v4 = (*(int (__cdecl **)(int, int))(*(_DWORD *)v3 + 12))(v3, 2);
  (*((void (__cdecl **)(vgui::DesktopIcon *const, int))this->_vptr_Panel + 97))(this, 1);
  (*((void (__cdecl **)(vgui::DesktopIcon *const, int))this->_vptr_Panel + 99))(this, 1);
  v5 = this->_miniApp;
  if ( v5 )
  {
    (*v5->_vptr_MiniApp)(v5, buf, 256);
    (*(void (__cdecl **)(int, char *, int *, int *))(*(_DWORD *)v4 + 12))(v4, buf, &tWide, tTall);
    (*((void (__cdecl **)(vgui::DesktopIcon *const, int, int, int, _DWORD))this->_vptr_Panel + 100))(
      this,
      255,
      255,
      255,
      0);
    (*((void (__cdecl **)(vgui::DesktopIcon *const, int, int))this->_vptr_Panel + 101))(
      this,
      wide / 2 - tWide / 2,
      tall - 20);
    (*((void (__cdecl **)(vgui::DesktopIcon *const, char *, unsigned int))this->_vptr_Panel + 102))(
      this,
      buf,
      strlen(buf));
  }
}

void vgui::DesktopIcon::DesktopIcon(vgui::DesktopIcon *const this, vgui::MiniApp *miniApp, vgui::Image *image)
{
  vgui::InputSignal *v3; // eax
  int wide; // [esp+28h] [ebp-24h] BYREF
  int tall[4]; // [esp+2Ch] [ebp-20h] BYREF

  vgui::Panel::Panel(this, 0, 0, 32, 50);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::DesktopIcon + 2);
  this->_desktop = 0;
  this->_image = image;
  this->_miniApp = miniApp;
  if ( image )
  {
    (*((void (__cdecl **)(vgui::Image *, int *, int *))image->_vptr_Image + 2))(image, tall, &wide);
    (*((void (__cdecl **)(vgui::DesktopIcon *const, int, int))this->_vptr_Panel + 2))(this, tall[0], wide);
    (*((void (__cdecl **)(vgui::Image *, int *, int *))image->_vptr_Image + 2))(image, &wide, tall);
    vgui::Panel::setSize(this, wide, tall[0]);
  }
  v3 = (vgui::InputSignal *)operator new(0x1Cu);
  v3[1]._vptr_InputSignal = (int (**)(...))this;
  v3->_vptr_InputSignal = (int (**)(...))&off_43908;
  LOBYTE(v3[2]._vptr_InputSignal) = 0;
  vgui::Panel::addInputSignal(this, v3);
}

