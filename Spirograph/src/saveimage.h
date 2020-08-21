#ifndef SAVE_IMAGE_H_
#define SAVE_IMAGE_H_

#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <time.h>
/* TODO: add time so that I create the image files with date as name */

#define FOLDER_PATH_NAME "C:/Users/Devin Coughlin/Desktop/Spirograph Images/"
#define FILE_EXTENSION ".bmp"
#define FOLDER_PATH_SIZE 80
#define FILENAME_SIZE 30

void saveimage(char* path, char* file_name);

#endif
