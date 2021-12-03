#include <VGUI_DesktopIcon.h>

#include <VGUI_Image.h>
#include <VGUI_InputSignal.h>
#include <VGUI_Desktop.h>
#include <VGUI_App.h>
#include <VGUI_MiniApp.h>
#include <VGUI_Font.h>
#include <VGUI_MouseCode.h>

namespace
{
  class FooHandler : public vgui::InputSignal
  {
  private:
    bool _dragging;
    int _dragStart[2];
    int _dragOrgPos[2];
    vgui::DesktopIcon* _desktopIcon;

  public:
    FooHandler(vgui::DesktopIcon* desktopIcon) : _desktopIcon{ desktopIcon } {}
    void cursorMoved(int x, int y, vgui::Panel* panel)
    {
      if (_dragging)
      {
        panel->getApp()->getCursorPos(x, y);

        _desktopIcon->setPos(
          _dragOrgPos[0] + x - _dragStart[0],
          _dragOrgPos[1] + y - _dragStart[1]);

        auto parent = _desktopIcon->getParent();
        if (parent)
          parent->requestFocusPrev();
      }
    }
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
    {
      panel->getApp()->getCursorPos(_dragStart[0], _dragStart[1]);
      panel->getApp()->setMouseCapture(panel);

      _desktopIcon->getPos(_dragOrgPos[0], _dragOrgPos[1]);
      _desktopIcon->requestFocus();
    }
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel)
    {
      _desktopIcon->doActivate();
    }
    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel)
    {
      auto app = panel->getApp();

      _dragging = false;
      app->setMouseCapture(nullptr);
    }
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
};

vgui::DesktopIcon::DesktopIcon(vgui::MiniApp* miniApp, vgui::Image* image)
  : vgui::Panel{ 0, 0, 32, 50 },
  _desktop{ nullptr },
  _miniApp{ miniApp },
  _image{ image }
{
  int wide;
  int tall;

  if (image)
  {
    image->getSize(wide, tall);
    setSize(wide, tall);
  }

  addInputSignal(new FooHandler{this});
}

void vgui::DesktopIcon::doActivate()
{
  if (_desktop)
    _desktop->iconActivated(this);
}

void vgui::DesktopIcon::setImage(vgui::Image* image)
{
  int wide;
  int tall;

  _image = image;
  if (image)
  {
    _image->getSize(wide, tall);
    setSize(wide, tall);
  }
}

void vgui::DesktopIcon::setDesktop(vgui::Desktop* desktop)
{
  _desktop = desktop;
}

vgui::MiniApp* vgui::DesktopIcon::getMiniApp()
{
  return _miniApp;
}

void vgui::DesktopIcon::paintBackground()
{
  char buf[256];
  int wide, tall;
  int tWide, tTall;

  vgui::Panel::paintBackground();

  getPaintSize(wide, tall);
  if (_image)
    _image->doPaint(this);

  auto font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary2);

  drawSetTextFont(vgui::Scheme::SchemeFont::sf_primary1);
  drawSetTextColor(vgui::Scheme::SchemeColor::sc_black);

  if (_miniApp)
  {
    _miniApp->getName(buf, 256);
    font->getTextSize(buf, tWide, tTall);

    drawSetTextColor(255, 255, 255, 0);
    drawSetTextPos(wide / 2 - tWide / 2, tall - 20);
    drawPrintText(buf, strlen(buf));
  }
}
