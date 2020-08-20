#include "spirograph.h"
#include "displaytext.h"

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


  /* create a spirograph */
  /* NOTE: Constructor looks like Spirograph(int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation) */
  Spirograph sp_graph = Spirograph(500, 355, 200, 2.0);

  double resolution_rate = 0.01;
  int pen_color = 4;

  /* set pen color */
  setcolor(pen_color);

  /* display text */
  displaytext(sp_graph, resolution_rate, pen_color);

  /* draw */
  sp_graph.draw(resolution_rate);

  /* clean up */
  getch();
  closegraph();

  return 0;
}
