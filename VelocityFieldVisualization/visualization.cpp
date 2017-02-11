#include "visualization.h"
#include <cmath>

double SMALL = 1e-10;

void drawGrid(Grid gridData) {

	glColor4f(1.0, 1.0, 1.0, 0.01);//网格线颜色 及 透明度

	glBegin(GL_LINES);

	float curX = gridData.x_min - gridData.x_div;
	float curY = gridData.y_min - gridData.y_div;
	float curZ = gridData.z_min - gridData.z_div;

	for (int z = 0; z <= gridData.z_resolution;  z++) {
		curZ += gridData.z_div;
		curY = gridData.y_min - gridData.y_div;
		for (int y = 0; y <= gridData.y_resolution; y++) {
			curY += gridData.y_div;
			glVertex3f(gridData.x_min, curY, curZ);
			glVertex3f(gridData.x_max, curY, curZ);
		}
	}

	curX = gridData.x_min - gridData.x_div;
	curY = gridData.y_min - gridData.y_div;
	curZ = gridData.z_min - gridData.z_div;

	for (int z = 0; z <= gridData.z_resolution; z++) {
		curZ += gridData.z_div;
		curX = gridData.x_min - gridData.x_div;
		for (int x = 0; x <= gridData.x_resolution; x++) {
			curX += gridData.x_div;
			glVertex3f(curX, gridData.y_min, curZ);
			glVertex3f(curX, gridData.y_max, curZ);
		}
	}

	curX = gridData.x_min - gridData.x_div;
	curY = gridData.y_min - gridData.y_div;
	curZ = gridData.z_min - gridData.z_div;

	for (int y = 0; y <= gridData.y_resolution; y++) {
		curY += gridData.y_div;
		curX = gridData.x_min - gridData.x_div;
		for (int x = 0; x <= gridData.x_resolution; x++) {
			curX += gridData.x_div;
			glVertex3f(curX, curY, gridData.z_min);
			glVertex3f(curX, curY, gridData.z_max);
		}
	}

	glEnd();
}

float3 getCenterPosition(Grid gridData, int i) {
	int x = i%gridData.x_resolution;
	i /= gridData.x_resolution;
	int y = i%gridData.y_resolution;
	i /= gridData.y_resolution;
	int z = i%gridData.z_resolution;

	return float3(gridData.x_min + x*gridData.x_div + gridData.x_div / 2,
				  gridData.y_min + y*gridData.y_div + gridData.y_div / 2,
				  gridData.z_min + z*gridData.z_div + gridData.z_div / 2);
}

float3 normalize(float3 v) {
	float norm = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	if (norm == 0) {
		//.....
	}
	return v / norm;
}

float myMin(float a, float b, float c) {
	int temp = a < b ? a : b;
	return temp < c ? temp : c;
}

void drawArrow(Grid gridData, float3 *direction) {

	glColor4f(0.0, 1.0, 0.0, 0.4);//速度场线颜色  及 透明度
	float length = myMin(gridData.x_div, gridData.y_div, gridData.z_div);

	glBegin(GL_LINES);
	for (int i = 0; i < gridData.total_cell_num; i++) {
		float3 centerPos = getCenterPosition(gridData,i);
		
		if (abs(direction[i].x)<=SMALL && abs(direction[i].y)<=SMALL && abs(direction[i].z)<=SMALL) {
			glVertex3f(centerPos.x, centerPos.y, centerPos.z);
			glVertex3f(centerPos.x, centerPos.y, centerPos.z);
		}
		else {
			//if (centerPos.z>0 || centerPos.z<-4) continue; // 截面 取得z的坐标在0-4范围内的
			float3 normalized = normalize(direction[i])/1.5; // 1.5  值越大画的速度场线越短
			
			glVertex3f(centerPos.x - normalized.x / 2.0, centerPos.y - normalized.y / 2.0, centerPos.z - normalized.z / 2.0);
			glVertex3f(centerPos.x + normalized.x / 2.0, centerPos.y + normalized.y / 2.0, centerPos.z + normalized.z / 2.0);
		}
	}
	glEnd();
}