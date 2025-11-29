/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    LaserGeometry.h - Calculates the angle of the laser to produce the desired output
                    - Returns raw angles for driving motors
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/
#ifndef LaserGeometry_h
#define LaserGeometry_h

#include "Constants.h"
#include "Window.h"

class LaserGeometry
{  
    public:
        LaserGeometry(double WindowLength, double WindowWidth, double LaserHeight, double LaserWidthOffSet, /*double LaserTrackLength,*/ double MaximumHorizontalAngleOfLaser, double MaximumVerticalAngleOfLaser);

        //Dimensions of the window
        double plane_length;
        double plane_width;

        double LASER_HEIGHT;
        double LASER_Y_OFFSET;
        double horizontal_laser_angle;
        double vertical_laser_angle;

        int x_res = Window::getWindowXResolution();
        int y_res = Window::getWindowYResolution();

        int x_current_pixel();
        int y_current_pixel();

        double x_current_pixel_coordinate();
        double y_current_pixel_coordinate();

        double yaw();
        double pitch();
        
    private:

    void setGeometry(double pLength, double pWidth, double laserHeight, double laserWidthOffset, /*double tLength,*/ double maxLaserHAngle, double maxLaserVAngle)
        {
            //Set window dimensions
            plane_length = pLength;
            plane_width = pWidth;
            //Define laser geometry

            //Rotation of the laser is around the origin of the beam
            //Height of the laser stays the same
            LASER_HEIGHT = laserHeight;
            //if(tLength > MAX_TRACK_LENGTH){tLength = MAX_TRACK_LENGTH;}
            //Maximum travel distance of the laser
            //const double LASER_TRACK_LENGTH = tLength;
            if(laserWidthOffset > MAX_LASER_WIDTH_OFFSET){laserWidthOffset = MAX_LASER_WIDTH_OFFSET;}
            //Distance between the window and laser (base)
            LASER_Y_OFFSET = laserWidthOffset;
            if(maxLaserHAngle > MAX_HORIZONTAL_LASER_ANGLE){maxLaserHAngle = MAX_HORIZONTAL_LASER_ANGLE / 180.0;}
            horizontal_laser_angle = MAX_HORIZONTAL_LASER_ANGLE * 180.0;
            if(maxLaserVAngle > MAX_VERTICAL_LASER_ANGLE){maxLaserVAngle = MAX_VERTICAL_LASER_ANGLE / 180.0;}
            vertical_laser_angle = MAX_VERTICAL_LASER_ANGLE * 180.0;
        }

};
#endif