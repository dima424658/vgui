#include <VGUI_WizardPanel.h>

void vgui::WizardPanel::WizardPage::init(vgui::WizardPanel::WizardPage *const this)
{
  int (**v2)(...); // eax

  this->_backWizardPage = 0;
  this->_nextButtonText = 0;
  this->_finishedButtonText = 0;
  this->_cancelButtonText = 0;
  this->_wantedFocus = 0;
  this->_title = 0;
  v2 = this->_vptr_Panel;
  this->_nextWizardPage = 0;
  this->_backButtonText = 0;
  this->_backButtonEnabled = 0;
  this->_nextButtonEnabled = 0;
  this->_finishedButtonEnabled = 0;
  this->_cancelButtonEnabled = 1;
  this->_backButtonVisible = 1;
  this->_nextButtonVisible = 1;
  this->_finishedButtonVisible = 1;
  this->_cancelButtonVisible = 1;
  v2[162](this, "Untitled");
  (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *const, const char *))this->_vptr_Panel + 154))(this, "<< Back");
  (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *const, const char *))this->_vptr_Panel + 155))(this, "Next >>");
  (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *const, const char *))this->_vptr_Panel + 156))(this, "Finished");
  (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *const, const char *))this->_vptr_Panel + 157))(this, "Cancel");
}

void vgui::WizardPanel::WizardPage::setBackWizardPage(vgui::WizardPanel::WizardPage *const this, vgui::WizardPanel::WizardPage *backWizardPage)
{
  int (**v2)(...); // ecx

  v2 = this->_vptr_Panel;
  this->_backWizardPage = backWizardPage;
  v2[138](this, backWizardPage != 0);
}

void vgui::WizardPanel::WizardPage::setNextWizardPage(vgui::WizardPanel::WizardPage *const this, vgui::WizardPanel::WizardPage *nextWizardPage)
{
  int (**v2)(...); // ecx

  v2 = this->_vptr_Panel;
  this->_nextWizardPage = nextWizardPage;
  v2[139](this, nextWizardPage != 0);
}

vgui::WizardPanel::WizardPage *__cdecl vgui::WizardPanel::WizardPage::getBackWizardPage(vgui::WizardPanel::WizardPage *const this)
{
  return this->_backWizardPage;
}

vgui::WizardPanel::WizardPage *__cdecl vgui::WizardPanel::WizardPage::getNextWizardPage(vgui::WizardPanel::WizardPage *const this)
{
  return this->_nextWizardPage;
}

