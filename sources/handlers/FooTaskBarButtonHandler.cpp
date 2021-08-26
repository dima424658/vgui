#include "FooTaskBarButtonHandler.h"

#include <VGUI_App.h>
#include <VGUI_Button.h>
#include <VGUI_Frame.h>

FooTaskBarButtonHandler::FooTaskBarButtonHandler(vgui::Frame* frame, vgui::Button* button)
    : _frame{ frame }, _button{ button } {}

void  FooTaskBarButtonHandler::closing(vgui::Frame* frame) {}

void  FooTaskBarButtonHandler::focusChanged(bool lost, vgui::Panel* panel)
{
    _button->setSelected(!lost);
}

void  FooTaskBarButtonHandler::actionPerformed(vgui::Panel* panel)
{
    _frame->setVisible(true);
    _frame->requestFocus();
}

void  FooTaskBarButtonHandler::minimizing(vgui::Frame* frame, bool toTray)
{
    _frame->setVisible(false);
    _frame->getApp()->requestFocus(nullptr);
}