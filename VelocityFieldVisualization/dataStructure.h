#ifndef DATASTRUCTURE__H
#define DATASTRUCTURE__H

class Grid {
public:
	float x_min, y_min, z_min;
	float x_max, y_max, z_max;
	float x_length, y_length, z_length;
	int x_resolution, y_resolution, z_resolution;
	float x_div, y_div, z_div;
	int total_cell_num;

	Grid();
	Grid(float x_min, float y_min, float z_min, float x_max, float y_max, float z_max, int x_resolution, int y_resolution, int z_resolution);
};

#endif