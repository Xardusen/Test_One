#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main1()
{
	//源代码，暂时不需要
	//if( argc != 2)
	//{
	// cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
	// return -1;
	//}

	Mat image;
	image = imread("opencv-logo.png", IMREAD_COLOR); // Read the file

													 //源代码，暂时不需要
													 //if( image.empty() ) // Check for invalid input
													 //{
													 //    cout << "Could not open or find the image" << std::endl ;
													 //    return -1;
													 //}

													 //显示凸图像
	namedWindow("OpencvLogo", 0); // Create a window for display.
	imshow("OpencvLogo", image); // Show our image inside it.

								 //转化灰度图
	Mat img_grey;
	cvtColor(image, img_grey, COLOR_BGR2GRAY);
	namedWindow("Logo_grey", 0);
	imshow("Logo_grey", img_grey);


	waitKey(0); // Wait for a keystroke in the window
	cvDestroyWindow("OpencvLogo");//cvReleaseImage(image);
	cvDestroyWindow("Logo_grey");//cvReleaseImage(image);
	return 0;
}
