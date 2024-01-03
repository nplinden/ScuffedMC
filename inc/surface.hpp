#ifndef SURFACE_HPP_INCLUDED
#define SURFACE_HPP_INCLUDED
#include "particle.hpp"

class Surface {
    public:
    virtual double distance(const Particle& p) = 0 ;
    virtual bool isleft(const Particle& p) = 0 ;
    virtual bool isright(const Particle& p) = 0 ;
    virtual bool ison(const Particle& p) = 0 ;
} ;

#endif