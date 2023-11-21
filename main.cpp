#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(){
    cout << "*** Face Detection using OpenCV ***" <<endl;

    // capture object
    VideoCapture lap_cam(0);

    // check if camera is reading 
    if(!lap_cam.isOpened()){
        cout<<"Failed to get Camera Readings..."<<endl;
        return -1;
    }else{
        cout<<"Getting Camera Readings Successfully"<<endl;
    };

    Mat frames;

    while (true)
    {
        lap_cam.read(frames);
        namedWindow("Laptop Camera Reading...", WINDOW_FREERATIO);
        imshow("Laptop Camera Reading...", frames);
        waitKey(1);
    };    
};