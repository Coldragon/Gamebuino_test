#include <Gamebuino-Meta.h>
#include "dummy.h"
#include "Counter.h"
#include "Popup.h"
#include "Image.cpp"
#include "Debug.h"
#include <cstdio>

int result;
Image myImg = Image(IMAGE_Coldoge);

void setup()
{
	DEBUG_INIT();
	gb.begin();
}

const char* menu[] = 
{
	"Set Name",
	"Set Tax amount",
	"Set Health focus",
	"Set Alert level",
	"Set Protection",
};

void loop()
{
	while (!gb.update());
	gb.display.clear();
	gb.display.setColor(BLUE);
	gb.display.fill();
	
	char name[16];
	if (gb.buttons.pressed(BUTTON_MENU))
	{
		uint8_t entry = gb.gui.menu("What should we do ?", menu);
		switch(entry)
		{
		case 0:
			gb.lights.fill(GREEN);
			gb.gui.keyboard("Set Name", name, 16);
			gb.lights.fill(BLACK);
			popup(name);
			break;
		case 1:
			result = counter_select("Set Tax amount", 25,0, 85000, YELLOW); 
			popup(result);
			break;
		case 2:
			result = counter_select("Set Health focus", 0, 0, 100, PURPLE);
			popup(result);
			break;
		case 3:
			result = counter_select("Set Alert level", 0, 0, 5, RED);
			popup(result);
			break;
		case 4:
			result = counter_select("Set Protection", 25, 50, 200, BLUE);
			popup(result);
			break;
		}
	}

	gb.display.drawImage(0, 0, myImg);
	gb.display.setColor(WHITE);
	gb.display.print(result);
}

