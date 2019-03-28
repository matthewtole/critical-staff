#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <FastLED.h>
#pragma GCC diagnostic pop

#include "./crown.h"
#include "./constants.h"

class CrownPattern
{
  public:
	virtual void update(CRGB pixels[]);

  protected:
	void set_color(CRGB pixels[], CHSV color);
	void set_face_color(CRGB pixels[], uint8_t face, CHSV color);
};

class CrownPatternPulseWhite : public CrownPattern
{
	void update(CRGB pixels[]);
};

class CrownPatternRainbowPulse : public CrownPattern
{
  private:
	Chrono chrono;
	uint8_t hue_1;
	uint8_t hue_2;

  public:
	CrownPatternRainbowPulse();
	void update(CRGB pixels[]);
};

class CrownPatternRainbowChase : public CrownPattern
{
  private:
	Chrono chrono;
	uint8_t hue;
	uint8_t pixel;

  public:
	CrownPatternRainbowChase();
	void update(CRGB pixels[]);
};

class CrownPatternColorRows : public CrownPattern
{
  private:
	Chrono chrono;
	uint8_t hue_1;
	uint8_t hue_2;

  public:
	CrownPatternColorRows();
	void update(CRGB pixels[]);
};

class CrownPatternPixelFlash : public CrownPattern
{
  private:
	Chrono chrono;
	Chrono chrono_fade;
	Chrono chrono_hue;
	uint8_t hue_1;
	uint8_t hue_2;

  public:
	CrownPatternPixelFlash();
	void update(CRGB pixels[]);
};

class CrownPatternFaceFlash : public CrownPattern
{
  private:
	Chrono chrono;
	Chrono chrono_fade;
	Chrono chrono_hue;
	uint8_t hue_1;
	uint8_t hue_2;

  public:
	CrownPatternFaceFlash();
	void update(CRGB pixels[]);
};
