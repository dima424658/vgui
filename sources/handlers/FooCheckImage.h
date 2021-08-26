#pragma once

#include <VGUI_Image.h>
#include <VGUI_CheckButton.h>

class FooCheckImage : public vgui::Image
{
private:
    vgui::CheckButton* _checkButton;
public:
    FooCheckImage(vgui::CheckButton* checkButton);
	virtual void paint(vgui::Panel* panel);
};