/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    Frame.h - Help user with delays and offsets 
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/
#ifndef Frame_h
#define Frame_h

#include "Constants.h"
#include "include\Window.h"

class Frame
{
    public:
        Frame();

        static double pixelDelay(double FPS);

        double fps = 0.0;
};
#endif