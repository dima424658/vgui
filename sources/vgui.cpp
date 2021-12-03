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
}