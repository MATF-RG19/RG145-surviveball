#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "Constansts.h"
using namespace std;

static int timer_active;

static void on_keyboard(unsigned char key, int x, int y);
static void on_release(unsigned char key, int x, int y);
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
    glutKeyboardUpFunc(on_release);
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

        case ARROW_UP:
            CAMERA_Y += 0.1;
            cout << CAMERA_Y << "\n";
            break;

        case ARROW_DOWN:
            CAMERA_Y -= 0.1;
            cout << CAMERA_Y << "\n";
            break;

        case KEY_START:
            if (!animation_ongoing) {
                animation_ongoing = 1;
                glutTimerFunc(20, on_timer, 0);
            }
            break;

        case KEY_LEFT:
            ATTEMPT_LEFT = 1;
            break;

        case KEY_RIGHT:
            ATTEMPT_RIGHT = 1;
            break;

        case KEY_JUMP:
            break;

    }
}

static void on_release(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        ATTEMPT_LEFT = 0;
        break;
    case 'd':
    case 'D':
        ATTEMPT_RIGHT = 0;
        break;
    }
}

static void on_timer(int value){
    if (value != 0)
    return;

    Z_PLANE1 -= 0.5;
    Z_PLANE2 -= 0.5;

    if (Z_PLANE1 + 50 <= 0) {
        Z_PLANE1 = 150;
    }
    if (Z_PLANE2 + 50 <= 0) {
        Z_PLANE2 = 150;
    }

    if (ATTEMPT_LEFT && BALL_X < 2.2) {
        BALL_X += 0.1;
    }

    if (ATTEMPT_RIGHT && BALL_X > -2.2) {
        BALL_X -= 0.1;
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
        glTranslatef(0, -Y_PLANE1, Z_PLANE1);
        glScalef(X_PLANE1, Y_PLANE1, LENGTH);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.29, 0.447, 0.584); /*sa interneta boja*/
        glTranslatef(0, -Y_PLANE2, Z_PLANE2);
        glScalef(X_PLANE2, Y_PLANE2, LENGTH);
        glutSolidCube(1);
    glPopMatrix();
}

static void draw_ball() {
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(BALL_X, BALL_Y, BALL_Z);
        glutSolidSphere(0.6, 100, 100);
    glPopMatrix();
}

static void on_display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(BALL_X, 3 + CAMERA_Y, -1,
              BALL_X, 1.5 + CAMERA_Y, 2,
              0, 1, 0);
    draw_plane();

    glPushMatrix();
        glTranslatef(BALL_X, BALL_Y, 0);
        draw_ball();
    glPopMatrix();

    glutSwapBuffers();
}


