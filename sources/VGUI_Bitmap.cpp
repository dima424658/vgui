#include <VGUI_Bitmap.h>

#include <VGUI_Panel.h>
#include <VGUI_SurfaceBase.h>

vgui::Bitmap::Bitmap()
  : _rgba{ nullptr },
  _id{},
  _uploaded{}
{
}

void vgui::Bitmap::setSize(int wide, int tall)
{
  vgui::Image::setSize(wide, tall);

  if (_rgba)
    delete [] _rgba;

  _rgba = new uchar[4 * wide * tall];
}

void vgui::Bitmap::setRGBA(int x, int y, uchar r, uchar g, uchar b, uchar a)
{
  if (_rgba)
  {
    int wide, tall;
    getSize(wide, tall);

    if (x >= 0 && x < wide && y >= 0 && y < tall)
    {
      _rgba[4 * x + 4 * y * wide] = r;
      _rgba[4 * x + 1 + 4 * y * wide] = g;
      _rgba[4 * x + 2 + 4 * y * wide] = b;
      _rgba[4 * wide * y + 3 + 4 * x] = a;
    }
  }
}

void vgui::Bitmap::paint(vgui::Panel* panel)
{
  bool v4; // zf
  vgui::Color color;
  int wide, tall;
  int r, g, b, a;
  int x, y;

  if (!_rgba)
  {
    getSize(wide, tall);

    if (!_id)
    {
      auto surface = panel->getSurfaceBase();
      if (surface)
        _id = surface->createNewTextureID();
    }

    if (!_uploaded)
    {
      drawSetTextureRGBA(_id, reinterpret_cast<char*>(_rgba), wide, tall);
      _uploaded = true;
    }

    getColor(color);
    color.getColor(r, g, b, a);

    drawSetTexture(_id);
    drawSetColor(r, g, b, a);
    getPos(x, y);
    drawTexturedRect(x, y, x + wide, y + tall);
  }
}