#include "sphere.hpp"
#include "particle.hpp"
#include <cmath>
#include <limits>
#include <iostream>
using Eigen::MatrixXd;
using Eigen::Vector3d;

Sphere::Sphere(double radius, Vector3d center){
    radius_ = radius ;
    center_ = center ;
} ;

Sphere::Sphere(double radius) : Sphere(radius, Vector3d(0., 0., 0.)){} ;

double Sphere::distance(const Particle& p){
    Vector3d dcenter = p.position_ - center_  ;
    double C = pow(dcenter.norm(), 2) - pow(radius_, 2) ;
    double B = dcenter.dot(p.direction_) ;
    double disc = pow(B, 2) - C ;
    // std::cout << "B = " << B << " C = " << C << std::endl ;
    // std::cout << "radius = " << radius_ << std::endl ;
    if (disc >= 0.) {
        if (C < 0.){
            // The particle is inside the sphere, we take the only positive
            // root.
            return -B + sqrt(pow(B, 2) - C) ;
        } else {
            // The particle is outside the sphere, both roots are positive and 
            // we take the smallest one.
            double d = -B - sqrt(pow(B, 2) - C) ;
            if (d >= 0) {
                return d ;
            }
        }
    }
    // If we get here, there is no intersection with the sphere
    return std::numeric_limits<double>::quiet_NaN() ;
}

bool Sphere::isleft(const Particle& p){
    Vector3d dcenter = p.position_ - center_  ;
    return dcenter.norm() < radius_ ;
}

bool Sphere::isright(const Particle& p){
    Vector3d dcenter = p.position_ - center_  ;
    return dcenter.norm() > radius_ ;
}

bool Sphere::ison(const Particle& p){
    Vector3d dcenter = p.position_ - center_  ;
    return dcenter.norm() == radius_ ;
}
