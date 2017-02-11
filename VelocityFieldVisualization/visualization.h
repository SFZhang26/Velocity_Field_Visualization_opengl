#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <GL/glut.h> 
#include "float3.h"
#include "dataStructure.h"

void drawGrid(Grid gridData);

void drawArrow(Grid gridData, float3 *direction);

#endif