#ifndef PLANE_HPP_INCLUDED
#define PLANE_HPP_INCLUDED
#include "particle.hpp"
#include "surface.hpp"
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::Vector3d;

class PPlane : public Surface {
    public:
    double offset_ ;
    Vector3d normal_ ;
    PPlane(double offset, Vector3d normal) ;
    double distance(const Particle& p) ;
    bool isleft(const Particle& p) ;
    bool isright(const Particle& p) ;
    bool ison(const Particle& p) ;
} ;

class XPlane : public PPlane {
    public:
    XPlane(double x0);
} ;

class YPlane : public PPlane {
    public:
    YPlane(double y0);
} ;

class ZPlane : public PPlane {
    public:
    ZPlane(double z0);
} ;

#endif