#ifndef _JWINDOW_H_
#define _JWINDOW_H__

#include "JWindowBase.h"
namespace JFC {
	class JEvent;
class JWindow : public JWindowBase//：继承JWindowBase基类
{
public:
	JWindow();
	JWindow(SHORT x, SHORT y, SHORT width, SHORT height);
	~JWindow();
	virtual void OnKeyEvent(JEvent* e);
	virtual void Draw();
	void Show();
};

}//namespace JFC
#endif // !_JWINDOW_H_