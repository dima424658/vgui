#pragma once

#include <VGUI_ActionSignal.h>
#include <VGUI_WizardPanel.h>

namespace handlers
{
  class FooBackHandler : public vgui::ActionSignal
  {
  public:
    FooBackHandler(vgui::WizardPanel* wizardPanel);
    virtual void actionPerformed(vgui::Panel* panel);

  protected:
    vgui::WizardPanel* _wizardPanel;
  };

  class FooNextHandler : public vgui::ActionSignal
  {
  public:
    FooNextHandler(vgui::WizardPanel* wizardPanel);
    virtual void actionPerformed(vgui::Panel* panel);

  protected:
    vgui::WizardPanel* _wizardPanel;
  };
};