bool vgui::WizardPanel::WizardPage::isBackButtonEnabled(vgui::WizardPanel::WizardPage *const this)
{
  return this->_backButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isNextButtonEnabled(vgui::WizardPanel::WizardPage *const this)
{
  return this->_nextButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isFinishedButtonEnabled(vgui::WizardPanel::WizardPage *const this)
{
  return this->_finishedButtonEnabled;
}

bool vgui::WizardPanel::WizardPage::isCancelButtonEnabled(vgui::WizardPanel::WizardPage *const this)
{
  return this->_cancelButtonEnabled;
}

void vgui::WizardPanel::WizardPage::setBackButtonEnabled(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_backButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setNextButtonEnabled(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_nextButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setFinishedButtonEnabled(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_finishedButtonEnabled = state;
}

void vgui::WizardPanel::WizardPage::setCancelButtonEnabled(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_cancelButtonEnabled = state;
}

bool vgui::WizardPanel::WizardPage::isBackButtonVisible(vgui::WizardPanel::WizardPage *const this)
{
  return this->_backButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isNextButtonVisible(vgui::WizardPanel::WizardPage *const this)
{
  return this->_nextButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isFinishedButtonVisible(vgui::WizardPanel::WizardPage *const this)
{
  return this->_finishedButtonVisible;
}

bool vgui::WizardPanel::WizardPage::isCancelButtonVisible(vgui::WizardPanel::WizardPage *const this)
{
  return this->_cancelButtonVisible;
}

void vgui::WizardPanel::WizardPage::setBackButtonVisible(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_backButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setNextButtonVisible(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_nextButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setFinishedButtonVisible(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_finishedButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::setCancelButtonVisible(vgui::WizardPanel::WizardPage *const this, bool state)
{
  this->_cancelButtonVisible = state;
}

void vgui::WizardPanel::WizardPage::fireSwitchingToBackPageSignals(vgui::WizardPanel::WizardPage *const this)
{
  int v1; // ebx
  vgui::ActionSignal *v2; // eax

  if ( this->_switchingToBackPageSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_switchingToBackPageSignalDar._data[v1++];
      (*v2->_vptr_ActionSignal)(v2, this);
    }
    while ( this->_switchingToBackPageSignalDar._count > v1 );
  }
}

void vgui::WizardPanel::WizardPage::fireSwitchingToNextPageSignals(vgui::WizardPanel::WizardPage *const this)
{
  int v1; // ebx
  vgui::ActionSignal *v2; // eax

  if ( this->_switchingToNextPageSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_switchingToNextPageSignalDar._data[v1++];
      (*v2->_vptr_ActionSignal)(v2, this);
    }
    while ( this->_switchingToNextPageSignalDar._count > v1 );
  }
}

void vgui::WizardPanel::WizardPage::setWantedFocus(vgui::WizardPanel::WizardPage *const this, vgui::Panel *panel)
{
  this->_wantedFocus = panel;
}

void vgui::WizardPanel::performLayout(vgui::WizardPanel *const this)
{
  int v2; // esi
  int v3; // ebp
  int v4; // edi
  uint8_t v5; // al
  uint8_t v6; // al
  vgui::Button *v7; // edx
  int v8; // eax
  uint8_t v9; // al
  uint8_t v10; // al
  vgui::Button *v11; // edx
  int v12; // eax
  uint8_t v13; // al
  uint8_t v14; // al
  vgui::Button *v15; // edx
  int v16; // eax
  void (__cdecl *v17)(vgui::Button *, _DWORD); // esi
  uint8_t v18; // al
  void (__cdecl *v19)(vgui::Button *, _DWORD); // esi
  uint8_t v20; // al
  vgui::Button *v21; // edx
  void (__cdecl *v22)(vgui::Button *, int, int); // esi
  int v23; // eax
  void (__cdecl *v24)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v25)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v26)(vgui::Button *, int, int); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v27)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v28)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v29)(vgui::Button *, int, int); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v30)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v31)(vgui::Button *, _DWORD); // [esp+2Ch] [ebp-130h]
  void (__cdecl *v32)(vgui::Button *, int, int); // [esp+2Ch] [ebp-130h]
  char buf[256]; // [esp+38h] [ebp-124h] BYREF
  int wide; // [esp+138h] [ebp-24h] BYREF
  int tall[8]; // [esp+13Ch] [ebp-20h] BYREF

  (*((void (__cdecl **)(vgui::WizardPanel *const, int *, int *))this->_vptr_Panel + 58))(this, &wide, tall);
  (*(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_backButton + 36))(this->_backButton, 0);
  (*(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_nextButton + 36))(this->_nextButton, 0);
  (*(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_finishedButton + 36))(this->_finishedButton, 0);
  (*(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_cancelButton + 36))(this->_cancelButton, 0);
  if ( this->_currentWizardPage )
  {
    v2 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_backButton + 28))(this->_backButton);
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, int, int, int, int))this->_currentWizardPage->_vptr_Panel + 4))(
      this->_currentWizardPage,
      2,
      2,
      wide - 4,
      tall[0] - v2 - 8);
    v3 = wide - 4;
    v4 = tall[0] - v2 - 2;
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, char *, int))this->_currentWizardPage->_vptr_Panel + 153))(
      this->_currentWizardPage,
      buf,
      256);
    (*(void (__cdecl **)(vgui::Button *, char *))(*(_DWORD *)this->_cancelButton + 516))(this->_cancelButton, buf);
    v24 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_cancelButton + 252);
    v5 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 137))(this->_currentWizardPage);
    v24(this->_cancelButton, v5);
    v25 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_cancelButton + 36);
    v6 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 145))(this->_currentWizardPage);
    v25(this->_cancelButton, v6);
    v7 = this->_cancelButton;
    v26 = **(void (__cdecl ***)(vgui::Button *, int, int))v7->baseclass_0;
    v8 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)v7->baseclass_0 + 24))(v7);
    v26(this->_cancelButton, v3 - v8, v4);
    if ( (*((uint8_t (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 145))(this->_currentWizardPage) )
      v3 -= (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_cancelButton + 24))(this->_cancelButton) + 4;
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, char *, int))this->_currentWizardPage->_vptr_Panel + 152))(
      this->_currentWizardPage,
      buf,
      256);
    (*(void (__cdecl **)(vgui::Button *, char *))(*(_DWORD *)this->_finishedButton + 516))(this->_finishedButton, buf);
    v27 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_finishedButton + 252);
    v9 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 136))(this->_currentWizardPage);
    v27(this->_finishedButton, v9);
    v28 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_finishedButton + 36);
    v10 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 144))(this->_currentWizardPage);
    v28(this->_finishedButton, v10);
    v11 = this->_finishedButton;
    v29 = **(void (__cdecl ***)(vgui::Button *, int, int))v11->baseclass_0;
    v12 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)v11->baseclass_0 + 24))(v11);
    v29(this->_finishedButton, v3 - v12, v4);
    if ( (*((uint8_t (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 144))(this->_currentWizardPage) )
      v3 -= (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_finishedButton + 24))(this->_finishedButton) + 4;
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, char *, int))this->_currentWizardPage->_vptr_Panel + 151))(
      this->_currentWizardPage,
      buf,
      256);
    (*(void (__cdecl **)(vgui::Button *, char *))(*(_DWORD *)this->_nextButton + 516))(this->_nextButton, buf);
    v30 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_nextButton + 252);
    v13 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 135))(this->_currentWizardPage);
    v30(this->_nextButton, v13);
    v31 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_nextButton + 36);
    v14 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 143))(this->_currentWizardPage);
    v31(this->_nextButton, v14);
    v15 = this->_nextButton;
    v32 = **(void (__cdecl ***)(vgui::Button *, int, int))v15->baseclass_0;
    v16 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)v15->baseclass_0 + 24))(v15);
    v32(this->_nextButton, v3 - v16, v4);
    if ( (*((uint8_t (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 143))(this->_currentWizardPage) )
      v3 -= (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_nextButton + 24))(this->_nextButton) + 4;
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, char *, int))this->_currentWizardPage->_vptr_Panel + 150))(
      this->_currentWizardPage,
      buf,
      256);
    (*(void (__cdecl **)(vgui::Button *, char *))(*(_DWORD *)this->_backButton + 516))(this->_backButton, buf);
    v17 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_backButton + 252);
    v18 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 134))(this->_currentWizardPage);
    v17(this->_backButton, v18);
    v19 = *(void (__cdecl **)(vgui::Button *, _DWORD))(*(_DWORD *)this->_backButton + 36);
    v20 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 142))(this->_currentWizardPage);
    v19(this->_backButton, v20);
    v21 = this->_backButton;
    v22 = **(void (__cdecl ***)(vgui::Button *, int, int))v21->baseclass_0;
    v23 = (*(int (__cdecl **)(vgui::Button *))(*(_DWORD *)v21->baseclass_0 + 24))(v21);
    v22(this->_backButton, v3 - v23, v4);
    if ( (*((uint8_t (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 142))(this->_currentWizardPage) )
      (*(void (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_backButton + 24))(this->_backButton);
  }
}

void vgui::WizardPanel::setCurrentWizardPage(vgui::WizardPanel *const this, vgui::WizardPanel::WizardPage *currentWizardPage)
{
  int v2; // esi
  void (__cdecl *v3)(int, int); // edi
  int v4; // eax

  if ( this->_currentWizardPage )
    (*((void (__cdecl **)(vgui::WizardPanel *const, vgui::WizardPanel::WizardPage *))this->_vptr_Panel + 19))(
      this,
      this->_currentWizardPage);
  this->_currentWizardPage = currentWizardPage;
  if ( currentWizardPage )
  {
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *, vgui::WizardPanel *const))currentWizardPage->_vptr_Panel + 16))(
      currentWizardPage,
      this);
    v2 = (*((int (__cdecl **)(vgui::WizardPanel *const))this->_vptr_Panel + 83))(this);
    v3 = *(void (__cdecl **)(int, int))(*(_DWORD *)v2 + 68);
    v4 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 159))(this->_currentWizardPage);
    v3(v2, v4);
  }
  (*((void (__cdecl **)(vgui::WizardPanel *const))this->_vptr_Panel + 129))(this);
  (*((void (__cdecl **)(vgui::WizardPanel *const, _DWORD))this->_vptr_Panel + 46))(this, 0);
}

