#include <iostream>

/**
*@brief ������� ���ü���� �˰��� dll�� ���� �������.
*/
#include "../../SPM_KHU/SPM_KHU/SPM_IF_KHU_KETI3.h"
#include "../../SPM_KHU/SPM_KHU/SPM_KHU.h"

#if DEBUG
#pragma comment(lib, "../../SPM_KHU/x64/Debug/SPM_KHU.lib")
#else
#pragma comment(lib, "../../SPM_KHU/x64/Release/SPM_KHU.lib")
#endif



// cv::imread() ���� ���� �߰�
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



	// �׽�Ʈ�� �Է� �̹��� �ҷ�����.
	cv::Mat img_input = GetImageInput();
	cv::imshow("input image", img_input);



	
	
	
	// ����� ���ü���� �˰����� �����ϱ� ���� Ŭ���� �ν��Ͻ�ȭ
	CSPM_IF_KHU_KETI3* SPM_KHU = new CSPM_KHU;

	// ����� ���ü���� �˰��� ����
	cv::Mat img_output = SPM_KHU->Enhance(img_input);

	// ��� ���� ���
	cv::imshow("output image", img_output);







	// ����� Ȯ�� �ϱ� ���� OpenCV �Է� ���
	cv::waitKey();


	// �޸� ����
	delete SPM_KHU;

	return 0;
}


// �׽�Ʈ�� �Է� �̹��� �ҷ�����.
// ���� Ư��������� ���α׷������� ī�޶�, ���� �� �������̽� �Լ��� ��ü�� ����.
cv::Mat GetImageInput()
{
	cv::Mat img = cv::imread("test.jpg");

	return img;
}