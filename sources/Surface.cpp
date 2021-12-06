#include <VGUI_Surface.h>
#include <VGUI_Panel.h>

#include <VGUI_Bitmap.h>
#include <VGUI_Font.h>
#include <VGUI_ImagePanel.h>
#include "handlers/BaseFontPlat.h"
#include "handlers/SurfacePlat.hpp"

vgui::Surface::Surface(vgui::Panel* embeddedPanel)
  : vgui::SurfaceBase{ embeddedPanel }
{
  createPlat();
  recreateContext();
}

void  vgui::Surface::setTitle(const char* title)
{

}

void  vgui::Surface::setWindowedMode()
{

}

void  vgui::Surface::setAsTopMost(bool state)
{

}

bool vgui::Surface::isWithin(int x, int y)
{
  return false;
}

void  vgui::Surface::GetMousePos(int& x, int& y)
{

}

void vgui::Surface::drawSetColor(int r, int g, int b, int a)
{

}

void vgui::Surface::drawFilledRect(int x0, int y0, int x1, int y1)
{

}

void vgui::Surface::drawSetTextColor(int r, int g, int b, int a)
{

}

void vgui::Surface::drawSetTextPos(int x, int y)
{

}

void vgui::Surface::drawPrintText(const char *text, int textLen)
{

}

void vgui::Surface::drawTexturedRect(int x0, int y0, int x1, int y1)
{

}

void vgui::Surface::invalidate(vgui::Panel *panel)
{

}

void vgui::Surface::enableMouseCapture(bool state)
{

}

void vgui::Surface::swapBuffers()
{

}

void vgui::Surface::createPopup(vgui::Panel* embeddedPanel)
{
  embeddedPanel->setParent(nullptr);
  auto v2 = new vgui::Surface{ embeddedPanel }; // ???
}

bool vgui::Surface::createPlat()
{
  return true;
}

bool vgui::Surface::recreateContext()
{
  int wide, tall;
  getPanel()->getSize(wide, tall);

  return true;
}

void vgui::Surface::drawOutlinedRect(int x0, int y0, int x1, int y1)
{
  drawFilledRect(x0, y0, x1, y0 + 1);
  drawFilledRect(x0, y1 - 1, x1, y1);
  drawFilledRect(x0, y0 + 1, x0 + 1, y1 - 1);
  drawFilledRect(x1 - 1, y0 + 1, x1, y1 - 1);
}

int vgui::Surface::createNewTextureID()
{
  static int staticBindIndex = 2700; // ??? 
  return staticBindIndex++;
}

struct Texture
{
  int _id;
};

constexpr int staticTextureMaxCount = 128;

static Texture* staticTextureCurrent;
static int staticTextureCount = 0;
static Texture staticTexture[staticTextureMaxCount];

void vgui::Surface::drawSetTexture(int id)
{
  if (staticTextureCurrent && id == staticTextureCurrent->_id)
    return;

  for (auto i = 0; i < staticTextureCount; ++i)
    if (staticTexture[i]._id == id)
      staticTextureCurrent = &staticTexture[i];
}

void vgui::Surface::pushMakeCurrent(vgui::Panel* panel, bool useInsets)
{
  int inset[4]{ 0, 0, 0, 0 }, absThis[4], absPanel[4], clipRect[4];

  if (useInsets)
    panel->getInset(inset[0], inset[1], inset[2], inset[3]);

  getPanel()->getAbsExtents(absThis[0], absThis[1], absThis[2], absThis[3]);
  panel->getAbsExtents(absPanel[0], absPanel[1], absPanel[2], absPanel[3]);
  panel->getClipRect(clipRect[0], clipRect[1], clipRect[2], clipRect[3]);
}

void vgui::Surface::popMakeCurrent(vgui::Panel* panel)
{

}

void vgui::Surface::applyChanges()
{

}

void vgui::Surface::drawSetTextFont(vgui::Font* font)
{
  if (font)
    font->_plat->drawSetTextFont(_plat);
}

bool vgui::Surface::hasFocus()
{
  return true;
}

int vgui::Surface::getModeInfoCount()
{
  addModeInfo(640, 480, 16);
  addModeInfo(800, 600, 16);

  return getModeInfoCount();
}

void vgui::Surface::drawSetTextureRGBA(int id, const char* rgba, int wide, int tall)
{
  if (staticTextureCurrent && id == staticTextureCurrent->_id)
    return;

  for (auto i = 0; i < staticTextureCount; ++i)
    if (staticTexture[i]._id == id)
      return;

  if (staticTextureCount <= staticTextureMaxCount - 1)
    staticTexture[staticTextureCount++]._id = id;
}

void vgui::Surface::setCursor(vgui::Cursor* cursor)
{
  _currentCursor = cursor;

  if (cursor)
  {
    _emulatedCursor->setImage(cursor->getBitmap());
    cursor->getDefaultCursor();
  }
  else
  {
    _emulatedCursor->setImage(nullptr);
  }
}

bool vgui::Surface::setFullscreenMode(int wide, int tall, int bpp)
{
  if (!_plat->isFullscreen
    || _plat->fullscreenInfo[0] != wide
    || _plat->fullscreenInfo[1] != tall
    || _plat->fullscreenInfo[2] != bpp)
  {
    if (_modeInfoDar.getCount() == 0)
      getModeInfoCount();

    return false;
  }

  return true;
}

