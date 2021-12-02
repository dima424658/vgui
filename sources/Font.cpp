#include <cstring>

#include <VGUI_Font.h>
#include <VGUI_Dar.h>

#include "handlers/BaseFontPlat.h"
#include "handlers/FontPlat.h"

void vgui::Font::getTextSize(const char* text, int& wide, int& tall)
{
    int a, b, c;
    int newWide = 0;

    wide = 0;
    tall = 0;

    if (!text)
        return;

    tall = getTall();
    for (auto i = 0; text[i] != '\0'; ++i)
    {
        if (text[i] == '\n')
        {
            newWide = 0;
            tall += getTall();
        }
        else
        {
            getCharABCwide(text[i], a, b, c);
            newWide += a + b + c;

            wide = std::max(wide, newWide);
        }
    }
}

int vgui::Font::getId()
{
    return _id;
}

int vgui::Font::getWide()
{
    return _plat->getWide();
}

int vgui::Font::getTall()
{
    return _plat->getTall();
}

void vgui::Font::getCharRGBA(int ch, int rgbaX, int rgbaY, int rgbaWide, int rgbaTall, uchar* rgba)
{
    _plat->getCharRGBA(ch, rgbaX, rgbaY, rgbaWide, rgbaTall, rgba);
}

void vgui::Font::getCharABCwide(int ch, int& a, int& b, int& c)
{
    _plat->getCharABCwide(ch, a, b, c);
}

static vgui::Dar<vgui::BaseFontPlat*> staticFontPlatDar;
static int staticFontId = -1;

void vgui::Font::init(const char* name, void* pFileData, int fileDataLen, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
    _id = -1;
    _name = strdup(name);

    if (pFileData)
    {/*
        FileImageStream_Memory memStream{ pFileData, fileDataLen };

        auto plat = new FontPlat{};
        plat.

        char* v13 = new char[0x414u];
        VFontData* pData = (VFontData*)(v13 + 4);
        vgui::BaseFontPlat* v15 = (vgui::BaseFontPlat*)v13;

        VFontData::VFontData((VFontData* const)(v13 + 4));
        v15[260]._vptr_BaseFontPlat = 0;

        if (LoadVFontDataFrom32BitTGA(&memStream, pData))
        {
            auto v25 = new char[strlen(name) + 1];
            
            v15[260]._vptr_BaseFontPlat = (int (**)(...))v25;

            if (v25)
            {
                strcpy(v25, name);

                _plat = v15;

                staticFontPlatDar.addElement(_plat);
                _id = staticFontId++;
            }
        }
        (*((void(__cdecl**)(vgui::BaseFontPlat*))v15->_vptr_BaseFontPlat + 1))(v15);*/
    }
    else
    {
        _plat = nullptr;
        for (auto i = 0; i < staticFontPlatDar.getCount(); ++i)
            if (staticFontPlatDar[i]->equals(name, tall, wide, rotation, weight, italic, underline, strikeout, symbol))
            {
                _plat = staticFontPlatDar[i];
                break;
            }

        if (!_plat)
        {
            _plat = new vgui::FontPlat{name, tall, wide, rotation, weight, italic, underline, strikeout, symbol};
            staticFontPlatDar.addElement(_plat);
            _id = ++staticFontId;
        }
    }
}

vgui::Font::Font(const char* name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
    init(name, nullptr, 0, tall, wide, rotation, weight, italic, underline, strikeout, symbol);
}

vgui::Font::Font(const char* name, void* pFileData, int fileDataLen, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{
    init(name, pFileData, fileDataLen, tall, wide, rotation, weight, italic, underline, strikeout, symbol);
}