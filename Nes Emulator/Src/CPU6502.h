#pragma once

#include <cstdint>
#include <array>
#include <functional>

enum AddressingMode {
	None=0
};
class Bus;
class CPU6502{
public:
	void SetBus(Bus* bus);

	void Reset();
	void Clock();

	void InstructionAND(AddressingMode addr_mode);
	void InstructionXXX(AddressingMode addr_mode);
private:
	Bus* bus;

	std::array<void (CPU6502::*)(AddressingMode), 256> instructions;

	uint16_t pc = 0x0000; // Program Counter
	uint8_t opcode = 0x00; // Current Instruction
};