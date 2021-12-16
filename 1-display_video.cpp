/*
 * to compile: g++ 1-display_video.cpp -o 1 -I./include `pkg-config --cflags --libs opencv4`
 * usage: ./0 videos/THECATHYPNOSE.mp4
 * click any key to stop the x to quit
*/
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
 * main - Display a video
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 for success -1 for failure
*/
int main(int argc, char **argv)
{
    Mat frame;
    VideoCapture cap;
    namedWindow("First vid show", WINDOW_AUTOSIZE);
    cap.open(argv[1]);
    if (!cap.isOpened()) {
        cout << "Cannot Open\n";
    }
    while (cap.isOpened())
    {
        cap >> frame;
        if (!frame.data) break; // run out of video
        imshow("First vid show", frame);
        if (waitKey(33) >= 0) break;
    }

    return (0);
}