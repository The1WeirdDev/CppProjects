#include <iostream>

#include "Bus.h"

int main(int argc, char** argv) {
	Bus bus;
	bus.Reset();

	while (true) {
		bus.Clock();
	}
}