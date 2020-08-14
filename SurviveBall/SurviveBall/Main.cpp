#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Constansts.h"
using namespace std;

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

    GLfloat light_position[] = { 2, 5, 20, 0 };

    GLfloat light_ambient[] = { 0, 0, 0, 1 };

    GLfloat light_diffuse[] = { 1, 1, 1, 1 };

    GLfloat light_specular[] = { 1, 1, 1, 1 };

    GLfloat model_ambient[] = { 0.4, 0.4, 0.4, 1 };

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glEnable(GL_COLOR_MATERIAL);

    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y) {
    switch (key) {

        case KEY_ESC:
            exit(0);
            break;

        case KEY_START:
            if (!animation_ongoing) {
                animation_ongoing = 1;
                glutTimerFunc(20, on_timer, 0);
            }
            break;

        case KEY_LEFT:
            SHIFT_X += 0.5;
            break;

        case KEY_RIGHT:
            SHIFT_X -= 0.5;
            break;

        case KEY_JUMP:
            if (SHIFT_Y == 0) {
                JUMP_TIMEOUT = 20;
            }
            
            break;

    }
}

static void on_timer(int value){
    if (value != 0)
    return;

    if (JUMP_TIMEOUT >= 0) {
        SHIFT_Y = sin(JUMP_TIMEOUT*PI / 90);
        JUMP_TIMEOUT -= 1;
    }

    glutPostRedisplay();

    if (animation_ongoing)
        glutTimerFunc(20, on_timer, 0);
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
        glScalef(5, 1, 100);
        glutSolidCube(1);
    glPopMatrix();
}

static void draw_ball() {
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(BALL_X, BALL_Y, BALL_Z);
        glutSolidSphere(0.3, 100, 100);
    glPopMatrix();
}

static void on_display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2 + SHIFT_X, 2, -5,
              2 + SHIFT_X, 0, 2,
              0, 1, 0);
    draw_plane();

    glPushMatrix();
        glTranslatef(SHIFT_X, SHIFT_Y, 0);
        draw_ball();
    glPopMatrix();

    glutSwapBuffers();
}

