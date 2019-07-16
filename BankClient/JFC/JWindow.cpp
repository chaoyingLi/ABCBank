#include "JWindow.h"
#include"JEvent.h"
#include"JApplication.h"


using namespace JFC;

JWindow::JWindow()
{
}
JWindow::JWindow(SHORT x, SHORT y, SHORT width, SHORT height)
	: JWindowBase(x, y, width, height)
{

}

JWindow::~JWindow()
{
}

void JWindow::OnKeyEvent(JEvent* e) {

}
void JWindow::Draw()
{
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = { 0, 0, Width() - 1, Height() - 1 };
	FillRect(rect);
}

void JWindow::Show()
{
	jApp->SetCurrent(this);
	Draw();
	Refresh();
}