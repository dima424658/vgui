#pragma once

#include <VGUI_Panel.h>
#include <VGUI_App.h>
#include <VGUI_TickSignal.h>

class FooClock : public vgui::Panel, public vgui::TickSignal
{
private:
    int _hour, _minute, _second;
public:
	FooClock(int x,int y,int wide,int tall); 

	virtual void paintBackground();
    virtual void ticked();
    
};