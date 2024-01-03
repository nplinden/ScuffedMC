#ifndef SPHERE_HPP_INCLUDED
#define SPHERE_HPP_INCLUDED
#include "particle.hpp"
#include "surface.hpp"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::Vector3d;

class Sphere : public Surface{
    public:
    Vector3d center_ ;
    double radius_ ;
    Sphere(double radius) ;
    Sphere(double radius, Vector3d center) ;
    double distance(const Particle& p) ;
    bool isleft(const Particle& p) ;
    bool isright(const Particle& p) ;
    bool ison(const Particle& p) ;
} ;


#endif