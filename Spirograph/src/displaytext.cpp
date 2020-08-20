#include "displaytext.h"

void displaytext(Spirograph sp_graph, double resolution_rate, int pen_color) {

  /* NOTE: array needs to be size of type plus one for null character appended to the end */
  char outer_r[sizeof(int) + 1];
  char inner_r[sizeof(int) + 1];
  char angle_modifier[sizeof(double) + 1];
  char resolution[sizeof(double) + 1];
  char path_r[sizeof(int) + 1];

  /* fill strings with integer and double values */
  sprintf(outer_r, "%.d", sp_graph.get_outer_circle_radius());
  sprintf(inner_r, "%d", sp_graph.get_inner_circle_radius());
  sprintf(path_r, "%d", sp_graph.get_path_radius());
  sprintf(angle_modifier, "%.2f", sp_graph.get_angle_of_rotation());
  sprintf(resolution, "%.4f", resolution_rate);

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
  outtextxy(X_TEXT + textwidth(color_info), Y_TEXT + 5*textheight(R_info), getcolorname(pen_color));
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
