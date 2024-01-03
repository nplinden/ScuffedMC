#include "halfspace.hpp"


HalfSpace::HalfSpace(int sign, Surface& s) {
    sign_ = sign ;
    surface_ = s ;
} ;

bool HalfSpace::isin(Particle& p) {
    if (sign_ == -1) {
        return surface_.isleft(p) ;
    } else if (sign_ == 1) {
        return surface_.isright(p) ;
    }
} ;