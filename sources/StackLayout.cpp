#include <VGUI_StackLayout.h>

#include <VGUI_Panel.h>

vgui::StackLayout::StackLayout(int vgap, bool fitWide)
	: _vgap{ vgap }, _fitWide{ fitWide }
{
}

void vgui::StackLayout::performLayout(vgui::Panel* panel)
{
	int v2; // edi
	int v3; // ebx
	int v4; // [esp+2Ch] [ebp-40h]
	int tall[3]; // [esp+30h] [ebp-3Ch] BYREF
	int x; // [esp+3Ch] [ebp-30h] BYREF
	int y; // [esp+40h] [ebp-2Ch] BYREF
	int wide; // [esp+44h] [ebp-28h] BYREF
	int pwide; // [esp+48h] [ebp-24h] BYREF
	int ptall[8]; // [esp+4Ch] [ebp-20h] BYREF

	v3 = 0;

	for (auto i = 0; i < panel->getChildCount(); ++i)
	{
		auto child = panel->getChild(i);

		// FlowLayout.cpp

		(*(void(__cdecl**)(int, int*, int*, int*, int*))(*(_DWORD*)v4 + 20))(child, &x, &y, &wide, tall);
		(**(void(__cdecl***)(int, int, int))child)(child, x, v3);

		if (this->_fitWide)
		{
			(*((void(__cdecl**)(vgui::Panel*, int*, int*))panel->_vptr_Panel + 58))(panel, &pwide, ptall);
			(*(void(__cdecl**)(int, int, int))(*(_DWORD*)v4 + 8))(child, pwide, tall[0]);
		}

		v3 += tall[0] + this->_vgap;
	}
}
