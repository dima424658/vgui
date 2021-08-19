#include <VGUI_MiniApp.h>

void vgui::MiniApp::setName(vgui::MiniApp *const this, const char *name)
{
  this->_name = strdup(name);
}

void vgui::MiniApp::getName(vgui::MiniApp *const this, char *buf, int bufLen)
{
  char *s; // esi
  int v4; // edx
  char *v5; // edi
  int v6; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  char v9; // al
  __int16 v10; // cx
  int v11; // ecx

  if ( buf )
  {
    s = this->_name;
    v4 = strlen(s) + 1;
    if ( v4 > bufLen )
      v4 = bufLen;
    v5 = buf;
    v6 = v4 - 1;
    if ( (unsigned int)(v4 - 1) >= 8 )
    {
      if ( ((uint8_t)buf & 1) != 0 )
      {
        v9 = *s;
        v5 = buf + 1;
        ++s;
        *buf = v9;
        v6 = v4 - 2;
      }
      if ( ((uint8_t)v5 & 2) != 0 )
      {
        v10 = *(_WORD *)s;
        v6 -= 2;
        s += 2;
        *(_WORD *)v5 = v10;
        v5 += 2;
      }
      if ( ((uint8_t)v5 & 4) != 0 )
      {
        v11 = *(_DWORD *)s;
        v6 -= 4;
        s += 4;
        *(_DWORD *)v5 = v11;
        v5 += 4;
      }
      v8 = v6;
      LOBYTE(v6) = v6 & 3;
      v8 >>= 2;
      qmemcpy(v5, s, 4 * v8);
      s += 4 * v8;
      v5 += 4 * v8;
    }
    v7 = 0;
    if ( (v6 & 4) != 0 )
    {
      *(_DWORD *)v5 = *(_DWORD *)s;
      v7 = 4;
      if ( (v6 & 2) == 0 )
      {
LABEL_7:
        if ( (v6 & 1) == 0 )
        {
LABEL_8:
          buf[v4 - 1] = 0;
          return;
        }
LABEL_10:
        v5[v7] = s[v7];
        goto LABEL_8;
      }
    }
    else if ( (v6 & 2) == 0 )
    {
      goto LABEL_7;
    }
    *(_WORD *)&v5[v7] = *(_WORD *)&s[v7];
    v7 += 2;
    if ( (v6 & 1) == 0 )
      goto LABEL_8;
    goto LABEL_10;
  }
}

void vgui::MiniApp::MiniApp(vgui::MiniApp *const this)
{
  this->_vptr_MiniApp = (int (**)(...))(&`vtable for'vgui::MiniApp + 2);
  this->_name = (char *)"";
}

