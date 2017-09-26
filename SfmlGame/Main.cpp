#include <windows.h>
#include<time.h>
#include "game.h"
using namespace sf;
#define  HIDE_CONSOLE_WINDOW



int main()
{
#ifdef HIDE_CONSOLE_WINDOW
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif // HIDE_CONSOLE_WINDOW
	srand(time(0));
	game Game;
}