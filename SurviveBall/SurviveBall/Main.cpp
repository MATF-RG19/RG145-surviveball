#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Constansts.h"

static int timer_active;


static void on_keyboard(unsigned char key, int x, int y);
static void on_timer(int value);
static void on_reshape(int width, int height);
static void on_display(void);

static void draw_plane();
static void draw_ball();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

    glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH);
    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutCreateWindow("SurviveBall");

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    timer_active = 0;

    glClearColor(0.596, 1, 0.596, 1);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case KEY_ESC:
        exit(0);
        break;

    case KEY_LEFT:
        break;

    case KEY_RIGHT:
        break;

    }
}

static void on_timer(int value) {
    if (value != 0)
        return;

    glutPostRedisplay();

    if (timer_active)
        glutTimerFunc(50, on_timer, 0);
}

static void on_reshape(int width, int height) {

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,
        (float)width / height,
        1, 1500);
}

static void draw_plane() {
    glPushMatrix();
        glColor3f(0.29, 0.447, 0.584);
        glTranslatef(2, -0.100, 2);
        glScalef(10, 1, 30);
        glutSolidCube(1);
    glPopMatrix();
}

static void draw_ball() {
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(2, 1, -2);
        glutSolidSphere(0.3, 100, 100);
    glPopMatrix();
}

static void on_display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2, 2, -5,
              2, 0, 2,
              0, 1, 0);
    draw_plane();
    draw_ball();

    glutSwapBuffers();
}


