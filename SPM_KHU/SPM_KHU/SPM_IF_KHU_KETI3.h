/**
*@author 김동엽 (KETI, sword32@keti.re.kr)
*@data 2017-03-10
*@brief 이 클래스는 KETI3에서만 유지보수할 수 있음. 수정 필요 시 연락요망.
*/
#pragma once

#ifdef DLLEXPORT
#define CINTDLL __declspec(dllexport)
#else
#define CINTDLL __declspec(dllimport)
#endif



#include <opencv2/core.hpp> // OpenCV는 Project Property 반드시 수정해야 함. 내부 헤더 때문에.

#if DEBUG
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Debug/opencv_core310d.lib")
#else
#pragma comment(lib, "C:/OpenCV3.1/build/lib/Release/opencv_core310.lib")
#endif


class CINTDLL CSPM_IF_KHU_KETI3
{
public:
	CSPM_IF_KHU_KETI3();
	virtual cv::Mat Enhance(cv::Mat image_input);
	virtual ~CSPM_IF_KHU_KETI3();
};

