#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

static GLfloat g = 9.80;
static GLfloat place_x = 40.0;
static GLfloat place_y = 40.0;
float vy2 = 0.0;
float vx2 = -6.0;
double dt = 0.01;
double ang,arc;
double x,y;
float e = 0.7;

struct Ball {
    float vy;
    float vx;
    GLfloat iti_x;
    GLfloat iti_y;
};

struct Ball ball[2] = {
    0.0,6.0,-40,40,
    0.0,-6.0,40,40,
};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //枠
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(-48, -48);
    glVertex2d(48, -48);
    glVertex2d(48, 48);
    glVertex2d(-48, 48);
    glEnd();
    glFlush();

    //動かすボール
    glColor3f(1.0,1.0,0.0);
    glPushMatrix();
    glTranslatef(ball[0].iti_x,ball[0].iti_y,0.0);
    for(arc=0;arc<=360;arc+=10){
        ang = PI*arc/180.0;
        glBegin(GL_LINE_LOOP);
        x = 4*cos(ang);
        y = 4*sin(ang);
        glVertex2d(x, y);
    }
    glEnd();
    glPopMatrix();

    //動かされるボール
    glColor3f(0.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(ball[1].iti_x,ball[1].iti_y,0.0);
    for(arc=0;arc<=360;arc+=10){
        ang = PI*arc/180.0;
        glBegin(GL_LINE_LOOP);
        x = 4*cos(ang);
        y = 4*sin(ang);
        glVertex2d(x, y);
    }
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}
void simu(void)
{
    ball[0].iti_x += ball[0].vx*dt;
    ball[1].iti_x += ball[1].vx*dt;
    ball[0].iti_y += ball[0].vy*dt+(-g)*dt*dt/2;
    ball[1].iti_y += ball[1].vy*dt+(-g)*dt*dt/2;
    ball[0].vy += (-g)*dt;
    ball[1].vy += (-g)*dt;
    if(ball[0].iti_y <= -44 || ball[0].iti_y >= 44){
            ball[0].vy = -(ball[0].vy)*e;
        if(ball[0].iti_y <= -44){
            ball[0].iti_y = -44;
        }
        if(ball[0].iti_y >= 44){
            ball[0].iti_y = 44;
        }
    }
    if(ball[1].iti_y <= -44 || ball[1].iti_y >= 44){
        ball[1].vy = -(ball[1].vy)*e;
        if(ball[1].iti_y <= -44){
            ball[1].iti_y = -44;
        }
        if(ball[1].iti_y >= 44){
            ball[1].iti_y = 44;
        }
    }

    if(ball[0].iti_x <= -44 || ball[0].iti_x >= 44){
        ball[0].vx = -(ball[0].vx);
    }
    if(ball[1].iti_x <= -44 || ball[1].iti_x >= 44){
        ball[1].vx = -(ball[1].vx);
    }
    if(sqrt((ball[1].iti_x-ball[0].iti_x)*(ball[1].iti_x-ball[0].iti_x)+(ball[1].iti_y-ball[0].iti_y)*(ball[1].iti_y-ball[0].iti_y)) <= 8){
        ball[0].vx = -(ball[0].vx);
        ball[1].vx = -(ball[1].vx);
    }

    glutPostRedisplay();
}

void init(void)
{
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

void mouse(int button, int state, int x, int y){
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if ( state == GLUT_DOWN)
                glutIdleFunc(simu);
            break;
        case GLUT_RIGHT_BUTTON:
            if ( state == GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key){
        case 'u':
            ball[0].vy += 30;
            break;
        case 'a':
            ball[0].vx -= 30;
            if(ball[0].vx <= -40){
                ball[0].vx = ball[0].vx + 40;
            }
            break;
        case 'd':
            ball[0].vx += 30;
            if(ball[0].vx >= 40){
                ball[0].vx = ball[0].vx - 40;
            }
            break;
    }
    if ( key == '\x1b') exit(0);
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
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
