#include "FooTreeFolderDefaultHandler.h"

handlers::FooTreeFolderDefaultHandler::FooTreeFolderDefaultHandler(vgui::TreeFolder* treeFolder)
    : _treeFolder{ treeFolder }
{
}

void handlers::FooTreeFolderDefaultHandler::mousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
    _treeFolder->setOpened(!_treeFolder->isOpened());
}

void handlers::FooTreeFolderDefaultHandler::cursorMoved(int x, int y, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::cursorEntered(vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::cursorExited(vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::mouseWheeled(int delta, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
void handlers::FooTreeFolderDefaultHandler::keyFocusTicked(vgui::Panel* panel) {}