#include <VGUI_BitmapTGA.h>

bool vgui::BitmapTGA::loadTGA(vgui::BitmapTGA *const this, vgui::InputStream *is, bool invertAlpha)
{
  bool v3; // bl
  int v5; // ebp
  int v6; // ebp
  uchar *v7; // ebx
  signed __int8 v8; // al
  int v9; // ebx
  uchar v10; // al
  bool v11; // zf
  uchar v12; // al
  uchar v13; // al
  uchar v14; // al
  uchar v15; // al
  int v16; // edx
  uint8_t v17; // al
  uchar *v18; // ebx
  uchar v19; // al
  uchar v20; // al
  uchar v21; // al
  uchar v22; // al
  uchar v23; // al
  uchar v24; // al
  uchar column; // [esp+1Ch] [ebp-50h]
  int columna; // [esp+1Ch] [ebp-50h]
  int columnb; // [esp+1Ch] [ebp-50h]
  uchar v28; // [esp+20h] [ebp-4Ch]
  uchar packetSize; // [esp+30h] [ebp-3Ch]
  uint8_t packetSizea; // [esp+30h] [ebp-3Ch]
  int packetSizeb; // [esp+30h] [ebp-3Ch]
  uchar j; // [esp+34h] [ebp-38h]
  char ja; // [esp+34h] [ebp-38h]
  int v34; // [esp+38h] [ebp-34h]
  uchar pixel_size; // [esp+3Ch] [ebp-30h]
  uchar v36; // [esp+3Dh] [ebp-2Fh]
  uchar v37; // [esp+3Eh] [ebp-2Eh]
  uchar v38; // [esp+3Fh] [ebp-2Dh]
  vgui::DataInputStream dis; // [esp+44h] [ebp-28h] BYREF
  bool success[13]; // [esp+4Fh] [ebp-1Dh] BYREF

  v3 = 0;
  if ( is )
  {
    vgui::DataInputStream::DataInputStream(&dis, is);
    success[0] = 0;
    column = vgui::DataInputStream::readUChar(&dis, success);
    if ( success[0] )
    {
      packetSize = vgui::DataInputStream::readUChar(&dis, success);
      if ( success[0] )
      {
        j = vgui::DataInputStream::readUChar(&dis, success);
        if ( success[0] )
        {
          vgui::DataInputStream::readUShort(&dis, success);
          if ( success[0] )
          {
            vgui::DataInputStream::readUShort(&dis, success);
            if ( success[0] )
            {
              vgui::DataInputStream::readUChar(&dis, success);
              if ( success[0] )
              {
                vgui::DataInputStream::readUShort(&dis, success);
                if ( success[0] )
                {
                  vgui::DataInputStream::readUShort(&dis, success);
                  if ( success[0] )
                  {
                    v34 = vgui::DataInputStream::readUShort(&dis, success);
                    if ( success[0] )
                    {
                      v5 = vgui::DataInputStream::readUShort(&dis, success);
                      if ( success[0] )
                      {
                        pixel_size = vgui::DataInputStream::readUChar(&dis, success);
                        if ( success[0] )
                        {
                          vgui::DataInputStream::readUChar(&dis, success);
                          if ( success[0] && (j == 10 || j == 2) )
                          {
                            v3 = 0;
                            if ( !packetSize && (pixel_size == 32 || pixel_size == 24) )
                            {
                              v3 = 0;
                              (*((void (__cdecl **)(vgui::BitmapTGA *const, int, int))this->_vptr_Image + 5))(
                                this,
                                v34,
                                v5);
                              if ( this->_rgba )
                              {
                                if ( column )
                                  vgui::DataInputStream::seekRelative(&dis, column, success);
                                v6 = v5 - 1;
                                if ( j == 2 )
                                {
                                  packetSizeb = v34 * 4 * v6;
                                  while ( v6 != -1 )
                                  {
                                    columnb = 0;
                                    v18 = &this->_rgba[packetSizeb];
                                    while ( columnb < v34 )
                                    {
                                      if ( pixel_size == 24 )
                                      {
                                        v23 = vgui::DataInputStream::readUChar(&dis, success);
                                        v11 = !success[0];
                                        v18[2] = v23;
                                        if ( v11 )
                                          return 0;
                                        v24 = vgui::DataInputStream::readUChar(&dis, success);
                                        v11 = !success[0];
                                        v18[1] = v24;
                                        if ( v11 )
                                          return 0;
                                        *v18 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v18[3] = -1;
                                        v18 += 4;
                                      }
                                      else
                                      {
                                        v20 = vgui::DataInputStream::readUChar(&dis, success);
                                        v11 = !success[0];
                                        v18[2] = v20;
                                        if ( v11 )
                                          return 0;
                                        v21 = vgui::DataInputStream::readUChar(&dis, success);
                                        v11 = !success[0];
                                        v18[1] = v21;
                                        if ( v11 )
                                          return 0;
                                        *v18 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v22 = vgui::DataInputStream::readUChar(&dis, success);
                                        v11 = !success[0];
                                        v18[3] = ~v22;
                                        if ( v11 )
                                          return 0;
                                        if ( invertAlpha )
                                          v18[3] = v22;
                                        v18 += 4;
                                      }
                                      ++columnb;
                                    }
                                    --v6;
                                    packetSizeb += -4 * v34;
                                  }
                                }
                                else
                                {
                                  while ( v6 != -1 )
                                  {
                                    columna = 0;
                                    v7 = &this->_rgba[4 * v6 * v34];
LABEL_25:
                                    while ( columna < v34 )
                                    {
                                      v8 = vgui::DataInputStream::readUChar(&dis, success);
                                      if ( !success[0] )
                                        return 0;
                                      packetSizea = (v8 & 0x7F) + 1;
                                      ja = 0;
                                      if ( v8 >= 0 )
                                      {
                                        while ( 1 )
                                        {
                                          if ( pixel_size == 24 )
                                          {
                                            v14 = vgui::DataInputStream::readUChar(&dis, success);
                                            v11 = !success[0];
                                            v7[2] = v14;
                                            if ( v11 )
                                              return 0;
                                            v15 = vgui::DataInputStream::readUChar(&dis, success);
                                            v11 = !success[0];
                                            v7[1] = v15;
                                            if ( v11 )
                                              return 0;
                                            *v7 = vgui::DataInputStream::readUChar(&dis, success);
                                            if ( !success[0] )
                                              return 0;
                                            v7[3] = -!invertAlpha;
                                            v7 += 4;
                                          }
                                          else
                                          {
                                            v10 = vgui::DataInputStream::readUChar(&dis, success);
                                            v11 = !success[0];
                                            v7[2] = v10;
                                            if ( v11 )
                                              return 0;
                                            v12 = vgui::DataInputStream::readUChar(&dis, success);
                                            v11 = !success[0];
                                            v7[1] = v12;
                                            if ( v11 )
                                              return 0;
                                            *v7 = vgui::DataInputStream::readUChar(&dis, success);
                                            if ( !success[0] )
                                              return 0;
                                            v13 = vgui::DataInputStream::readUChar(&dis, success);
                                            v11 = !success[0];
                                            v7[3] = v13;
                                            if ( v11 )
                                              return 0;
                                            if ( invertAlpha )
                                              v7[3] = ~v13;
                                            v7 += 4;
                                          }
                                          if ( ++columna == v34 )
                                          {
                                            if ( !v6 )
                                              goto LABEL_56;
                                            v9 = columna;
                                            --v6;
                                            columna = 0;
                                            v7 = &this->_rgba[4 * v6 * v9];
                                          }
                                          if ( packetSizea <= (uint8_t)++ja )
                                            goto LABEL_25;
                                        }
                                      }
                                      if ( pixel_size == 24 )
                                      {
                                        v36 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v37 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v38 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v28 = -!invertAlpha;
                                      }
                                      else
                                      {
                                        v36 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v37 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v38 = vgui::DataInputStream::readUChar(&dis, success);
                                        if ( !success[0] )
                                          return 0;
                                        v19 = vgui::DataInputStream::readUChar(&dis, success);
                                        v28 = v19;
                                        if ( !success[0] )
                                          return 0;
                                        if ( invertAlpha )
                                          v28 = ~v19;
                                      }
                                      v16 = columna;
                                      v17 = 0;
                                      do
                                      {
                                        ++v16;
                                        *v7 = v38;
                                        v7[1] = v37;
                                        v7[2] = v36;
                                        v7[3] = v28;
                                        v7 += 4;
                                        if ( v16 == v34 )
                                        {
                                          if ( !v6 )
                                            goto LABEL_56;
                                          v7 = &this->_rgba[4 * --v6 * v16];
                                          v16 = 0;
                                        }
                                        ++v17;
                                      }
                                      while ( packetSizea > v17 );
                                      columna = v16;
                                    }
                                    --v6;
                                  }
                                }
LABEL_56:
                                v3 = 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return v3;
}

void vgui::BitmapTGA::BitmapTGA(vgui::BitmapTGA *const this, vgui::InputStream *is, bool invertAlpha)
{
  vgui::Bitmap::Bitmap(this);
  this->_vptr_Image = (int (**)(...))(&`vtable for'vgui::BitmapTGA + 2);
  vgui::BitmapTGA::loadTGA(this, is, invertAlpha);
}

