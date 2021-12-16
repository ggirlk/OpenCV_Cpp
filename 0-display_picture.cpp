/*
 * to compile: g++ 0-display_picture.cpp -o 0 -I./include `pkg-config --cflags --libs opencv4`
 * usage: ./0 images/wow.png
 * click any key to quit
*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

/*
 * main - Display a picture
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success -1 for failure
*/
int main(int argc, char **argv)
{
    Mat img;

    img = imread(argv[1], -1);

    if (img.empty()) return (-1);

    //namedWindow("Fist pic show", WINDOW_AUTOSIZE);

    imshow("First pic show", img);
    waitKey(0);

    //destroyWindow("First pic show");
    return (0);
}