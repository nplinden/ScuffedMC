#include "plane.hpp"
#include "particle.hpp"
#include <limits>
#include <Eigen/Dense>
using Eigen::MatrixXd;
using Eigen::Vector3d;


PPlane::PPlane(double offset, Vector3d normal){
    offset_ = offset ;
    normal_ = normal ;
};

double PPlane::distance(const Particle& p){
    double u = normal_.dot(p.direction_) ;
    double du = normal_.dot(p.position_) ;
    if (u != 0) {
        return (offset_ - du) / u ;
    } else {
        return std::numeric_limits<double>::quiet_NaN() ;
    }
};

bool PPlane::isleft(const Particle& p){
    double p_offset = normal_.dot(p.position_) ;
    return (p_offset < offset_) ;
} ;

bool PPlane::isright(const Particle& p){
    double p_offset = normal_.dot(p.position_) ;
    return (p_offset > offset_) ;
} ;

bool PPlane::ison(const Particle& p){
    double p_offset = normal_.dot(p.position_) ;
    return (p_offset == offset_) ;
}

XPlane::XPlane(double x0) : PPlane(x0, Vector3d(1.0, 0.0, 0.0)){};
YPlane::YPlane(double y0) : PPlane(y0, Vector3d(0.0, 1.0, 0.0)){};
ZPlane::ZPlane(double z0) : PPlane(z0, Vector3d(0.0, 0.0, 1.0)){};
