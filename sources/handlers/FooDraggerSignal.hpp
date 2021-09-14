#pragma once

#include <VGUI_InputSignal.h>

namespace vgui
{
    class Frame;
}

class FooDraggerSignal : public vgui::InputSignal
{
protected:
    vgui::Frame* _frame;
    bool _dragging;
    int _dragStart[2];
    int _dragOrgPos[2], _dragOrgPos2[2];
    int _dragOrgSize[2], _dragOrgSize2[2];

public:
    FooDraggerSignal(vgui::Frame* frame);
    
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
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};