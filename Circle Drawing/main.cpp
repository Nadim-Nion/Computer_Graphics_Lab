#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, .0);

    int i;
    const int vertices=100;
    const float angle= 2*3.1416/vertices;

    float prevX=0 , prevY=0;
    int r=1;

    glBegin(GL_TRIANGLES);
    for(i=0;i<=vertices;i++)
    {
       float newX= r*cos(angle*i);
       float newY= r*sin(angle*i);

       glVertex3f(0.0,0.0,0.0);
       glVertex3f(prevX,prevY,0.0);
       glVertex3f(newX,newY,0.0);

       prevX= newX;
       prevY= newY;
    }
    glEnd();


glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); //select clearing (background) color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
