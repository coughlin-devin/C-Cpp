#ifndef DISPLAYTEXT_H_
#define DISPLAYTEXT_H_

#include <stdio.h>
#include <graphics.h>
#include "spirograph.h"

#define X_TEXT 20
#define Y_TEXT 20

void displaytext(Spirograph sp_graph, double resolution_rate, int pen_color);
char* getcolorname(int color);

#endif
