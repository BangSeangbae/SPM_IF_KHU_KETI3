#pragma once

#ifdef DLLEXPORT
#define CINTDLL __declspec(dllexport)
#else
#define CINTDLL __declspec(dllimport)
#endif

/**
*@breif 경희대-KETI3 간 인터페이스를 위한 클래스 상속
*/
#include "SPM_IF_KHU_KETI3.h"

class CINTDLL CSPM_KHU
	: public CSPM_IF_KHU_KETI3
{
public:
	CSPM_KHU();
	virtual ~CSPM_KHU();
	// 경희대의 가시성향상 알고리즘을 실행하기 위한 가상 함수를 상속받은 함수.
	cv::Mat Enhance(cv::Mat img_input);
	// 파라미터를 입력하기 위한 세터함수
	int SetParam(float param0, float param1);
private:
	float m_param0;
	float m_param1;
public:
	// Canny edge 추출 예제
	cv::Mat CannyEdge(cv::Mat img_input);
};