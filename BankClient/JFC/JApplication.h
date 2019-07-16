#ifndef _JAPPLICATION_H_
	#define _JAPPLICATION_H_

namespace JFC {

	class JWindow;

// 一种特殊的单例模式,QT
class JApplication
{
public:
	JApplication();
	~JApplication();

	static JApplication* Instance() { return self_; }

	void ShowCursor() const;
	void HideCursor() const;

	JWindow* GetCurrent() const { return current_; }
	void  SetCurrent(JWindow* win) { current_ = win; }
	JWindow* Root() const { return root_; }

	int Exec();// 消息循环

private:
	static JApplication* self_;//JApplication自己
	JWindow* current_; // 当前接收按键的窗口JWindow
	JWindow* root_;// 根窗口JWindow
};
#define jApp JApplication::Instance()

}//nmaespace JFC
#endif // !_JAPPLICATION_H_