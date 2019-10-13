#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

void Dibujar_Linea_Incremental(float x1,float y1,float z1,float x2,float y2,float z2) {
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

void Mostrar(){
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3ub( 255, 255, 0 );
    Dibujar_Linea_Incremental(0,0,0,0.8,0.5,0.5);
    glutSwapBuffers();
}

void Mover(unsigned char key, int x, int y){ // Dos casos: Usando Vectores y librerias de OpenGL
   switch(key) {

    /*vector<int> traslacion(vector<int> org,vector<int> traslado){
        vector<int>res;
        for (size_t i = 0; i < org.size(); i+=2)   {
            res.push_back(org[i]+traslado[0]);
            res.push_back(org[i+1]+traslado[1]);
    }
    return res;
    }*/

    /// TRASLACION
    case 'w' :
        cout<<"Arriba"<<endl;
        glTranslatef(0.0, 0.1 ,0.0);
        break;
    case 'a' :
        cout<<"Izquierda"<<endl;
        glTranslatef(-0.1, 0.0 ,0.0);
        break;
    case 's' :
        cout<<"Abajo"<<endl;
        glTranslatef(0.0, -0.1, 0);
        break;
    case 'd' :
        cout<<"Derecha"<<endl;
        glTranslatef(0.1, 0 ,0.0);
        break;

    /*vector<int> rotacion(vector<int> org,float theta){
        vector<int>res;
        float val = 3.14/180;
        for (size_t i = 0; i < org.size(); i+=2)   {
            res.push_back(org[i]*cos(theta*val) - org[i+1]*sin(theta*val));
            res.push_back(org[i]*sin(theta*val) + org[i+1]*cos(theta*val));
        }
        return res;
    }*/

    /// ROTACION
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

    /*vector<int> escalamiento(vector<int> org,vector<float> escalar){
        vector<int>res;
        for (size_t i = 0; i < org.size(); i+=2)   {
            res.push_back(org[i]*escalar[0]);
            res.push_back(org[i+1]*escalar[1]);
        }
        return res;
    }*/

    /// SCALAR
    case '+' :
        glScalef(2,2,2);
        break;
    case '-' :
        glScalef(0.5,0.5,0.5);
        break;
    }
    glutPostRedisplay();
}

int main( int argc, char **argv){
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize( 350, 350 );
    glutInitWindowPosition(0, 0);
    glutCreateWindow( "Rotacion, Escalar y Traslacion" );
    glutKeyboardFunc(Mover);
    glutDisplayFunc( Mostrar );
    glutMainLoop();
    return 0;
}
