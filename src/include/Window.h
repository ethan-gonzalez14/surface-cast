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

class Window
{
    public:
        

        std::vector int window[];

        Window();
        Window(int xRes, int yRes, double FPS);
        static int getWindowXResolution(){return x_res;}
        static int getWindowYResolution(){return y_res;}
        void getImage(int CSPin, std::string folderPath);
        void setWindow();

        static int getCurrentPixelX(){return xPixel;}
        static int getCurrentPixelY(){return xPixel;}

    private:
        static int x_res;
        static int y_res;
        double fps;

        int xPixel; //current pixel coord as updated by window
        int yPixel;

        bool sdInitialized;
        char* imageFolder;
        std::vector<std::string> imageFiles;
        int currentFrame;

        //add function that returns laser on/off
};
#endif