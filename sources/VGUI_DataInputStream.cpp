#include <VGUI_DataInputStream.h>

void `virtual thunk to'vgui::DataInputStream::seekStart(vgui::DataInputStream *this, bool *a2)
{
  vgui::DataInputStream::seekStart(
    (vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 12)),
    a2);
}

void vgui::DataInputStream::seekStart(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    (*v2->_vptr_InputStream)(this->_is);
  else
    *success = 0;
}

void `virtual thunk to'vgui::DataInputStream::seekRelative(vgui::DataInputStream *this, int a2, bool *a3)
{
  vgui::DataInputStream::seekRelative(
    (vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 16)),
    a2,
    a3);
}

void vgui::DataInputStream::seekRelative(vgui::DataInputStream *const this, int count, bool *const success)
{
  vgui::InputStream *v3; // eax

  v3 = this->_is;
  if ( v3 )
    (*((void (__cdecl **)(vgui::InputStream *))v3->_vptr_InputStream + 1))(this->_is);
  else
    *success = 0;
}

void `virtual thunk to'vgui::DataInputStream::seekEnd(vgui::DataInputStream *this, bool *a2)
{
  vgui::DataInputStream::seekEnd((vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 20)), a2);
}

void vgui::DataInputStream::seekEnd(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    (*((void (__cdecl **)(vgui::InputStream *))v2->_vptr_InputStream + 2))(this->_is);
  else
    *success = 0;
}

int `virtual thunk to'vgui::DataInputStream::getAvailable(vgui::DataInputStream *this, bool *a2)
{
  return vgui::DataInputStream::getAvailable(
           (vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 24)),
           a2);
}

int vgui::DataInputStream::getAvailable(vgui::DataInputStream *const this, bool *const success)
{
  int result; // eax

  result = (int)this->_is;
  if ( result )
    return (*(int (__cdecl **)(vgui::InputStream *))(*(_DWORD *)result + 12))(this->_is);
  *success = 0;
  return result;
}

void `virtual thunk to'vgui::DataInputStream::readUChar(vgui::DataInputStream *this, uint8_t *a2, int a3, bool *a4)
{
  vgui::DataInputStream::readUChar(
    (vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 32)),
    a2,
    a3,
    a4);
}

void vgui::DataInputStream::readUChar(vgui::DataInputStream *const this, uchar *buf, int count, bool *const success)
{
  vgui::InputStream *v4; // eax

  v4 = this->_is;
  if ( v4 )
    (*((void (__cdecl **)(vgui::InputStream *))v4->_vptr_InputStream + 5))(this->_is);
  else
    *success = 0;
}

void `virtual thunk to'vgui::DataInputStream::close(vgui::DataInputStream *this, bool *a2)
{
  vgui::DataInputStream::close((vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 36)), a2);
}

void vgui::DataInputStream::close(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    (*((void (__cdecl **)(vgui::InputStream *))v2->_vptr_InputStream + 6))(this->_is);
  else
    *success = 0;
}

void vgui::DataInputStream::close(vgui::DataInputStream *const this)
{
  bool success[13]; // [esp+1Fh] [ebp-Dh] BYREF

  (*(void (__cdecl **)(vgui::DataInputStream *const, bool *))(*(_DWORD *)this->gap0 + 24))(this, success);
}

bool vgui::DataInputStream::readBool(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    LOBYTE(v2) = (*((uint8_t (__cdecl **)(vgui::InputStream *, bool *const))v2->_vptr_InputStream + 4))(
                   v2,
                   success) != 0;
  else
    *success = 0;
  return (char)v2;
}

char vgui::DataInputStream::readChar(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    LOBYTE(v2) = (*((int (__cdecl **)(vgui::InputStream *))v2->_vptr_InputStream + 4))(this->_is);
  else
    *success = 0;
  return (char)v2;
}

