#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float p =0.0; // Lower limit of x-axis and y-axis
float q=0.0;

void display(void)
{
    //glColor3f (1.0, 0.0, .0);

    glClear (GL_COLOR_BUFFER_BIT);

    //River
    glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(1.0,0.0,0.0);
    glVertex3f(1.0,0.5,0.0);
    glVertex3f(0.0,0.5,0.0);
    glEnd();

    //Boat-1

    if (p<=1.0) // 1.0 is the higher limit of x-axis and y-axis
    {
        p = p+0.00005;
    }
    else
        p=0;

    glutPostRedisplay();



    glColor3f(0.0f, 1.0f, 0.0f);//Green.Lower part of the Boat
    glBegin(GL_QUADS);
    glVertex3f(0.1+p,0.1,0.0);
    glVertex3f(0.2+p,0.1,0.0);
    glVertex3f(0.3+p,0.17,0.0);
    glVertex3f(0.0+p,0.17,0.0);
    glEnd();

   glColor3f(1.0f, 0.0f, 0.0f);//red.Upper part of the Boat
   glBegin(GL_TRIANGLES);
   glVertex3f(0.2+p,0.18,0.0);
   glVertex3f(0.25+p,0.18,0.0);
   glVertex3f(0.2+p,0.3,0.0);
   glEnd();


   //Boat-2

   if (q<=1.0) // 1.0 is the higher limit of x-axis and y-axis
    {
        q = q+0.00005;
    }
    else
        q=0;



   glColor3f(1.0f, 1.0f, 0.0f);//yellow.Lower part of the Boat
    glBegin(GL_QUADS);
    glVertex3f(0.1+q,0.32,0.0);
    glVertex3f(0.2+q,0.32,0.0);
    glVertex3f(0.3+q,0.38,0.0);
    glVertex3f(0.0+q,0.38,0.0);
    glEnd();

    glColor3f(0.0,0.0,1.0);//Blue.Upper part of the Boat
    glBegin(GL_TRIANGLES);
    glVertex3f(0.2+q,0.39,0.0);
    glVertex3f(0.25+q,0.39,0.0);
    glVertex3f(0.2+q,0.48,0.0);
    glEnd();


    //Hill-1
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_TRIANGLES);
    glVertex3f(0.3,0.5,0.0);
    glVertex3f(0.4,0.5,0.0);
    glVertex3f(0.35,0.7,0.0);
    glEnd();


     //Hill-2
    glColor3f(0.1f, 0.0f, 0.0f);//Brown
    glBegin(GL_TRIANGLES);
    glVertex3f(0.4,0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(0.45,0.7,0.0);
    glEnd();

    /*//Sun

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
    glEnd();*/




glFlush ();
}
void init (void)
{
    glClearColor (0.0, 1.0, 1.0, 0.0); //glColor3f(0.0f, 1.0f, 1.0f);//light blue
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
    glutCreateWindow ("River View");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
