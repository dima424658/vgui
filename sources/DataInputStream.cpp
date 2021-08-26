#include <VGUI_DataInputStream.h>

template<typename T>
T readAny(vgui::InputStream* is, bool& success)
{
  uchar result[sizeof(T)];

  is->readUChar(result, sizeof(T), success);

  return *reinterpret_cast<T*>(result);
}

void vgui::DataInputStream::seekStart(bool& success)
{
  if (_is)
    _is->seekStart(success);
  else
    success = false;
}

void vgui::DataInputStream::seekRelative(int count, bool& success)
{
  if (_is)
    _is->seekRelative(count, success);
  else
    success = false;
}

void vgui::DataInputStream::seekEnd(bool& success)
{
  if (_is)
    _is->seekEnd(success);
  else
    success = false;
}

int vgui::DataInputStream::getAvailable(bool& success)
{
  int result;

  if (_is)
    result = _is->getAvailable(success);
  else
    success = false;

  return result;
}

void vgui::DataInputStream::readUChar(uchar* buf, int count, bool& success)
{
  if (_is)
    _is->readUChar(buf, count, success);
  else
    success = false;
}

void vgui::DataInputStream::close(bool& success)
{
  if (_is)
    _is->close(success);
  else
    success = false;
}

void vgui::DataInputStream::close()
{
  bool success;
  close(success);
}

bool vgui::DataInputStream::readBool(bool& success)
{
  if (_is)
    return readAny<bool>(_is, success) != 0;

  success = false;
  return {};
}

char vgui::DataInputStream::readChar(bool& success)
{
  if (_is)
    return readAny<char>(_is, success);

  success = false;
  return {};
}

uchar vgui::DataInputStream::readUChar(bool& success)
{
  if (_is)
    return readAny<uchar>(_is, success);

  success = false;
  return {};
}

short vgui::DataInputStream::readShort(bool& success)
{
  if (_is)
    return readAny<short>(_is, success);

  success = false;
  return {};
}

ushort vgui::DataInputStream::readUShort(bool& success)
{
  if (_is)
    return readAny<ushort>(_is, success);

  success = false;
  return {};
}

int vgui::DataInputStream::readInt(bool& success)
{
  if (_is)
    return readAny<int>(_is, success);

  success = false;
  return {};
}

uint vgui::DataInputStream::readUInt(bool& success)
{
  if (_is)
    return readAny<uint>(_is, success);

  success = false;
  return {};
}

long vgui::DataInputStream::readLong(bool& success)
{
  if (_is)
    return readAny<long>(_is, success); // ??? sizeof(long)

  success = false;
  return {};
}

ulong vgui::DataInputStream::readULong(bool& success)
{
  if (_is)
    return readAny<ulong>(_is, success);

  success = false;
  return {};
}

float vgui::DataInputStream::readFloat(bool& success)
{
  if (_is)
    return readAny<float>(_is, success);

  success = false;
  return {};
}

double vgui::DataInputStream::readDouble(bool& success)
{
  if (_is)
    return readAny<double>(_is, success);

  success = false;
  return {};
}

void vgui::DataInputStream::readLine(char* buf, int bufLen, bool& success)
{
  bool success = true;
  uchar ch_0 = '\0';

  if (_is)
  {
    for (auto i = 0; i < bufLen; ++i)
    {
      buf[i] = readAny<char>(_is, success);
      if (!success || buf[i] == '\n')
        return;
    }
  
    do ch_0 = readAny<uchar>(_is, success);
    while (success && ch_0 != '\n');
  }
  else
    success = false;
}

vgui::DataInputStream::DataInputStream(vgui::InputStream* is)
  : _is{ is }
{}

