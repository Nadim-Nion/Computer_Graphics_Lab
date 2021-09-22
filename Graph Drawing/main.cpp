#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
    float i;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.1, 1.0);

  glBegin(GL_LINES);

  for(i=0.0;i<1.0;i=i+0.1)
  {
  glVertex3f(0.0,0.1+i,0.0);
  glVertex3f(1.0,0.1+i,0.0);

  glVertex3f(0.0+i,0.1,0.0);
  glVertex3f(0.0+i,1.0,0.0);
  }




  glEnd();

glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0); //select clearing (background) color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Graph");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
