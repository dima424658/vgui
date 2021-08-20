#include <VGUI_ConfigWizard.h>

#include <VGUI_Button.h>
#include <VGUI_LineBorder.h>
#include <VGUI_LoweredBorder.h>
#include <VGUI_TreeFolder.h>

vgui::ConfigWizard::ConfigWizard(int x, int y, int wide, int tall)
  : vgui::Panel{x, y, wide, tall}
{
  vgui::LineBorder *border = new vgui::LineBorder;
  setBorder(border);

  _treeFolder = new vgui::TreeFolder{"DonkeyFoo", 10, 10};
  _treeFolder->setParent(this);
  _treeFolder->setBorder(new vgui::LoweredBorder);

  _client = new vgui::Panel{80,30, 64, 64};
  _client->setParent(this);
  _client->setBorder(new vgui::LineBorder);

  _okButton = new vgui::Button{"Ok", 80, 80, 60, 20};
  _okButton->setParent(this);

  _cancelButton = new vgui::Button{"Cancel", 120, 80};
  _cancelButton->setParent(this);

  _applyButton = new vgui::Button{"Apply", 160, 80};
  _applyButton->setParent(this);

  _helpButton = new vgui::Button{"Help", 200, 80};
  _helpButton->setParent(this);
}

void vgui::ConfigWizard::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);

  getPaintSize(wide, tall);

  _treeFolder->setBounds(10, 10, 160, tall - 60);
  _client->setBounds(180, 10, wide - 190, tall - 60);

  _helpButton->setPos(wide - 80, tall - 25);
  _applyButton->setPos(wide - 150, tall - 25);
  _cancelButton->setPos(wide - 220, tall - 25);
  _okButton->setPos(wide - 290, tall - 25);
}