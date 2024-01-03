#ifndef PARTICLE_HPP_INCLUDED
#define PARTICLE_HPP_INCLUDED
#include <Eigen/Dense>
#include <iostream>
using Eigen::Vector3d;

class Particle {
    public:
    Particle(Vector3d position, Vector3d direction) ;
    Vector3d position_ ;
    Vector3d direction_ ;
    double energy_ ;
    friend std::ostream& operator<< (std::ostream& stream, const Particle& p) ;
};

#endif // PARTICLE_HPP_INCLUDED