#include <VGUI_HeaderPanel.h>

#include <VGUI_App.h>
#include <VGUI_ChangeSignal.h>
#include <VGUI_InputSignal.h>

namespace
{
  class HeaderPanelSignal : public vgui::InputSignal
  {
  private:
    vgui::HeaderPanel* _headerPanel;

  public:
    HeaderPanelSignal(vgui::HeaderPanel* headerPanel) : _headerPanel{ headerPanel } {}

    void cursorMoved(int x, int y, vgui::Panel* panel) { _headerPanel->privateCursorMoved(x, y, panel); }
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mousePressed(vgui::MouseCode code, vgui::Panel* panel) { _headerPanel->privateMousePressed(code, panel); }
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel) { _headerPanel->privateMouseReleased(code, panel); }
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
}

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

  for (auto i = 0; i < _sectionPanelDar.getCount(); ++i)
  {
    _sectionPanelDar[i]->getBounds(x, y, wide, tall);
    x += wide + _sliderWide;
  }

  _sectionPanelDar.addElement(panel);
  panel->setParent(_sectionLayer);
  panel->setBounds(x, y, wide, tall);

  getPaintSize(wide, tall);

  auto newSlider = new vgui::Panel{ 0, 0, _sliderWide, tall };
  newSlider->setPaintBorderEnabled(false);
  newSlider->setPaintBackgroundEnabled(false);
  newSlider->setPaintEnabled(false);
  newSlider->setPos(wide + x, 0);
  newSlider->addInputSignal(new HeaderPanelSignal{this});
  newSlider->setCursor(getApp()->getScheme()->getCursor(vgui::Scheme::SchemeCursor::scu_sizewe));
  newSlider->setParent(this);
  
  _sliderPanelDar.addElement(newSlider);

  fireChangeSignal();
  repaint();
}

vgui::HeaderPanel::HeaderPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _sliderWide{ 11 },
  _dragging{ false },
  _sectionLayer{ new vgui::Panel{ 0, 0, wide, tall } }
{
  _sectionLayer->setPaintBorderEnabled(false);
  _sectionLayer->setPaintBackgroundEnabled(false);
  _sectionLayer->setPaintEnabled(false);
  _sectionLayer->setParent(this);
}