/**
 * 
 * CRITICAL STAFF
 * 
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#include <Chrono.h>
#include <Button.h>
#pragma GCC diagnostic pop

const int PIN_NEOPIXELs = 7;
const int PIN_DIAL = 14;

const int NUM_PIXELS_HEAD = 2;
const int NUM_PIXELS_SHAFT = 4;

const int PIXEL_MAX_BRIGHTNESS = 100;

CRGB pixels[NUM_PIXELS_HEAD + NUM_PIXELS_SHAFT];
int pixel_brightness = PIXEL_MAX_BRIGHTNESS;

Chrono myChrono;

Button button1(2);

void set_head_pixel(int p, CHSV c)
{
	pixels[p] = c;
}

void set_shaft_pixel(int p, CHSV c)
{
	pixels[NUM_PIXELS_HEAD + p] = c;
}

void setup()
{
	FastLED.addLeds<NEOPIXEL, PIN_NEOPIXELs>(pixels, NUM_PIXELS_HEAD + NUM_PIXELS_SHAFT);
}

void set_head_color(CHSV c)
{
	for (int p = 0; p < NUM_PIXELS_HEAD; p += 1)
	{
		set_head_pixel(p, c);
	}
}

void set_shaft_color(CHSV c)
{
	for (int p = 0; p < NUM_PIXELS_SHAFT; p += 1)
	{
		set_shaft_pixel(p, c);
	}
}

void set_brightness_from_dial()
{
	int dial_value = max(1, min(1000, analogRead(PIN_DIAL)));
	float dial_pc = (float(dial_value) / 1000.0f);
	pixel_brightness = max(1, dial_pc * PIXEL_MAX_BRIGHTNESS);
}

void loop()
{
	// set_brightness_from_dial();

	pixels[0] = CHSV(0, 255, pixel_brightness);
	pixels[1] = CHSV(255, 0, pixel_brightness);
	FastLED.show();

	// static uint8_t hue1 = 0;
	// static uint8_t hue2 = 255;
	// if (myChrono.hasPassed(100))
	// {
	//   fill_gradient(pixels, 0, CHSV(hue1, 255, pixel_brightness), 7, CHSV(hue2, 255, pixel_brightness));
	//   // set_head_color(CHSV(hue - 20, 255, pixel_brightness));
	//   // set_shaft_color(CHSV(hue + 20, 255, pixel_brightness));
	//   FastLED.show();
	//   hue1++;
	//   hue2--;
	//   myChrono.restart();
	// }

	if (button1.pressed())
	{
		// hue = 0;
	}
}