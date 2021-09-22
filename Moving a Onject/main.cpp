#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
float p=-10.0;

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);



    if (p<=10) // 10 is the higher limit of x-axis and y-axis
    {
        p = p+0.005;
    }
    else
        p=-10.0;

    glutPostRedisplay();


    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0); //white
    glVertex2f(p,4);
    glVertex2f(p+5,4);
    glVertex2f(p+5,-7);
    glVertex2f(p,-7);
    glEnd();


glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); //select clearing (background) color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Moving Object");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
