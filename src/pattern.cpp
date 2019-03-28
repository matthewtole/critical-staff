#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#pragma GCC diagnostic pop

#include "./crown.h"
#include "./constants.h"
#include "./pattern.h"

uint8_t rows[5][11] =
	{
		{7, 0, 4, 7, 9, 10, 12, 13},
		{8, 1, 2, 3, 5, 6, 8, 11, 14},
		{8, 15, 16, 18, 21, 23, 24, 26, 28},
		{7, 17, 19, 20, 22, 25, 27, 29},
		{3, 30, 31, 32}};

uint8_t dots[NUM_FACES * PIXELS_PER_FACE] = {0, 4, 7, 9, 10, 12, 13, 1, 2, 3, 5, 6, 8, 11, 14, 15, 16, 18, 21, 23, 24, 26, 28, 17, 19, 20, 22, 25, 27, 29, 32, 31, 30};

void CrownPattern::set_color(CRGB pixels[], CHSV color)
{
	for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
	{
		pixels[p] = color;
	}
}
void CrownPattern::set_face_color(CRGB pixels[], uint8_t face, CHSV color)
{
	uint8_t offset = face * PIXELS_PER_FACE;
	for (uint8_t p = 0; p < PIXELS_PER_FACE; p += 1)
	{
		pixels[offset + p] = color;
	}
}

void CrownPatternPulseWhite::update(CRGB pixels[])
{
	for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
	{
		set_color(pixels, blend(CHSV(255, 0, 20), CHSV(255, 0, MAX_BRIGHTNESS), beatsin8(45, 0, 255, 0)));
	}
}

CrownPatternRainbowPulse::CrownPatternRainbowPulse()
{
	hue_1 = 0;
	hue_2 = 100;
}

void CrownPatternRainbowPulse::update(CRGB pixels[])
{
	if (chrono.hasPassed(100, true))
	{
		hue_1 = (hue_1 + 1) % 256;
		hue_2 = (hue_2 + 1) % 256;
	}
	for (uint8_t f = 0; f < NUM_FACES; f += 1)
	{
		set_face_color(pixels, f, blend(CHSV(hue_1, 255, MAX_BRIGHTNESS), CHSV(hue_2, 255, MAX_BRIGHTNESS), beatsin8(20, 0, 255, 0, f * 18)));
	}
}

CrownPatternRainbowChase::CrownPatternRainbowChase()
{
	hue = 0;
	pixel = 0;
}

void CrownPatternRainbowChase::update(CRGB pixels[])
{
	if (chrono.hasPassed(50, true))
	{
		pixels[dots[pixel]] = CHSV(hue, 255, MAX_BRIGHTNESS);
		pixel = (pixel + 1) % (NUM_FACES * PIXELS_PER_FACE);
		if (pixel == 0)
		{
			hue = (hue + 10) % 256;
		}
		for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
		{
			if (p == pixel)
			{
				continue;
			}
			pixels[p].fadeToBlackBy(30);
		}
	}
}

CrownPatternColorRows::CrownPatternColorRows()
{
	hue_1 = 0;
	hue_2 = 0;
}

void CrownPatternColorRows::update(CRGB pixels[])
{
	if (chrono.hasPassed(100, true))
	{
		hue_1 = (hue_1 + 1) % 256;
		hue_2 = (hue_2 + 1) % 256;
	}
	for (uint8_t r = 0; r < 5; r += 1)
	{
		CHSV c = blend(CHSV(hue_2, 255, MAX_BRIGHTNESS), CHSV(hue_1, 255, MAX_BRIGHTNESS), beatsin8(30, 0, 255, 0, r * 20));
		for (uint8_t p = 1; p <= rows[r][0]; p += 1)
		{
			pixels[rows[r][p]] = c;
		}
	}
}

CrownPatternPixelFlash::CrownPatternPixelFlash()
{
	hue_1 = 0;
	hue_2 = 16;
}

void CrownPatternPixelFlash::update(CRGB pixels[])
{
	if (chrono.hasPassed(random(200, 400), true))
	{
		uint8_t p = random(0, NUM_FACES * PIXELS_PER_FACE);
		pixels[p] = CHSV(random(hue_1, hue_2), random(150, 255), random(MAX_BRIGHTNESS / 2, MAX_BRIGHTNESS));
	}
	if (chrono_hue.hasPassed(500, true))
	{
		hue_1 = (hue_1 + 1) % 256;
		hue_2 = (hue_2 + 1) % 256;
	}
	if (chrono_fade.hasPassed(50, true))
	{
		for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
		{
			pixels[p].fadeToBlackBy(1);
		}
	}
}

CrownPatternFaceFlash::CrownPatternFaceFlash()
{
	hue_1 = 0;
	hue_2 = 16;
}

void CrownPatternFaceFlash::update(CRGB pixels[])
{
	if (chrono.hasPassed(random(200, 400), true))
	{
		uint8_t p = random(0, NUM_FACES);
		set_face_color(pixels, p, CHSV(random(hue_1, hue_2), random(150, 255), random(MAX_BRIGHTNESS / 2, MAX_BRIGHTNESS)));
	}
	if (chrono_hue.hasPassed(500, true))
	{
		hue_1 = (hue_1 + 1) % 256;
		hue_2 = (hue_2 + 1) % 256;
	}
	if (chrono_fade.hasPassed(50, true))
	{
		for (uint8_t p = 0; p < NUM_FACES * PIXELS_PER_FACE; p += 1)
		{
			pixels[p].fadeToBlackBy(1);
		}
	}
}
