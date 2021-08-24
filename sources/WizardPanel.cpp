#include <VGUI_WizardPanel.h>

#include <VGUI_ActionSignal.h>
#include <VGUI_Button.h>
#include <VGUI_App.h>

#include "handlers/FooBackNextHandler.h"

void vgui::WizardPanel::WizardPage::init()
{
  _backWizardPage = nullptr;
  _nextButtonText = nullptr;
  _finishedButtonText = nullptr;
  _cancelButtonText = nullptr;
  _wantedFocus = nullptr;
  _title = nullptr;

  _nextWizardPage = nullptr;
  _backButtonText = nullptr;
  _backButtonEnabled = false;
  _nextButtonEnabled = false;
  _finishedButtonEnabled = false;
  _cancelButtonEnabled = true;
  _backButtonVisible = true;
  _nextButtonVisible = true;
  _finishedButtonVisible = true;
  _cancelButtonVisible = true;

  setTitle("Untitled");

  setBackButtonText("<< Back");
  setNextButtonText("Next >>");
  setFinishedButtonText("Finished");
  setCancelButtonText("Cancel");
}

void vgui::WizardPanel::WizardPage::setBackWizardPage(vgui::WizardPanel::WizardPage* backWizardPage)
{
  _backWizardPage = backWizardPage;
  setBackButtonEnabled(backWizardPage != 0);
}

void vgui::WizardPanel::WizardPage::setNextWizardPage(vgui::WizardPanel::WizardPage* nextWizardPage)
{
  _nextWizardPage = nextWizardPage;
  setNextButtonEnabled(nextWizardPage != 0);
}

vgui::WizardPanel::WizardPage* vgui::WizardPanel::WizardPage::getBackWizardPage()
{
  return _backWizardPage;
}

vgui::WizardPanel::WizardPage* vgui::WizardPanel::WizardPage::getNextWizardPage()
{
  return _nextWizardPage;
}