void vgui::WizardPanel::addFinishedActionSignal(vgui::WizardPanel *const this, vgui::ActionSignal *s)
{
  (*(void (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_finishedButton + 576))(this->_finishedButton);
}

void vgui::WizardPanel::addCancelledActionSignal(vgui::WizardPanel *const this, vgui::ActionSignal *s)
{
  (*(void (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_cancelButton + 576))(this->_cancelButton);
}

void vgui::WizardPanel::fireFinishedActionSignal(vgui::WizardPanel *const this)
{
  (*(void (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_finishedButton + 600))(this->_finishedButton);
}

void vgui::WizardPanel::fireCancelledActionSignal(vgui::WizardPanel *const this)
{
  (*(void (__cdecl **)(vgui::Button *))(*(_DWORD *)this->_cancelButton + 600))(this->_cancelButton);
}

void vgui::WizardPanel::firePageChangedActionSignal(vgui::WizardPanel *const this)
{
  int v1; // ebx
  vgui::ActionSignal *v2; // eax

  if ( this->_pageChangedActionSignalDar._count > 0 )
  {
    v1 = 0;
    do
    {
      v2 = this->_pageChangedActionSignalDar._data[v1++];
      (*v2->_vptr_ActionSignal)(v2, this);
    }
    while ( this->_pageChangedActionSignalDar._count > v1 );
  }
}

void vgui::WizardPanel::doBack(vgui::WizardPanel *const this)
{
  vgui::WizardPanel::WizardPage *v1; // eax
  void (__cdecl *v2)(vgui::WizardPanel *const, int); // esi
  int v3; // eax

  v1 = this->_currentWizardPage;
  if ( v1 )
  {
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *))v1->_vptr_Panel + 127))(this->_currentWizardPage);
    v2 = (void (__cdecl *)(vgui::WizardPanel *const, int))*((_DWORD *)this->_vptr_Panel + 130);
    v3 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 132))(this->_currentWizardPage);
    v2(this, v3);
  }
}

