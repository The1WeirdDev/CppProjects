#pragma once

#include <array>

#include "CPU6502.h"

class Bus{
public:
	Bus();

	void Reset();
	void Clock();

	uint8_t GetRam(uint16_t location);
	void SetRam(uint16_t location, uint8_t value);
private:
	std::array<uint8_t, 1024 * 64> ram;
	CPU6502 cpu;
};