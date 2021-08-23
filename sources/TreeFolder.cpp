#include <VGUI_TreeFolder.h>

#include <VGUI_Label.h>
#include <VGUI_InputSignal.h>
#include <VGUI_Layout.h>

#include <cmath>

bool vgui::TreeFolder::isOpened()
{
  return _opened;
}

void vgui::TreeFolder::setOpenedTraverse(bool state)
{
  setOpened(true);

  for (auto i = 0; i < getChildCount(); ++i)
  {
    auto lpsrc = dynamic_cast<vgui::TreeFolder*>(getChild(i));
    if (lpsrc)
      setOpenedTraverse(true);
  }
}

void vgui::TreeFolder::paintBackground()
{
  int tall, wide;
  int y_0, x_0;

  v1 = 10;
  v2 = 1;
  (*((void(__cdecl**)(vgui::TreeFolder* const, int))_vptr_Panel + 93))(this, 1);


  while (1)
  {
    v4 = v2 < (*((int(__cdecl**)(vgui::TreeFolder* const))_vptr_Panel + 43))(this);
    v5 = _vptr_Panel;
    if (!v4)
      break;
    v6 = (const void*)v5[44](this, v2);
    (*(void(__cdecl**)(const void*, int*, int*, int*, int*))(*(_DWORD*)v6 + 20))(v6, &y_0, tall, x_0, wide);
    if (_dynamic_cast(
      v6,
      (const struct __class_type_info*)&`typeinfo for'vgui::Panel,
      (const struct __class_type_info*)&`typeinfo for'vgui::TreeFolder,
      0))
    {
      v3 = tall[0] + 10;
      tall[0] += 10;
    }
    else
    {
      v3 = tall[0] + wide[0] / 2;
      tall[0] = v3;
    }
    ++v2;
    (*((void(__cdecl**)(vgui::TreeFolder* const, int, int, int, int))_vptr_Panel + 95))(
      this,
      15,
      v3,
      30,
      v3 + 1);
    v1 = tall[0];
  }
  v7 = 1;
  v5[95](this, 15, 10, 16, v1);
  if ((*((int(__cdecl**)(vgui::TreeFolder* const))_vptr_Panel + 43))(this) > 1)
  {
    do
    {
      v8 = (const void*)(*((int(__cdecl**)(vgui::TreeFolder* const, int))_vptr_Panel + 44))(this, v7);
      (*(void(__cdecl**)(const void*, int*, int*, int*, int*))(*(_DWORD*)v8 + 20))(v8, x_0, &y_0, wide, tall);
      v9 = _dynamic_cast(
        v8,
        (const struct __class_type_info*)&`typeinfo for'vgui::Panel,
        (const struct __class_type_info*)&`typeinfo for'vgui::TreeFolder,
        0);
      if (v9
        && (v10 = _vptr_Panel,
          y_0 += 10,
          v10[93](this, 2),
          (*((void(__cdecl**)(vgui::TreeFolder* const, int, int, int, int))_vptr_Panel + 95))(
            this,
            10,
            y_0 - 5,
            21,
            y_0 + 6),
          (*((void(__cdecl**)(vgui::TreeFolder* const, int))_vptr_Panel + 93))(this, 1),
          (*((void(__cdecl**)(vgui::TreeFolder* const, int, int, int, int))_vptr_Panel + 96))(
            this,
            10,
            y_0 - 5,
            21,
            y_0 + 6),
          (*((void(__cdecl**)(vgui::TreeFolder* const, int, int, int, int))_vptr_Panel + 95))(
            this,
            12,
            y_0,
            19,
            y_0 + 1),
          !(*(uint8_t(__cdecl**)(void*))(*(_DWORD*)v9 + 520))(v9)))
      {
        ++v7;
        (*((void(__cdecl**)(vgui::TreeFolder* const, int, int, int, int))_vptr_Panel + 95))(
          this,
          15,
          y_0 - 3,
          16,
          y_0 + 4);
      }
      else
      {
        ++v7;
      }
    } while (v7 < (*((int(__cdecl**)(vgui::TreeFolder* const))_vptr_Panel + 43))(this));
  }
}

