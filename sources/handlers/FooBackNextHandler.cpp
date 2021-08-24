#include "FooBackNextHandler.h"

handlers::FooBackHandler::FooBackHandler(vgui::WizardPanel* wizardPanel)
  : _wizardPanel{ wizardPanel }
{
}

void handlers::FooBackHandler::actionPerformed(vgui::Panel* panel)
{
  _wizardPanel->doBack();
}

handlers::FooNextHandler::FooNextHandler(vgui::WizardPanel* wizardPanel)
  : _wizardPanel{ wizardPanel }
{
}

void handlers::FooNextHandler::actionPerformed(vgui::Panel* panel)
{
  _wizardPanel->doNext();
}