#include "formula.h"

/* returns the angle rotation */
double rotation(int R, int r, double theta) {
  return theta*M_PI*lcm(R, r) / R;
}

/* least common multiple */
int lcm(int a, int b) {
  return (int)fabs(a*b)/gcd(a, b);
}

/* greatest common denominator */
int gcd(int a, int b) {
  if (a == b) {
    return a;
  }
  else if (a > b) {
    return gcd(a - b, b);
  }
  else {
    return gcd(a, b - a);
  }
}

/* OPTIMIZE: can probaly extract the code for getx() and gety() */
/* x position of the pen */
int getx(int R, int r, int d, double theta) {
  double x = (R - r)*cos(theta) + d*cos((R - r)*theta / r);
  return (int) x + X_CENTER;
}

/* y position of the pen */
int gety(int R, int r, int d, double theta) {
  double y = (R - r)*sin(theta) - d*sin((R - r)*theta / r);
  return (int) y + Y_CENTER;
}