bool vgui::WizardPanel::WizardPage::isBackButtonEnabled()
{
  return _backButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isNextButtonEnabled()
{
  return _nextButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isFinishedButtonEnabled()
{
  return _finishedButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isCancelButtonEnabled()
{
  return _cancelButtonEnabled;
}

void vgui::WizardPanel::WizardPage::setBackButtonEnabled(bool state)
{
  _backButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setNextButtonEnabled(bool state)
{
  _nextButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setFinishedButtonEnabled(bool state)
{
  _finishedButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setCancelButtonEnabled(bool state)
{
  _cancelButtonEnabled = state;
}

bool vgui::WizardPanel::WizardPage::isBackButtonVisible()
{
  return _backButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isNextButtonVisible()
{
  return _nextButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isFinishedButtonVisible()
{
  return _finishedButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isCancelButtonVisible()
{
  return _cancelButtonVisible;
}

void vgui::WizardPanel::WizardPage::setBackButtonVisible(bool state)
{
  _backButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setNextButtonVisible(bool state)
{
  _nextButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setFinishedButtonVisible(bool state)
{
  _finishedButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setCancelButtonVisible(bool state)
{
  _cancelButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::fireSwitchingToBackPageSignals()
{
  for (auto i = 0; i < _switchingToBackPageSignalDar.getCount(); ++i)
    _switchingToBackPageSignalDar[i]->actionPerformed(this);
}

void vgui::WizardPanel::WizardPage::fireSwitchingToNextPageSignals()
{
  for (auto i = 0; i < _switchingToNextPageSignalDar.getCount(); ++i)
    _switchingToNextPageSignalDar[i]->actionPerformed(this);
}

void vgui::WizardPanel::WizardPage::setWantedFocus(vgui::Panel* panel)
{
  _wantedFocus = panel;
}

void vgui::WizardPanel::performLayout()
{
  char buf[256];
  int wide, tall;

  getPaintSize(wide, tall);

  _backButton->setVisible(false);
  _nextButton->setVisible(false);
  _finishedButton->setVisible(false);
  _cancelButton->setVisible(false);

  if (!_currentWizardPage)
    return;

  wide -= 4;
  _currentWizardPage->setBounds(2, 2, wide, tall - _backButton->getTall() - 2);

  _currentWizardPage->getCancelButtonText(buf, 256);
  _cancelButton->setText(buf);
  _cancelButton->setEnabled(_currentWizardPage->isCancelButtonEnabled());
  _cancelButton->setVisible(_currentWizardPage->isCancelButtonVisible());
  _cancelButton->setPos(wide - _cancelButton->getWide(), tall - _backButton->getTall() - 2);

  if (_currentWizardPage->isCancelButtonVisible())
    wide -= _cancelButton->getWide() + 4;

  _currentWizardPage->getFinishedButtonText(buf, 256);
  _finishedButton->setText(buf);
  _finishedButton->setEnabled(_currentWizardPage->isFinishedButtonEnabled());
  _finishedButton->setVisible(_currentWizardPage->isFinishedButtonVisible());
  _finishedButton->setPos(wide - _finishedButton->getWide(), tall - _backButton->getTall() - 2);

  if (_currentWizardPage->isFinishedButtonVisible())
    wide -= _finishedButton->getWide() + 4;

  _currentWizardPage->getFinishedButtonText(buf, 256);
  _nextButton->setText(buf);
  _nextButton->setEnabled(_currentWizardPage->isNextButtonEnabled());
  _nextButton->setVisible(_currentWizardPage->isNextButtonVisible());
  _nextButton->setPos(wide - _nextButton->getWide(), tall - _backButton->getTall() - 2);

  if (_currentWizardPage->isNextButtonVisible())
    wide -= _nextButton->getWide() + 4;

  _currentWizardPage->getFinishedButtonText(buf, 256);
  _backButton->setText(buf);
  _backButton->setEnabled(_currentWizardPage->isBackButtonEnabled());
  _backButton->setVisible(_currentWizardPage->isBackButtonVisible());
  _backButton->setPos(wide - _backButton->getWide(), tall - _backButton->getTall() - 2);

  if (_currentWizardPage->isBackButtonVisible())
    wide -= _backButton->getWide() + 4;
}

void vgui::WizardPanel::setCurrentWizardPage(vgui::WizardPanel::WizardPage* currentWizardPage)
{
  if (_currentWizardPage)
    removeChild(_currentWizardPage);

  _currentWizardPage = currentWizardPage;
  if (currentWizardPage)
  {
    currentWizardPage->setParent(this);

    getApp()->requestFocus(_currentWizardPage->getWantedFocus());
  }

  firePageChangedActionSignal();
  invalidateLayout(false);
}

void vgui::WizardPanel::addFinishedActionSignal(vgui::ActionSignal* s)
{
  _finishedButton->addActionSignal(s);
}

void vgui::WizardPanel::addCancelledActionSignal(vgui::ActionSignal* s)
{
  _cancelButton->addActionSignal(s);
}

void vgui::WizardPanel::fireFinishedActionSignal()
{
  _finishedButton->fireActionSignal()
}

void vgui::WizardPanel::fireCancelledActionSignal()
{
  _cancelButton->fireActionSignal();
}

void vgui::WizardPanel::firePageChangedActionSignal()
{
  for (auto i = 0; i < _pageChangedActionSignalDar.getCount(); ++i)
    _pageChangedActionSignalDar[i]->actionPerformed(this);
}

void vgui::WizardPanel::doBack()
{
  if (_currentWizardPage)
  {
    _currentWizardPage->fireSwitchingToBackPageSignals();
    setCurrentWizardPage(_currentWizardPage->getBackWizardPage());
  }
}

void vgui::WizardPanel::doNext()
{
  if (_currentWizardPage)
  {
    _currentWizardPage->fireSwitchingToNextPageSignals();
    setCurrentWizardPage(_currentWizardPage->getNextWizardPage());
  }
}

void vgui::WizardPanel::getCurrentWizardPageTitle(char* buf, int bufLen)
{
  _currentWizardPage->getTitle(buf, bufLen);
}

vgui::WizardPanel::WizardPage* vgui::WizardPanel::getCurrentWizardPage()
{
  return _currentWizardPage;
}

void vgui::WizardPanel::WizardPage::getTitle(char* buf, int bufLen)
{
  vgui::vgui_strcpy(buf, bufLen, _title);
}

void vgui::WizardPanel::WizardPage::setTitle(const char* title)
{
  delete [] _title;
  _title = vgui::vgui_strdup(title);
}

void vgui::WizardPanel::WizardPage::setCancelButtonText(const char* text)
{
  delete [] _cancelButtonText;
  _cancelButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setFinishedButtonText(const char* text)
{
  delete [] _finishedButtonText;
  _finishedButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setNextButtonText(const char* text)
{
  delete [] _nextButtonText;
  _nextButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setBackButtonText(const char* text)
{
  delete [] _backButtonText;
  _backButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::getBackButtonText(char* text, int textLen)
{
  vgui::vgui_strcpy(text, textLen, _backButtonText);
}

void vgui::WizardPanel::WizardPage::getCancelButtonText(char* text, int textLen)
{
  vgui::vgui_strcpy(text, textLen, _cancelButtonText);
}

void vgui::WizardPanel::WizardPage::getFinishedButtonText(char* text, int textLen)
{
  vgui::vgui_strcpy(text, textLen, _finishedButtonText);
}

void vgui::WizardPanel::WizardPage::getNextButtonText(char* text, int textLen)
{
  vgui::vgui_strcpy(text, textLen, _nextButtonText);
}

void vgui::WizardPanel::WizardPage::addSwitchingToNextPageSignal(vgui::ActionSignal* s)
{
  _switchingToNextPageSignalDar.addElement(s);
}

void vgui::WizardPanel::WizardPage::addSwitchingToBackPageSignal(vgui::ActionSignal* s)
{
  _switchingToBackPageSignalDar.addElement(s);
}

void vgui::WizardPanel::addPageChangedActionSignal(vgui::ActionSignal* s)
{
  _pageChangedActionSignalDar.addElement(s);
}

vgui::WizardPanel::WizardPage::WizardPage()
  : vgui::Panel{ 0, 0, 64, 64 }
{
  init();
}

vgui::WizardPanel::WizardPage::WizardPage(int wide, int tall)
  : vgui::Panel{ 0, 0, wide, tall }
{
  init();
}

vgui::WizardPanel::WizardPanel(int x, int y, int wide, int tall)
  : vgui::Panel{ x, y, wide, tall }
{
  _currentWizardPage = nullptr;

  _backButton = new vgui::Button{ "back", 20, 100 };
  _backButton->setParent(this);
  _backButton->addActionSignal(new handlers::FooBackHandler(this));

  _nextButton = new vgui::Button{ "next", 80, 100 };
  _nextButton->setParent(this);
  _nextButton->addActionSignal(new handlers::FooNextHandler(this));

  _finishedButton = new vgui::Button{ "finished", 120, 100 };
  _finishedButton->setParent(this);

  _cancelButton = new vgui::Button{ "cancel", 180, 100 };
  _cancelButton->setParent(this);
}

