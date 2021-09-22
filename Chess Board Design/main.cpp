#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    int i,j;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.1, 1.0);

    bool color_change=false;

    for(i=0;i<=10;i=i+1)
    {
        for(j=0;j<=10;j=j+1)
        {
            if(color_change)
            {
                glColor3f(0.0,0.0,0.0); //black
                color_change=!color_change;
            }
            else
            {
                glColor3f(1.0,1.0,1.0); //white
            color_change=!color_change;
            }

            glBegin(GL_QUADS);
            glVertex2i(i,j);
            glVertex2i(i,j+1);
            glVertex2i(i+1,j+1);
            glVertex2i(i+1,j);
            glEnd();


        }
    }




  glFlush ();
}


void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); //select clearing (background) color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,10.0,0.0,10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Chess Board");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
