#pragma once

#include "CUtlRBTree.h"

#include "BaseFontPlat.h"
#include "VFontData.hpp"

namespace vgui
{
    class FontPlat : public vgui::BaseFontPlat
    {
    public:
        struct abc_t
        {
            char a;
            char b;
            char c;
        };

        struct abc_cache_t
        {
            wchar_t wch;
            abc_t abc;
        };

        FontPlat(VFontData bitmapFont);
        FontPlat(const char* name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol);
        int equals(const char* name, int tall, int wide, float rotation, int weight, bool italic, bool underline, bool strikeout, bool symbol);
        void getCharRGBA(int, int, int, int, int, uchar *);
        void getCharABCwide(int, int &, int &, int &);
        int getTall();
        int getWide();
        void drawSetTextFont(vgui::SurfacePlat *);

        static bool ExtendedABCWidthsCacheLessFunc(const vgui::FontPlat::abc_cache_t* lhs, const vgui::FontPlat::abc_cache_t* rhs);

    private:
        int bufSize[2];
        uchar *buf;
        VFontData m_BitmapFont;
        char m_szName[32];

        int m_iWide;
        int m_iTall;
        int m_iWeight;
        int m_iFlags = 0;

        bool m_bBitmapFont = false;
        bool m_bAntiAliased = false;
        bool m_bRotary = false;
        bool m_bAdditive = false;
        bool m_bUnderlined = false;

        int m_iDropShadowOffset = 0;
        int m_iOutlineSize = 0;
        int m_iMaxCharWidth = 0;
        int m_iAscent = 0;
        CUtlRBTree<vgui::FontPlat::abc_cache_t, unsigned short> m_ExtendedABCWidthsCache;
        int m_iScanLines = 0;
        int m_iBlur = 0;
        float *m_pGaussianDistribution = nullptr;
    };
} // namespace vgui
