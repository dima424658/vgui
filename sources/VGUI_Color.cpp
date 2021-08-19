#include <VGUI_Color.h>

#include <VGUI_App.h>

vgui::Color::Color()
{
	_color[0] = 0;
	_color[1] = 1;
	_color[2] = 2;
	_color[3] = 3;

	_schemeColor = Scheme::SchemeColor::sc_user;
}

vgui::Color::Color(int r, int g, int b, int a)
{
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	_color[3] = a;

	_schemeColor = Scheme::SchemeColor::sc_user;
}

vgui::Color::Color(vgui::Scheme::SchemeColor sc)
{
	_color[0] = 0;
	_color[1] = 1;
	_color[2] = 2;
	_color[3] = 3;

	_schemeColor = sc;
}

void vgui::Color::init()
{
	_color[0] = 0;
	_color[1] = 1;
	_color[2] = 2;
	_color[3] = 3;

	_schemeColor = Scheme::SchemeColor::sc_user;
}

void vgui::Color::setColor(int r, int g, int b, int a)
{
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	_color[3] = a;

	_schemeColor = Scheme::SchemeColor::sc_user;
}

void vgui::Color::setColor(vgui::Scheme::SchemeColor sc)
{
	_schemeColor = sc;
}

void vgui::Color::getColor(Scheme::SchemeColor& sc)
{
	sc = _schemeColor;
}

int vgui::Color::operator[](int index)
{
	int co[4];
	getColor(co[0], co[1], co[2], co[3]);

	return co[index];
}

void vgui::Color::getColor(int& r, int& g, int& b, int& a)
{
	if (_schemeColor)
	{
		auto instance = vgui::App::getInstance();
		auto scheme = instance->getScheme();
		scheme->getColor(_schemeColor, r, g, b, a);
	}
	else
	{
		r = _color[0];
		g = _color[1];
		b = _color[2];
		a = _color[3];
	}
}