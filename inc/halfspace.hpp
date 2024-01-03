#ifndef HALFSPACE_HPP_INCLUDED
#define HALFSPACE_HPP_INCLUDED
#include "surface.hpp"
#include "particle.hpp"

class HalfSpace {
    public:
    Surface& surface_ ;
    int sign_ ;
    bool isin(const Particle& p) ;
    HalfSpace(int sign, Surface& s) ;
} ;

#endif
