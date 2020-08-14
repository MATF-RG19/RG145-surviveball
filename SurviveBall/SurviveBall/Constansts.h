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

const int MOVEMENT = 2;

double BALL_X = 2;
double BALL_Y = 1;
double BALL_Z = -2;

double PLANE_SCALE_X = 10;
double PLANE_SCALE_Y = 1;
double PLANE_SCALE_Z = 30;

double SHIFT_X = 0;
double SHIFT_Y = 0;

float animation_parameter = 0;
float animation_ongoing = 0;

float JUMP_TIMEOUT = 0;
