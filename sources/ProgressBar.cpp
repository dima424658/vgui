#include <VGUI_ProgressBar.h>

#include <cmath>

void vgui::ProgressBar::paintBackground()
{
  int segmentWide;
  int wide, tall;

  getPaintSize(wide, tall);
  drawSetColor(vgui::Scheme::SchemeColor::sc_secondary2);
  drawFilledRect(0, 0, wide, tall);

  int offset = 0;
  segmentWide = wide / _segmentCount - 2;
  for (auto i = 1; i <= _progress; ++i)
  {
    drawSetColor(0, 0, 100, 0);
    drawFilledRect(offset, 0, offset + segmentWide, tall);
    offset += wide / _segmentCount;
  }

  if (_segmentCount > _progress) // ???
  {
    drawSetColor(0, 0, 100, 0);
    drawFilledRect(offset, 0, offset + segmentWide, tall);
  }
}

int vgui::ProgressBar::getSegmentCount()
{
  return _segmentCount;
}

void vgui::ProgressBar::setProgress(float progress)
{
  if (_progress != progress)
  {
    _progress = progress;
    repaint();
  }
}

vgui::ProgressBar::ProgressBar(int segmentCount)
  : vgui::Panel{ 0, 0, 10, 110 }
{
  _progress = 0.0f;
  _segmentCount = segmentCount;
}

