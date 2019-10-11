#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void middlePointLine(){
    glClear( GL_COLOR_BUFFER_BIT );
	glColor3f(1,1,1);

    float x1 = -0.9;
    float y1 = -0.9;
    float x2 = 0.9;
    float y2 = 0.9;

    float dx, dy, incE, incNE, d, x,y;

    dx = x2 - x1;
    dy = y2 - y1;
    d = 2* dy-dx;
    incE = 2*dy;
    incNE = 2*(dy-dx);

    x = x1;
    y = x1;

    glBegin(GL_POINTS);
    glVertex2f(x,y);

    while( x < x2){
      if(d <= 0){
        d = d + incE;
        x = x+0.01;
      }else{
        d = d + incNE;
        x = x + 0.01;
        y = y + 0.01;
      }
      glVertex2f(x,y);

    }
    glEnd();
    glutSwapBuffers();
}

int main( int argc, char **argv ){
    glutInit( &argc, argv );
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(350,350);
	glutInitWindowPosition(100,100);
    glutCreateWindow("Linea usando Middle Point 2D");
    glutDisplayFunc(middlePointLine);
    glutMainLoop();
    return 0;
}
