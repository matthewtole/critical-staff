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

Chrono myChrono;
Crown crown;

void setup()
{
	crown.setup();
}

void loop()
{
	crown.loop();

	static int h = 0;
	if (myChrono.hasPassed(15, true))
	{
		crown.set_face_color(1, CHSV(h, 255, 100));
		crown.set_face_color(2, CHSV(h + 50, 255, 100));
		crown.apply();
		h += 1;
	}
}
