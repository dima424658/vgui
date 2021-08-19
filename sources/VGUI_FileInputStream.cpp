#include <VGUI_FileInputStream.h>

int vgui::FileInputStream::getAvailable(vgui::FileInputStream *const this, bool *const success)
{
  *success = 0;
  return 0;
}

void vgui::FileInputStream::close(vgui::FileInputStream *const this)
{
  bool success[13]; // [esp+1Fh] [ebp-Dh] BYREF

  (*((void (__cdecl **)(vgui::FileInputStream *const, bool *))this->_vptr_InputStream + 6))(this, success);
}

void vgui::FileInputStream::close(vgui::FileInputStream *const this, bool *const success)
{
  if ( this->_fp )
    *success = fclose(this->_fp) == 0;
  else
    *success = 0;
}

void vgui::FileInputStream::readUChar(vgui::FileInputStream *const this, uchar *buf, int count, bool *const success)
{
  if ( this->_fp )
    *success = fread(buf, count, 1u, this->_fp) == 1;
  else
    *success = 0;
}

uchar vgui::FileInputStream::readUChar(vgui::FileInputStream *const this, bool *const success)
{
  FILE *v2; // eax
  bool v3; // zf
  uchar ret[13]; // [esp+1Fh] [ebp-Dh] BYREF

  v2 = this->_fp;
  if ( v2 )
  {
    v3 = fread(ret, 1u, 1u, this->_fp) == 1;
    LOBYTE(v2) = ret[0];
    *success = v3;
  }
  else
  {
    *success = 0;
  }
  return (uint8_t)v2;
}

void vgui::FileInputStream::seekEnd(vgui::FileInputStream *const this, bool *const success)
{
  FILE *stream; // eax

  stream = this->_fp;
  if ( stream )
    *success = fseek(stream, 2, 0) != 0;
  else
    *success = 0;
}

void vgui::FileInputStream::seekRelative(vgui::FileInputStream *const this, int count, bool *const success)
{
  if ( this->_fp )
    *success = fseek(this->_fp, 1, count) != 0;
  else
    *success = 0;
}

void vgui::FileInputStream::seekStart(vgui::FileInputStream *const this, bool *const success)
{
  FILE *stream; // eax

  stream = this->_fp;
  if ( stream )
    *success = fseek(stream, 0, 0) != 0;
  else
    *success = 0;
}

void vgui::FileInputStream::FileInputStream(vgui::FileInputStream *const this, const char *fileName, bool textMode)
{
  this->_vptr_InputStream = (int (**)(...))(&`vtable for'vgui::FileInputStream + 2);
  if ( textMode )
    this->_fp = fopen(fileName, "rt");
  else
    this->_fp = fopen(fileName, "rb");
}

