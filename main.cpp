#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    cout << "*** Face Detection using OpenCV ***" << endl;

    // capture object
    VideoCapture lap_cam(0);

    // prepare cascade object and load cascade classifier file
    CascadeClassifier face_detection;
    
    // image object
    Mat frames;    

    face_detection.load("D:\\C++\\OpenCV\\15_face_detection_cascadeclassifier\\haarcascade_frontalface_default.xml");

    while (true)
    {
        lap_cam.read(frames);

        // create vector for a face
        vector<Rect> faces;

        face_detection.detectMultiScale(frames, faces, 1.3, 5);

        // loop to go through the video
        for( int i=0; i<faces.size(); i++){
            rectangle(frames, faces[i].tl(), faces[i].br(), Scalar(50, 50, 255), 3);
        };

        namedWindow("Laptop Camera Reading...", WINDOW_FREERATIO);
        imshow("Laptop Camera Reading...", frames);
        waitKey(1);
    };
};