#include <GL/glut.h> 
#include "float3.h"
#include "dataStructure.h"
#include "importData.h"
#include "visualization.h"
#include <iostream>

using namespace std;

float window_width = 600;
float window_height = 600;

// 参数依次：x、y、z轴 最小坐标  x、y、z轴 最大坐标   x、y、z分辨率
Grid gridData(-8, -8, -8, 8, 8, 8, 16, 16, 16);
float3 *direction = nullptr;

void init(void)
{
	glClearColor(0, 0, 0, 1.0);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH); 
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -30.0f); //平移可以改变远近
	
	//drawGrid(gridData);  //画网格线 不过不画绿线看得比较清楚  画了网格线 速度场线就不清楚了

	drawArrow(gridData, direction); //画速度场线

	glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, (float)w / h, 0.1f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char ** argv)
{
	//读入速度场
	direction = new float3[gridData.total_cell_num];
	readVelocityField(gridData, direction);

	/*初始化*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Velocity Field");//窗口标题
	init();
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);

	/*绘制与显示*/

	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	
	glutMainLoop();
	return(0);
}