#include <VGUI_BorderPair.h>

vgui::BorderPair::BorderPair(vgui::Border* border0, vgui::Border* border1)
{
	_border[0] = border0;
	_border[1] = border1;
}

void vgui::BorderPair::doPaint(vgui::Panel* panel)
{
	if (_border[0])
		_border[0]->doPaint(panel);

	if (_border[1])
		_border[1]->doPaint(panel);
}

void vgui::BorderPair::paint(vgui::Panel* panel)
{
	if (_border[0])
		_border[0]->paint(panel);

	if (_border[1])
		_border[1]->paint(panel);
}