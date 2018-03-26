#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//手动输入矩阵图像
	Mat ima_1(4, 5, CV_8UC3, Scalar(0, 255, 0));
	imshow("ima_1", ima_1);
	cout << "ima_1=" << endl << ima_1 << endl;
	waitKey(0);
	destroyWindow("ima_1");
	return 0;


	//////检验if后括号操作是不是默认进行
	////Mat ima = imread("camel.png");
	//Mat ima;
	//if (!ima = imread("camel.png"));
	//{
	//	cout << "读取失败" << endl;
	//}
	//namedWindow("camel", 0);
	//imshow("camel", ima);
	//waitKey(0);
	//destroyWindow("camel");
	//return 0;
}