#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

void Poligono(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	glLoadIdentity();

	double radio = 0.8;
	int lados = 8;

	glBegin(GL_LINES);
	for(int i=0; i < lados; i++)
	{
		glVertex2f(cos(i*2*M_PI/lados)*radio, sin(i*2*M_PI/lados)*radio);
		glVertex2f(cos((i+1) * 2*M_PI/lados)*radio, sin((i+1) * 2*M_PI/lados)*radio);
	}
	glEnd();
	glFlush();
}


int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Poligono usando Middle Point");
	glClearColor(0,0,0,0);
	glutDisplayFunc(Poligono);
	glutMainLoop();
	return 0;
}
