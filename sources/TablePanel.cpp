#include <algorithm>

#include <VGUI_TablePanel.h>
#include <VGUI_HeaderPanel.h>
#include <VGUI_ChangeSignal.h>
#include <VGUI_InputSignal.h>
#include <VGUI_RepaintSignal.h>

namespace
{
  class FooVGuiTablePanelHandler : public vgui::InputSignal, public vgui::RepaintSignal, public vgui::ChangeSignal
  {
  private:
    vgui::TablePanel* _table;

  public:
    FooVGuiTablePanelHandler(vgui::TablePanel* table) : _table{ table } {}
    
    void valueChanged(vgui::Panel* panel)
    {
      int cols = _table->getColumnCount();
      int x0, x1;

      auto header = dynamic_cast<vgui::HeaderPanel*>(panel);

      for (auto i = 0; i < header->getSectionCount() && i < cols; ++i)
      {
        header->getSectionExtents(i, x0, x1);
        _table->setColumnExtents(i, x0, x1);
      }
    }

    void panelRepainted(vgui::Panel* panel) { _table->repaint(); }

    void mousePressed(vgui::MouseCode code, vgui::Panel* panel) { _table->privateMousePressed(code, panel); }
    void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) { _table->privateMouseDoublePressed(code, panel); }
    void keyTyped(vgui::KeyCode code, vgui::Panel* panel) { _table->privateKeyTyped(code, panel); }
    void cursorMoved(int x, int y, vgui::Panel* panel) {}
    void cursorEntered(vgui::Panel* panel) {}
    void cursorExited(vgui::Panel* panel) {}
    void mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
    void mouseWheeled(int delta, vgui::Panel* panel) {}
    void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
    void keyFocusTicked(vgui::Panel* panel) {}
  };
};

void vgui::TablePanel::setCellEditingEnabled(bool state)
{
  _cellEditingEnabled = state;
}

void vgui::TablePanel::setGridSize(int wide, int tall)
{
  _gridWide = wide;
  _gridTall = tall;
}

void vgui::TablePanel::setGridVisible(bool horizontal, bool vertical)
{
  _gridVisible[0] = horizontal;
  _gridVisible[1] = horizontal;
}

int vgui::TablePanel::getColumnCount()
{
  return _columnDar.getCount();
}

void vgui::TablePanel::setColumnExtents(int column, int x0, int x1)
{
  _columnDar.setElementAt((x0 << 12) + x1, column);
  repaint(); // ???
}

void vgui::TablePanel::setSelectedCell(int column, int row)
{
  if (_selectedCell[0] != column || _selectedCell[1] != row)
  {
    repaint();
    stopCellEditing();
  }

  _selectedCell[0] = column;
  _selectedCell[1] = row;
}

void vgui::TablePanel::getSelectedCell(int& column, int& row)
{
  column = _selectedCell[0];
  row = _selectedCell[1];
}

void vgui::TablePanel::setColumnSelectionEnabled(bool state)
{
  _columnSelectionEnabled = state;
  repaint();
}

void vgui::TablePanel::setRowSelectionEnabled(bool state)
{
  _rowSelectionEnabled = state;
  repaint();
}

void vgui::TablePanel::setCellSectionEnabled(bool state)
{
  _cellSelectionEnabled = state;
  repaint();
}

void vgui::TablePanel::setEditableCell(int column, int row)
{
  if (_editableCell[0] != column || _editableCell[1] != row)
  {
    stopCellEditing();
    _editableCellPanel = isWithinTraverse(column, row);
    if (_editableCellPanel)
      _editableCellPanel->setParent(this);
  }

  _editableCell[0] = column;
  _editableCell[1] = row;
}

void vgui::TablePanel::stopCellEditing()
{
  if (_editableCellPanel)
  {
    _editableCellPanel->setParent(nullptr);
    _editableCellPanel = nullptr;
    _editableCell[0] = -1;
    _editableCell[1] = -1;
  }
}

void vgui::TablePanel::getVirtualSize(int& wide, int& tall)
{
  wide = _virtualSize[0];
  tall = _virtualSize[1];
}

