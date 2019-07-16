#ifndef _JWINDOW_BASE_H_
#define _JWINDOW_BASE_H_

#include <string>
#include <Windows.h>
#include"Color.h"

namespace JFC {
	typedef SMALL_RECT JRECT;
class JWindowBase
{
public:
	//构造函数
	JWindowBase();
	JWindowBase(SHORT x, SHORT y, SHORT width, SHORT height);

	//析构函数
	~JWindowBase();

	SHORT Width() const { return width_; }
	SHORT Height() const { return height_; }
	// 设置文本颜色
	void SetTextColor(WORD fColor) { fColor_ = fColor; }

	// 获取文本颜色
	WORD GetTextColor() const { return fColor_; }

	// 设置背景色
	void SetBkColor(WORD bColor) { bColor_ = bColor; }

	// 获取背景色
	WORD GetBkColor() const { return bColor_; }

	// 设置光标位置
	void SetCursorPos(SHORT x, SHORT y);

	// 刷新窗口
	void Refresh();

	// 清除矩形区域
	void FillRect(JRECT rect);

	// 绘制文本（x, y相对于本窗口的位置，并不是相对整个控制台窗口的位置）
	void DrawText(SHORT x, SHORT y, const std::string& text);

	// 在窗口正中间绘制文本
	void DrawText(const std::string& text);

	// 在水平位置画线
	void DrawHLine(SHORT y, SHORT x1, SHORT x2, char ch);

	// 在垂直位置画线
	void DrawVLine(SHORT x, SHORT y1, SHORT y2, char ch);

	// 清除窗口
	void ClearWindow();

//ScreenBuffer内部类
private:
	class ScreenBuffer
	{
	public:
		ScreenBuffer()
		{

		}

		~ScreenBuffer()
		{

		}

		void write(SHORT x, SHORT y, CHAR_INFO ci)
		{
			buffer_[y * 80 + x] = ci;
		}

		void write(SHORT x, SHORT y, const std::string& str, WORD fColor, WORD bColor)
		{
			CHAR_INFO ci;
			ci.Attributes = fColor | bColor;

			for (size_t i = 0; i < str.length(); ++i)
			{
				ci.Char.AsciiChar = str[i];
				write(x + i, y, ci);
			}
		}

		void refresh(SHORT x, SHORT y, SHORT width, SHORT height)
		{
			COORD size = { 80, 25 };
			COORD coord = { x, y };
			JRECT rect = { x, y, x + width - 1, y + height - 1 };
			WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),
				buffer_,
				size,
				coord,
				&rect);
		}


		CHAR_INFO buffer_[80 * 25];
	};
public:
	static ScreenBuffer sb_;
protected:
	SHORT x_;			// x坐标
	SHORT y_;			// y坐标
	SHORT width_;		// 宽度
	SHORT height_;		// 高度
	WORD fColor_;		// 前景色（文本颜色）
	WORD bColor_;		// 背景色
};

}//namespace JFC
#endif // !_JWINDOW_BASE_H_
