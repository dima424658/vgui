#include "FooMinimizeButton.hpp"

#include <VGUI_Frame.h>

FooMinimizeButtonHandler::FooMinimizeButtonHandler(vgui::Frame* frame)
    : _frame{ frame }
{}

void FooMinimizeButtonHandler::actionPerformed(vgui::Panel* panel)
{
    _frame->fireMinimizingSignal();
}

FooCloseButtonHandler::FooCloseButtonHandler(vgui::Frame* frame)
    : _frame{frame}
{}

void FooCloseButtonHandler::actionPerformed(vgui::Panel* panel)
{
    _frame->fireClosingSignal();

}