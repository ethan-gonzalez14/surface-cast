/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    Frame.cpp - Help user with delays and offsets 
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/

#include "include\Frame.h"

Frame::Frame()
{
    fps = 0.0;
}
double Frame::pixelDelay(double FPS)
{
    return 1 / (FPS * Window::getWindowXRresolution() * Window::getWindowYResolution());
}