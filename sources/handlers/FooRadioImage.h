#pragma once

#include <VGUI_Image.h>
#include <VGUI_RadioButton.h>

class FooRadioImage : public vgui::Image
{
private:
    vgui::RadioButton* _radioButton;
public:
    FooRadioImage(vgui::RadioButton* radioButton);
protected:
    virtual void paint(vgui::Panel* panel);
};