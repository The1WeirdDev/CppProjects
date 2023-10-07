#include "Bus.h"

Bus::Bus() {
}
void Bus::Reset() {
	cpu.Reset();
	std::fill(ram.begin(), ram.end(), 0);

	cpu.SetBus(this);
}

void Bus::Clock() {
	cpu.Clock();
}
uint8_t Bus::GetRam(uint16_t location) {
	if (location >= 0 && location < 0xFFFF)
		return ram[location];

	return 0x00;
}
void Bus::SetRam(uint16_t location, uint8_t value) {
	if (location >= 0 && location < 0xFFFF)
		ram[location] = value;
}