#include "Classes.h"
#include <vector>

double CAMERA_Y = 0;

float animation_parameter = 0;
float animation_ongoing = 0;

int ATTEMPT_LEFT = 0;
int ATTEMPT_RIGHT = 0;

Coordinates ball_coordinates(0, 0, 5);
Coordinates plane1_coordinates(10, 1, 50);
Coordinates plane2_coordinates(10, 1, 150);

int FIRST_PLANE = 0;
int SECOND_PLANE = 0;

std::vector<Coordinates> obstacles_plane1;
std::vector<Coordinates> obstacles_plane2;