#define PI 3.14159265359

const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 600;
const int WINDOW_POSITION_X = 100;
const int WINDOW_POSITION_Y = 100;

const unsigned char KEY_ESC = 27;
const unsigned char KEY_LEFT = 'a';
const unsigned char KEY_RIGHT = 'd';
const unsigned char KEY_JUMP = 32;
const unsigned char KEY_TURBO = 87;
const unsigned char KEY_START = 'g';

const unsigned char ARROW_UP = 'u';
const unsigned char ARROW_DOWN = 'j';


const int MOVEMENT = 2;

double BALL_X = 0;
double BALL_Y = 0.05;
double BALL_Z = 5;

double X_PLANE1 = 10;
double Y_PLANE1 = 1;
double Z_PLANE1 = 50;
double X_PLANE2 = 10;
double Y_PLANE2 = 1;
double Z_PLANE2 = 150;

double LENGTH = 100;

double CAMERA_Y = 0;

float animation_parameter = 0;
float animation_ongoing = 0;


int ATTEMPT_LEFT = 0;
int ATTEMPT_RIGHT = 0;
