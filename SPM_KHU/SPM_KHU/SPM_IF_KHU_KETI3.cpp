#define DLLEXPORT	// dll 생성을 위해 추가
#include "SPM_IF_KHU_KETI3.h"



CSPM_IF_KHU_KETI3::CSPM_IF_KHU_KETI3()
{
}


CSPM_IF_KHU_KETI3::~CSPM_IF_KHU_KETI3()
{
}


/**
*@brief 경희대의 가시성향상 알고리즘을 실행하기 위한 가상 함수.
*@detail KETI3에서는 이 가상함수를 오버라이드한 함수를 호출함으로써 경희대 가시성향상 알고리즘을 활용하는 것임.
*/
cv::Mat CSPM_IF_KHU_KETI3::Enhance(cv::Mat img_input)
{
	return img_input;
}