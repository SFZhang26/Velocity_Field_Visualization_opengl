#include "dataStructure.h"
#include "float3.h"

Grid::Grid(float x_min, float y_min, float z_min, float x_max, float y_max, float z_max, int x_resolution, int y_resolution, int z_resolution) {
	this->x_min = x_min;
	this->y_min = y_min;
	this->z_min = z_min;
	this->x_max = x_max;
	this->y_max = y_max;
	this->z_max = z_max;
	this->x_resolution = x_resolution;
	this->y_resolution = y_resolution;
	this->z_resolution = z_resolution;

	if (x_resolution == 0 || y_resolution == 0 || z_resolution == 0) {}

	x_length = x_max - x_min;
	y_length = y_max - y_min;
	z_length = z_max - z_min;

	x_div = x_length / x_resolution;
	y_div = y_length / y_resolution;
	z_div = z_length / z_resolution;

	total_cell_num = x_resolution* y_resolution*z_resolution;
}