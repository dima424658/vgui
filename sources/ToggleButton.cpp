#include <VGUI_ToggleButton.h>
#include <VGUI_ButtonController.h>
#include <VGUI_InputSignal.h>

namespace
{
    class FooDefaultToggleButtonController : public vgui::ButtonController, public vgui::InputSignal
    {
    private:
        vgui::ToggleButton* _button;

    public:
        FooDefaultToggleButtonController(vgui::ToggleButton* button) : _button{ button } {}

        void addSignals(vgui::Button* button) { button->addInputSignal(this); }
        void removeSignals(vgui::Button* button) { button->removeInputSignal(this); }

        void mousePressed(vgui::MouseCode code, vgui::Panel* panel)
        {
            _button->setSelected(!_button->isSelected());
            _button->fireActionSignal();
            _button->repaint();
        }
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

vgui::ToggleButton::ToggleButton(const char* text, int x, int y, int wide, int tall)
	: vgui::Button{ text, x, y, wide, tall }
{
	auto controller = new FooDefaultToggleButtonController{this};
	setButtonController(controller);
}

vgui::ToggleButton::ToggleButton(const char* text, int x, int y)
	: vgui::Button{ text, x, y }
{
	auto controller = new FooDefaultToggleButtonController{this};
	setButtonController(controller);
}