void vgui::WizardPanel::doNext(vgui::WizardPanel *const this)
{
  vgui::WizardPanel::WizardPage *v1; // eax
  void (__cdecl *v2)(vgui::WizardPanel *const, int); // esi
  int v3; // eax

  v1 = this->_currentWizardPage;
  if ( v1 )
  {
    (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *))v1->_vptr_Panel + 128))(this->_currentWizardPage);
    v2 = (void (__cdecl *)(vgui::WizardPanel *const, int))*((_DWORD *)this->_vptr_Panel + 130);
    v3 = (*((int (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 133))(this->_currentWizardPage);
    v2(this, v3);
  }
}

void vgui::WizardPanel::getCurrentWizardPageTitle(vgui::WizardPanel *const this, char *buf, int bufLen)
{
  (*((void (__cdecl **)(vgui::WizardPanel::WizardPage *))this->_currentWizardPage->_vptr_Panel + 163))(this->_currentWizardPage);
}

vgui::WizardPanel::WizardPage *__cdecl vgui::WizardPanel::getCurrentWizardPage(vgui::WizardPanel *const this)
{
  return this->_currentWizardPage;
}

void vgui::WizardPanel::WizardPage::getTitle(vgui::WizardPanel::WizardPage *const this, char *buf, int bufLen)
{
  vgui::vgui_strcpy(buf, bufLen, this->_title);
}

void vgui::WizardPanel::WizardPage::setTitle(vgui::WizardPanel::WizardPage *const this, const char *title)
{
  operator delete(this->_title);
  this->_title = vgui::vgui_strdup(title);
}

void vgui::WizardPanel::WizardPage::setCancelButtonText(vgui::WizardPanel::WizardPage *const this, const char *text)
{
  operator delete(this->_cancelButtonText);
  this->_cancelButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setFinishedButtonText(vgui::WizardPanel::WizardPage *const this, const char *text)
{
  operator delete(this->_finishedButtonText);
  this->_finishedButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setNextButtonText(vgui::WizardPanel::WizardPage *const this, const char *text)
{
  operator delete(this->_nextButtonText);
  this->_nextButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::setBackButtonText(vgui::WizardPanel::WizardPage *const this, const char *text)
{
  operator delete(this->_backButtonText);
  this->_backButtonText = vgui::vgui_strdup(text);
}

void vgui::WizardPanel::WizardPage::getBackButtonText(vgui::WizardPanel::WizardPage *const this, char *text, int textLen)
{
  char *s; // esi
  signed int v4; // eax
  unsigned int v5; // edx
  char *v6; // edi
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  char v10; // al
  __int16 v11; // cx
  int v12; // ecx

  s = this->_backButtonText;
  v4 = strlen(s);
  v5 = textLen - 1;
  v6 = text;
  if ( v4 <= textLen - 1 )
    v5 = v4;
  v7 = v5;
  if ( v5 >= 8 )
  {
    if ( ((uint8_t)text & 1) != 0 )
    {
      v10 = *s;
      v6 = text + 1;
      ++s;
      *text = v10;
      v7 = v5 - 1;
    }
    if ( ((uint8_t)v6 & 2) != 0 )
    {
      v11 = *(_WORD *)s;
      v7 -= 2;
      s += 2;
      *(_WORD *)v6 = v11;
      v6 += 2;
    }
    if ( ((uint8_t)v6 & 4) != 0 )
    {
      v12 = *(_DWORD *)s;
      v7 -= 4;
      s += 4;
      *(_DWORD *)v6 = v12;
      v6 += 4;
    }
    v9 = v7;
    LOBYTE(v7) = v7 & 3;
    v9 >>= 2;
    qmemcpy(v6, s, 4 * v9);
    s += 4 * v9;
    v6 += 4 * v9;
  }
  v8 = 0;
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)v6 = *(_DWORD *)s;
    v8 = 4;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_WORD *)&v6[v8] = *(_WORD *)&s[v8];
    v8 += 2;
  }
  if ( (v7 & 1) != 0 )
    v6[v8] = s[v8];
  text[v5] = 0;
}

void vgui::WizardPanel::WizardPage::getCancelButtonText(vgui::WizardPanel::WizardPage *const this, char *text, int textLen)
{
  char *s; // esi
  signed int v4; // eax
  unsigned int v5; // edx
  char *v6; // edi
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  char v10; // al
  __int16 v11; // cx
  int v12; // ecx

  s = this->_cancelButtonText;
  v4 = strlen(s);
  v5 = textLen - 1;
  v6 = text;
  if ( v4 <= textLen - 1 )
    v5 = v4;
  v7 = v5;
  if ( v5 >= 8 )
  {
    if ( ((uint8_t)text & 1) != 0 )
    {
      v10 = *s;
      v6 = text + 1;
      ++s;
      *text = v10;
      v7 = v5 - 1;
    }
    if ( ((uint8_t)v6 & 2) != 0 )
    {
      v11 = *(_WORD *)s;
      v7 -= 2;
      s += 2;
      *(_WORD *)v6 = v11;
      v6 += 2;
    }
    if ( ((uint8_t)v6 & 4) != 0 )
    {
      v12 = *(_DWORD *)s;
      v7 -= 4;
      s += 4;
      *(_DWORD *)v6 = v12;
      v6 += 4;
    }
    v9 = v7;
    LOBYTE(v7) = v7 & 3;
    v9 >>= 2;
    qmemcpy(v6, s, 4 * v9);
    s += 4 * v9;
    v6 += 4 * v9;
  }
  v8 = 0;
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)v6 = *(_DWORD *)s;
    v8 = 4;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_WORD *)&v6[v8] = *(_WORD *)&s[v8];
    v8 += 2;
  }
  if ( (v7 & 1) != 0 )
    v6[v8] = s[v8];
  text[v5] = 0;
}

