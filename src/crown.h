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

#include <FastLED.h>

#define NUM_FACES 2
#define PIXELS_PER_FACE 1
#define PIN_CROWN 7

class Crown
{
  private:
	uint8_t pixel_pin;
	CRGB pixels[NUM_FACES * PIXELS_PER_FACE];

  public:
	Crown();
	void setup();
	void loop();
	void set_color(CHSV color);
	void set_face_color(uint8_t face, CHSV color);
	void apply();
};
