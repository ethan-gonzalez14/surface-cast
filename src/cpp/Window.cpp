/*
    SurfaceCast - Library for a horizontal laser projector
    Created by Ethan Gonzalez
    
    Window.h - Extracts information from an image file to generate the pixels 
    
    "window" refers to the rectangular portion of the surface that the laser projects to, i.e. the visible 'screen' which may vary in size
*/

#include "include\Window.h"

int Window::x_res;
int Window::y_res;
int Window::xPixel;
int Window::yPixel;
bool Window::laserOn;

Window::Window()
{
    x_res = 128;
    y_res = 128;
    xPixel = 0;
    yPixel = 0;
    laserOn = false;
    sdInitialized = false;
    imageLoaded = false;
    currentFrame = 0;
    currentPixel = 0;
}
Window::Window(int xRes, int yRes)
{
    //Window object
    //Sets values
    x_res = xRes;
    y_res = yRes;
    xPixel = 0;
    yPixel = 0;
    laserOn = false;
    sdInitialized = false;
    imageLoaded = false;
    currentFrame = 0;
    currentPixel = 0;
}
void Window::getImage(int CSPin, const char* folderPath)
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
        File folder = SD.open(folderPath);
        if(!folder)
        {
            Serial.print("Failed to open folder: ");
            Serial.println(folderPath);
            return;
        }

        File image = folder.openNextFile(); //Get first image file
        while(image)
        {
            if(!image.isDirectory()) //check to see if it is not a subfolder
            {
                imageFiles.push_back(std::string(image.name())); //store name of the image's file path
            }
            image.close();
            image = folder.openNextFile(); //next file
        }
        folder.close();

        Serial.print("Found ");
        Serial.print(imageFiles.size());
        Serial.println(" images.");
    }

    if (imageFiles.empty())
    {
        Serial.println("No images loaded!");
        return;
    }

    if(!imageLoaded)
    {
        window.clear();
        File imageFile = SD.open(imageFiles[currentFrame].c_str()); //open image
        if(!imageFile)
        {
            Serial.print("Failed to open image: ");
            Serial.println(imageFiles[currentFrame].c_str());
            return;
        }

        imageFile.seek(14); //Possibly the header size, may be different
        const int bmpWidth = x_res;
        const int bmpHeight = y_res;
        const int rowBytes = ((bmpWidth + 7) / 8 + 3) & ~ 3; //total number of bytes to read for each row in the bmp

        //Loop through each row
        for(int row = 0; row < bmpHeight; row++)
        {
            //Loop through each bit in each byte in the row
            for(int byte = 0; byte < rowBytes; byte++)
            {
                if(!imageFile.available())
                {
                    break;
                }
                byte b = imageFile.read();
                //Loop through each bit in the byte
                for(int bit = 7; bit >= 0; bit--)
                {
                    int column = byte * 8 + (7 - bit); //x-coordinate
                    if(column >= bmpWidth)
                    {
                        continue; //Disregard padding bits
                    }

                    bool pixelOn = !(b & (1 << bit)); //Assumes black is ON
                    xPixel = column;
                    yPixel = (bmpHeight - 1 - row); //BMP starts from the bottom
                    window.push_back({xPixel, yPixel, pixelOn}); //Append to vector array of all the pixels
                }
            }
        }
        imageFile.close();
        currentFrame = (currentFrame + 1) % imageFiles.size();
        imageLoaded = true;
    }
}
void Window::setWindow()//Runs in the loop with appropriate timing (miilis)
{
    //called after getImage
    //within a for loop that iterates every 1/(fps * numPixels) (use millis)
    if(window.empty())
    {
        return;
    }
    Pixel p = window[currentPixel];
    xPixel = p.x;
    yPixel = p.y;
    laserOn = p.pixelState;
    currentPixel = (currentPixel + 1) % window.size();
    if(currentPixel == 0)
    {
        imageLoaded = false;
    }
    
}