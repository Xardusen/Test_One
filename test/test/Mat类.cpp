#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	//�ֶ��������ͼ��
	Mat ima_1(4, 5, CV_8UC3, Scalar(0, 255, 0));
	imshow("ima_1", ima_1);
	cout << "ima_1=" << endl << ima_1 << endl;
	waitKey(0);
	destroyWindow("ima_1");
	return 0;


	//////����if�����Ų����ǲ���Ĭ�Ͻ���
	////Mat ima = imread("camel.png");
	//Mat ima;
	//if (!ima = imread("camel.png"));
	//{
	//	cout << "��ȡʧ��" << endl;
	//}
	//namedWindow("camel", 0);
	//imshow("camel", ima);
	//waitKey(0);
	//destroyWindow("camel");
	//return 0;
}