void vgui::WizardPanel::WizardPage::getFinishedButtonText(vgui::WizardPanel::WizardPage *const this, char *text, int textLen)
{
  char *s; // esi
  signed int v4; // eax
  unsigned int v5; // edx
  char *v6; // edi
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  char v10; // al
  __int16 v11; // cx
  int v12; // ecx

  s = this->_finishedButtonText;
  v4 = strlen(s);
  v5 = textLen - 1;
  v6 = text;
  if ( v4 <= textLen - 1 )
    v5 = v4;
  v7 = v5;
  if ( v5 >= 8 )
  {
    if ( ((uint8_t)text & 1) != 0 )
    {
      v10 = *s;
      v6 = text + 1;
      ++s;
      *text = v10;
      v7 = v5 - 1;
    }
    if ( ((uint8_t)v6 & 2) != 0 )
    {
      v11 = *(_WORD *)s;
      v7 -= 2;
      s += 2;
      *(_WORD *)v6 = v11;
      v6 += 2;
    }
    if ( ((uint8_t)v6 & 4) != 0 )
    {
      v12 = *(_DWORD *)s;
      v7 -= 4;
      s += 4;
      *(_DWORD *)v6 = v12;
      v6 += 4;
    }
    v9 = v7;
    LOBYTE(v7) = v7 & 3;
    v9 >>= 2;
    qmemcpy(v6, s, 4 * v9);
    s += 4 * v9;
    v6 += 4 * v9;
  }
  v8 = 0;
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)v6 = *(_DWORD *)s;
    v8 = 4;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_WORD *)&v6[v8] = *(_WORD *)&s[v8];
    v8 += 2;
  }
  if ( (v7 & 1) != 0 )
    v6[v8] = s[v8];
  text[v5] = 0;
}

void vgui::WizardPanel::WizardPage::getNextButtonText(vgui::WizardPanel::WizardPage *const this, char *text, int textLen)
{
  char *s; // esi
  signed int v4; // eax
  unsigned int v5; // edx
  char *v6; // edi
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // ecx
  char v10; // al
  __int16 v11; // cx
  int v12; // ecx

  s = this->_nextButtonText;
  v4 = strlen(s);
  v5 = textLen - 1;
  v6 = text;
  if ( v4 <= textLen - 1 )
    v5 = v4;
  v7 = v5;
  if ( v5 >= 8 )
  {
    if ( ((uint8_t)text & 1) != 0 )
    {
      v10 = *s;
      v6 = text + 1;
      ++s;
      *text = v10;
      v7 = v5 - 1;
    }
    if ( ((uint8_t)v6 & 2) != 0 )
    {
      v11 = *(_WORD *)s;
      v7 -= 2;
      s += 2;
      *(_WORD *)v6 = v11;
      v6 += 2;
    }
    if ( ((uint8_t)v6 & 4) != 0 )
    {
      v12 = *(_DWORD *)s;
      v7 -= 4;
      s += 4;
      *(_DWORD *)v6 = v12;
      v6 += 4;
    }
    v9 = v7;
    LOBYTE(v7) = v7 & 3;
    v9 >>= 2;
    qmemcpy(v6, s, 4 * v9);
    s += 4 * v9;
    v6 += 4 * v9;
  }
  v8 = 0;
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)v6 = *(_DWORD *)s;
    v8 = 4;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_WORD *)&v6[v8] = *(_WORD *)&s[v8];
    v8 += 2;
  }
  if ( (v7 & 1) != 0 )
    v6[v8] = s[v8];
  text[v5] = 0;
}

