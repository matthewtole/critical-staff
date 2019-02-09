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
#pragma GCC diagnostic pop

#include "crown.h"
#include "touch-panel.h"

Chrono myChrono = Chrono();
Crown crown = Crown();
TouchPanel touch_panel = TouchPanel();

void setup()
{
	Serial.begin(9600);
	touch_panel.setup();
	crown.setup();
	crown.set_color(CHSV(0, 255, 50));
	crown.apply();
}

bool running = false;

void loop()
{
	crown.loop();
	touch_panel.loop();

	if (touch_panel.was_tapped(9))
	{
		running = !running;
	}

	static int h = 0;
	if (myChrono.hasPassed(10, true) && running)
	{
		crown.set_face_color(1, CHSV(h, 255, 50));
		crown.set_face_color(2, CHSV(h + 50, 255, 50));
		crown.apply();
		h += 1;
	}
}
