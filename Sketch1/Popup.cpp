#include <Gamebuino-Meta.h>
#include "Debug.h"

void popup(int returned)
{
	static String temp_str = { "\0" };
	temp_str = String("Value : ") + returned;
	gb.gui.popup(temp_str.c_str(), 50);
}

void popup(char* text)
{
	static String temp_str = { "\0" };
	temp_str = String("Text : ") + text;
	gb.gui.popup(temp_str.c_str(), 50);
}

void popup(String popup)
{
	static String temp_str = { "\0" };
	temp_str = String(popup);
	gb.gui.popup(temp_str.c_str(), 50);
	DEBUG_PRINT(popup);
	DEBUG_PRINT(temp_str);
}