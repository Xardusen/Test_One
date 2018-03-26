#include<iostream>
#include<vector>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\features2d\features2d.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;


int main2()
{
	//��ȡͼƬ
	Mat Orgbd1 = imread("image.jpg");
	Mat Orgbd2 = imread("image_R.jpg"); //linuxLogo.jpg     right_0001.bmp image/image_Rԭͼ�����������Ϊ280���� 
	//cout << "The image I size is" << rgbd1.rows << "and" <<rgbd1 .cols<< endl;//�鿴ͼ��size

	//��˹ģ��
	Mat rgbd1, rgbd2;
	GaussianBlur(Orgbd1, rgbd1, Size(5, 5), 0, 0);
	GaussianBlur(Orgbd2, rgbd2, Size(5, 5), 0, 0);

	//��������㲢��ȡ��descriptor
	Ptr<ORB> orb = ORB::create();
	vector<KeyPoint> Keypoints1, Keypoints2;
	Mat descriptors1, descriptors2;
	orb->detectAndCompute(rgbd1, Mat(), Keypoints1, descriptors1);//��Ⲣ����������
	orb->detectAndCompute(rgbd2, Mat(), Keypoints2, descriptors2);

	//���������
	cout << "Key points of image1 is " << Keypoints1.size() << endl;
	//Points coodinate in image1
	/*for (int i = 0; i < Keypoints1.size() ;i++)
	{
		cout << "Key points" << i << "position is " << '(' << Keypoints1[i].pt.x << ',' << Keypoints1[i].pt.y << ')' << endl;
	}*/
	cout << "Key points of image2 is " << Keypoints2.size() << endl;

	//���ӻ�����ʾ�ؼ���
	Mat ShowKeypoints1, ShowKeypoints2;
	drawKeypoints(rgbd1, Keypoints1, ShowKeypoints1);
	drawKeypoints(rgbd2, Keypoints2, ShowKeypoints2);
	imshow("Keypoints1", ShowKeypoints1);
	imshow("Keypoints2", ShowKeypoints2);
	waitKey(0);

	////��ȡͼ1��������point[0]��ROI
	//cout << "Key point 0 is located at " << '(' << Keypoints1[0].pt.x << ',' << Keypoints1[0].pt.y << ')' << endl;
	//Rect rect(Keypoints1[0].pt.x - 10, Keypoints1[0].pt.y - 10, 20, 20);
	//Mat rgbd1_ROI1 = rgbd1(rect);
	//imshow("ROI of feature0 in im1", rgbd1_ROI1);
	//waitKey(0);

	//Matching
	vector<DMatch> matches;
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
	matcher->match(descriptors1, descriptors2, matches);
	cout << "find out total " << matches.size() <<" matches" << endl;
	cout << "matches 0 is " << matches[0].queryIdx<< "and"<< matches[0].trainIdx << " matches" << endl;

	//��ȡ����ƥ��
	vector<DMatch> matches_0 = { matches[0]};

	//��ȡƥ���0����ROI����ʾ
	Rect rect1(Keypoints1[matches[0].queryIdx].pt.x - 10, Keypoints1[matches[0].queryIdx].pt.y - 10, 20, 20);
	Mat point_in_im1 = rgbd1(rect1);
	imshow("area1", point_in_im1);
	Rect rect2(Keypoints1[matches[0].trainIdx].pt.x - 10, Keypoints1[matches[0].trainIdx].pt.y - 10, 20, 20);
	Mat point_in_im2 = rgbd1(rect2);
	imshow("area2", point_in_im2);
	waitKey(0);

	//���ӻ�ƥ����
	Mat ShowMatches;
	drawMatches(rgbd1, Keypoints1, rgbd2, Keypoints2, matches, ShowMatches);
	

	imshow("matches", ShowMatches);
	waitKey(0);

	destroyAllWindows();//��� �������ͷŴ���,���ⱨ��

	return 0;
}