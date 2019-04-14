#include "Counter.h"

int counter_select(char* title_, int default_counter_, int counter_max_, Color counter_color_, Color background_color_)
{
	int counter = default_counter_;
	int counter_max = counter_max_;
	Color counter_color = counter_color_;
	bool finish = false;
	char* title = title_;

	while (!finish)
	{
		while (!gb.update());
		gb.display.clear();

		// Accept
		if (gb.buttons.pressed(BUTTON_A))
			finish = true;

		// Refuse
		if (gb.buttons.pressed(BUTTON_B))
			return -1;

		// +1 
		if (gb.buttons.repeat(BUTTON_UP, 0))
		{
			counter++;
			if (counter > counter_max)
				counter = counter_max;

			if (gb.buttons.pressed(BUTTON_UP))
				gb.sound.playOK();
		}

		// -1
		if (gb.buttons.repeat(BUTTON_DOWN, 0))
		{
			counter--;
			if (counter < 0)
				counter = 0;

			if (gb.buttons.pressed(BUTTON_DOWN))
				gb.sound.playCancel();
		}

		// +10%
		if (gb.buttons.repeat(BUTTON_RIGHT, 0))
		{
			const int move = (counter_max / 10);
			if (move != 0)
				counter += (counter_max / 10);
			else
				counter++;

			if (counter > counter_max)
				counter = counter_max;

			if (gb.buttons.pressed(BUTTON_RIGHT))
				gb.sound.playOK();
		}
		// -10%
		if (gb.buttons.repeat(BUTTON_LEFT, 0))
		{
			const int move = (counter_max / 10);
			if (move != 0)
				counter -= move;
			else
				counter--;
			if (counter < 0)
				counter = 0;

			if (gb.buttons.pressed(BUTTON_LEFT))
				gb.sound.playOK();
		}


		gb.display.setColor(background_color_);
		gb.display.fill();
		gb.display.setColor(counter_color);
		gb.display.fillRect(0, 0, (static_cast<double>(gb.display.width()) / static_cast<double>((counter_max))) * (counter), gb.display.height());
		gb.display.setColor(WHITE);
		gb.display.print(title);
		gb.display.setColor(WHITE);

		if (counter / 1000000 > 0)
			gb.display.setFontSize(2);
		else if(counter / 10000 > 0)
			gb.display.setFontSize(3);
		else if(counter/1000 > 0)
			gb.display.setFontSize(4);
		else if (counter / 100 > 0)
			gb.display.setFontSize(5);
		else
			gb.display.setFontSize(6);

		gb.display.setCursor(4, gb.display.height() / 2);
		gb.display.print(counter);
		gb.display.setFontSize(1);
		gb.lights.fill(counter_color);
	}

	gb.lights.fill(BLACK);
	return counter;
}