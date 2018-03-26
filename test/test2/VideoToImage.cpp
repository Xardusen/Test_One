// GetApictureOfVideos.cpp : 定义控制台应用程序的入口点。

#define  _CRT_SECURE_NO_WARNINGS

//#include "stdafx.h"
#include "string"
#include <iostream>//io流  cout
#include <opencv2/highgui/highgui.hpp>//添加此句不出错说明安装配置成功
#include <time.h>

using namespace std;
using namespace cv;

void Video_to_Image(string filename)
{
    VideoCapture capture(filename);//获取VideoCapture 对象
	
    if (!capture.isOpened())
    {
        cout << "open video error";
    }
    //capture.get十分强大 可以获得帧的很多信息
    int frame_width = (int)capture.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = (int)capture.get(CAP_PROP_FRAME_HEIGHT);
    int frame_number = capture.get(CAP_PROP_FRAME_COUNT);
    cout << "frame_width is " << frame_width << endl;
    cout << "frame_height is " << frame_height << endl;
    cout << "frame_number is " << frame_number << endl;

    //srand((unsigned)time(NULL));//#时间点
    //long frameToStart = rand() % frame_number;//#取  最大帧数之内的 随机数
	int frameToStart = 0;
    cout <<"帧开始的地方"<< frameToStart << endl;
    capture.set(CAP_PROP_POS_FRAMES, frameToStart);//从此时的帧数开始获取帧

    Mat frame; //#Mat对象  其实就是图像对象
    char image_name[50];
    if (!capture.read(frame))
    {
        cout << "读取视频失败" << endl;
     }
    imshow("che", frame);//显示
    sprintf(image_name, "D:\\QQBrowser\\VideoData\\%s%s", "image", ".jpg");//保存的图片名
    imwrite(image_name, frame);//#写入  前面是  path+name不要忘了后缀 后面是 帧
    capture.release();//#释放对象
	
}
int main1()
{
    string filename = "D:\\QQBrowser\\VideoData\\f5_dynamic_deint_L.avi";
    Video_to_Image(filename);
    waitKey(0);
	destroyWindow("che");
    return 0;
}