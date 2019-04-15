#include <Gamebuino-Meta.h>
#include "Debug.h"

void popup(String popup)
{
	static String temp_str = { "\0" };
	temp_str = String(popup);
	gb.gui.popup(temp_str.c_str(), 50);
}