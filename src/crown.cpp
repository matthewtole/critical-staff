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
#pragma GCC diagnostic pop

#include "crown.h"

Crown::Crown()
{
}

void Crown::setup()
{
	FastLED.addLeds<NEOPIXEL, PIN_CROWN>(pixels, NUM_FACES * PIXELS_PER_FACE);
}

void Crown::loop()
{
}

void Crown::set_color(CHSV color)
{
	for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
	{
		pixels[p] = color;
	}
}

void Crown::set_face_color(uint8_t face, CHSV color)
{
	uint8_t offset = (face - 1) * PIXELS_PER_FACE;
	for (uint8_t p = 0; p < PIXELS_PER_FACE; p += 1)
	{
		pixels[offset + p] = color;
	}
}

void Crown::apply()
{
	FastLED.show();
}
