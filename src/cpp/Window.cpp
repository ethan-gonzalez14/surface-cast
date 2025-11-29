/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    Window.h - Extracts information from an image file to generate the pixels 
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/

#include "include\Window.h"

Window::Window()
{
    x_res = 128;
    y_res = 128;
    fps = 30.0;
}
Window::Window(int xRes, int yRes, double FPS)
{
    //Window object
    //Sets values
    x_res = xRes;
    y_res = yRes;
    fps = FPS; //may not need
}
void getImage(int CSPin, std::string filePath)
{
    //called within the arduino loop
    if(!sdInitialized)
    {
        if(!SD.Begin(CSPin))
        {
            Serial.println("SD initialization failed!");
            return;
        }
        Serial.println("SD initialized.");
        sdInitialized = true;

        //Open folder
        File folder = SD.open(imageFolder);
        if(!folder)
        {
            Serial.print("Failed to open folder: ");
            Serial.println(imageFolder);
            return;
        }

        File image = folder.openNextFile(); //Get first image file
        while(image)
        {
            if(!image.isDirectory()) //check to see if it is not a subfolder
            {
                imageFiles.push_back(std::string(image.name())); //store name of the image's fiel path
            }
            image.close();
            image = folder.openNextFile(); //next file
        }
        folder.close();

        Serial.print("Found ");
        Serial.print(imageFiles.size());
        Serial.println(" images.");
    }
}
void Window::setWindow()//Runs in the loop with appropriate timing (miilis)
{
    //called after getImage
    //within a for loop that iterates every 1/(fps * numPixels) (use millis)
    //laser geometry is run, updating the motors
    if (imageFiles.empty())
    {
        Serial.println("No images loaded!");
        return;
    }

    File imageFile = SD.open(imageFiles[currentFrame].c_str()); //open image
    if(!imageFile)
    {
        Serial.print("Failed to open image: ");
        Serial.println(imageFiles[currentFrame].c_str());
        return;
    }

    imageFile.seek(14); //Possibly the header size, may be different
    const int bmpWidth = x_res;
    const int bmpLength = y_res;
    const int rowBytes = //finish this to extract pixels as a vector
    
    //update xPixel and yPixel based on vector/array
   
    //fps may not matter as this may run in a loop tuned to go based on the fps
}

