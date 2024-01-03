#include <iostream>
#include <fstream>
#include <vector>
#include "config.h"
#include <Eigen/Dense>
#include "particle.hpp"
#include "plane.hpp"
#include "sphere.hpp"
#include "cylinder.hpp"
using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Vector3d;
using Eigen::Vector2d;

int main(int argc, char* argv[])
{

  /*
  XPlane xplane = XPlane(10.) ;
  YPlane yplane = YPlane(0.) ;
  ZPlane zplane = ZPlane(10.) ;
  Sphere sphere1 = Sphere(5.) ;
  Vector3d center(10, 10, 10) ;
  Sphere sphere2 = Sphere(5., center) ;

  Vector3d position(0., 0., 0.) ;
  Vector3d direction(1., 1., 1.) ;
  direction /= direction.norm() ;
  Particle p = Particle(position, direction) ;

  std::cout << p ;
  std::cout << "Distance to XPlane = " << xplane.distance(p) << std::endl ;
  std::cout << "Distance to YPlane = " << yplane.distance(p) << std::endl ;
  std::cout << "Distance to ZPlane = " << zplane.distance(p) << std::endl ;
  std::cout << "Distance to sphere1 = " << sphere1.distance(p) << std::endl ;
  std::cout << "Distance to sphere2 = " << sphere2.distance(p) << std::endl ;

  p.direction_ = Vector3d(0., 1., 0.) ;
  XInfCylinder cyl1x(5.) ;
  XInfCylinder cyl2x(5., Vector3d(0., 15., 0.)) ;
  std::cout << "Distance to cyl1 (x) = " << cyl1x.distance(p) << std::endl ;
  std::cout << "Distance to cyl2 (x) = " << cyl2x.distance(p) << std::endl ;

  p.direction_ = Vector3d(1., 0., 0.) ;
  YInfCylinder cyl1y(5.) ;
  YInfCylinder cyl2y(5., Vector3d(15., 0., 0.)) ;
  std::cout << "Distance to cyl1 (y) = " << cyl1y.distance(p) << std::endl ;
  std::cout << "Distance to cyl2 (y) = " << cyl2y.distance(p) << std::endl ;

  p.direction_ = Vector3d(1., 0., 0.) ;
  ZInfCylinder cyl1z(5.) ;
  ZInfCylinder cyl2z(5., Vector3d(15., 0., 0.)) ;
  std::cout << "Distance to cyl1 (z) = " << cyl1z.distance(p) << std::endl ;
  std::cout << "Distance to cyl2 (z) = " << cyl2z.distance(p) << std::endl ;
  */

  auto xs = VectorXd::LinSpaced(1000, -10., 10.) ;
  auto ys = VectorXd::LinSpaced(1000, -10., 10.) ;
  // std::cout << xs.transpose() << std::endl ;
  // std::cout << ys.transpose() << std::endl ;
  MatrixXd matrix(1000, 1000) ;
  Sphere sphere(5.) ;
  XInfCylinder cylinder(5.) ;
  Vector3d position(0., 0., 0.) ;
  Vector3d direction(0., 0., 0.) ;
  Particle p(position, direction) ;
  for (int ix(0); ix < xs.size(); ix++) {
    auto x = xs(ix) ;
    for (int iy(0); iy < ys.size(); iy++) {
      auto y = ys(iy) ;
      p.position_(0) = x ;
      p.position_(1) = y ;
      bool isin = sphere.isleft(p) ;
      if (sphere.isleft(p)) {
        matrix(ix, iy) = 1. ;
      } else {
        matrix(ix, iy) = 0. ;
      }
    }
  }
  // std::cout << tot << std::endl ;
  // std::cout << matrix << std::endl ;
  std::ofstream myfile;
  myfile.open ("matrix.txt");
  myfile << matrix ;
  myfile.close();

  return 0;
}
