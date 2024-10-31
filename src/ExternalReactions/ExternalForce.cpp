#include "ExternalForce.hpp"


    // Constructor with default values 
    Force :: forceVector :: forceVector (float x_val, float y_val, float z_val)
        : x(x_val), y(y_val), z(z_val) {
        
     }
    // Constructor for Force class 
    Force :: Force(forceVector direction, forceVector location)
        : Direction (direction), Location(location), frameType(BODY){
        
    }

    // Destructor 
    Force :: ~Force() {
        
    }

    void Force :: applyForce() {
        
    }

    string Force :: forceName(string name) {
        return name;
    }

    double locationUnits(double units){
        return units; 
    }
    void Force :: changeFrame(Frame newFrame) {
        frameType = newFrame;
    }
