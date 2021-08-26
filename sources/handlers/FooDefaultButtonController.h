#pragma once

#include <VGUI_ButtonController.h>
#include <VGUI_InputSignal.h>

class FooDefaultButtonController : public vgui::ButtonController, public vgui::InputSignal
{
private:
    vgui::Button* _button;
public:
    FooDefaultButtonController(vgui::Button* button);
    
    virtual void addSignals(vgui::Button* button);
    virtual void removeSignals(vgui::Button* button);

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
};