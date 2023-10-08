#pragma once

#include <cstdint>
#include <array>
#include <functional>

enum AddressingMode {
	None=0,
	ZeroPageX, // Zero page Indexed
	ZeroPageY, // Zero page Indexed
	Immediate, // Immediate
	Implied, // Immediate
	Absolute, // Absolute Indexed
	AbsoluteX, // Absolute Indexed
	AbsoluteY, // Absolute Indexed
	IndexedIndirectX, // Indexed Indirect
	IndirectIndexedY // Indirect Indexed
};
class Bus;

class CPU6502{
public:
	struct Instruction {
		void (CPU6502::* func)(AddressingMode) = nullptr;
		AddressingMode mode;
	};
	void SetBus(Bus* bus);

	void Reset();
	void Clock();

	uint8_t GetFlag(uint8_t flag);
	void SetFlag(uint8_t flag, bool set = true);

	void InstructionAND(AddressingMode addr_mode);

	void InstructionTAX(AddressingMode addr_mode);
	void InstructionTAY(AddressingMode addr_mode);
	void InstructionTXA(AddressingMode addr_mode);
	void InstructionTYA(AddressingMode addr_mode);

	void InstructionLDA(AddressingMode addr_mode);

	void InstructionXXX(AddressingMode addr_mode);

	enum Flags {
		C = (1 << 0), // Carry
		Z = (1 << 1), // Zero
		I = (1 << 2), // Interrupt Disable
		D = (1 << 3), // Decimal
		B = (1 << 4), // B Flag
		U = (1 << 5), // Unused
		V = (1 << 6), // Overflow
		N = (1 << 7), // Negative
	};
private:
	Bus* bus;
	 
	std::array<Instruction, 256> instructions{ &CPU6502::InstructionXXX, AddressingMode::None};

	uint16_t pc = 0x0000; // Program Counter
	uint8_t status = 0x00;
	uint8_t opcode = 0x00; // Current Instruction
	uint8_t sp = 0x0;

	//Registers
	uint8_t a = 0x0;
	uint8_t x = 0x0;
	uint8_t y = 0x0;

};