#include "FooDefaultToggleButtonController.h"

handlers::FooDefaultToggleButtonController::FooDefaultToggleButtonController(vgui::ToggleButton* button)
    : _button{ button }
{}

void handlers::FooDefaultToggleButtonController::addSignals(vgui::Button* button)
{
    button->addInputSignal(this);
}

void handlers::FooDefaultToggleButtonController::removeSignals(vgui::Button* button)
{
    button->removeInputSignal(this);
}

void handlers::FooDefaultToggleButtonController::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    _button->setSelected(!_button->isSelected());
    _button->fireActionSignal();
    _button->repaint();
}

void handlers::FooDefaultToggleButtonController::cursorMoved(int x, int y, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::cursorEntered(vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::cursorExited(vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::mouseWheeled(int delta, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooDefaultToggleButtonController::keyFocusTicked(vgui::Panel* panel) {}