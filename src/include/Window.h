/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    Window.h - Extracts information from an image file to generate the pixels 
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/
#ifndef Window_h
#define Window_h

#include "Constants.h"
#include <SD.h>
#include <SPI.h>

struct Pixel
{
    int x;
    int y;
    bool pixelState;
};
class Window
{
    public:
        

        

        Window();
        Window(int xRes, int yRes);
        static int getWindowXResolution(){return x_res;}
        static int getWindowYResolution(){return y_res;}
        void getImage(int CSPin, std::string folderPath);
        void setWindow();

        static int getCurrentPixelX(){return xPixel;}
        static int getCurrentPixelY(){return yPixel;}
        static int getLaserState(){return laserOn;}

    private:
        std::vector<Pixel> window;
        static int x_res;
        static int y_res;

        static int xPixel; //current pixel coord as updated by window
        static int yPixel;
        static bool laserOn;

        bool sdInitialized = false;
        std::vector<std::string> imageFiles;
        int currentFrame = 0;
        int currentPixel = 0;
        bool imageLoaded = false;

        //add function that returns laser on/off
};
#endif