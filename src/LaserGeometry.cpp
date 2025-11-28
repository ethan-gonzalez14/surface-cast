/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    LaserGeometry.cpp - Calculates the angle of the laser to produce the desired output
                      - Returns motor output parameters
*/

//#include "Arduino.h"
#include "LaserGeometry.h"

LaserGeometry::LaserGeometry(double WindowLength, double WindowWidth, double LaserHeight, double LaserWidthOffSet, double LaserTrackLength, double MaximumHorizontalAngleOfLaser, double MaximumVerticalAngleOfLaser)
{
    //Missing code to edit user inptu values depending on motor, measurements, etc
    setGeometry(WindowLength, WindowWidth, LaserHeight, LaserWidthOffSet, LaserTrackLength, MaximumHorizontalAngleOfLaser, MaximumVerticalAngleOfLaser);

}