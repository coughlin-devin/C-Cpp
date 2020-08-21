#include "saveimage.h"

void clearstr(char* str);

void saveimage(char* path, char* file_name) {

  /* generate time */
  time_t now;
  char* date = ctime(&now);             /* NOTE: string formtat: weekday month day hr:min:sec year */ //25 chars long

  /* create file_name */
  strcpy(file_name, date);              /* copy date string into file_name */
  strcat(file_name, FILE_EXTENSION);    /* append .bmp to file_name */

  /* create image file and move it into dest folder */
  writeimagefile(file_name);            /* write image to .bmp file in src directory */
  strcpy(path, FOLDER_PATH_NAME);            /* copy dest folder path into path */
  strcat(path, file_name);              /* append image file to folder path */
  rename(file_name, path);              /* move file to folder by renaming the path */

  clearstr(path);
  clearstr(file_name);
}

void clearstr(char* str) {
  int index = 0;
  while (*(str + index*sizeof(char)) != 0) {
    *(str + index*sizeof(char)) = 0;
  }
}