void vgui::TreeFolder::setOpened(bool state)
{
  vgui::TreeFolder* lpsrc; // ebx
  void* v3; // esi
  void* v4; // eax

  lpsrc = this;
  if (_opened != state)
  {
    _opened = state;
    v3 = 0;
    do
    {
      v4 = _dynamic_cast(
        lpsrc,
        (const struct __class_type_info*)&`typeinfo for'vgui::Panel,
        (const struct __class_type_info*)&`typeinfo for'vgui::TreeFolder,
        0);
      if (v4)
      {
        v3 = v4;
        (*(void(__cdecl**)(void*, int))(*(_DWORD*)v4 + 184))(v4, 1);
      }
      lpsrc = (vgui::TreeFolder*)(*((int(__cdecl**)(vgui::TreeFolder*))lpsrc->_vptr_Panel + 8))(lpsrc);
    } while (lpsrc);
    if (v3)
      (*(void(__cdecl**)(void*))(*(_DWORD*)v3 + 268))(v3);
  }
}

class FooTreeFolderDefaultHandler : public vgui::InputSignal
{
public:
  FooTreeFolderDefaultHandler(vgui::TreeFolder* treeFolder) : _treeFolder{ treeFolder } {}

  virtual void cursorMoved(int x, int y, vgui::Panel* panel) {}
  virtual void cursorEntered(vgui::Panel* panel) {}
  virtual void cursorExited(vgui::Panel* panel) {}
  virtual void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
  {
    _treeFolder->setOpened(!_treeFolder->isOpened());
  }
  virtual void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
  virtual void mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
  virtual void mouseWheeled(int delta, vgui::Panel* panel) {}
  virtual void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
  virtual void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
  virtual void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
  virtual void keyFocusTicked(vgui::Panel* panel) {}

protected:
  vgui::TreeFolder* _treeFolder;
};

class FooTabFolderVerticalLayout : public vgui::Layout
{
private:
  int _hgap, _vgap;
public:
  FooTabFolderVerticalLayout(int hgap, int vgap) : _hgap{ hgap }, _vgap{ vgap } {}

  virtual void performLayout(vgui::Panel* panel)
  {
    int maxx = 0;
    int wide, tall;
    int y = 0;

    for (auto i = 0; i < panel->getChildCount(); ++i)
    {
      auto child = panel->getChild(i);
      auto tchild = dynamic_cast<vgui::TreeFolder*>(child);
      if (tchild)
        tchild->invalidateLayout(true);

      child->getSize(wide, tall);
      child->setPos(i ? _hgap : 0, y);

      maxx = std::max(maxx, wide + (i ? _hgap : 0));
      y += tall + _vgap;
    }

    auto tree_panel = dynamic_cast<vgui::TreeFolder*>(panel);
    if (tree_panel)
    {
      if (tree_panel->isOpened())
        tree_panel->setSize(maxx + 2, y);
      else if (tree_panel->getChild(0))
      {
        tree_panel->getChild(0)->getSize(wide, tall);
        tree_panel->setSize(wide, tall);
      }
    }
  }
};

void vgui::TreeFolder::init(const char* name)
{
  _opened = false;

  auto label = new vgui::Label{ name, 0, 0 };
  label->addInputSignal(new FooTreeFolderDefaultHandler{ this });
  label->setParent(this);

  setLayout(new FooTabFolderVerticalLayout{54, 0}); // ???
}

vgui::TreeFolder::TreeFolder(const char* name)
  : vgui::Panel{ 0, 0, 500, 500 }
{
  init(name);
}

vgui::TreeFolder::TreeFolder(const char* name, int x, int y)
  : vgui::Panel{ x, y, 500, 500 }
{
  init(name);
}