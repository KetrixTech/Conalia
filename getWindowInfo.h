#include <windows.h>
struct _getWindowSize
{
	int getWindowHeight()
	{
		HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(outputHandle, &info);
		return info.srWindow.Right;
	}
	int getWindowWidth()
	{
		HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(outputHandle, &info);
		return info.srWindow.Bottom;
	}
	int tpl;
}getWindowSize;
struct _getCursorPosition
{
	int X()
	{
		HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(outputHandle, &info);
		return info.dwCursorPosition.X;
	}
	int Y()
	{
		HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(outputHandle, &info);
		return info.dwCursorPosition.Y;
	}
	int tpl;
}getCursorPosition;