uchar `virtual thunk to'vgui::DataInputStream::readUChar(vgui::DataInputStream *this, bool *a2)
{
  return vgui::DataInputStream::readUChar(
           (vgui::DataInputStream *)((char *)this + *(_DWORD *)(*(_DWORD *)this->gap0 - 28)),
           a2);
}

uchar vgui::DataInputStream::readUChar(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax

  v2 = this->_is;
  if ( v2 )
    LOBYTE(v2) = (*((int (__cdecl **)(vgui::InputStream *))v2->_vptr_InputStream + 4))(this->_is);
  else
    *success = 0;
  return (uint8_t)v2;
}

__int16 vgui::DataInputStream::readShort(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax
  __int16 ret[7]; // [esp+1Eh] [ebp-Eh] BYREF

  v2 = this->_is;
  if ( v2 )
  {
    (*((void (__cdecl **)(vgui::InputStream *, __int16 *, int, bool *const))v2->_vptr_InputStream + 5))(
      v2,
      ret,
      2,
      success);
    LOWORD(v2) = ret[0];
  }
  else
  {
    *success = 0;
  }
  return (__int16)v2;
}

ushort vgui::DataInputStream::readUShort(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax
  ushort ret[7]; // [esp+1Eh] [ebp-Eh] BYREF

  v2 = this->_is;
  if ( v2 )
  {
    (*((void (__cdecl **)(vgui::InputStream *, ushort *, int, bool *const))v2->_vptr_InputStream + 5))(
      v2,
      ret,
      2,
      success);
    LOWORD(v2) = ret[0];
  }
  else
  {
    *success = 0;
  }
  return (unsigned __int16)v2;
}

int vgui::DataInputStream::readInt(vgui::DataInputStream *const this, bool *const success)
{
  int result; // eax
  int ret[4]; // [esp+1Ch] [ebp-10h] BYREF

  result = (int)this->_is;
  if ( result )
  {
    (*(void (__cdecl **)(int, int *, int, bool *const))(*(_DWORD *)result + 20))(result, ret, 4, success);
    result = ret[0];
  }
  else
  {
    *success = 0;
  }
  return result;
}

uint vgui::DataInputStream::readUInt(vgui::DataInputStream *const this, bool *const success)
{
  uint result; // eax
  uint ret[4]; // [esp+1Ch] [ebp-10h] BYREF

  result = (uint)this->_is;
  if ( result )
  {
    (*(void (__cdecl **)(uint, uint *, int, bool *const))(*(_DWORD *)result + 20))(result, ret, 4, success);
    result = ret[0];
  }
  else
  {
    *success = 0;
  }
  return result;
}

int vgui::DataInputStream::readLong(vgui::DataInputStream *const this, bool *const success)
{
  int result; // eax
  int ret[4]; // [esp+1Ch] [ebp-10h] BYREF

  result = (int)this->_is;
  if ( result )
  {
    (*(void (__cdecl **)(int, int *, int, bool *const))(*(_DWORD *)result + 20))(result, ret, 4, success);
    result = ret[0];
  }
  else
  {
    *success = 0;
  }
  return result;
}

ulong vgui::DataInputStream::readULong(vgui::DataInputStream *const this, bool *const success)
{
  ulong result; // eax
  ulong ret[4]; // [esp+1Ch] [ebp-10h] BYREF

  result = (ulong)this->_is;
  if ( result )
  {
    (*(void (__cdecl **)(ulong, ulong *, int, bool *const))(*(_DWORD *)result + 20))(result, ret, 4, success);
    result = ret[0];
  }
  else
  {
    *success = 0;
  }
  return result;
}

float vgui::DataInputStream::readFloat(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax
  long double result; // fst7
  float ret[4]; // [esp+1Ch] [ebp-10h] BYREF

  v2 = this->_is;
  if ( v2 )
  {
    (*((void (__cdecl **)(vgui::InputStream *, float *, int, bool *const))v2->_vptr_InputStream + 5))(
      v2,
      ret,
      4,
      success);
    result = ret[0];
  }
  else
  {
    *success = 0;
    result = 0.0;
  }
  return result;
}

double vgui::DataInputStream::readDouble(vgui::DataInputStream *const this, bool *const success)
{
  vgui::InputStream *v2; // eax
  long double result; // fst7
  double ret[2]; // [esp+18h] [ebp-14h] BYREF

  v2 = this->_is;
  if ( v2 )
  {
    (*((void (__cdecl **)(vgui::InputStream *, double *, int, bool *const))v2->_vptr_InputStream + 5))(
      v2,
      ret,
      8,
      success);
    result = ret[0];
  }
  else
  {
    *success = 0;
    result = 0.0;
  }
  return result;
}

void vgui::DataInputStream::readLine(vgui::DataInputStream *const this, char *buf, int bufLen, bool *const success)
{
  vgui::InputStream *v4; // eax
  int v5; // ebx
  uchar ch_0[44]; // [esp+20h] [ebp-2Ch] BYREF

  v4 = this->_is;
  if ( v4 )
  {
    if ( bufLen <= 0 )
    {
LABEL_10:
      while ( 1 )
      {
        (*((void (__cdecl **)(vgui::InputStream *, uchar *, int, bool *const))v4->_vptr_InputStream + 5))(
          v4,
          ch_0,
          1,
          success);
        if ( !*success || ch_0[0] == 10 )
          break;
        v4 = this->_is;
      }
    }
    else
    {
      v5 = 0;
      while ( 1 )
      {
        buf[v5] = 0;
        (*((void (__cdecl **)(vgui::InputStream *, uchar *, int, bool *const))this->_is->_vptr_InputStream + 5))(
          this->_is,
          ch_0,
          1,
          success);
        if ( !*success || ch_0[0] == 10 )
          break;
        buf[v5++] = ch_0[0];
        if ( v5 == bufLen )
        {
          v4 = this->_is;
          goto LABEL_10;
        }
      }
    }
  }
  else
  {
    *success = 0;
  }
}

void vgui::DataInputStream::DataInputStream(vgui::DataInputStream *const this, const void **const __vtt_parm, vgui::InputStream *is)
{
  _DWORD *v3; // edx

  v3 = *__vtt_parm;
  *(_DWORD *)this->gap0 = *__vtt_parm;
  *(_DWORD *)&this->gap0[*(v3 - 10)] = __vtt_parm[1];
  this->_is = is;
}

void vgui::DataInputStream::DataInputStream(vgui::DataInputStream *const this, vgui::InputStream *is)
{
  *(_DWORD *)this->gap0 = (char *)&`vtable for'vgui::DataInputStream + 40;
  this->_is = is;
}

