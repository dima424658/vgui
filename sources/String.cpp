#include <VGUI_String.h>

#include <cstring>

vgui::String::String()
{
  _text = "";
}

vgui::String::String(const char *text)
{
  _text = new char[std::strlen(text) + 1];
}

vgui::String::String(const vgui::String& src)
{
  _text = src._text;
}

vgui::String::~String()
{
  delete[] _text;
  _text = nullptr;
}

int vgui::String::getCount(const char *text)
{
  return std::strlen(text);
}

int vgui::String::getCount()
{
  return getCount(_text);
}

bool vgui::String::operator==(vgui::String text)
{
  return std::strcmp(_text, text._text) == 0;
}

bool vgui::String::operator==(const char *text)
{
  return std::strcmp(_text, text) == 0;
}

char vgui::String::operator[](int index)
{
  return _text[index];
}

const char *vgui::String::getChars()
{
  return _text;
}

