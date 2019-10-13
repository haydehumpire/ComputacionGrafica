#include <GL/glut.h>
#include<iostream>
using namespace std;
GLfloat xRotated, yRotated, zRotated;

bool pantalla_completa = false;
bool mouse_abajo = false;
float xr = 0.0f;
float yr = 0.0f;
float xd = 0.0f;
float yd = 0.0f;

void init(void){
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.0f);
}

void Linea_3D(float x1, float y1, float z1, float x2,float y2,float z2){
    glBegin(GL_POINTS);
    float m,x,y,z,dy,dx;
    dy=y2-y1;
    dx=x2-x1;
    m=dy/dx;
    for(x=x1;x<=x2;x+=0.01){
        y=(y1+m*(x-x1));
        glVertex3f(x,y,x);
    }
    glEnd();
    glFlush();
}

void Pixeles(float x, float y, float z){
    glBegin(GL_POINTS);
    glColor3f(1,0,0);
    x=y=z=0;
    glVertex3f(x,y,z);
    glEnd();
    glFlush();
}

void displey(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f,0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);
    glRotatef(xr, 1.0f, 0.0f, 0.0f);
    glRotatef(yr, 0.0f, 1.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2.0f, 0.0f);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2.0f);
    glEnd();

    glColor3f(1,1,1);
    glPointSize(4);
    Linea_3D(-0.5f, -0.5f,-0.5f,0.5f,0.5f,0.5f);
    glColor3f(0,0,1);
    glFlush();
    glutSwapBuffers();
}

void Redimensionar(int w, int h){
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glViewport(0, 0, w, h);
gluPerspective(45.0f, 1.0f * w/h, 1.0f, 100.0f);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

void Re_modelar(int x, int y){
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

int main(int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100, 100);
glutInitWindowSize(350,350);
glutCreateWindow("Linea 3D");
init();

glutDisplayFunc(displey);
glutMouseFunc(Mouse);
glutMotionFunc(Movimiento_Mouse);
glutReshapeFunc(Redimensionar);
glutMainLoop();
return 0;
}
