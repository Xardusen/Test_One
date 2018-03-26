// GetApictureOfVideos.cpp : �������̨Ӧ�ó������ڵ㡣

#define  _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include "string"
#include <iostream>//io��  cout
#include <opencv2/highgui/highgui.hpp>//��Ӵ˾䲻����˵����װ���óɹ�
#include <time.h>

using namespace std;
using namespace cv;

void Video_to_Image(string filename)
{
    VideoCapture capture(filename);//��ȡVideoCapture ����
	
    if (!capture.isOpened())
    {
        cout << "open video error";
    }
    //capture.getʮ��ǿ�� ���Ի��֡�ĺܶ���Ϣ
    int frame_width = (int)capture.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
    int frame_number = capture.get(CAP_PROP_FRAME_COUNT);
    cout << "frame_width is " << frame_width << endl;
    cout << "frame_height is " << frame_height << endl;
    cout << "frame_number is " << frame_number << endl;

    //srand((unsigned)time(NULL));//#ʱ���
    //long frameToStart = rand() % frame_number;//#ȡ  ���֡��֮�ڵ� �����
	int frameToStart = 0;
    cout <<"֡��ʼ�ĵط�"<< frameToStart << endl;
    capture.set(CAP_PROP_POS_FRAMES, frameToStart);//�Ӵ�ʱ��֡����ʼ��ȡ֡

    Mat frame; //#Mat����  ��ʵ����ͼ�����
    char image_name[50];
    if (!capture.read(frame))
    {
        cout << "��ȡ��Ƶʧ��" << endl;
     }
    imshow("che", frame);//��ʾ
    sprintf(image_name, "D:\\QQBrowser\\VideoData\\%s%s", "image", ".jpg");//�����ͼƬ��
    imwrite(image_name, frame);//#д��  ǰ����  path+name��Ҫ���˺�׺ ������ ֡
    capture.release();//#�ͷŶ���
	
}
int main1()
{
    string filename = "D:\\QQBrowser\\VideoData\\f5_dynamic_deint_L.avi";
    Video_to_Image(filename);
    waitKey(0);
	destroyWindow("che");
    return 0;
}