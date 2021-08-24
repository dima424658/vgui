#include <VGUI_FlowLayout.h>

#include <VGUI_Panel.h>

vgui::FlowLayout::FlowLayout(int hgap)
	: _hgap{ hgap }
{
}

void vgui::FlowLayout::performLayout(vgui::Panel* panel)
{
	int x, y;
	int wide, tall;
	int offset = 0;

	for (auto i = 0; i < panel->getChildCount(); ++i)
	{
		auto child = panel->getChild(i);
		child->getBounds(x, y, wide, tall);
		child->setSize(offset, y);
		offset += wide + _hgap;
	}
}