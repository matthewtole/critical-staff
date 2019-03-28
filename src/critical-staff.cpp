/**
 * =====================================
 * ╔═╗┬─┐┬┌┬┐┬┌─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌─┐┌─┐
 * ║  ├┬┘│ │ ││  ├─┤│    ╚═╗ │ ├─┤├┤ ├┤
 * ╚═╝┴└─┴ ┴ ┴└─┘┴ ┴┴─┘  ╚═╝ ┴ ┴ ┴└  └
 * =====================================
 * @file critical-staff.cpp
 * @author Matthew Tole (matthewtole@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-02-08
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#include <Chrono.h>
#include <Button.h>
#include <ArduinoLog.h>
#pragma GCC diagnostic pop

#include "crown.h"
#include "touch-panel.h"
#include "constants.h"

Chrono myChrono = Chrono();
Crown crown = Crown();
TouchPanel touch_panel = TouchPanel();
Button button = Button(2);
uint8_t experiment_number = 0;

void setup()
{
	pinMode(2, INPUT_PULLUP);
	Serial.begin(9600);
	Log.begin(LOG_LEVEL_VERBOSE, &Serial);
	touch_panel.setup();
	crown.setup();
}

void loop()
{
	crown.loop();
	touch_panel.loop();
	FastLED.setBrightness(analogRead(14) / 4);

	if (button.pressed())
	{
		experiment_number = (experiment_number + 1) % 7;
		switch (experiment_number)
		{
		case 0:
			crown.set_pattern(OFF);
			break;
		case 1:
			crown.set_pattern(PULSE_WHITE);
			break;
		case 2:
			crown.set_pattern(RAINBOW_CHASE_PULSE);
			break;
		case 3:
			crown.set_pattern(RAINBOW_CHASE);
			break;
		case 4:
			crown.set_pattern(COLOR_ROWS);
			break;
		case 5:
			crown.set_pattern(FACE_FLASH);
			break;
		case 6:
			crown.set_pattern(PIXEL_FLASH);
			break;
		}
	}
}
