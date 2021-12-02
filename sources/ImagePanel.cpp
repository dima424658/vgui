#include <VGUI_ImagePanel.h>

#include <VGUI_Image.h>

vgui::ImagePanel::ImagePanel(vgui::Image* image)
	: vgui::Panel{ 0, 0, 64, 64 }
{
	setImage(image);
}

void vgui::ImagePanel::setImage(vgui::Image* image)
{
	int wide;
	int tall;

	_image = image;
	if (image)
	{
		_image->getSize(wide, tall);
		setSize(wide, tall);
	}

	repaint();
}

void vgui::ImagePanel::paintBackground()
{
	if (_image)
	{
		drawSetColor(Scheme::SchemeColor::sc_white);
		_image->doPaint(this);
	}
}
