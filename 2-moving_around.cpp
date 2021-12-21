/*
 * to compile: g++ 2-moving_around.cpp -o 2 -I./include `pkg-config --cflags --libs opencv4`
 * usage: ./2 videos/THECATHYPNOSE.mp4
 * click ESC to quit
*/
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // start out in single step mode

VideoCapture g_cap;

/*
 * onTrackbarSlide - update the slider position
 * @pos: the new trackbar position
 *
 * Return: Nothing
*/
void onTrackbarSlide(int pos, void *)
{
    g_cap.set(CAP_PROP_POS_FRAMES, pos);
    if (!g_dontset) g_run = 1;
    g_dontset = 0;
}

/*
 * main - Display a video
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always 0
*/
int main(int argc, char **argv)
{
    int frames, tmpw, tmph, current_pos;
    Mat frame;
    namedWindow("TrackbarSlide Show", WINDOW_AUTOSIZE);
    g_cap.open(argv[1]);

    frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
    tmpw = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
    tmph = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);
    cout << "video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl;
    createTrackbar("Position", "TrackbarSlide Show", &g_slider_position, frames, onTrackbarSlide);
    if (!g_cap.isOpened()) {
        cout << "Cannot Open\n";
    }

    while (g_cap.isOpened())
    {
        if (g_run)
        {
            g_cap >> frame;
            if (!frame.data) break; // run out of video
            current_pos = (int) g_cap.get(CAP_PROP_POS_FRAMES);
            g_dontset = 1;
            setTrackbarPos("Position", "TrackbarSlide Show", current_pos);
            imshow("TrackbarSlide Show", frame);
            g_run -= 1;
        }
        char c = (char) waitKey(10);

        if (c == 's') // single step
            {g_run = 1; cout << "Single step run = " << g_run << endl;}
        if (c == 'r') // run mode
            {g_run = -1; cout << "Run mode, run = " << g_run << endl;}
        if (c == 27)
            break;
        
    }

    return (0);
}
