#include <VGUI_TreeFolder.h>

#include <VGUI_Label.h>
#include <VGUI_Layout.h>
#include <VGUI_InputSignal.h>

namespace
{
  class FooTabFolderVerticalLayout : public vgui::Layout
  {
  private:
    int _hgap, _vgap;

  public:
    FooTabFolderVerticalLayout(int hgap, int vgap) : _hgap{ hgap }, _vgap{ vgap }{}

    void performLayout(vgui::Panel* panel)
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

  class FooTreeFolderDefaultHandler : public vgui::InputSignal
  {
  private:
    vgui::TreeFolder* _treeFolder;
  public:
    FooTreeFolderDefaultHandler(vgui::TreeFolder* treeFolder) : _treeFolder{ treeFolder } {}

    void mousePressed(vgui::MouseCode code, vgui::Panel* panel) { _treeFolder->setOpened(!_treeFolder->isOpened()); }
    void cursorMoved(int x, int y, vgui::Panel* panel) {}
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
}

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

  auto y_1 = 10;

  drawSetColor(vgui::Scheme::SchemeColor::sc_black);

  for (auto i = 0; i < getChildCount(); ++i)
  {
    auto child = getChild(i);
    child->getBounds(x_0, y_0, wide, tall);

    auto folder = dynamic_cast<vgui::TreeFolder*>(child);
    int v3;
    if (folder)
    {
      v3 = y_0 + 10;
      y_0 += 10;
    }
    else
    {
      v3 = y_0 + tall / 2;
      y_0 = v3;
    }

    y_1 = y_0;
    drawFilledRect(15, v3, 30, v3 + 1);
  }

  drawFilledRect(15, 10, 16, y_1);
  for (auto i = 0; i < getChildCount(); ++i)
  {
    auto child = getChild(i);
    child->getBounds(x_0, y_0, wide, tall);

    auto folder = dynamic_cast<vgui::TreeFolder*>(child);
    if (folder)
    {
      y_0 += 10;
      drawSetColor(vgui::Scheme::SchemeColor::sc_white);
      drawFilledRect(10, y_0 - 5, 21, y_0 + 6);
      drawOutlinedRect(10, y_0 - 5, 21, y_0 + 6);
      drawFilledRect(12, y_0, 19, y_0 + 1);

      if (!folder->isOpened())
        drawFilledRect(15, y_0 - 3, 16, y_0 + 4);
    }
  }
}

void vgui::TreeFolder::setOpened(bool state)
{
  vgui::Panel* lpsrc = this;

  if (_opened != state)
  {
    _opened = state;

    vgui::TreeFolder* folder = nullptr;
    while (lpsrc)
    {
      folder = dynamic_cast<vgui::TreeFolder*>(lpsrc);
      if (folder)
        folder->invalidateLayout(true);
      lpsrc = lpsrc->getParent();
    }

    if (folder)
      folder->repaintParent();
  }
}

void vgui::TreeFolder::init(const char* name)
{
  _opened = false;

  auto label = new vgui::Label{ name, 0, 0 };
  label->addInputSignal(new handlers::FooTreeFolderDefaultHandler{ this });
  label->setParent(this);

  setLayout(new handlers::FooTabFolderVerticalLayout{ 54, 0 }); // ???
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