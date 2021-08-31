#pragma once

#include "CUtlRBTree.h"

namespace vgui
{
    class FontPlat
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

        bool equals(char const *, int, int, float, int, bool, bool, bool, bool);
        void getCharRGBA(int, int, int, int, int, uchar *);
        void getCharABCwide(int, int &, int &, int &);
        int getTall();
        int getWide();
        void drawSetTextFont(vgui::SurfacePlat *);

    private:
        int bufSize[2];
        uchar *buf;
        VFontData m_BitmapFont;
        bool m_bBitmapFont;
        char m_szName[32];
        int m_iTall;
        int m_iWeight;
        int m_iFlags;
        bool m_bAntiAliased;
        bool m_bRotary;
        bool m_bAdditive;
        int m_iDropShadowOffset;
        bool m_bUnderlined;
        int m_iOutlineSize;
        int m_iHeight;
        int m_iMaxCharWidth;
        int m_iAscent;
        CUtlRBTree<vgui::FontPlat::abc_cache_t, unsigned short> m_ExtendedABCWidthsCache;
        int m_iScanLines;
        int m_iBlur;
        float *m_pGaussianDistribution;
    };
} // namespace vgui
