#include <stdio.h>
#include <GL/glut.h>

GLfloat x1,y1,x2,y2,x3,y3,x4,y4;

void Deteccion_Borde(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re){
    float mx,x,temp;
    int i;
    if((y2-y1)<0)
    {
        temp=x1;x1=x2;x2=temp;
        temp=y1;y1=y2;y2=temp;
    }
    if((y2-y1)!=0)
        mx=(x2-x1)/(y2-y1);
    else
        mx=x2-x1;
        x=x1;
    for(i=y1;i<y2;i++)
    {
        if(x<le[i])
            le[i]=x;

        if(x>re[i])
            re[i]=x;
        x+=mx;
    }
}

void Dibujar_Pixeles(int x,int y)
{
    glColor3f(1.0,0,1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void Scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4){
    int le[500],re[500];
    int i,y;
    for(i=0;i<500;i++)
    {
        le[i]=500;
        re[i]=0;
    }
    Deteccion_Borde(x1,y1,x2,y2,le,re);
    Deteccion_Borde(x2,y2,x3,y3,le,re);
    Deteccion_Borde(x3,y3,x4,y4,le,re);
    Deteccion_Borde(x4,y4,x1,y1,le,re);
    for(y=0;y<500;y++)
    {
        if(le[y]<=re[y])
        for(i=le[y]+1;i<re[y];i++)
        Dibujar_Pixeles(i,y);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    x1=200,y1=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();
    Scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
    glFlush();
}

void myinit(){
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(350,350);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Pintado del Poligono");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
