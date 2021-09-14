#include "FooVGuiTablePanelHandler.hpp"

#include <VGUI_TablePanel.h>
#include <VGUI_HeaderPanel.h>

void vgui::FooVGuiTablePanelHandler::valueChanged(vgui::Panel* panel)
{
    int cols = _table->getColumnCount();
    int x0, x1;

    auto header = dynamic_cast<vgui::HeaderPanel*>(panel);

    for (auto i = 0; i < header->getSectionCount() && i < cols; ++i)
    {
        header->getSectionExtents(i, x0, x1);
        _table->setColumnExtents(i, x0, x1);
    }
}

void vgui::FooVGuiTablePanelHandler::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    _table->privateMousePressed(code, panel);
}

void vgui::FooVGuiTablePanelHandler::mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    _table->privateMouseDoublePressed(code, panel);
}

void vgui::FooVGuiTablePanelHandler::keyTyped(vgui::KeyCode code, vgui::Panel* panel)
{
    _table->privateKeyTyped(code, panel);    
}

void vgui::FooVGuiTablePanelHandler::panelRepainted(vgui::Panel *panel)
{
    _table->repaint();
}

void vgui::FooVGuiTablePanelHandler::cursorMoved(int x, int y, vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::cursorEntered(vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::cursorExited(vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::mouseWheeled(int delta, vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
void vgui::FooVGuiTablePanelHandler::keyFocusTicked(vgui::Panel* panel) {}
