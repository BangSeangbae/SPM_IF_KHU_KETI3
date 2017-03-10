#define DLLEXPORT	// dll 생성을 위해 추가
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
*@brief 경희대의 가시성향상 알고리즘을 실행하기 위한 가상 함수를 상속받은 함수.
*@detail KETI3에서 가시성향상을 위해 호출할 함수.
*/
cv::Mat CSPM_KHU::Enhance(cv::Mat img_input)
{
	/**
	*@ 경희대의 가시성향상 알고리즘이 여기서 구현될 예정임.
	*/



	// 예를 들기 위해서, canny edge를 추출 예제를 적용
	cv::Mat img_output = CannyEdge(img_input);


	return img_output;
}

/**
*@brief 파라미터를 입력하기 위한 세터함수
*@detail 경희대의 가시성향상 알고리즘에 필요한 변수를 설정하는 함수의 예
*/
int CSPM_KHU::SetParam(float param0, float param1)
{
	return 0;
}


// Canny edge 추출 예제
cv::Mat CSPM_KHU::CannyEdge(cv::Mat img_input)
{
	// [참고] http://docs.opencv.org/3.1.0/da/d5c/tutorial_canny_detector.html


	// 입력 영상은 RGB이므로 Gray 한 채널로 변환
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
