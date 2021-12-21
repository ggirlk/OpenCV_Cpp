/*
 * to compile: g++ 3-simple_transformation.cpp -o 3 -I./include `pkg-config --cflags --libs opencv4`
 * usage: ./3 videos/THECATHYPNOSE.mp4
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
    // make a change : GaussianBlur(), blur(), medianBlur() or bilateralFilter().
    GaussianBlur(image, out, Size(5,5), 3, 3);
    GaussianBlur(out, out, Size(5,5), 3, 3);
    
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
