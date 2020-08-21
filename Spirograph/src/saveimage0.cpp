#include "saveimage.h"

void clearstr(char* str);

void saveimage() {
  const char* file_extension = ".bmp";
  const char* path_prefix = "C:/Users/Devin Coughlin/Desktop/Spirograph Images/";

  char path[FOLDER_PATH_SIZE] = {};
  char file_name[FILENAME_SIZE] = {};
  char image_number[IMAGE_NUMBER_SIZE] = {};

  /* NOTE: need to clear strings each loop */
  for (int i = 0; i < 10; i++) {
    sprintf(image_number, "%d", i);
    strcat(file_name, image_number);
    strcat(file_name, file_extension);
    writeimagefile(file_name);  /* write image to .bmp file in src directory */
    strcat(path, file_name);    /* append image file to folder path */
    rename(file_name, path);    /* move file to folder by renaming the path */
    clearstr(path);
    clearstr(file_name);
    clearstr(image_number);
  }
}

void clearstr(char* str) {
  for (size_t i = 0; i < strlen(str); i++) {
    *(str + i*sizeof(char)) = 0;
  }
}
