/**
 * =====================================
 * ╔═╗┬─┐┬┌┬┐┬┌─┐┌─┐┬    ╔═╗┌┬┐┌─┐┌─┐┌─┐
 * ║  ├┬┘│ │ ││  ├─┤│    ╚═╗ │ ├─┤├┤ ├┤
 * ╚═╝┴└─┴ ┴ ┴└─┘┴ ┴┴─┘  ╚═╝ ┴ ┴ ┴└  └
 * =====================================
 * @file touch-panel.h
 * @author Matthew Tole (matthewtole@gmail.com)
 * @brief
 * @version 0.1
 * @date 2019-02-08
 */

#pragma once

#include <Adafruit_MPR121.h>

#define NUM_PADS 12

#define TAP_TOUCH_MS 150
#define TAP_RELEASE_MS 150

class TouchPanelPad
{
  private:
	unsigned long last_touched;
	unsigned long last_released;
	unsigned long last_touch_ms;

  public:
	TouchPanelPad();
	void set_is_touched(bool touched);
	bool is_being_touched();
	bool was_tapped();
};

class TouchPanel
{
  private:
	Adafruit_MPR121 panel;
	TouchPanelPad pads[NUM_PADS];

  public:
	TouchPanel();
	void setup();
	void loop();
	bool is_being_touched(uint8_t pad);
	bool was_tapped(uint8_t pad);
};
