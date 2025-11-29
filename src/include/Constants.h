#ifndef Constants.h
#define Constants.h

//#include <Arduino.h>
#include <cmath>
#include <string>
#include <vector>

//All predetermined values are in CGS untis

const double PI = 3.141592653;

const double MAX_LASER_HEIGHT = 100.0;
const double MAX_TRACK_LENGTH = 25.0;
const double MAX_LASER_WIDTH_OFFSET = 20.0;
//Maximum rotation that can be acheived by the laser
//Ideally, but no more than, pi radians
const double MAX_HORIZONTAL_LASER_ANGLE = PI;
//Ideally less than pi/4 radians
//Only the angle starting at the laser's horizontal position is measured
const double MAX_VERTICAL_LASER_ANGLE = PI / 2;

#endif