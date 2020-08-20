#ifndef Spirograph_H_
#define Spirograph_H_

#include "formula.h"

class Spirograph {
private:
  int outer_circle_radius;
  int inner_circle_radius;
  int path_radius;
  double angle_of_rotation;

public:
  Spirograph (int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation);

  /* draw the spirograph */
  void draw(double resolution_rate);

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
