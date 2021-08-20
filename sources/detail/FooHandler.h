#pragma once

#include <VGUI_InputSignal.h>
#include <VGUI_DesktopIcon.h>

namespace vgui
{
    enum MouseCode
    {
        MOUSE_LEFT,
        MOUSE_RIGHT = 1,
        MOUSE_MIDDLE = 2,
        MOUSE_LAST = 3
    };
};

namespace detail
{
    class FooHandler : public vgui::InputSignal
    {
    public:
        virtual void cursorMoved(int x, int y, vgui::Panel *panel);
        virtual void cursorEntered(vgui::Panel *panel);
        virtual void cursorExited(vgui::Panel *panel);
        virtual void mousePressed(vgui::MouseCode code, vgui::Panel *panel);
        virtual void mouseDoublePressed(vgui::MouseCode code, vgui::Panel *panel);
        virtual void mouseReleased(vgui::MouseCode code, vgui::Panel *panel);
        virtual void mouseWheeled(int delta, vgui::Panel *panel);
        virtual void keyPressed(vgui::KeyCode code, vgui::Panel *panel);
        virtual void keyTyped(vgui::KeyCode code, vgui::Panel *panel);
        virtual void keyReleased(vgui::KeyCode code, vgui::Panel *panel);
        virtual void keyFocusTicked(vgui::Panel *panel);

    protected:
        bool _dragging;
        int _dragStart[2];
        int _dragOrgPos[2];
        vgui::DesktopIcon *_desktopIcon;
    };
}