void vgui::WizardPanel::WizardPage::addSwitchingToNextPageSignal(vgui::WizardPanel::WizardPage *const this, vgui::ActionSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::ActionSignal*> *v3; // esi
  vgui::ActionSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::ActionSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::ActionSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_switchingToNextPageSignalDar._count;
  v3 = &this->_switchingToNextPageSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_switchingToNextPageSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_switchingToNextPageSignalDar._capacity;
  v7 = v2 + 1;
  if ( v2 + 1 > v6 )
  {
    if ( v6 || (v6 = 1, v9 = 4, v7 > 1) )
    {
      do
        v6 *= 2;
      while ( v7 > v6 );
      v9 = 4 * v6;
    }
    v13 = v6;
    v10 = (_BYTE *)operator new[](v9);
    v14 = (vgui::ActionSignal **)v10;
    if ( !v10 )
      exit(0);
    v15 = v9;
    v11 = v10;
    if ( v15 >= 8 )
    {
      if ( ((uint8_t)v10 & 1) != 0 )
      {
        *v10 = 0;
        --v15;
        v11 = v10 + 1;
      }
      if ( ((uint8_t)v11 & 2) != 0 )
      {
        *v11++ = 0;
        v15 -= 2;
      }
      if ( ((uint8_t)v11 & 4) != 0 )
      {
        *(_DWORD *)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ( (v15 & 4) != 0 )
    {
      *(_DWORD *)v11 = 0;
      v11 += 2;
    }
    if ( (v15 & 2) != 0 )
      *v11++ = 0;
    if ( (v15 & 1) != 0 )
      *(_BYTE *)v11 = 0;
    v2 = this->_switchingToNextPageSignalDar._count;
    this->_switchingToNextPageSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_switchingToNextPageSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_switchingToNextPageSignalDar._data )
    {
      operator delete[](this->_switchingToNextPageSignalDar._data);
      v2 = this->_switchingToNextPageSignalDar._count;
    }
    v8 = v14;
    this->_switchingToNextPageSignalDar._data = v14;
  }
  else
  {
    v8 = this->_switchingToNextPageSignalDar._data;
  }
  v8[v2] = s;
  ++this->_switchingToNextPageSignalDar._count;
}

void vgui::WizardPanel::WizardPage::addSwitchingToBackPageSignal(vgui::WizardPanel::WizardPage *const this, vgui::ActionSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::ActionSignal*> *v3; // esi
  vgui::ActionSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::ActionSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::ActionSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_switchingToBackPageSignalDar._count;
  v3 = &this->_switchingToBackPageSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_switchingToBackPageSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_switchingToBackPageSignalDar._capacity;
  v7 = v2 + 1;
  if ( v2 + 1 > v6 )
  {
    if ( v6 || (v6 = 1, v9 = 4, v7 > 1) )
    {
      do
        v6 *= 2;
      while ( v7 > v6 );
      v9 = 4 * v6;
    }
    v13 = v6;
    v10 = (_BYTE *)operator new[](v9);
    v14 = (vgui::ActionSignal **)v10;
    if ( !v10 )
      exit(0);
    v15 = v9;
    v11 = v10;
    if ( v15 >= 8 )
    {
      if ( ((uint8_t)v10 & 1) != 0 )
      {
        *v10 = 0;
        --v15;
        v11 = v10 + 1;
      }
      if ( ((uint8_t)v11 & 2) != 0 )
      {
        *v11++ = 0;
        v15 -= 2;
      }
      if ( ((uint8_t)v11 & 4) != 0 )
      {
        *(_DWORD *)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ( (v15 & 4) != 0 )
    {
      *(_DWORD *)v11 = 0;
      v11 += 2;
    }
    if ( (v15 & 2) != 0 )
      *v11++ = 0;
    if ( (v15 & 1) != 0 )
      *(_BYTE *)v11 = 0;
    v2 = this->_switchingToBackPageSignalDar._count;
    this->_switchingToBackPageSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_switchingToBackPageSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_switchingToBackPageSignalDar._data )
    {
      operator delete[](this->_switchingToBackPageSignalDar._data);
      v2 = this->_switchingToBackPageSignalDar._count;
    }
    v8 = v14;
    this->_switchingToBackPageSignalDar._data = v14;
  }
  else
  {
    v8 = this->_switchingToBackPageSignalDar._data;
  }
  v8[v2] = s;
  ++this->_switchingToBackPageSignalDar._count;
}

void vgui::WizardPanel::addPageChangedActionSignal(vgui::WizardPanel *const this, vgui::ActionSignal *s)
{
  int v2; // ecx
  vgui::Dar<vgui::ActionSignal*> *v3; // esi
  vgui::ActionSignal **v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // eax
  vgui::ActionSignal **v8; // eax
  unsigned int v9; // edi
  _BYTE *v10; // eax
  _WORD *v11; // edi
  int v12; // eax
  int v13; // [esp+14h] [ebp-28h]
  vgui::ActionSignal **v14; // [esp+18h] [ebp-24h]
  unsigned int v15; // [esp+1Ch] [ebp-20h]

  v2 = this->_pageChangedActionSignalDar._count;
  v3 = &this->_pageChangedActionSignalDar;
  if ( v2 > 0 )
  {
    v4 = this->_pageChangedActionSignalDar._data;
    v5 = 0;
    if ( s == *v4 )
      return;
    while ( ++v5 != v2 )
    {
      if ( s == v4[v5] )
        return;
    }
  }
  v6 = this->_pageChangedActionSignalDar._capacity;
  v7 = v2 + 1;
  if ( v2 + 1 > v6 )
  {
    if ( v6 || (v6 = 1, v9 = 4, v7 > 1) )
    {
      do
        v6 *= 2;
      while ( v7 > v6 );
      v9 = 4 * v6;
    }
    v13 = v6;
    v10 = (_BYTE *)operator new[](v9);
    v14 = (vgui::ActionSignal **)v10;
    if ( !v10 )
      exit(0);
    v15 = v9;
    v11 = v10;
    if ( v15 >= 8 )
    {
      if ( ((uint8_t)v10 & 1) != 0 )
      {
        *v10 = 0;
        --v15;
        v11 = v10 + 1;
      }
      if ( ((uint8_t)v11 & 2) != 0 )
      {
        *v11++ = 0;
        v15 -= 2;
      }
      if ( ((uint8_t)v11 & 4) != 0 )
      {
        *(_DWORD *)v11 = 0;
        v11 += 2;
        v15 -= 4;
      }
      memset(v11, 0, 4 * (v15 >> 2));
      v11 += 2 * (v15 >> 2);
      LOBYTE(v15) = v15 & 3;
    }
    if ( (v15 & 4) != 0 )
    {
      *(_DWORD *)v11 = 0;
      v11 += 2;
    }
    if ( (v15 & 2) != 0 )
      *v11++ = 0;
    if ( (v15 & 1) != 0 )
      *(_BYTE *)v11 = 0;
    v2 = this->_pageChangedActionSignalDar._count;
    this->_pageChangedActionSignalDar._capacity = v13;
    if ( v2 > 0 )
    {
      v12 = 0;
      do
      {
        v14[v12] = this->_pageChangedActionSignalDar._data[v12];
        ++v12;
        v2 = v3->_count;
      }
      while ( v12 < v3->_count );
    }
    if ( this->_pageChangedActionSignalDar._data )
    {
      operator delete[](this->_pageChangedActionSignalDar._data);
      v2 = this->_pageChangedActionSignalDar._count;
    }
    v8 = v14;
    this->_pageChangedActionSignalDar._data = v14;
  }
  else
  {
    v8 = this->_pageChangedActionSignalDar._data;
  }
  v8[v2] = s;
  ++this->_pageChangedActionSignalDar._count;
}

void vgui::WizardPanel::WizardPage::WizardPage(vgui::WizardPanel::WizardPage *const this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // edx
  vgui::ActionSignal **v4; // edx
  vgui::ActionSignal **v5; // eax
  vgui::ActionSignal **v6; // edi
  int v7; // edx
  int v8; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel(this, 0, 0, 64, 64);
  this->_switchingToBackPageSignalDar._count = 0;
  this->_switchingToBackPageSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::WizardPanel::WizardPage + 2);
  this->_switchingToBackPageSignalDar._data = 0;
  v1 = operator new[](0x10u);
  if ( !v1 )
    goto LABEL_14;
  *(_DWORD *)v1 = 0;
  *(_DWORD *)(v1 + 4) = 0;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 0;
  v2 = this->_switchingToBackPageSignalDar._count;
  this->_switchingToBackPageSignalDar._capacity = 4;
  if ( v2 > 0 )
  {
    v3 = 0;
    do
    {
      *(_DWORD *)(v1 + 4 * v3) = this->_switchingToBackPageSignalDar._data[v3];
      ++v3;
    }
    while ( v3 < this->_switchingToBackPageSignalDar._count );
  }
  v4 = this->_switchingToBackPageSignalDar._data;
  if ( v4 )
  {
    v8 = v1;
    operator delete[]((VFontData *const)v4);
    v1 = v8;
  }
  this->_switchingToBackPageSignalDar._data = (vgui::ActionSignal **)v1;
  this->_switchingToNextPageSignalDar._count = 0;
  this->_switchingToNextPageSignalDar._capacity = 0;
  this->_switchingToNextPageSignalDar._data = 0;
  v5 = (vgui::ActionSignal **)operator new[](0x10u);
  v6 = v5;
  if ( !v5 )
LABEL_14:
    exit(0);
  *v5 = 0;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  this->_switchingToNextPageSignalDar._capacity = 4;
  if ( this->_switchingToNextPageSignalDar._count > 0 )
  {
    v7 = 0;
    do
    {
      v5[v7] = this->_switchingToNextPageSignalDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_switchingToNextPageSignalDar._count );
  }
  if ( this->_switchingToNextPageSignalDar._data )
    operator delete[]((VFontData *const)this->_switchingToNextPageSignalDar._data);
  this->_switchingToNextPageSignalDar._data = v6;
  vgui::WizardPanel::WizardPage::init(this);
}

void vgui::WizardPanel::WizardPage::WizardPage(vgui::WizardPanel::WizardPage *const this, int wide, int tall)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edx
  vgui::ActionSignal **v6; // edx
  vgui::ActionSignal **v7; // eax
  vgui::ActionSignal **v8; // edi
  int v9; // edx
  int v10; // edx
  int v11; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel(this, 0, 0, wide, tall);
  this->_switchingToBackPageSignalDar._count = 0;
  this->_switchingToBackPageSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::WizardPanel::WizardPage + 2);
  this->_switchingToBackPageSignalDar._data = 0;
  v3 = operator new[](0x10u);
  if ( !v3 )
    goto LABEL_14;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  v4 = this->_switchingToBackPageSignalDar._count;
  this->_switchingToBackPageSignalDar._capacity = 4;
  if ( v4 > 0 )
  {
    v5 = 0;
    do
    {
      *(_DWORD *)(v3 + 4 * v5) = this->_switchingToBackPageSignalDar._data[v5];
      ++v5;
    }
    while ( v5 < this->_switchingToBackPageSignalDar._count );
  }
  v6 = this->_switchingToBackPageSignalDar._data;
  if ( v6 )
  {
    v11 = v3;
    operator delete[]((VFontData *const)v6);
    v3 = v11;
  }
  this->_switchingToBackPageSignalDar._data = (vgui::ActionSignal **)v3;
  this->_switchingToNextPageSignalDar._capacity = 0;
  this->_switchingToNextPageSignalDar._count = 0;
  this->_switchingToNextPageSignalDar._data = 0;
  v7 = (vgui::ActionSignal **)operator new[](0x10u);
  v8 = v7;
  if ( !v7 )
