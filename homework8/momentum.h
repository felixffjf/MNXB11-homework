#ifndef __MOMENTUM_H__
#define __MOMENTUM_H__

#include <TObject.h>
#include <cmath> // for magnitude calculation

class Momentum : public TObject {
public:
    Momentum();                  // Default constructor
    Momentum(Int_t variable);    // Parameterized constructor
    virtual ~Momentum();         // Destructor

    void SetMomentum(Float_t x, Float_t y, Float_t z); // Setter for momentum
    Float_t GetMagnitude() const; // Function to calculate magnitude

    Float_t GetPx() const { return px; } // Getter for px
    Float_t GetPy() const { return py; } // Getter for py

private:
    Float_t px; // x-component of momentum
    Float_t py; // y-component of momentum
    Float_t pz; // z-component of momentum

    ClassDef(Momentum, 1); // Macro for class definition
};

#endif // __MOMENTUM_H__
