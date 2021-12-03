#include <algorithm>
#include <VGUI_ScrollPanel.h>
#include <VGUI_ScrollBar.h>

void vgui::ScrollPanel::setScrollBarVisible(bool horizontal, bool vertical)
{
  _horizontalScrollBar->setVisible(horizontal);
  _verticalScrollBar->setVisible(vertical);

  validate();
}

void vgui::ScrollPanel::setScrollValue(int horizontal, int vertical)
{
  _horizontalScrollBar->setValue(horizontal);
  _verticalScrollBar->setValue(vertical);
  recomputeScroll();
}

void vgui::ScrollPanel::getScrollValue(int& horizontal, int& vertical)
{
  horizontal = _horizontalScrollBar->getValue();
  vertical = _verticalScrollBar->getValue();
}

void vgui::ScrollPanel::recomputeScroll()
{
  int x, y;

  getScrollValue(x, y);
  _client->setPos(-x, -y);
  _clientClip->repaint();
}

void vgui::ScrollPanel::setScrollBarAutoVisible(bool horizontal, bool vertical)
{
  _autoVisible[0] = horizontal;
  _autoVisible[1] = vertical;

  validate();
}

void vgui::ScrollPanel::recomputeClientSize()
{
  int wide = 0, tall = 0;

  for (auto i = 0; i < _client->getChildCount(); ++i)
  {
    auto child = _client->getChild(i);
    if (child->isVisible())
    {
      int x, y;
      int w, t;

      child->getPos(x, y);
      child->getVirtualSize(w, t);

      tall = std::max(tall, y + t);
      wide = std::max(wide, x + w);
    }
  }

  setSize(wide, tall);

  _horizontalScrollBar->setRange(0, _client->getWide() - _clientClip->getWide());
  _horizontalScrollBar->setRangeWindow(_client->getWide());

  _verticalScrollBar->setRange(0, _client->getTall() - _clientClip->getTall());
  _horizontalScrollBar->setRangeWindow(_client->getTall());
}

void vgui::ScrollPanel::validate()
{
  int wide, tall;

  _horizontalScrollBar->setRangeWindowEnabled(true);
  _verticalScrollBar->setRangeWindowEnabled(true);

  getSize(wide, tall);

  setSize(wide, tall); // ???
  setSize(wide, tall);
  setSize(wide, tall);
  setSize(wide, tall);
}

void vgui::ScrollPanel::setSize(int wide, int tall)
{
  vgui::Panel::setSize(wide, tall);
  getPaintSize(wide, tall);

  if (_autoVisible[0])
    _horizontalScrollBar->setVisible(!_horizontalScrollBar->hasFullRange());

  if (_autoVisible[1])
    _verticalScrollBar->setVisible(!_verticalScrollBar->hasFullRange());

  if (_verticalScrollBar->isVisible())
    wide -= _verticalScrollBar->getWide();

  if (_horizontalScrollBar->isVisible())
    tall -= _horizontalScrollBar->getTall();


  _verticalScrollBar->setBounds(wide, 0, _verticalScrollBar->getWide(), tall);
  _horizontalScrollBar->setBounds(0, tall, wide, _horizontalScrollBar->getTall());
  _clientClip->setSize(wide, tall);

  recomputeClientSize();
  repaint();
}

vgui::ScrollPanel::ScrollPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _clientClip{ new vgui::Panel{ 0, 0, wide - 16, tall - 16 } },
  _client{ new vgui::Panel{ 0, 0, 2 * wide, 2 * tall } },
  _horizontalScrollBar{ new vgui::ScrollBar{ 0, tall - 16, wide - 16, 16, false } },
  _verticalScrollBar{ new vgui::ScrollBar{ wide - 16, 0, 16, tall - 16, true } },
  _autoVisible{true, true}
{
  setPaintBorderEnabled(true);
  setPaintBackgroundEnabled(false);
  setPaintEnabled(true);

  _clientClip->setParent(this);
  _clientClip->setBgColor({ 0, 128, 0, 0 });
  _clientClip->setPaintBorderEnabled(true);
  _clientClip->setPaintBackgroundEnabled(false);
  _clientClip->setPaintEnabled(false);

  _client->setParent(_clientClip);
  _clientClip->setPaintBorderEnabled(true);
  _clientClip->setPaintBackgroundEnabled(false);
  _clientClip->setPaintEnabled(false);

  _horizontalScrollBar->setParent(this);
  _horizontalScrollBar->addIntChangeSignal(nullptr);
  _horizontalScrollBar->setVisible(false);

  _verticalScrollBar->setParent(this);
  _verticalScrollBar->addIntChangeSignal(nullptr);
  _verticalScrollBar->setVisible(false);

  validate();
}