LABEL_14:
    exit(0);
  *v7 = 0;
  v7[1] = 0;
  v7[2] = 0;
  v7[3] = 0;
  v9 = this->_switchingToNextPageSignalDar._count;
  this->_switchingToNextPageSignalDar._capacity = 4;
  if ( v9 > 0 )
  {
    v10 = 0;
    do
    {
      v7[v10] = this->_switchingToNextPageSignalDar._data[v10];
      ++v10;
    }
    while ( v10 < this->_switchingToNextPageSignalDar._count );
  }
  if ( this->_switchingToNextPageSignalDar._data )
    operator delete[]((VFontData *const)this->_switchingToNextPageSignalDar._data);
  this->_switchingToNextPageSignalDar._data = v8;
  vgui::WizardPanel::WizardPage::init(this);
}

void vgui::WizardPanel::WizardPanel(vgui::WizardPanel *const this, int x, int y, int wide, int tall)
{
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  vgui::ActionSignal **v8; // edx
  vgui::Button *v9; // esi
  void (__cdecl *v10)(vgui::Button *, _DWORD *); // esi
  _DWORD *v11; // eax
  vgui::Button *v12; // esi
  void (__cdecl *v13)(vgui::Button *, _DWORD *); // esi
  _DWORD *v14; // eax
  vgui::Button *v15; // esi
  vgui::Button *v16; // esi
  int v17; // [esp+2Ch] [ebp-10h]

  vgui::Panel::Panel(this, x, y, wide, tall);
  this->_pageChangedActionSignalDar._count = 0;
  this->_pageChangedActionSignalDar._capacity = 0;
  this->_vptr_Panel = (int (**)(...))(&`vtable for'vgui::WizardPanel + 2);
  this->_pageChangedActionSignalDar._data = 0;
  v5 = operator new[](0x10u);
  if ( !v5 )
    exit(0);
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  v6 = this->_pageChangedActionSignalDar._count;
  this->_pageChangedActionSignalDar._capacity = 4;
  if ( v6 > 0 )
  {
    v7 = 0;
    do
    {
      *(_DWORD *)(v5 + 4 * v7) = this->_pageChangedActionSignalDar._data[v7];
      ++v7;
    }
    while ( v7 < this->_pageChangedActionSignalDar._count );
  }
  v8 = this->_pageChangedActionSignalDar._data;
  if ( v8 )
  {
    v17 = v5;
    operator delete[]((VFontData *const)v8);
    v5 = v17;
  }
  this->_pageChangedActionSignalDar._data = (vgui::ActionSignal **)v5;
  this->_currentWizardPage = 0;
  v9 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v9, "back", 20, 100);
  this->_backButton = v9;
  (*(void (__cdecl **)(vgui::Button *, vgui::WizardPanel *const))(*(_DWORD *)v9->baseclass_0 + 64))(v9, this);
  v10 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_backButton + 576);
  v11 = operator new(8u);
  v11[1] = this;
  *v11 = &off_4A008;
  v10(this->_backButton, v11);
  v12 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v12, "next", 80, 100);
  this->_nextButton = v12;
  (*(void (__cdecl **)(vgui::Button *, vgui::WizardPanel *const))(*(_DWORD *)v12->baseclass_0 + 64))(v12, this);
  v13 = *(void (__cdecl **)(vgui::Button *, _DWORD *))(*(_DWORD *)this->_nextButton + 576);
  v14 = operator new(8u);
  v14[1] = this;
  *v14 = &off_4A018;
  v13(this->_nextButton, v14);
  v15 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v15, "finished", 120, 100);
  this->_finishedButton = v15;
  (*(void (__cdecl **)(vgui::Button *, vgui::WizardPanel *const))(*(_DWORD *)v15->baseclass_0 + 64))(v15, this);
  v16 = (vgui::Button *)operator new(0xF0u);
  vgui::Button::Button(v16, "cancel", 180, 100);
  this->_cancelButton = v16;
  (*(void (__cdecl **)(vgui::Button *, vgui::WizardPanel *const))(*(_DWORD *)v16->baseclass_0 + 64))(v16, this);
}

