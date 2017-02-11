#include <GL/glut.h> 
#include "float3.h"
#include "dataStructure.h"
#include "importData.h"
#include "visualization.h"
#include <iostream>

using namespace std;

float window_width = 600;
float window_height = 600;

// �������Σ�x��y��z�� ��С����  x��y��z�� �������   x��y��z�ֱ���
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

	glTranslatef(0.0f, 0.0f, -30.0f); //ƽ�ƿ��Ըı�Զ��
	
	//drawGrid(gridData);  //�������� �����������߿��ñȽ����  ���������� �ٶȳ��߾Ͳ������

	drawArrow(gridData, direction); //���ٶȳ���

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
	//�����ٶȳ�
	direction = new float3[gridData.total_cell_num];
	readVelocityField(gridData, direction);

	/*��ʼ��*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Velocity Field");//���ڱ���
	init();
	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);

	/*��������ʾ*/

	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	
	glutMainLoop();
	return(0);
}