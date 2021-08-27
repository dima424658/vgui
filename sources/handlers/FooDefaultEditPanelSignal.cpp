#include "FooDefaultEditPanelSignal.h"

#include <VGUI_App.h>
#include <VGUI_MouseCode.h>
#include <VGUI_KeyCode.h>


FooDefaultEditPanelSignal::FooDefaultEditPanelSignal(vgui::EditPanel* editPanel)
    : _editPanel{ editPanel }
{}

void FooDefaultEditPanelSignal::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    _editPanel->requestFocus();
    _editPanel->repaint();
}

void FooDefaultEditPanelSignal::keyTyped(vgui::KeyCode code, vgui::Panel* panel)
{
    switch (code)
    {
    case vgui::KeyCode::KEY_ENTER:
        _editPanel->doCursorNewLine();
        break;
    case vgui::KeyCode::KEY_BACKSPACE:
        _editPanel->doCursorBackspace();
        break;
    case vgui::KeyCode::KEY_DELETE:
        _editPanel->doCursorDelete();
        break;
    case vgui::KeyCode::KEY_HOME:
        _editPanel->doCursorToStartOfLine();
        break;
    case vgui::KeyCode::KEY_END:
        _editPanel->doCursorToEndOfLine();
        break;
    case vgui::KeyCode::KEY_LSHIFT:
    case vgui::KeyCode::KEY_RSHIFT:
    case vgui::KeyCode::KEY_LALT:
    case vgui::KeyCode::KEY_RALT:
    case vgui::KeyCode::KEY_LCONTROL:
    case vgui::KeyCode::KEY_RCONTROL:
        return;
    case vgui::KeyCode::KEY_UP:
        _editPanel->doCursorUp();
        break;
    case vgui::KeyCode::KEY_LEFT:
        _editPanel->doCursorLeft();
        break;
    case vgui::KeyCode::KEY_DOWN:
        _editPanel->doCursorDown();
        break;
    case vgui::KeyCode::KEY_RIGHT:
        _editPanel->doCursorRight();
        break;
    default:
        auto ch = _editPanel->getApp()->getKeyCodeChar(code, _editPanel->isKeyDown(vgui::KeyCode::KEY_LSHIFT) || _editPanel->isKeyDown(vgui::KeyCode::KEY_RSHIFT));
        _editPanel->doCursorInsertChar(ch);
        break;
    }
}

void FooDefaultEditPanelSignal::keyFocusTicked(vgui::Panel* panel)
{
    bool blink;
    int nextBlinkTime;

    _editPanel->getCursorBlink(blink, nextBlinkTime);
    if (_editPanel->getApp()->getTimeMillis() > nextBlinkTime)
        _editPanel->setCursorBlink(!blink);
}

void FooDefaultEditPanelSignal::cursorMoved(int x, int y, vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::cursorEntered(vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::cursorExited(vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::mouseWheeled(int delta, vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
void FooDefaultEditPanelSignal::keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}