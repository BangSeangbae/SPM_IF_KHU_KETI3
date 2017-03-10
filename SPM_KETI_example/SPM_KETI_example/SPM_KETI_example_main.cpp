#include <iostream>

/**
*@brief 경희대의 가시성향상 알고리즘 dll을 위한 헤더파일.
*/
#include "../../SPM_KHU/SPM_KHU/SPM_IF_KHU_KETI3.h"
#include "../../SPM_KHU/SPM_KHU/SPM_KHU.h"

#if DEBUG
#pragma comment(lib, "../../SPM_KHU/x64/Debug/SPM_KHU.lib")
#else
#pragma comment(lib, "../../SPM_KHU/x64/Release/SPM_KHU.lib")
#endif



// cv::imread() 등을 위한 추가
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#if DEBUG
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Debug/opencv_imgcodecs310d.lib")	// http://stackoverflow.com/questions/28624644/opencv-linking-error-win32-vs2012
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Debug/opencv_core310d.lib")
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Debug/opencv_highgui310d.lib")
#else
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Release/opencv_imgcodecs310.lib")
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Release/opencv_core310.lib")
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Release/opencv_highgui310.lib")
#endif


cv::Mat GetImageInput();


int main(void)
{
	std::cout << "=====================================" << '\n';
	std::cout << "   SPM KHU-KETI3 Interface Example" << '\n';
	std::cout << "   - Version: 0.01" << '\n';
	std::cout << "=====================================" << '\n' << '\n';



	// 테스트용 입력 이미지 불러오기.
	cv::Mat img_input = GetImageInput();
	cv::imshow("input image", img_input);



	
	
	
	// 경희대 가시성향상 알고리즘을 수행하기 위한 클래스 인스턴스화
	CSPM_IF_KHU_KETI3* SPM_KHU = new CSPM_KHU;

	// 경희대 가시성향상 알고리즘 수행
	cv::Mat img_output = SPM_KHU->Enhance(img_input);

	// 결과 영상 출력
	cv::imshow("output image", img_output);







	// 결과를 확인 하기 위한 OpenCV 입력 대기
	cv::waitKey();


	// 메모리 해제
	delete SPM_KHU;

	return 0;
}


// 테스트용 입력 이미지 불러오기.
// 실제 특수목적기계 프로그램에서는 카메라, 센서 등 인터페이스 함수로 대체될 것임.
cv::Mat GetImageInput()
{
	cv::Mat img = cv::imread("test.jpg");

	return img;
}