#ifndef _JWINDOW_H_
#define _JWINDOW_H__

namespace JFC {
	class JEvent;
class JWindow
{
public:
	JWindow();
	~JWindow();
	virtual void OnKeyEvent(JEvent* e);
};

}//namespace JFC
#endif // !_JWINDOW_H_