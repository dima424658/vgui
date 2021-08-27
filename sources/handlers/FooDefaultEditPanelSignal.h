#pragma once

#include <VGUI_InputSignal.h>
#include <VGUI_EditPanel.h>

class FooDefaultEditPanelSignal : public vgui::InputSignal
{
private:
    vgui::EditPanel* _editPanel;
    
public:
	FooDefaultEditPanelSignal(vgui::EditPanel* editPanel);
	virtual void cursorMoved(int x,int y,vgui::Panel* panel);
	virtual void cursorEntered(vgui::Panel* panel);
	virtual void cursorExited(vgui::Panel* panel);
	virtual void mousePressed(vgui::MouseCode code,vgui::Panel* panel);
	virtual void mouseDoublePressed(vgui::MouseCode code,vgui::Panel* panel);
	virtual void mouseReleased(vgui::MouseCode code,vgui::Panel* panel);
	virtual void mouseWheeled(int delta,vgui::Panel* panel);
	virtual void keyPressed(vgui::KeyCode code,vgui::Panel* panel);
	virtual void keyTyped(vgui::KeyCode code,vgui::Panel* panel);
	virtual void keyReleased(vgui::KeyCode code,vgui::Panel* panel);
	virtual void keyFocusTicked(vgui::Panel* panel);
};