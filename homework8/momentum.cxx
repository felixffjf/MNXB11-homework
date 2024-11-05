#include "momentum.h"
#include <cmath> 

ClassImp(MyClass) // Macro for implementing ROOT class

// Default constructor
MyClass::MyClass() : px(0), py(0), pz(0) {}

// Parameterized constructor
MyClass::MyClass(Int_t variable) : px(variable), py(variable), pz(variable) {}

// Destructor
MyClass::~MyClass() {}

// Set momentum components
void MyClass::SetMomentum(Float_t x, Float_t y, Float_t z) {
    px = x;
    py = y;
    pz = z;
}

// Calculate magnitude of momentum vector
Float_t MyClass::GetMagnitude() const {
    return std::sqrt(px * px + py * py + pz * pz);
}
