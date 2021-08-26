#pragma once

#include <VGUI_ActionSignal.h>
#include <VGUI_FrameSignal.h>
#include <VGUI_FocusChangeSignal.h>

class FooTaskBarButtonHandler : public vgui::ActionSignal, public vgui::FrameSignal, public vgui::FocusChangeSignal
{
private:
    vgui::Frame* _frame;
    vgui::Button* _button;
public:
    FooTaskBarButtonHandler(vgui::Frame* frame, vgui::Button* button);

    virtual void closing(vgui::Frame* frame);
    virtual void focusChanged(bool lost, vgui::Panel* panel);
    virtual void actionPerformed(vgui::Panel* panel);
    virtual void minimizing(vgui::Frame* frame, bool toTray);
};