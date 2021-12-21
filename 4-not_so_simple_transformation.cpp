/*
 * to compile: g++ 4-not_so_simple_transformation.cpp -o 4 -I./include `pkg-config --cflags --libs opencv4`
 * usage: ./4 images/wow.png
 * click ESC to quit
*/
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
 * show - create some windows to show the input and output images in.
 * @image: the image matrix
 *
 * Return: Nothing
*/
void show(Mat & image)
{
    namedWindow("In", WINDOW_AUTOSIZE);
    namedWindow("Out", WINDOW_AUTOSIZE);
    imshow("In", image);

    Mat out;

    pyrDown(image, out);
    
    imshow("Out", out);
    waitKey(0);
}

/*
 * main - function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
*/
int main(int argc, char **argv)
{
    Mat img;

    img = imread(argv[1], -1);
    
    show(img);
    return (0);
}
