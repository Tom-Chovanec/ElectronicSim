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
}

Resistor::~Resistor() {
    // Resistor specific destruction
}

Capacitor::Capacitor() {
    // Capacitor specific initialization
    imagePath = "res/images/capacitor.png";
}

Capacitor::~Capacitor() {
    // Capacitor specific destruction
}

Inductor::Inductor() {
    // Inductor specific initialization
    imagePath = "res/images/inductor.png";
}

Inductor::~Inductor() {
    // Inductor specific destruction
}
