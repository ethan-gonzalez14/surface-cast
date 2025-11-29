/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    LaserGeometry.cpp - Calculates the angle of the laser to produce the desired output
                      - Returns raw angles for driving motors
*/

#include "include\LaserGeometry.h"

LaserGeometry::LaserGeometry(double WindowLength, double WindowWidth, double LaserHeight, double LaserWidthOffSet, /*double LaserTrackLength,*/ double MaximumHorizontalAngleOfLaser, double MaximumVerticalAngleOfLaser)
{
    //Missing code to edit user input values depending on motor, measurements, etc
    setGeometry(WindowLength, WindowWidth, LaserHeight, LaserWidthOffSet, /*LaserTrackLength,*/ MaximumHorizontalAngleOfLaser, MaximumVerticalAngleOfLaser);

}
int LaserGeometry::x_current_pixel()
{
    return Window::getCurrentPixelX();
}
int LaserGeometry::y_current_pixel()
{
    return Window::getCurrentPixelY();
}
double LaserGeometry::x_current_pixel_coordinate()
{
    double x_pixel_spacing = plane_length / x_res;
    double x_pixel_coordinate = x_pixel_spacing * x_current_pixel();
    return x_pixel_coordinate;
}
double LaserGeometry::y_current_pixel_coordinate()
{
    double y_pixel_spacing = plane_width / y_res;
    double y_pixel_coordinate = y_pixel_spacing * y_current_pixel();
    return y_pixel_coordinate;
}
double LaserGeometry::yaw(double xPixel, double yPixel)
{
    //remember to pass in x/y_current_pixel_coordinate
    double vx = xPixel;
    double vy = yPixel + LASER_Y_OFFSET;
    double vz = -LASER_HEIGHT;
    
    return (180.0 * atan2(vx, vy) / PI);
}
double LaserGeometry::pitch(double xPixel, double yPixel)
{
    //remember to pass in x/y_current_pixel_coordinate
    double vx = xPixel;
    double vy = yPixel + LASER_Y_OFFSET;
    double vz = -LASER_HEIGHT;

    double planar_distance = sqrt(pow(vx, 2) + pow(vy, 2));
    
    return 90.0 + (180.0 * atan(planar_distance / vz) / PI);
}
//Create master periodic function that runs 