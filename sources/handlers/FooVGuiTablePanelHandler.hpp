#pragma once

#include <VGUI_ChangeSignal.h>
#include <VGUI_InputSignal.h>
#include <VGUI_RepaintSignal.h>

namespace vgui
{
    class TablePanel;

    class FooVGuiTablePanelHandler : public vgui::InputSignal, public vgui::RepaintSignal, public vgui::ChangeSignal
    {
    private:
        vgui::TablePanel* _table;
    public:
        FooVGuiTablePanelHandler(vgui::TablePanel* table);

        virtual void valueChanged(vgui::Panel* panel);
        virtual void cursorMoved(int x, int y, vgui::Panel* panel);
        virtual void cursorEntered(vgui::Panel* panel);
        virtual void cursorExited(vgui::Panel* panel);
        virtual void mousePressed(vgui::MouseCode code, vgui::Panel* panel);
        virtual void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel);
        virtual void mouseReleased(vgui::MouseCode code, vgui::Panel* panel);
        virtual void mouseWheeled(int delta, vgui::Panel* panel);
        virtual void keyPressed(vgui::KeyCode code, vgui::Panel* panel);
        virtual void keyTyped(vgui::KeyCode code, vgui::Panel* panel);
        virtual void keyReleased(vgui::KeyCode code, vgui::Panel* panel);
        virtual void keyFocusTicked(vgui::Panel* panel);
        virtual void panelRepainted(vgui::Panel *panel);
    };
};