void vgui::TablePanel::paint()
{
  bool cellSelected;
  int x0;
  int x1;
  vgui::Color fgColor;
  int wide, tall;
  int r, g, b, a;

  int x1gap = _gridWide - (_gridWide / 2 - 1);
  int x0gap = _gridWide / 2 - 1;

  getPaintSize(wide, tall);
  getFgColor(fgColor);
  fgColor.getColor(r, g, b, a);

  if (_gridVisible[1])
    for (auto i = 0; i < _columnDar.getCount(); ++i)
    {
      drawSetColor(r, g, b, a);
      drawFilledRect(_columnDar[i] & 0xFFF - x1gap, 0, x0gap + _columnDar[i] & 0xFFF, tall);
    }

  int yOffset = 0;
  if (_gridVisible[0])
    for (auto i = 0; i < getRowCount(); ++i)
    {
      drawSetColor(r, g, b, a);
      drawFilledRect(0, yOffset, _columnDar[i] & 0xFFF, yOffset + _gridTall);
      yOffset += _gridTall + getCellTall(i);
    }

  _virtualSize[0] = 0;
  _virtualSize[1] = 0;

  for (auto j = 0; j < _columnDar.getCount(); ++j)
  {
    x0 = x0gap + ((_columnDar[j] >> 12) & 0xFFF);
    x1 = (_columnDar[j] & 0xFFF) - x1gap;
    if (x1 > _virtualSize[0])
      _virtualSize[0] = x1;

    auto tallOffset = _gridTall;
    for (auto i = x1 - x0; i < getRowCount(); ++i)
    {
      cellSelected = false;
      if (_cellSelectionEnabled && _selectedCell[0] == j)
        cellSelected = i == _selectedCell[1];

      if (_editableCell[0] == j && _editableCell[1] == i)
      {
        if (_editableCellPanel)
        {
          _editableCellPanel->setBounds(x0, _gridTall, i, getCellTall(i));
          _editableCellPanel->repaint();
          _editableCellPanel->solveTraverse();
        }
      }
      else
      {
        auto cell = getCellRenderer(j, i, _columnSelectionEnabled && (j == _selectedCell[0]), _rowSelectionEnabled && (i == _selectedCell[1]), cellSelected);
        if (cell)
        {
          cell->setParent(this);
          cell->setBounds(x0, tallOffset, i, getCellTall(i));
          cell->repaint();
          cell->solveTraverse();
          cell->paintTraverse();
          cell->setParent(nullptr);
        }
      }

      tallOffset += _gridTall + getCellTall(i);
      if (tallOffset > _virtualSize[1])
        _virtualSize[1] = x1;
    }
  }
}

void vgui::TablePanel::setHeaderPanel(vgui::HeaderPanel* header)
{
  header->addChangeSignal(new FooVGuiTablePanelHandler{ this });
  header->fireChangeSignal();

  repaint();
}

void vgui::TablePanel::privateMousePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  if (_cellEditingEnabled)
  {
    setSelectedCell(_mouseOverCell[0], _mouseOverCell[1]);
    requestFocus();
  }
}

void vgui::TablePanel::privateMouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel)
{
  int col, row;

  if (_cellEditingEnabled)
  {
    setSelectedCell(_mouseOverCell[0], _mouseOverCell[1]);
    getSelectedCell(col, row);
    setEditableCell(col, row);
  }
}

void vgui::TablePanel::privateKeyTyped(vgui::KeyCode code, vgui::Panel* panel)
{
  int col, row;

  if (_cellEditingEnabled)
  {
    getSelectedCell(col, row);
    switch (code)
    {
    case KEY_ENTER:
      setEditableCell(col, row);
      return;
    case KEY_UP:
      setSelectedCell(col, std::min(0, --row));
      return;
    case KEY_LEFT:
      setSelectedCell(std::min(0, --col), row);
      return;
    case KEY_DOWN:
      setSelectedCell(col, ++row);
      return;
    case KEY_RIGHT:
      setSelectedCell(++col, row);
      return;
    default:
      return;
    }
  }
}

void vgui::TablePanel::setColumnCount(int columnCount)
{
  _columnDar.setCount(columnCount);
}

vgui::TablePanel::TablePanel(int x, int y, int wide, int tall, int columnCount)
  : vgui::Panel{ x, y, wide, tall },
  _gridWide{ 2 },
  _gridTall{ 2 },
  _gridVisible{ false, false },
  _selectedCell{ -1, -1 },
  _mouseOverCell{ 0, 0 },
  _fakeInputPanel{ new vgui::Panel{} },
  _editableCell{ -1, -1 },
  _virtualSize{ wide, tall },
  _editableCellPanel{ nullptr },
  _columnSelectionEnabled{ false },
  _rowSelectionEnabled{ true },
  _cellSelectionEnabled{ true },
  _cellEditingEnabled{ true }
{
  vgui::Color p_color{ vgui::Scheme::SchemeColor::sc_white };
  setFgColor(p_color);

  addInputSignal(new FooVGuiTablePanelHandler{ this });
}