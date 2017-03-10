#pragma once

#ifdef DLLEXPORT
#define CINTDLL __declspec(dllexport)
#else
#define CINTDLL __declspec(dllimport)
#endif

/**
*@breif �����-KETI3 �� �������̽��� ���� Ŭ���� ���
*/
#include "SPM_IF_KHU_KETI3.h"

class CINTDLL CSPM_KHU
	: public CSPM_IF_KHU_KETI3
{
public:
	CSPM_KHU();
	virtual ~CSPM_KHU();
	// ������� ���ü���� �˰����� �����ϱ� ���� ���� �Լ��� ��ӹ��� �Լ�.
	cv::Mat Enhance(cv::Mat img_input);
	// �Ķ���͸� �Է��ϱ� ���� �����Լ�
	int SetParam(float param0, float param1);
private:
	float m_param0;
	float m_param1;
public:
	// Canny edge ���� ����
	cv::Mat CannyEdge(cv::Mat img_input);
};