#include <cstdarg>
#include <cstdio>
#include <cstring>

#include <VGUI.h>
#include <VGUI_Dar.h>

#include "handlers/BaseFontPlat.h"
#include "handlers/FontPlat.h"

namespace vgui
{
    Dar<vgui::BaseFontPlat*> staticFontPlatDar;
    int staticFontId = -1;

    void Font_Reset()
    {
        staticFontPlatDar.removeAll();
    }

    int vgui_printf(const char* format, ...)
    {
        int result;
        char buf[2048];
        std::va_list __varargs;

        va_start(__varargs, format);
        result = std::vsprintf(buf, format, __varargs);
        std::printf("%s", buf);
        return result;
    }

    void vgui_strcpy(char* dst, int dstLen, const char* src)
    {
        std::strncpy(dst, src, dstLen);
    }

    char* vgui_strdup(const char* src)
    {
        return std::strcpy(new char[std::strlen(src) + 1], src);
    }
}