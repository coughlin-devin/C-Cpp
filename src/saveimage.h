#ifndef SAVE_IMAGE_H_
#define SAVE_IMAGE_H_

#include <stdio.h>
#include <string.h>
#include <graphics.h>
#include <time.h>

#define FOLDER_PATH_NAME "C:/Users/Devin Coughlin/Desktop/Spirograph Images/" //50
#define FILE_EXTENSION ".bmp" //4
#define TIME_BUFFER_SIZE 22
#define INDEX_BUFFER_SIZE 3
#define FILENAME_SIZE TIME_BUFFER_SIZE + INDEX_BUFFER_SIZE
#define FOLDER_PATH_SIZE FILENAME_SIZE + 54 + 1

void saveimage(char* path, char* file_name, char* time_buffer, char* index_buffer);
void clearstr(char* str);
char* formatdate(char* file_name, char* time_buffer);

#endif
