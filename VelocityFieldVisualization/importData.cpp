#include "importData.h"
#include <iostream>

void readVelocityField(Grid gridData, float3 *direction) {
	FILE* fp;

	fp = fopen("data/velocity_field.txt", "r"); //Êý¾ÝÎ»ÖÃ

	if (fp == NULL) {
		std::cout << "Can not open file!" << std::endl;
		exit(0);
	}
	float max_length = 0.0f;
	for (int i = 0; i < gridData.total_cell_num; i++) {
		fscanf(fp, "%f %f %f", &direction[i].x, &direction[i].y, &direction[i].z);
		
		int norm = sqrt(direction[i].x*direction[i].x + direction[i].y*direction[i].y + direction[i].z*direction[i].z);
		if (norm>max_length) max_length = norm;
	}

	fclose(fp);
}