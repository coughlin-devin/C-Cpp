#include "spirograph.hpp"

/* Constructor */
Spirograph::Spirograph (int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation) {
    this->outer_circle_radius = outer_circle_radius;
    this->inner_circle_radius = inner_circle_radius;
    this->path_radius = path_radius;
    this->angle_of_rotation = angle_of_rotation;
}

void Spirograph::draw(double resolution_rate) {
  int R = this->get_outer_circle_radius();
  int r = this->get_inner_circle_radius();
  int d = this->get_path_radius();

  double theta = 0;                                                             /* start angle */
  double max_theta = rotation(R, r, this->get_angle_of_rotation());             /* end angle */

  moveto(getx(R, r, d, theta), gety(R, r, d, theta));                           /* position pen at start point */

  while (theta < max_theta) {                                                   /* while theta is not 2π radians */
    lineto(getx(R, r, d, theta), gety(R, r, d, theta));
    theta += resolution_rate;
  }
}

/* increment one or more of the radii by the passed values*/
void Spirograph::incrementRadii(int rout, int rin, int rpath) {
  this->set_outer_circle_radius(this->get_outer_circle_radius() + rout);
  this->set_inner_circle_radius(this->get_inner_circle_radius() + rin);
  this->set_path_radius(this->get_path_radius() + rpath);
}
