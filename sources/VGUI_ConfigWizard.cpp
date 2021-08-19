#include <VGUI_ConfigWizard.h>

void vgui::ConfigWizard::setSize(vgui::ConfigWizard *const this, int wide, int tall)
{
  vgui::Panel::setSize(this, wide, tall);
  (*((void (__cdecl **)(vgui::ConfigWizard *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, &tall);
  (*((void (__cdecl **)(vgui::TreeFolder *, int, int, int, int))this->_treeFolder->_vptr_Panel + 4))(
    this->_treeFolder,
    10,
    10,
    160,
    tall - 60);
  (*((void (__cdecl **)(vgui::Panel *, int, int, int, int))this->_client->_vptr_Panel + 4))(
    this->_client,
    180,
    10,
    wide - 190,
    tall - 60);
  (**(void (__cdecl ***)(vgui::Button *, int, int))this->_helpButton)(this->_helpButton, wide - 80, tall - 25);
  (**(void (__cdecl ***)(vgui::Button *, int, int))this->_applyButton)(this->_applyButton, wide - 150, tall - 25);
  (**(void (__cdecl ***)(vgui::Button *, int, int))this->_cancelButton)(this->_cancelButton, wide - 220, tall - 25);
  (**(void (__cdecl ***)(vgui::Button *, int, int))this->_okButton)(this->_okButton, wide - 290, tall - 25);
}

void vgui::ConfigWizard::ConfigWizard(vgui::ConfigWizard *const this, int x, int y, int wide, int tall)
{
  vgui::LineBorder *border; // esi
  vgui::TreeFolder *v6; // esi
  void (__cdecl *v7)(vgui::TreeFolder *, vgui::LoweredBorder *); // esi
  vgui::LoweredBorder *v8; // edi
  vgui::Panel *v9; // esi
  void (__cdecl *v10)(vgui::Panel *, vgui::LineBorder *); // esi
  vgui::LineBorder *v11; // edi
  vgui::Button *v12; // esi
  vgui::Button *v13; // esi
  vgui::Button *v14; // esi
  vgui::Button *v15; // esi

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::ConfigWizard + 2);
  border = (vgui::LineBorder *)operator new(0x44u);
  vgui::LineBorder::LineBorder(border);
  vgui::Panel::setBorder(this, border);
  v6 = (vgui::TreeFolder *)operator new(0xBCu);
  vgui::TreeFolder::TreeFolder(v6, "DonkeyFoo", 10, 10);
  this->_treeFolder = v6;
  (*((void (__cdecl **)(vgui::TreeFolder *, vgui::ConfigWizard *const))v6->_vptr_Panel + 16))(v6, this);
  v7 = (void (__cdecl *)(vgui::TreeFolder *, vgui::LoweredBorder *))*((_DWORD *)this->_treeFolder->_vptr_Panel + 53);
  v8 = (vgui::LoweredBorder *)operator new(0x38u);
  vgui::LoweredBorder::LoweredBorder(v8);
  v7(this->_treeFolder, v8);
  v9 = (vgui::Panel *)operator new(0xBCu);
  vgui::Panel::Panel(v9, 80, 30, 64, 64);
  this->_client = v9;
  (*((void (__cdecl **)(vgui::Panel *, vgui::ConfigWizard *const))v9->_vptr_Panel + 16))(v9, this);
  v10 = (void (__cdecl *)(vgui::Panel *, vgui::LineBorder *))*((_DWORD *)this->_client->_vptr_Panel + 53);
  v11 = (vgui::LineBorder *)operator new(0x44u);
  vgui::LineBorder::LineBorder(v11);
  v10(this->_client, v11);
  v12 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v12, "Ok", 80, 80, 60, 20);
  this->_okButton = v12;
  (*(void (__cdecl **)(vgui::Button *, vgui::ConfigWizard *const))(*(_DWORD *)v12->baseclass_0 + 64))(v12, this);
  v13 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v13, "Cancel", 120, 80);
  this->_cancelButton = v13;
  (*(void (__cdecl **)(vgui::Button *, vgui::ConfigWizard *const))(*(_DWORD *)v13->baseclass_0 + 64))(v13, this);
  v14 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v14, "Apply", 160, 80);
  this->_applyButton = v14;
  (*(void (__cdecl **)(vgui::Button *, vgui::ConfigWizard *const))(*(_DWORD *)v14->baseclass_0 + 64))(v14, this);
  v15 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v15, "Help", 200, 80);
  this->_helpButton = v15;
  (*(void (__cdecl **)(vgui::Button *, vgui::ConfigWizard *const))(*(_DWORD *)v15->baseclass_0 + 64))(v15, this);
}

