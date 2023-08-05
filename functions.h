pragma once
#ifndef OPENCV_sys
#define OPENCV_sys
#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<String>
#include <tuple>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace cv;

#endif

//a golbal variable we will use for the delay of the functions
int waittime = 50;
//a function that helps us change system strings into std strings
void MarshalString(System::String^ s, std::string& os) {

	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//function to show main data of an image
void img_details(Mat src, Mat dst) {
	if (src.empty()) {
		MessageBox::Show("no image ");
		return;
	}

	cvtColor(src, dst, COLOR_BGR2GRAY);//we change a 3 change image into a 1 gray scale image
	int max = dst.at<uchar>(0, 0);//we get the highest ampitude value in a grey scale of the image
	for (int i = 0; i < dst.rows; i++)
		for (int j = 0; j < dst.cols; j++)
			if (dst.at<uchar>(i, j) > max)
				max = dst.at<uchar>(i, j);

	int min = dst.at<uchar>(0, 0);//we get the lowest ampitude value in a grey scale of the image
	for (int i = 0; i < dst.rows; i++)
		for (int j = 0; j < dst.cols; j++)
			if (dst.at<uchar>(i, j) < min)
				min = dst.at<uchar>(i, j);

	int sum = 0;//we get the sum of ampitude values in a grey scale of the image
	for (int i = 0; i < dst.rows; i++)
		for (int j = 0; j < dst.cols; j++)
			sum = sum + dst.at<uchar>(i, j);

	int avg = sum / dst.total();//and get the average of it
	//and show all needed data in a messagebox
	MessageBox::Show("total no of pixels = " + src.total() + "\nimage rows = " + src.rows + "\nimage cols = " + src.cols + "\nimage pixel depth = " + src.depth() +
		"\nimage channels = " + src.channels() + "\n\nmax grey amplitude = " + max + "\nmin grey amplitude = " + min + "\naverage grey amplitude = " + avg);

}