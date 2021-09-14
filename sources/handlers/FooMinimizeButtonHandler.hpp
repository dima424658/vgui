#pragma once

#include <VGUI_ActionSignal.h>

namespace vgui
{
    class Frame;
};

class FooMinimizeButtonHandler : public vgui::ActionSignal
{
private:
    vgui::Frame* _frame;
public:
    FooMinimizeButtonHandler(vgui::Frame* frame);

	virtual void actionPerformed(vgui::Panel* panel);
};

class FooCloseButtonHandler : public vgui::ActionSignal
{
private:
    vgui::Frame* _frame;
public:
    FooCloseButtonHandler(vgui::Frame* frame);

	virtual void actionPerformed(vgui::Panel* panel);
};