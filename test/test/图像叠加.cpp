#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main2()
{
	float thres = 0.5;
	float thres_o;
	Mat Logo1, Logo2, Co_img;

	Logo1 = imread("LinuxLogo.jpg");
	Logo2 = imread("WindowsLogo.jpg");
	thres_o = 1 - thres;
	addWeighted(Logo1, thres, Logo2, thres_o,0.0, Co_img);//常数0.0为像素点强度值加量

	namedWindow("合成图像", 0);
	imshow("合成图像", Co_img);
	waitKey(0);
	destroyWindow("合成图像");


	return(0);
}