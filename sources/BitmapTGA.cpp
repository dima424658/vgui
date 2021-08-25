#include <VGUI_BitmapTGA.h>

#include <VGUI_DataInputStream.h>


vgui::BitmapTGA::BitmapTGA(vgui::InputStream *is, bool invertAlpha)
{
  loadTGA(is, invertAlpha);
}

bool vgui::BitmapTGA::loadTGA(vgui::InputStream *is, bool invertAlpha)
{
  uchar column;
  int columna;
  uchar packetSize;
  uchar packetSizea;
  int packetSizeb;
  uchar j;
  uchar ja;
  uchar pixel_size;
  bool success = false;

  if (!is)
    return false;

  vgui::DataInputStream dis{is};

  column = dis.readUChar(success);
  if (!success)
    return false;

  packetSize = dis.readUChar(success);
  if (!success)
    return false;

  j = dis.readUChar(success);
  if (!success)
    return false;

  dis.readUShort(success);
  if (!success)
    return false;

  dis.readUShort(success);
  if (!success)
    return false;

  dis.readUChar(success);
  if (!success)
    return false;

  dis.readUShort(success);
  if (!success)
    return false;

  dis.readUShort(success);
  if (!success)
    return false;

  auto x = dis.readUShort(success);
  if (!success)
    return false;

  auto y = dis.readUShort(success);
  if (!success)
    return false;

  pixel_size = dis.readUChar(success);
  if (!success)
    return false;

  dis.readUChar(success);
  if (!success)
    return false;

  if (!success)
    return false;

  if (j != 10 && j != 2)
    return false;

  if (packetSize)
    return false;

  if (pixel_size != 32 && pixel_size != 24)
    return false;

  setSize(x, y);
  if (!_rgba)
    return false;

  if (column)
    dis.seekRelative(column, success);

  --y;

  if (j == 2)
  {
    packetSizeb = x * 4 * y;
    for (; y != -1; --y)
    {
      auto ptr = &_rgba[packetSizeb];

      for (auto columnb = 0; columnb < x; ++columnb)
      {
        ptr[2] = dis.readUChar(success);
        if (!success)
          return false;

        ptr[1] = dis.readUChar(success);
        if (!success)
          return false;

        ptr[0] = dis.readUChar(success);
        if (!success)
          return false;

        if (pixel_size == 24)
        {
          ptr[3] = -1;
        }
        else
        {
          auto alpha = dis.readUChar(success);
          if (!success)
            return false;
          ptr[3] = invertAlpha ? alpha : ~alpha;
        }

        ptr += 4;
      }
    }

    packetSizeb += -4 * x;
  }
  else
  {
    for (; y != -1; --y)
    {
      columna = 0;
      auto ptr = &_rgba[4 * y * x];
    LABEL_25:
      while (columna < x)
      {
        auto v8 = dis.readUChar(success);
        if (!success)
          return false;
        packetSizea = (v8 & 0x7F) + 1;
        ja = 0;
        if (v8 >= 0)
        {
          while (true)
          {
            ptr[2] = dis.readUChar(success);
            if (!success)
              return false;

            ptr[1] = dis.readUChar(success);
            if (!success)
              return false;

            ptr[0] = dis.readUChar(success);
            if (!success)
              return false;

            if (pixel_size == 24)
            {
              ptr[3] = -1;
            }
            else
            {
              auto alpha = dis.readUChar(success);
              if (!success)
                return false;
              ptr[3] = invertAlpha ? alpha : ~alpha;
            }

            if (++columna == x)
            {
              if (!y)
                return true;

              --y;
              ptr = &this->_rgba[4 * y * columna];
              columna = 0;
            }

            if (packetSizea <= ++ja)
              goto LABEL_25;
          }
        }

        auto red = dis.readUChar(success);
        if (!success)
          return false;
        auto green = dis.readUChar(success);
        if (!success)
          return false;
        auto blue = dis.readUChar(success);
        if (!success)
          return false;

        int alpha;
        if (pixel_size == 24)
          auto alpha = -!invertAlpha;
        else
        {
          alpha = dis.readUChar(success);
          if (!success)
            return false;
          if (invertAlpha)
            alpha = ~alpha;
        }

        for (auto i = 0; i < packetSizea; ++i)
        {
          ++columna;
          ptr[0] = red;
          ptr[1] = green;
          ptr[2] = blue;
          ptr[3] = alpha;
          ptr += 4;

          if (columna == x)
          {
            if (!y)
              return true;
            ptr = &_rgba[4 * --y * columna];
            columna = 0;
          }
        }
      }
    }
  }

  return true;
}