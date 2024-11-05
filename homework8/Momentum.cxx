#include "Momentum.h"
#include <cmath> // For sqrt function

ClassImp(Momentum) // Macro for implementing ROOT class

// Default constructor
Momentum::Momentum() : px(0), py(0), pz(0) {}

// Parameterized constructor
Momentum::Momentum(Int_t variable) : px(variable), py(variable), pz(variable) {}

// Destructor
Momentum::~Momentum() {}

// Set momentum components
void Momentum::SetMomentum(Float_t x, Float_t y, Float_t z) {
    px = x;
    py = y;
    pz = z;
}

// Calculate magnitude of momentum vector
Float_t Momentum::GetMagnitude() const {
    return std::sqrt(px * px + py * py + pz * pz);
}
