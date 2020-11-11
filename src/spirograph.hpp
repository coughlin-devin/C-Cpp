#ifndef SPIROGRAPH_H_
#define SPIROGRAPH_H_

#include "formula.hpp"

#define OUTER_CIRCLE_RADIUS 493
#define INNER_CIRCLE_RADIUS 211
#define PATH_RADIUS 220
#define ANGLE_OF_ROTATION 2.0

class Spirograph {
private:
  int outer_circle_radius;
  int inner_circle_radius;
  int path_radius;
  double angle_of_rotation;

public:
  Spirograph();
  Spirograph(int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation);

  /* draw the spirograph */
  void draw(double resolution_rate);

  /* increment one or more of the radii by the passed values*/
  void incrementRadii(int rout, int rin, int rpath);

  /* Setters */
  void set_outer_circle_radius(int radius) {
    outer_circle_radius = radius;
  }
  void set_inner_circle_radius(int radius) {
    inner_circle_radius = radius;
  }
  void set_path_radius(int radius) {
    path_radius = radius;
  }
  void set_angle_of_rotation(double theta) {
    angle_of_rotation = theta;
  }

  /* Getters */
  int get_outer_circle_radius() {
    return outer_circle_radius;
  }
  int get_inner_circle_radius() {
    return inner_circle_radius;
  }
  int get_path_radius() {
    return path_radius;
  }
  double get_angle_of_rotation() {
    return angle_of_rotation;
  }

  ~Spirograph () {};
};
#endif
