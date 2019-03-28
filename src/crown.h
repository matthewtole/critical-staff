/**
 * =====================================
 * ╔═╗┬─┐┬┌┬┐┬┌─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌─┐┌─┐
 * ║  ├┬┘│ │ ││  ├─┤│    ╚═╗ │ ├─┤├┤ ├┤
 * ╚═╝┴└─┴ ┴ ┴└─┘┴ ┴┴─┘  ╚═╝ ┴ ┴ ┴└  └
 * =====================================
 * @file crown.h
 * @author Matthew Tole (matthewtole@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-02-08
 */

#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#include <Chrono.h>
#pragma GCC diagnostic pop

#include "./pattern.h"

enum CrownPatternName
{
	OFF,
	PULSE_WHITE,
	RAINBOW_CHASE_PULSE,
	RAINBOW_CHASE,
	COLOR_ROWS,
	PIXEL_FLASH,
	FACE_FLASH,
	EXPERIMENT
};

class Crown
{
  private:
	uint8_t pixel_pin;
	CRGB pixels[NUM_FACES * PIXELS_PER_FACE];
	CrownPattern *pattern;

  public:
	Crown();
	void setup();
	void loop();
	void set_pattern(CrownPatternName pattern);
	void apply();
};
