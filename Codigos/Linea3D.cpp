#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

void drawLineIncremental(float x1,float y1,float z1,float x2,float y2,float z2) {
   float x,y,z;
   float a;
   glBegin(GL_POINTS);
       a = (y2-y1)/(x2-x1);
       for (z =z1; z<=z2;)
       {
           for(x=x1; x<=x2;){
              y = (y1+ a*(x-x1));
              glVertex3f(x,y,z);
              x+=0.01;
           }
           z+=0.01;
        }

   glEnd();
}

void display(){
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3ub( 255, 255, 0 );
    drawLineIncremental(0,0,0,0.8,0.5,0.5);
    glutSwapBuffers();
}

void Move(unsigned char key, int x, int y)
{
   switch(key) {
    case 'i' :
        cout<<"Arriba"<<endl;
        glRotatef(5.0, 1.0, 0.0, 0.0);
        break;
    case 'j' :
        cout<<"Izquierda"<<endl;
        glRotatef(-5.0, 0.0, 1.0, 0.0);
        break;
    case 'k' :
        cout<<"Abajo"<<endl;
        glRotatef(-5.0, 1.0, 0.0, 0.0);
        break;
    case 'l' :
        cout<<"Derecha"<<endl;
        glRotatef(5.0, 0.0, 1.0, 0.0);
        break;
    }
    glutPostRedisplay();
}

int main( int argc, char **argv ){
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 350, 350 );
    glutInitWindowPosition(0, 0);
    glutCreateWindow( "Linea 3D" );

    glutKeyboardFunc(Move);

    glutDisplayFunc( display );
    glutMainLoop();
    return 0;
}
