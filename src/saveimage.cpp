#include "saveimage.hpp"

  void saveimage(char* path, char* file_name, char* time_buffer, char* index_buffer) {

  file_name = formatdate(file_name, time_buffer);
  /* NOTE: index_buffer full with index */
  strcat(file_name, index_buffer);
  strcat(file_name, FILE_EXTENSION);    /* append .bmp to file_name */

  /* create image file and move it into dest folder */
  writeimagefile(file_name);            /* write image to .bmp file in src directory */
  strcpy(path, FOLDER_PATH_NAME);       /* copy dest folder path into path */
  strcat(path, file_name);              /* append image file to folder path */
  rename(file_name, path);              /* move file to folder by renaming the path */

  clearstr(path);
  clearstr(file_name);
  clearstr(index_buffer);
}

void clearstr(char* str) {
  int index = 0;
  while (*(str + index*sizeof(char)) != 0) {
    *(str + index*sizeof(char)) = 0;
  }
}

char* formatdate(char* file_name, char* time_buffer) {

  /* generate time */
  time_t now = time(&now);
  tm* ltm = localtime(&now);

  /* create file_name */
  strftime(time_buffer, TIME_BUFFER_SIZE, "%m-%d-%Y_%H.%M.%S_i", ltm);
  strcpy(file_name, time_buffer);
  clearstr(time_buffer);

  return file_name;
}
