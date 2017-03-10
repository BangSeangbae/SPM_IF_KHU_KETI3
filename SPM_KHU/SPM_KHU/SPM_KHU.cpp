#define DLLEXPORT	// dll ������ ���� �߰�
#include "SPM_KHU.h"


#include <opencv2/imgproc.hpp>

#if DEBUG
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Debug/opencv_imgproc310d.lib")
#else
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Release/opencv_imgproc310.lib")
#endif



CSPM_KHU::CSPM_KHU()
	: m_param0(0)
	, m_param1(0)
{

}


CSPM_KHU::~CSPM_KHU()
{

}


/**
*@brief ������� ���ü���� �˰����� �����ϱ� ���� ���� �Լ��� ��ӹ��� �Լ�.
*@detail KETI3���� ���ü������ ���� ȣ���� �Լ�.
*/
cv::Mat CSPM_KHU::Enhance(cv::Mat img_input)
{
	/**
	*@ ������� ���ü���� �˰����� ���⼭ ������ ������.
	*/



	// ���� ��� ���ؼ�, canny edge�� ���� ������ ����
	cv::Mat img_output = CannyEdge(img_input);


	return img_output;
}

/**
*@brief �Ķ���͸� �Է��ϱ� ���� �����Լ�
*@detail ������� ���ü���� �˰��� �ʿ��� ������ �����ϴ� �Լ��� ��
*/
int CSPM_KHU::SetParam(float param0, float param1)
{
	return 0;
}


// Canny edge ���� ����
cv::Mat CSPM_KHU::CannyEdge(cv::Mat img_input)
{
	// [����] http://docs.opencv.org/3.1.0/da/d5c/tutorial_canny_detector.html


	// �Է� ������ RGB�̹Ƿ� Gray �� ä�η� ��ȯ
	cv::Mat src_gray;
	cv::cvtColor(img_input, src_gray, CV_BGR2GRAY);
	
	cv::Mat detected_edges;
	int ratio = 3;
	int kernel_size = 3;
	int lowThreshold = 1;
	cv::blur(src_gray, detected_edges, cv::Size(3, 3));
	cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);

	return detected_edges;
}
