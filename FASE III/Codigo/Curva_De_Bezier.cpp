#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

class Point {
public:
    float x,y;
    void setxy(float x2,float y2)
    {
        x = x2; y = y2;
    }
    const Point & operator=(const Point &rPoint)
    {
        x = rPoint.x;
        y = rPoint.y;
        return *this;
    }
};

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float Binomial(float n,float k)
{
    float ans;
    ans = factorial(n)/(factorial(k)*factorial(n-k));
    return ans;
}

Point abc[20];
int SCREEN_HEIGHT = 500;
int points = 0;
int cant_clicks = 3;

void Inicio() {
    glClearColor(0.0, 0.0, 0.5, 0.0); // pantalla
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,500.0);
}

void Dibujar_Punto(int x,int y) {
    glBegin(GL_POINTS);
     glVertex2i(x,y);
    glEnd();
    glFlush();
}

void Dibujar_Linea(Point p1,Point p2) {
    glBegin(GL_LINES);
      glVertex2f(p1.x,p1.y);
      glVertex2f(p2.x,p2.y);
    glEnd();
    glFlush();
}

Point Dibujar_Bezier(Point PT[],double t) {
    Point P;
    P.x=pow((1-t),3)*PT[0].x+3*t*pow((1-t),2)*PT[1].x+3*(1-t)*pow(t,2)*PT[2].x+pow(t,3)*PT[3].x;
    P.y=pow((1-t),3)*PT[0].y+3*t*pow((1-t),2)*PT[1].y+3*(1-t)*pow(t,2)*PT[2].y+pow(t,3)*PT[3].y;

    return P;
}

Point Bezier_Generalizado(Point PT[],double t) {
        Point P;
        P.x = 0; P.y = 0;
        for (int i = 0; i<cant_clicks; i++)
        {
            P.x = P.x + Binomial((float)(cant_clicks-1),(float)i)*pow(t,(double)i)*pow((1-t),(cant_clicks-1-i))*PT[i].x;
            P.y = P.y + Binomial((float)(cant_clicks-1),(float)i)*pow(t,(double)i)*pow((1-t),(cant_clicks-1-i))*PT[i].y;
        }
        return P;
    }


void Mouse(int button,int state,int x,int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    abc[points].setxy((float)x,(float)(SCREEN_HEIGHT-y));
    points++;
    Dibujar_Punto(x,SCREEN_HEIGHT-y);

    if(points == cant_clicks)
    {
        glColor3f(1.0, 1.0, 1.0); // color curvas
        for(int k=0;k<cant_clicks-1;k++)
            Dibujar_Linea(abc[k],abc[k+1]);

        Point p1 = abc[0];
        cout<<p1.x<<"Puntos: "<<p1.y<<endl;
        for(double t = 0.0;t <= 1.0; t += 0.02)
        {
            Point p2 = Bezier_Generalizado(abc,t);
            cout<<p1.x<<", "<<p1.y<<endl;
            cout<<p2.x<<", "<<p2.y<<endl;
            cout<<endl;
            Dibujar_Linea(p1,p2);
            p1 = p2;
        }
        points = 0;
    }
  }
}

void Pantalla() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc,char *argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(300,50);
    glutCreateWindow("Curva Bezier - Con tres puntos");
    glutMouseFunc(Mouse);
    glutDisplayFunc(Pantalla);
    Inicio();
    glutMainLoop();
    return 0;
}
