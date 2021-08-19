#include <VGUI_FlowLayout.h>

#include <VGUI_Panel.h>

vgui::FlowLayout::FlowLayout(int hgap)
	: _hgap{ hgap }
{
}

void vgui::FlowLayout::performLayout(vgui::Panel* panel)
{
	int v3;
	int x;
	int y;
	int wide;
	int tall[7];

	v3 = 0;
	
	for (auto i = 0; i < panel->getChildCount(); ++i)
	{
		auto child = panel->getChild(i);

		// StackLayout.cpp

		child->getBounds(x, y, wide, tall); // ???

		(**(void(__cdecl***)(int, int, int))v5)(v5, v3, y);
		v3 += wide + _hgap;
	}

}