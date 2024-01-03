#include "particle.hpp"
#include <iostream>
#include <Eigen/Dense>
using Eigen::Vector3d;

Particle::Particle(Vector3d position, 
                   Vector3d direction){
    position_ = position ;
    direction_ = direction ;
    energy_ = 0 ;
} ;

std::ostream& operator<< (std::ostream& stream, const Particle& p) {
    stream << "Position :\n" << p.position_ << std::endl
           << "Direction :\n" << p.direction_ << std::endl;
    return stream ;
} ;