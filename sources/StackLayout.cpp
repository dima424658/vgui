#include <VGUI_StackLayout.h>

#include <VGUI_Panel.h>

vgui::StackLayout::StackLayout(int vgap, bool fitWide)
	: _vgap{ vgap }, _fitWide{ fitWide }
{
}

void vgui::StackLayout::performLayout(vgui::Panel* panel)
{
	int x, y;
	int tall, wide;
	int pwide, ptall;
	int offset = 0;

	for (auto i = 0; i < panel->getChildCount(); ++i)
	{
		auto child = panel->getChild(i);
		child->getBounds(x, y, wide, tall);
		child->setPos(x, offset);
		
		if (_fitWide)
		{
			panel->getPaintSize(pwide, ptall);
			child->setSize(pwide, ptall);
		}

		offset += tall + _vgap;
	}
}
