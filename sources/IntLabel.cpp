#include <cstdio>
#include <cstring>

#include <VGUI_IntLabel.h>

vgui::IntLabel::IntLabel(int value, int x, int y, int wide, int tall)
	: vgui::Label{ nullptr, x, y, wide, tall },
	_value{ value }
{
	//this->_vptr_IntChangeSignal = (int (**)(...))(&`vtable for'vgui::IntLabel + 145);
	//	* (_DWORD*)this->baseclass_0 = &`vtable for'vgui::IntLabel + 2;

	if (_value)
		repaint();
}

void vgui::IntLabel::intChanged(int value, vgui::Panel* panel)
{
	setValue(value);
}

void vgui::IntLabel::paintBackground()
{
	char buf[50];

	std::sprintf(buf, "%d", _value);
	vgui::Panel::paintBackground();
	drawSetColor(Scheme::SchemeColor::sc_black);
	drawSetTextColor(Scheme::SchemeColor::sc_black);
	drawPrintText(0, 0, buf, std::strlen(buf));
}

void vgui::IntLabel::setValue(int value)
{
	if (_value != value)
	{
		_value = value;
		repaint();
	}
}
