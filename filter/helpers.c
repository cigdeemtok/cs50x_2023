#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            float avg = 0;
            avg = (image[i][j].rgbtBlue+image[i][j].rgbtGreen+image[i][j].rgbtRed)/3;
            avg = (int)round(avg);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width/2; j++){
            RGBTRIPLE temp;
            temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //duplicate the image
    RGBTRIPLE temp[height][width];
    for(int i = 0;i<height;i++){
        for(int j = 0; j<width;j++){
            temp[i][j] = image[i][j];
        }
    }
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            float avgRed = 0, avgBlue = 0, avgGreen = 0;
            int counter = 0;
            //created k and l for checking boundaries
            for(int k = -1; k<2; k++){//k is -1 0 +1 for i
                for(int l = -1; l<2; l++){//l is -1 0 +1 for j
                    if(i+k<0 || i+k>=height){
                        continue;
                    }
                    if(j+l<0 || j+l>=width){
                        continue;
                    }
                    avgRed += image[i+k][j+l].rgbtRed;
                    avgBlue += image[i+k][j+l].rgbtBlue;
                    avgGreen += image[i+k][j+l].rgbtGreen;
                    counter++;
                }
            }
            temp[i][j].rgbtRed = avgRed/counter;
            temp[i][j].rgbtBlue = avgBlue/counter;
            temp[i][j].rgbtGreen = avgGreen/counter;

        }
    }
    //assign blurred image
    for(int i = 0;i<height;i++){
        for(int j = 0; j<width;j++){
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //duplicate the image
    RGBTRIPLE temp[height][width];
    for(int i = 0;i<height;i++){
        for(int j = 0; j<width;j++){
            temp[i][j] = image[i][j];
        }
    }
    //gx matrix for x-axis
    int Gx[3][3] = {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}};
    //gy matrix for y-axis
    int Gy[3][3] = {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}};
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
            float sumXRed = 0, sumXBlue = 0, sumXGreen = 0;
            float sumYRed = 0, sumYBlue = 0, sumYGreen = 0;
            //created k and l for checking boundaries
            for(int k = -1; k<2; k++){//k is -1 0 +1 for i
                for(int l = -1; l<2; l++){//l is -1 0 +1 for j
                    if(i+k<0 || i+k>=height){
                        continue;
                    }
                    if(j+l<0 || j+l>=width){
                        continue;
                    }
                    //calculation for gx
                    sumXRed += ((image[i+k][j+l].rgbtRed)*(Gx[k+1][l+1]));
                    sumXBlue += ((image[i+k][j+l].rgbtBlue)*(Gx[k+1][l+1]));
                    sumXGreen += ((image[i+k][j+l].rgbtGreen)*(Gx[k+1][l+1]));
                    //calculation for gy
                    sumYRed += ((image[i+k][j+l].rgbtRed)*(Gy[k+1][l+1]));
                    sumYBlue += ((image[i+k][j+l].rgbtBlue)*(Gy[k+1][l+1]));
                    sumYGreen += ((image[i+k][j+l].rgbtGreen)*(Gy[k+1][l+1]));
                }
            }
            //calculate new rgb values by taking roots of gx^2+gy^2
            int red = round(sqrt((sumXRed*sumXRed)+(sumYRed*sumYRed)));
            int blue = round(sqrt((sumXBlue*sumXBlue)+(sumYBlue*sumYBlue)));
            int green = round(sqrt((sumXGreen*sumXGreen)+(sumYGreen*sumYGreen)));

            //cap at 255 if value is higher than 255
            //because rgb values are betwewn 0 to 255
            if(red>255){
                red = 255;
            }

            if(blue>255){
                blue = 255;
            }

            if(green>255){
                green = 255;
            }

            //assign new values to temp
            //because we wanna keep calculating original values
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtBlue = blue;
            temp[i][j].rgbtGreen = green;

        }
    }
    //assign filtered image
    for(int i = 0;i<height;i++){
        for(int j = 0; j<width;j++){
            image[i][j] = temp[i][j];
        }
    }
    return;
}
