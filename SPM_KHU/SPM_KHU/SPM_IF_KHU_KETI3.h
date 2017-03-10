/**
*@author �赿�� (KETI, sword32@keti.re.kr)
*@data 2017-03-10
*@brief �� Ŭ������ KETI3������ ���������� �� ����. ���� �ʿ� �� �������.
*/
#pragma once

#ifdef DLLEXPORT
#define CINTDLL __declspec(dllexport)
#else
#define CINTDLL __declspec(dllimport)
#endif



#include <opencv2/core.hpp> // OpenCV�� Project Property �ݵ�� �����ؾ� ��. ���� ��� ������.

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

