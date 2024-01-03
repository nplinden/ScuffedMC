#ifndef CYLINDER_HPP_INCLUDED
#define CYLINDER_HPP_INCLUDED
#include "particle.hpp"
#include "surface.hpp"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::Vector2d;


class InfCylinder : public Surface {
    public:
    Vector3d center_ ;
    Vector3d direction_ ;
    double radius_ ;
    InfCylinder(double radius, Vector3d center, Vector3d direction) ;
    double distance(const Particle& p) ;
    bool isleft(const Particle& p) ;
    bool isright(const Particle& p) ;
    bool ison(const Particle& p) ;
} ;

class XInfCylinder : public InfCylinder{
    public:
    XInfCylinder(double radius) ;
    XInfCylinder(double radius, Vector3d center) ;
} ;

class YInfCylinder : public InfCylinder{
    public:
    YInfCylinder(double radius) ;
    YInfCylinder(double radius, Vector3d center) ;
} ;

class ZInfCylinder : public InfCylinder{
    public:
    ZInfCylinder(double radius) ;
    ZInfCylinder(double radius, Vector3d center) ;
} ;


#endif