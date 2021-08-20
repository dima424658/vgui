#include <VGUI_ImagePanel.h>

#include <VGUI_Image.h>

vgui::ImagePanel::ImagePanel(vgui::Image* image)
	: vgui::Panel{ 0, 0, 64, 64 },
	_image{ image }
{
	
	int wide; // [esp+28h] [ebp-14h] BYREF
	int tall; // [esp+2Ch] [ebp-10h] BYREF

	if (image)
	{
		_image->getSize(wide, tall);
		setSize(wide, tall); // ???
		/*
		(*((void(__cdecl**)(vgui::ImagePanel* const, int, int))this->_vptr_Panel + 2))(this, wide, tall);
		
		.text:0002E120                 mov     edx, [esp+3Ch+var_10]
		.text:0002E124                 mov     eax, [ebx]
		.text:0002E126                 mov     [esp+3Ch+var_3C], ebx
		.text:0002E129                 mov     [esp+3Ch+y], edx
		.text:0002E12D                 mov     edx, [esp+3Ch+var_14]
		.text:0002E131                 mov     [esp+3Ch+x], edx
		.text:0002E135                 call    dword ptr [eax+8]
		*/
	}

	repaint();
}

void vgui::ImagePanel::setImage(vgui::Image* image)
{
	int wide; // [esp+18h] [ebp-14h] BYREF
	int tall; // [esp+1Ch] [ebp-10h] BYREF

	this->_image = image;
	if (image)
	{
		_image->getSize(wide, tall);
		setSize(wide, tall); // ???
		//(*((void(__cdecl**)(vgui::ImagePanel* const, int, int))this->_vptr_Panel + 2))(this, wide, tall);
	}

	(*((void(__cdecl**)(vgui::ImagePanel* const))this->_vptr_Panel + 12))(this); // paintBackground??
}

void vgui::ImagePanel::paintBackground()
{
	if (_image)
	{
		(*((void(__cdecl**)(vgui::ImagePanel* const, int))this->_vptr_Panel + 93))(this, 2);
		_image->doPaint(this);
	}
}
