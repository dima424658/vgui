#include <cstring>

#include "FontPlat.h"

vgui::FontPlat::FontPlat(const char* name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
    : m_ExtendedABCWidthsCache{ &ExtendedABCWidthsCacheLessFunc }
{
    std::strncpy(m_szName, name, 32);

    m_iTall = tall;
    m_iWide = wide;
    m_iWeight = weight;
    m_bUnderlined = underline;
}

vgui::FontPlat::FontPlat(VFontData bitmapFont)
    : m_ExtendedABCWidthsCache{ &ExtendedABCWidthsCacheLessFunc }
{

}

int vgui::FontPlat::equals(const char* name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol)
{

}
void vgui::FontPlat::getCharRGBA(int, int, int, int, int, uchar *)
{

}
void vgui::FontPlat::getCharABCwide(int, int &, int &, int &)
{

}
int vgui::FontPlat::getTall()
{

}
int vgui::FontPlat::getWide()
{

}
void vgui::FontPlat::drawSetTextFont(vgui::SurfacePlat *)
{

}

bool vgui::FontPlat::ExtendedABCWidthsCacheLessFunc(const vgui::FontPlat::abc_cache_t* lhs, const vgui::FontPlat::abc_cache_t* rhs)
{
    return lhs->wch < rhs->wch;
}