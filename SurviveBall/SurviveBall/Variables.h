#include "Classes.h"
#include <vector>

double CAMERA_Y = 0;

float animation_parameter = 0;
float animation_ongoing = 0;

int ATTEMPT_LEFT = 0;
int ATTEMPT_RIGHT = 0;
int ATTEMPT_JUMP = 0;
double jump_counter = 0;

Coordinates ball_coordinates(0, 0, 5);
Coordinates plane1_coordinates(10, 1, 50);
Coordinates plane2_coordinates(10, 1, 150);

int FIRST_PLANE = 0;
int SECOND_PLANE = 0;
int REWARD_COUNTER = 0;

int SPEED_BOOSTER_ACTIVE = 0;
double SPEED_BOOST_VAR = 0;
double SPEED_INCREASE = 0;

std::vector<Coordinates> obstacles_plane1;
std::vector<Coordinates> obstacles_plane2;