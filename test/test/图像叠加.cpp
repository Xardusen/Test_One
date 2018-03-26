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
	addWeighted(Logo1, thres, Logo2, thres_o,0.0, Co_img);//����0.0Ϊ���ص�ǿ��ֵ����

	namedWindow("�ϳ�ͼ��", 0);
	imshow("�ϳ�ͼ��", Co_img);
	waitKey(0);
	destroyWindow("�ϳ�ͼ��");


	return(0);
}