#include <VGUI_ToggleButton.h>

#include <VGUI_ButtonController.h>
#include <VGUI_InputSignal.h>

class FooDefaultToggleButtonController : public vgui::ButtonController, public vgui::InputSignal
{
private:
	vgui::ToggleButton* _button;
public:
	FooDefaultToggleButtonController(vgui::ToggleButton* button) : _button{ button } {}
	virtual void addSignals(vgui::Button* button)
	{
		button->addInputSignal(this);
	}

	virtual void removeSignals(vgui::Button* button)
	{
		button->removeInputSignal(this);
	}

	virtual void cursorMoved(int x, int y, vgui::Panel* panel) {}
	virtual void cursorEntered(vgui::Panel* panel) {}
	virtual void cursorExited(vgui::Panel* panel) {}
	virtual void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
	{
		_button->setSelected(!_button->isSelected());
		_button->fireActionSignal();
		_button->repaint();
	}
	virtual void mouseDoublePressed(vgui::MouseCode code, vgui::Panel* panel) {}
	virtual void mouseReleased(vgui::MouseCode code, vgui::Panel* panel) {}
	virtual void mouseWheeled(int delta, vgui::Panel* panel) {}
	virtual void keyPressed(vgui::KeyCode code, vgui::Panel* panel) {}
	virtual void keyTyped(vgui::KeyCode code, vgui::Panel* panel) {}
	virtual void keyReleased(vgui::KeyCode code, vgui::Panel* panel) {}
	virtual void keyFocusTicked(vgui::Panel* panel) {}
};

vgui::ToggleButton::ToggleButton(const char* text, int x, int y, int wide, int tall)
	: vgui::Button{ text, x, y, wide, tall }
{
	vgui::ButtonController* controller = new FooDefaultToggleButtonController{this};
	setButtonController(controller);
}

vgui::ToggleButton::ToggleButton(const char* text, int x, int y)
	: vgui::Button{ text, x, y }
{
	vgui::ButtonController* controller = new FooDefaultToggleButtonController{this};
	setButtonController(controller);
}