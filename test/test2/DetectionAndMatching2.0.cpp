#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2\features2d\features2d.hpp>
#include "DetectionAndMatching2.0.h"

using namespace std;
using namespace cv;

/*------------------------------函数：将视频filename的前N帧转换成图像序列total_image-------------------------------------*/
Mat Video_to_Images(string filename, int N, Mat total_images[1000])
{
	VideoCapture video(filename);
	if (!video.isOpened())
	{
		cout << "读取视频失败" << endl;
	}
	cout << "视频高度：" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
	cout << "视频宽度：" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
	cout << "视频帧数：" << video.get(CAP_PROP_FRAME_COUNT) << endl;
	cout << "视频帧率：" << video.get(CAP_PROP_FPS) << endl;
	for (int i = 0; i < N; i++)
	{
		video.set(CAP_PROP_POS_FRAMES, i);
		Mat CurrentImage;
		if (!video.read(CurrentImage))
		{
			cout << "读取图像失败" << endl;
		}
		total_images[i] = CurrentImage;
	}
	return total_images[1000];
}
/*---------------------------------函数：对视频进行特征检测输出特征点位置-------------------------------------*/
typedef struct Point_of_Interests
{
	vector<KeyPoint> keypoints[100];
	Mat descriptors[100];
}POIs;
POIs feature_L, feature_R;
void Detect_on_Images(Mat total_images[100],Mat total_images_2[100])
{
	vector<KeyPoint> keypoints;
	Mat processing_img, descriptors;
	Ptr<ORB> orb = ORB::create();
	for (int i = 0; i < 80; i++)//特征检测范围：前80帧
	{
		GaussianBlur(total_images[i], processing_img, Size(5, 5), 0, 0);
		orb->detectAndCompute(processing_img, Mat(), keypoints, descriptors);
		feature_L.keypoints[i] = keypoints;
		feature_L.descriptors[i] = descriptors;
	}
	for (int i = 0; i < 80; i++)//特征检测范围：前80帧
	{
		GaussianBlur(total_images_2[i], processing_img, Size(5, 5), 0, 0);
		orb->detectAndCompute(processing_img, Mat(), keypoints, descriptors);
		feature_R.keypoints[i] = keypoints;
		feature_R.descriptors[i] = descriptors;
	}
}

int main()
{
	/*--------------------------------将左右视频转换成图像序列-------------------------------------*/
	Mat images_L[1001];
	Mat images_R[1001];
	string filname_L = "D:\\QQBrowser\\VideoData\\f5_dynamic_deint_L.avi";
	string filname_R = "D:\\QQBrowser\\VideoData\\f5_dynamic_deint_R.avi";
	cout << "左视频参数：" << endl;
	Video_to_Images(filname_L, 100, images_L);
	cout << "右视频参数：" << endl;
	Video_to_Images(filname_R, 100, images_R);
	/*------------------------------对左右图像(images_L,images_R)每一帧进行特征检测-------------------------------------*/
	Detect_on_Images(images_L,images_R);

	vector<DMatch> matches;
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
	matcher->match(feature_L.descriptors[0], feature_R.descriptors[0], matches);
	imshow("we", feature_L.descriptors[0]);
	imshow("we1", feature_R.descriptors[0]);

	Mat ShowMatches;
	//cout << matches[5].queryIdx << "and" << matches[5].trainIdx << endl;
	//drawMatches(images_L[0], feature_L.descriptors[0], images_R[0], feature_R.descriptors[0], matches, ShowMatches);
	

	imshow("左视频第一帧", images_L[0]);
	waitKey(0);
	destroyAllWindows();
	return 0;
}

//int main1()
//{
//	VideoCapture video("D:\\QQBrowser\\VideoData\\f5_dynamic_deint_L.avi");
//	if (!video.isOpened())
//	{
//		cout << "读取视频失败" << endl;
//	}
//	int videoCount = video.get(CAP_PROP_FRAME_COUNT);
//	cout << "视频高度：" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
//	cout << "视频宽度：" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
//	cout << "视频帧数：" << videoCount << endl;
//	cout << "视频帧率：" << video.get(CAP_PROP_FPS) << endl;
//	for (int i=0; i < 20/*videoCount*/;i++)
//	{
//		video.set(CAP_PROP_POS_FRAMES, i);
//		//提取图像
//		Mat CurrentImage;
//		if (!video.read(CurrentImage))
//		{
//			cout << "读取图像失败" << endl;
//		}
//		//建立提取出图像帧数组集合
//		Mat total[1000];
//		total[i] = CurrentImage;
//		cout << i << endl;
//		imshow("提取图像", total[i]);
//		waitKey(0);
//	}
//	destroyAllWindows();
//	return 0;
//}