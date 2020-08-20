#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define X_CENTER 950
#define Y_CENTER 500
#define X_TEXT 20
#define Y_TEXT 20
#define OUTER_CIRCLE_RADIUS 500
#define INNER_CIRCLE_RADIUS 355
#define ANGLE_OF_ROTATION 2.0
#define RESOLUTION_RATE 0.01
#define PATH_RADIUS 200
#define PEN_COLOR LIGHTBLUE

void draw();
void displaytext();
double rotation();
int lcm(int a, int b);
int gcd(int a, int b);
int getx(double theta);
int gety(double theta);
char* getcolorname(int color);

int main(int argc, char const *argv[]) {

 /* initialize graphics window */
 int error_code;
 initwindow(1900, 1000, "Spirograph");
 error_code = graphresult();

 if (error_code != grOk) { /* an error occurred */
   printf("Graphics error: %s\n", grapherrormsg(error_code));
   printf("Press andy key to exit:\n");
   getch();
   exit(1);               /* return with error code */
 }

 /* set pen color */
 setcolor(PEN_COLOR);

 /* display text */
 displaytext();

 /* draw */
 draw();

 /* clean up */
 getch();
 closegraph();

 return 0;
}

void draw() {
  double theta = 0;                     /* start angle */
  double max_theta = rotation();        /* end angle */
  moveto(getx(theta), gety(theta));     /* position pen at start point */
  while (theta < max_theta) {           /* while theta is not 2π radians */
    lineto(getx(theta), gety(theta));
    theta += RESOLUTION_RATE;
  }
}

void displaytext() {

  /* NOTE: array needs to be size of type plus one for null character appended to the end */
  char outer_r[sizeof(int) + 1];
  char inner_r[sizeof(int) + 1];
  char angle_modifier[sizeof(double) + 1];
  char resolution[sizeof(double) + 1];
  char path_r[sizeof(int) + 1];

  /* fill strings with integer and double values */
  sprintf(outer_r, "%.d", OUTER_CIRCLE_RADIUS);
  sprintf(inner_r, "%d", INNER_CIRCLE_RADIUS);
  sprintf(angle_modifier, "%.2f", ANGLE_OF_ROTATION);
  sprintf(resolution, "%.4f", RESOLUTION_RATE);
  sprintf(path_r, "%d", PATH_RADIUS);

  char* R_info = "OUTER_CIRCLE_RADIUS: ";
  char* r_info = "INNER_CIRCLE_RADIUS: ";
  char* angle_info = "ANGLE_OF_ROTATION: ";
  char* res_info = "RESOLUTION_RATE: ";
  char* path_info = "PATH_RADIUS: ";
  char* color_info = "PEN_COLOR: ";

  /* NOTE: adjust text y position with textheight() function */
  outtextxy(X_TEXT, Y_TEXT, R_info);
  outtextxy(X_TEXT, Y_TEXT + textheight(R_info), r_info);
  outtextxy(X_TEXT, Y_TEXT + 2*textheight(R_info), angle_info);
  outtextxy(X_TEXT, Y_TEXT + 3*textheight(R_info), res_info);
  outtextxy(X_TEXT, Y_TEXT + 4*textheight(R_info), path_info);
  outtextxy(X_TEXT, Y_TEXT + 5*textheight(R_info), color_info);

  /* NOTE: adjust text x position with textwidth() function */
  outtextxy(X_TEXT + textwidth(R_info), Y_TEXT, outer_r);
  outtextxy(X_TEXT + textwidth(r_info), Y_TEXT + textheight(R_info), inner_r);
  outtextxy(X_TEXT + textwidth(angle_info), Y_TEXT + 2*textheight(R_info), angle_modifier);
  outtextxy(X_TEXT + textwidth(res_info), Y_TEXT + 3*textheight(R_info), resolution);
  outtextxy(X_TEXT + textwidth(path_info), Y_TEXT + 4*textheight(R_info), path_r);
  outtextxy(X_TEXT + textwidth(color_info), Y_TEXT + 5*textheight(R_info), getcolorname(PEN_COLOR));
}

/* returns the angle rotation */
double rotation() {
  return ANGLE_OF_ROTATION*M_PI*lcm(OUTER_CIRCLE_RADIUS, INNER_CIRCLE_RADIUS) / OUTER_CIRCLE_RADIUS;
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
int getx(double theta) {
  double x = (OUTER_CIRCLE_RADIUS - INNER_CIRCLE_RADIUS)*cos(theta) + PATH_RADIUS*cos((OUTER_CIRCLE_RADIUS - INNER_CIRCLE_RADIUS)*theta / INNER_CIRCLE_RADIUS);
  return (int) x + X_CENTER;
}

/* y position of the pen */
int gety(double theta) {
 double y = (OUTER_CIRCLE_RADIUS - INNER_CIRCLE_RADIUS)*sin(theta) + PATH_RADIUS*sin((OUTER_CIRCLE_RADIUS - INNER_CIRCLE_RADIUS)*theta / INNER_CIRCLE_RADIUS);
  return (int) y + Y_CENTER;
}

char* getcolorname(int color) {
  switch (color) {
    case 0: return "BLACK"; break;
    case 1: return "BLUE"; break;
    case 2: return "GREEN"; break;
    case 3: return "CYAN"; break;
    case 4: return "RED"; break;
    case 5: return "MAGENTA"; break;
    case 6: return "BROWN"; break;
    case 7: return "LIGHTGRAY"; break;
    case 8: return "DARKGRAY"; break;
    case 9: return "LIGHTBLUE"; break;
    case 10: return "LIGHTGREEN"; break;
    case 11: return "LIGHTCYAN"; break;
    case 12: return "LIGHTRED"; break;
    case 13: return "LIGHTMAGENTA"; break;
    case 14: return "YELLOW"; break;
    case 15: return "WHITE"; break;
    default: return "UNEXPECTED INPUT"; break;
  }
}
