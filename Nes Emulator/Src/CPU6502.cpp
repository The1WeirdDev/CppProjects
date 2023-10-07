#include "CPU6502.h"

#include "Bus.h"

#include <iostream>

void CPU6502::SetBus(Bus* bus) {
	this->bus = bus;
}
void CPU6502::Reset() {
	pc = 0x0000;
	opcode = 0x00;

	std::fill(instructions.begin(), instructions.end(), &CPU6502::InstructionXXX);
}

void CPU6502::InstructionAND(AddressingMode addr_mode) {

}
void CPU6502::InstructionXXX(AddressingMode addr_mode) {
	printf("Unidentified Instruction (%d)\n", opcode);
}

void CPU6502::Clock() {
	opcode = bus->GetRam(pc);
	
	(this->*instructions[opcode])(AddressingMode::None);
}