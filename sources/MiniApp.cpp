#include <VGUI_MiniApp.h>

#include <cstring>

void vgui::MiniApp::setName(const char *name)
{
  _name = std::strdup(name);
}

void vgui::MiniApp::getName(char *buf, int bufLen)
{
  std::strncpy(buf, _name, bufLen);
}

vgui::MiniApp::MiniApp()
{
  _name = "";
}

