#include<opencv2\opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main() {
	VideoCapture cap;
	cap.open(0);
	while (1) {
		cv::Mat src, dx,dy,abs_dx,abs_dy;
		bool rSucess = cap.read(src);
		if (rSucess) {
			cvtColor(src, src, COLOR_RGB2GRAY);
			//求 X方向梯度
			Sobel(src, dx, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
			convertScaleAbs(dx, abs_dx);//使用线性变换转换输入数组元素成8位无符号整型
			imshow("X方向Sobel", abs_dx);
			//求 Y方向梯度
			Sobel(src, dy, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
			convertScaleAbs(dy, abs_dy);//使用线性变换转换输入数组元素成8位无符号整型
			imshow("Y方向Sobel", abs_dy);
			
			imshow("src", src);
			
			waitKey(0);
		}


	}

}