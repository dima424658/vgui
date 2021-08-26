#include <VGUI_FileInputStream.h>

vgui::FileInputStream::FileInputStream(const char *fileName, bool textMode)
{
  if (textMode)
    _fp = fopen(fileName, "rt");
  else
    _fp = fopen(fileName, "rb");
}

void vgui::FileInputStream::seekStart(bool &success)
{
  if (_fp)
    success = fseek(_fp, 0, 0) != 0;
  else
    success = false;
}

void vgui::FileInputStream::seekRelative(int count, bool &success)
{
  if (_fp)
    success = fseek(_fp, 1, count) != 0;
  else
    success = false;
}

void vgui::FileInputStream::seekEnd(bool &success)
{
  if (_fp)
    success = fseek(_fp, 2, 0) != 0;
  else
    success = false;
}

int vgui::FileInputStream::getAvailable(bool &success)
{
  success = false;
  return 0;
}

uchar vgui::FileInputStream::readUChar(bool &success)
{
  uchar ret;

  if (_fp)
  {
    success = fread(&ret, 1u, 1u, _fp) == 1;
    return ret;
  }
  else
  {
    success = false;
    return 0;
  }
}

void vgui::FileInputStream::readUChar(uchar *buf, int count, bool &success)
{
  if (_fp)
    success = fread(buf, count, 1u, _fp) == 1;
  else
    success = false;
}

void vgui::FileInputStream::close(bool &success)
{
  if (_fp)
    success = fclose(_fp) == 0;
  else
    success = false;
}

void vgui::FileInputStream::close()
{
  bool success;
  close(success);
}
