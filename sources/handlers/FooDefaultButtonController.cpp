#include "FooDefaultButtonController.h"

#include <VGUI_Button.h>

FooDefaultButtonController::FooDefaultButtonController(vgui::Button* button)
    : _button{ button } {}

void FooDefaultButtonController::addSignals(vgui::Button* button)
{
    button->addInputSignal(this);
}

void FooDefaultButtonController::removeSignals(vgui::Button* button)
{
    button->removeInputSignal(this);
}

void FooDefaultButtonController::mouseReleased(vgui::MouseCode code, vgui::Panel* panel)
{
    if (_button->isEnabled() && _button->isMouseClickEnabled(code))
    {
        _button->setSelected(false);
        _button->fireActionSignal();
        _button->repaint();
    }
}

void FooDefaultButtonController::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    if (_button->isEnabled() && _button->isMouseClickEnabled(code))
    {
        _button->setSelected(true);
        _button->repaint();
    }
}

void FooDefaultButtonController::cursorMoved(int x, int y, vgui::Panel* panel) {}
void FooDefaultButtonController::cursorEntered(vgui::Panel* panel) {}
void FooDefaultButtonController::cursorExited(vgui::Panel* panel) {}
void FooDefaultButtonController::mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
void FooDefaultButtonController::mouseWheeled(int delta, vgui::Panel* panel) {}
void FooDefaultButtonController::keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
void FooDefaultButtonController::keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
void FooDefaultButtonController::keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
void FooDefaultButtonController::keyFocusTicked(vgui::Panel* panel) {}