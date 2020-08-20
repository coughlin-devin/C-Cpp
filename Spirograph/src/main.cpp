#include "spirograph.h"
#include "displaytext.h"

int main(int argc, char const *argv[]) {

  /* initialize graphics window */
  int error_code;
  initwindow(950, 1000, "Spirograph");
  error_code = graphresult();

  if (error_code != grOk) { /* an error occurred */
    printf("Graphics error: %s\n", grapherrormsg(error_code));
    printf("Press andy key to exit:\n");
    getch();
    exit(1);               /* return with error code */
  }

  /* create a spirograph */
  /* NOTE: Constructor looks like Spirograph(int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation) */
  Spirograph sp_graph = Spirograph(500, 355, 200, 2.0);

  const double resolution_rate = 0.01;
  int pen_color = LIGHTBLUE;

  /* set pen color */
  setcolor(pen_color);

  /* display text */
  displaytext(sp_graph, resolution_rate, pen_color);

  /* draw */
  sp_graph.draw(resolution_rate);

  char file_name[16];
  char copy[8];
  const char* file_extension = ".bmp";
  strcpy(file_name, "image");
  char copy[8];
  char path[100] = "C:/Users/Devin Coughlin/Desktop/Spirograph Images/";

/* NOTE: need to clear strings each loop */
  for (int i = 0; i < 10; i++) {
    sprintf(copy, "%d", i);
    strcat(file_name, copy);
    strcat(file_name, file_extension);
    writeimagefile(file_name);
    strcat(path, file_name);
    rename(file_name, path);
  }

  /* clean up */
  getch();
  closegraph();

  return 0;
}
