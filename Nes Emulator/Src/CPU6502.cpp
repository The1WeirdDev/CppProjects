#include "CPU6502.h"

#include "Bus.h"

#include <iostream>

void CPU6502::SetBus(Bus* bus) {
	this->bus = bus;
}
void CPU6502::Reset() {
	pc = 0x0000;
	opcode = 0x00;
	status = 0x00;
	sp = 0x00;
	a = 0x00;
	x = 0x00;
	y = 0x00;

	//std::fill(instructions.begin(), instructions.end(), { &CPU6502::InstructionXXX, AddressingMode::None });

	/*
	INFO
	Addresses in instructions are stored low bit followed by high bit
	*/

	instructions[0x21] = { &CPU6502::InstructionAND, AddressingMode::IndexedIndirectX };
	instructions[0x31] = { &CPU6502::InstructionAND, AddressingMode::IndirectIndexedY };
	instructions[0x29] = { &CPU6502::InstructionAND, AddressingMode::Immediate };
	instructions[0x3D] = { &CPU6502::InstructionAND, AddressingMode::AbsoluteX };
	instructions[0x2D] = { &CPU6502::InstructionAND, AddressingMode::Absolute };
	instructions[0x25] = { &CPU6502::InstructionAND, AddressingMode::ZeroPageX };
	instructions[0x35] = { &CPU6502::InstructionAND, AddressingMode::ZeroPageY };

	instructions[0xAA] = { &CPU6502::InstructionTAX, AddressingMode::Implied };
	instructions[0xA8] = { &CPU6502::InstructionTAY, AddressingMode::Implied };
	instructions[0x8A] = { &CPU6502::InstructionTXA, AddressingMode::Implied };
	instructions[0x98] = { &CPU6502::InstructionTYA, AddressingMode::Implied };
}

uint8_t CPU6502::GetFlag(uint8_t flag) {
	return status & flag;
}

void CPU6502::SetFlag(uint8_t flag, bool set) {
	if (!set)
		status &= ~flag;
	else
		status |= flag;
}

void CPU6502::InstructionAND(AddressingMode addr_mode) {
	//ANDS the accumulator
	switch (addr_mode) {
	case AddressingMode::ZeroPageX:
		a &= bus->GetRam((bus->GetRam(pc + 1) + x) % 256);
		pc += 2;
		break;
	case AddressingMode::ZeroPageY:
		a &= bus->GetRam((bus->GetRam(pc + 1) + y) % 256);
		pc += 2;
		break;
	case AddressingMode::Immediate:
		a &= bus->GetRam(bus->GetRam(pc + 1));
		pc += 2;
		break;
	case AddressingMode::Absolute:
		uint8_t low = bus->GetRam(pc + 1);
		uint8_t high = bus->GetRam(pc + 2);
		uint16_t addr = (high << 8) | low;
		a &= bus->GetRam(addr);
		pc += 3;
		break;
	case AddressingMode::AbsoluteX:
		uint8_t low = bus->GetRam(pc + 1);
		uint8_t high = bus->GetRam(pc + 2);
		uint16_t addr = (high << 8) | low;
		a &= bus->GetRam(addr + x + GetFlag(Flags::C));
		pc += 3;
		break;
	case AddressingMode::AbsoluteY:
		uint8_t low = bus->GetRam(pc + 1);
		uint8_t high = bus->GetRam(pc + 2);
		uint16_t addr = (high << 8) | low;
		a &= bus->GetRam(addr + y + GetFlag(Flags::C));
		pc += 3;
		break;
	case AddressingMode::IndexedIndirectX:
		uint8_t arg1 = bus->GetRam(pc + 1) + x;
		a &= bus->GetRam(bus->GetRam(arg1 % 256) + bus->GetRam((arg1 + 1) % 256) * 256);
		pc += 2;
		break;
	case AddressingMode::IndirectIndexedY:
		uint8_t arg1 = bus->GetRam(pc + 1);
		a &= bus->GetRam(bus->GetRam((arg1) % 256) + bus->GetRam((arg1 + x + 1) % 256) * 256);
		pc += 2;
		break;
	default:
		printf("(AND) Called with invalid addressing mode\n");
	}

	SetFlag(Flags::N, a & 0b10000000);
	SetFlag(Flags::Z, a == 0);
}
void CPU6502::InstructionLDA(AddressingMode addr_mode) {

}
void CPU6502::InstructionTAX(AddressingMode addr_mode) {
	x = a;
	SetFlag(Flags::N, x & 128);
	SetFlag(Flags::Z, x == 0);
}
void CPU6502::InstructionTAY(AddressingMode addr_mode) {
	y = a;
	SetFlag(Flags::N, y & 128);
	SetFlag(Flags::Z, y == 0);
}
void CPU6502::InstructionTXA(AddressingMode addr_mode) {
	a = x;
	SetFlag(Flags::N, a & 128);
	SetFlag(Flags::Z, a == 0);
}
void CPU6502::InstructionTYA(AddressingMode addr_mode) {
	a = y;
	SetFlag(Flags::N, a & 128);
	SetFlag(Flags::Z, a == 0);
}

void CPU6502::InstructionXXX(AddressingMode addr_mode) {
	printf("Unidentified Instruction (%d)\n", opcode);
}

void CPU6502::Clock() {
	opcode = bus->GetRam(pc);
	
	//(this->*instructions[opcode])(AddressingMode::None);
}