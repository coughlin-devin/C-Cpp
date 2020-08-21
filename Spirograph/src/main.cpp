#include "spirograph.h"
#include "displaytext.h"
#include "saveimage.h"

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

  /* define variables */
  Spirograph sp_graph = Spirograph(500, 355, 200, 2.0);  /* NOTE: Constructor looks like Spirograph(int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation) */
  const double resolution_rate = 0.01;
  int pen_color = LIGHTBLUE;
  char* path = (char*) calloc(FOLDER_PATH_SIZE, sizeof(char));
  char* file_name = (char*) calloc(FILENAME_SIZE, sizeof(char));

  /* set pen color */
  setcolor(pen_color);

  for (size_t i = 0; i < 10; i++) {

    /* display text */
    displaytext(sp_graph, resolution_rate, pen_color);

    /* draw */
    sp_graph.draw(resolution_rate);

    /* save image to folder */
    saveimage(path, file_name);

    /* refresh */
    delay(30);
    cleardevice();
    sp_graph.set_inner_circle_radius(sp_graph.get_inner_circle_radius() + 19);
  }

  /* clean up */
  free(path);
  free(file_name);
  getch();
  closegraph();

  return 0;
}
