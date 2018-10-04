#include <cstdlib>
#include <cmath>
#include <GL/glut.h>


void display() {
    double x, y;
    double degree;

    glClear(GL_COLOR_BUFFER_BIT);

    //1リンク
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-3, -50);
    glVertex2d(3, -50);
    glVertex2d(3, -30);
    glVertex2d(-3, -30);
    glEnd();
    glFlush();

    //ジョイント
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    for(int angle=0; angle<=360; angle+=10) {
        degree = M_PI*angle/180.0;
        glBegin(GL_TRIANGLE_FAN);
        x = 3*cos(degree);
        y = 3*sin(degree);
        glVertex2d(x, y-30);
    }
    glEnd();
    glPopMatrix();

    //リンク
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-3, -30);
    glVertex2d(3, -30);
    glVertex2d(3, -10);
    glVertex2d(-3, -10);
    glEnd();
    
    //ジョイント
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    for(int angle=0; angle<=360; angle+=10) {
        degree = M_PI*angle/180.0;
        glBegin(GL_TRIANGLE_FAN);
        x = 3*cos(degree);
        y = 3*sin(degree);
        glVertex2d(x, y-10);
    }
    glEnd();
    glPopMatrix();

    //リンク
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-3, -10);
    glVertex2d(3, -10);
    glVertex2d(0, 5);
    glEnd();
    
    glutSwapBuffers();
}

void simu() {
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
    glViewport( 0, 0, w, h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA| GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition(550,250);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    //glutKeyboardFunc(keyboard);
    //glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
