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

#include <Adafruit_MPR121.h>
#include <Logging.h>

#include "touch-panel.h"

Log Log;

TouchPanel::TouchPanel()
{
	panel = Adafruit_MPR121();
}

void TouchPanel::setup()
{
	if (!panel.begin(0x5A))
	{
		Log.println(LOG_ERROR, "TouchPanel", "Sensor was not detected");
	}
	else
	{
		Log.println(LOG_INFO, "TouchPanel", "Sensor was detected.");
	}
}

void TouchPanel::loop()
{
	uint16_t touched = panel.touched();
	for (uint8_t p = 0; p < NUM_PADS; p += 1)
	{
		pads[p].set_is_touched(touched & _BV(p));
	}
}

bool TouchPanel::is_being_touched(uint8_t pad)
{
	return pads[pad].is_being_touched();
}

bool TouchPanel::was_tapped(uint8_t pad)
{
	return pads[pad].was_tapped();
}

TouchPanelPad::TouchPanelPad()
{
	last_touched = 0;
	last_released = 0;
	last_touch_ms = 0;
}

void TouchPanelPad::set_is_touched(bool touched)
{
	if (touched && !is_being_touched())
	{
		last_touched = millis();
	}
	else if (!touched && is_being_touched())
	{
		last_released = millis();
		last_touch_ms = last_released - last_touched;
		Log.println(LOG_DEBUG, "TouchPanel", String(last_touch_ms));
	}
}

bool TouchPanelPad::is_being_touched()
{
	return last_touched > last_released;
}

bool TouchPanelPad::was_tapped()
{
	if (last_touch_ms > 0 && !is_being_touched() && last_touch_ms <= TAP_TOUCH_MS && millis() - last_released >= TAP_RELEASE_MS)
	{
		last_touch_ms = 0;
		return true;
	}
	return false;
}
