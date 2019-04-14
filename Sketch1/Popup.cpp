#include <Gamebuino-Meta.h>
#include "Debug.h"

void popup(int returned)
{
	static char tempo[17] = { '\0' };
	sprintf(tempo, "Count: %d", returned);
	gb.gui.popup(tempo, 50);
	char tempo2[24] = { '\0' };
	sprintf(tempo2, "POPUP: %s", tempo);
	DEBUG_PRINT(tempo);
}

void popup(char* text)
{
	static char tempo[17] = { '\0' };
	sprintf(tempo, "Text: %s", text);
	gb.gui.popup(tempo, 50);
	char tempo2[24] = { '\0' };
	sprintf(tempo2, "POPUP: %s", tempo);
	DEBUG_PRINT(tempo);
}