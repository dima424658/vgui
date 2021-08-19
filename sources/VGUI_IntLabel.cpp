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
/*
void `non-virtual thunk to'vgui::IntLabel::intChanged(vgui::IntLabel *this, int a2, vgui::Panel *a3)
{
	vgui::IntLabel::intChanged((vgui::IntLabel*)((char*)this - 208), a2, a3);
}
*/
// 000464A4
void vgui::IntLabel::intChanged(int value, vgui::Panel* panel)
{
	setValue(value); // ???
	//(*(void (**)(void))(*(_DWORD*)this->baseclass_0 + 556))();
}

void vgui::IntLabel::paintBackground()
{
	size_t v2; // eax
	char buf[50]; // [esp+2Eh] [ebp-3Eh] BYREF

	sprintf(buf, "%d", _value);
	vgui::Panel::paintBackground();
	drawSetColor(Scheme::SchemeColor::sc_black);
	drawSetTextColor(Scheme::SchemeColor::sc_black);
	drawPrintText(0, 0, buf, strlen(buf));
}

void vgui::IntLabel::setValue(int value)
{
	if (_value != value)
	{
		_value = value;
		repaint();
	}
}
