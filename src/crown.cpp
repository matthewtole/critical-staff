/**
 * =====================================
 * ╔═╗┬─┐┬┌┬┐┬┌─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌─┐┌─┐
 * ║  ├┬┘│ │ ││  ├─┤│    ╚═╗ │ ├─┤├┤ ├┤
 * ╚═╝┴└─┴ ┴ ┴└─┘┴ ┴┴─┘  ╚═╝ ┴ ┴ ┴└  └
 * =====================================
 * @file crown.cpp
 * @author Matthew Tole (matthewtole@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-02-08
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#include <ArduinoLog.h>
#pragma GCC diagnostic pop

#include "crown.h"
#include "constants.h"

Crown::Crown()
{
}

void Crown::setup()
{
	FastLED.addLeds<NEOPIXEL, PIN_CROWN>(pixels, NUM_FACES * PIXELS_PER_FACE);
}

void Crown::loop()
{
	if (pattern != NULL)
	{
		pattern->update(pixels);
	}
	apply();
}

void Crown::apply()
{
	FastLED.show();
}

void Crown::set_pattern(CrownPatternName name)
{
	for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
	{
		pixels[p] = CHSV(0, 0, 0);
	}

	if (pattern)
	{
		delete pattern;
		pattern = NULL;
	}
	switch (name)
	{
	case PULSE_WHITE:
		pattern = new CrownPatternPulseWhite();
		break;
	case RAINBOW_CHASE_PULSE:
		pattern = new CrownPatternRainbowPulse();
		break;
	case RAINBOW_CHASE:
		pattern = new CrownPatternRainbowChase();
		break;
	case COLOR_ROWS:
		pattern = new CrownPatternColorRows();
		break;
	case PIXEL_FLASH:
		pattern = new CrownPatternFaceFlash();
		break;
	case FACE_FLASH:
		pattern = new CrownPatternPixelFlash();
		break;
	case OFF:
	case EXPERIMENT:
	default:
		break;
	}
}
