#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void Mostrar_Circunferencia(void){
    int lados=80;
    GLfloat radio = 0.8f;
    GLfloat DosPi = 2.0f*M_PI;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);

    for(int i = 0; i <=lados; i++) {
        glVertex2f((radio * cos(i *  DosPi/lados)), (radio* sin(i * DosPi/lados)));
        glVertex2f((radio * cos((i+1) *  DosPi/lados)), (radio* sin((i+1) * DosPi/lados)));
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(350, 350);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circunferencia usando Middle Point");
    glutDisplayFunc(Mostrar_Circunferencia);
    glutMainLoop();
    return 0;
}
