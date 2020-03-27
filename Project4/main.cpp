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
			//�� X�����ݶ�
			Sobel(src, dx, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
			convertScaleAbs(dx, abs_dx);//ʹ�����Ա任ת����������Ԫ�س�8λ�޷�������
			imshow("X����Sobel", abs_dx);
			//�� Y�����ݶ�
			Sobel(src, dy, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
			convertScaleAbs(dy, abs_dy);//ʹ�����Ա任ת����������Ԫ�س�8λ�޷�������
			imshow("Y����Sobel", abs_dy);
			
			imshow("src", src);
			
			waitKey(0);
		}


	}

}