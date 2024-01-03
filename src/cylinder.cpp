#include "cylinder.hpp"
#include "particle.hpp"
#include <cmath>
#include <limits>
#include <iostream>
using Eigen::MatrixXd;
using Eigen::Vector3d;

InfCylinder::InfCylinder(double radius, Vector3d center, Vector3d direction){
    radius_ = radius ;
    center_ = center ;
    direction_ = direction ;
} ;

double InfCylinder::distance(const Particle& p){
    Vector3d surf_proj = Vector3d(1., 1., 1.) - direction_ ;
    Vector3d dcenter = surf_proj.cwiseProduct(p.position_ - center_) ;
    Vector3d proj_dir = surf_proj.cwiseProduct(p.direction_) ;
    double A = pow(proj_dir.norm(), 2) ;
    double B = proj_dir.dot(dcenter) ;
    double C = pow(dcenter.norm(), 2) - pow(radius_, 2) ;

    if (A == 0.) {
        // Check that the particle's direction is not colinear to the cylinder
        // direction
        if (C==0.) {
            return 0. ;
        } else {
            return std::numeric_limits<double>::quiet_NaN() ;
        }
    } else if (pow(B, 2) - A*C < 0.) {
        return std::numeric_limits<double>::quiet_NaN() ;
    } else {
        if (C < 0.) {
            return (-B + sqrt(pow(B, 2) - A * C)) / A ;
        } else {
            return (-B - sqrt(pow(B, 2) - A * C)) / A ;
        }
    }
} ;

bool InfCylinder::isleft(const Particle& p){
    Vector3d surf_proj = Vector3d(1., 1., 1.) - direction_ ;
    Vector3d dcenter = surf_proj.cwiseProduct(p.position_ - center_) ;
    return dcenter.norm() < radius_ ;
}

bool InfCylinder::isright(const Particle& p){
    Vector3d surf_proj = Vector3d(1., 1., 1.) - direction_ ;
    Vector3d dcenter = surf_proj.cwiseProduct(p.position_ - center_) ;
    return dcenter.norm() > radius_ ;
}

bool InfCylinder::ison(const Particle& p){
    Vector3d surf_proj = Vector3d(1., 1., 1.) - direction_ ;
    Vector3d dcenter = surf_proj.cwiseProduct(p.position_ - center_) ;
    return dcenter.norm() == radius_ ;
}

XInfCylinder::XInfCylinder(double radius, Vector3d center) : InfCylinder(radius, center, Vector3d(1., 0., 0.)){} ;
XInfCylinder::XInfCylinder(double radius) : XInfCylinder(radius, Vector3d(0., 0., 0.)) {} ;
YInfCylinder::YInfCylinder(double radius, Vector3d center) : InfCylinder(radius, center, Vector3d(0., 1., 0.)){} ;
YInfCylinder::YInfCylinder(double radius) : YInfCylinder(radius, Vector3d(0., 0., 0.)) {} ;
ZInfCylinder::ZInfCylinder(double radius, Vector3d center) : InfCylinder(radius, center, Vector3d(0., 0., 1.)){} ;
ZInfCylinder::ZInfCylinder(double radius) : ZInfCylinder(radius, Vector3d(0., 0., 0.)) {} ;
