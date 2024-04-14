#include <headers/components.hpp>

ComponentC::ComponentC() {
    // Component specific initialization
}

ComponentC::~ComponentC() {
    // Component specific destruction
}

Resistor::Resistor() {
    // Resistor specific initialization
    imagePath = "res/images/resistor.png";
    gridSize = RESISTOR_SIZE;
}

Resistor::~Resistor() {
    // Resistor specific destruction
}

Capacitor::Capacitor() {
    // Capacitor specific initialization
    imagePath = "res/images/capacitor.png";
    gridSize = CAPACITOR_SIZE;
}

Capacitor::~Capacitor() {
    // Capacitor specific destruction
}

Inductor::Inductor() {
    // Inductor specific initialization
    imagePath = "res/images/inductor.png";
    gridSize = INDUCTOR_SIZE;
}

Inductor::~Inductor() {
    // Inductor specific destruction
}
