// Guard to prevent multiple inclusions
#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

#include <TObject.h>
#include <cmath> // for magnitude calculation

class MyClass : public TObject {
public:
    MyClass();                  // Default constructor
    MyClass(Int_t variable);    // Parameterized constructor
    virtual ~MyClass();         // Destructor

    void SetMomentum(Float_t x, Float_t y, Float_t z); // Setter for momentum
    Float_t GetMagnitude() const; // Function to calculate magnitude

private:
    Float_t px; // x-component of momentum
    Float_t py; // y-component of momentum
    Float_t pz; // z-component of momentum

    ClassDef(MyClass, 1); // Macro for class definition
};

#endif // __MY_CLASS_H__
