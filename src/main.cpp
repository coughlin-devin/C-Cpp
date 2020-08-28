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

  /* handle command line arguments */

  int R = OUTER_CIRCLE_RADIUS;
  int r = INNER_CIRCLE_RADIUS;

  switch(argc) {
    case 1:
      break;
    case 2:
      r = atoi(argv[1]);
      break;
    case 3:
      R = atoi(argv[2]);
      r = atoi(argv[1]);
      break;
    default:
      printf("Invalid command line arguments.\n");
      printf("Valid arguments: spirograph <outer radius (int)> <inner radius (int)> \n");
      break;
  }

  /* define variables */
  /* NOTE: Constructor looks like Spirograph(int outer_circle_radius, int inner_circle_radius, int path_radius, double angle_of_rotation) */
  Spirograph sp_graph = Spirograph(R, r, PATH_RADIUS, ANGLE_OF_ROTATION);
  const double resolution_rate = 0.01;
  int pen_color = LIGHTBLUE;
  char* path = (char*) calloc(FOLDER_PATH_SIZE, sizeof(char));
  char* file_name = (char*) calloc(FILENAME_SIZE, sizeof(char));
  char* time_buffer = (char*) calloc(TIME_BUFFER_SIZE, sizeof(char));

  /* set pen color */
  setcolor(pen_color);

  const int num_graphs = 6;
  for (size_t i = 0; i < num_graphs; i++) {

    /* OPTIMIZE: rework displaytext to be more efficient in a loop */
    /* display text */
    displaytext(sp_graph, resolution_rate);

    /* draw */
    sp_graph.draw(resolution_rate);

    /* save image to folder */
    //saveimage(path, file_name, time_buffer);

    /* refresh */
    delay(10); //delay 10 milliseconds
    cleardevice();
    /* IDEA: play around with changing the variables and look for patterns I can use to get a run of cool spirographs with a meaningful relationship */
    sp_graph.set_inner_circle_radius(sp_graph.get_inner_circle_radius() + 29);
  }

  /* clean up */
  free(path);
  free(file_name);
  free(time_buffer);
  delay(50);
  getch();
  closegraph();

  return 0;
}
