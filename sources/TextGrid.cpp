#include <algorithm>
#include <cstdarg>

#include <VGUI_TextGrid.h>

#include <VGUI_App.h>
#include <VGUI_Scheme.h>
#include <VGUI_Font.h>

void vgui::TextGrid::setXY(int x, int y)
{
  _xy[0] = x;
  _xy[1] = y;
}

void vgui::TextGrid::paintBackground()
{
  int fwide, ftall;
  int abc[3];
  int r, g, b, a;
  int x, y;

  vgui::Panel::paintBackground();

  auto font = getApp()->getScheme()->getFont(vgui::Scheme::SchemeFont::sf_primary2);
  font->getCharABCwide('W', abc[0], abc[1], abc[2]);

  fwide = abc[2] + abc[1] + abc[0];
  ftall = font->getTall();

  drawSetTextFont(vgui::Scheme::SchemeFont::sf_primary2);


  if (_gridSize[1] <= 0)
    return;

  for (auto i = 0; i < _gridSize[1]; ++i)
  {
    if (_gridSize[0] > 0)
    {
      x = 0;

      for (auto j = 0; j < _gridSize[0]; ++j)
      {
        auto ch = _grid[7 * j + 7 * i * _gridSize[0]];
        if (ch)
        {
          getFgColor(r, g, b, a);
          drawSetTextColor(r, g, b, a);
          drawPrintChar(x, y, ch);
        }

        x += fwide;
      }
    }
    y += ftall;
  }
}

int vgui::TextGrid::printf(const char* format, ...)
{
  std::va_list va;
  va_start(va, format);

  return vprintf(format, va);
}

int vgui::TextGrid::vprintf(const char* format, va_list argList)
{
  constexpr auto szBuf = 2048u;
  char buf[szBuf];

  int ret = vsprintf(buf, format, argList);

  for (auto i = 0; i < szBuf && buf[i] != '\0'; ++i)
  {
    if (buf[i] == '\n')
      newLine();
    else if ((_xy[0] >= 0) && (_xy[0] < _gridSize[0]) && (_xy[1] >= 0 && _xy[1] < _gridSize[1]))
    {
      _grid[7 * _xy[1] * _gridSize[0] + 7 * _xy[0]] = buf[i];
      ++_xy[0];
    }
  }

  repaint();
  return ret;
}

void vgui::TextGrid::newLine()
{
  if (_xy[1] == _gridSize[1] - 1)
  {
    if (_gridSize[1] > 1)
    {
      auto szGrid = _gridSize[0] - _xy[0];
      auto ptrGrid = &_grid[7 * _xy[0] + 7 * _gridSize[0] * _xy[1]];
      std::fill(ptrGrid, ptrGrid + szGrid, '\0');
      
      for (auto i = 1; i < _gridSize[1] ; ++i)
      {
        szGrid = 7 * _gridSize[0];
        auto fromGrid = &_grid[7 * _gridSize[0] * (i - 1)];
        ptrGrid = &_grid[7 * _gridSize[0] * i - _gridSize[0] * i];
        
        std::copy(ptrGrid, ptrGrid + szGrid, fromGrid);
      }

      szGrid = 7 * _gridSize[0];
      ptrGrid = &_grid[7 * _gridSize[0] * _xy[1]];
      std::fill(ptrGrid, ptrGrid + szGrid, '\0');
    }
    _xy[0] = 0;
  }
  else
  {
    _xy[0] = 0;
    ++_xy[1];
  }
}

void vgui::TextGrid::setGridSize(int wide, int tall)
{
  if (tall > 0 && wide > 0)
  {
    if (_grid)
      delete[] _grid;

    _grid = new char[7 * tall * wide]{};

    _gridSize[0] = wide;
    _gridSize[1] = tall;

  }
}

vgui::TextGrid::TextGrid(int gridWide, int gridTall, int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall },
  _grid{ nullptr },
  _gridSize{ 0, 0 },
  _xy{ 0, 0 }
{
  setBgColor(255, 255, 255, 0);
  setFgColor(0, 0, 0, 0);
  setGridSize(wide, tall);
}
