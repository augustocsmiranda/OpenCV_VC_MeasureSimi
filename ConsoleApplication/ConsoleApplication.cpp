#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main(int argc, char** argv) {

	std::string caminho = "C:/Users/kusan/Downloads/OpenCV_VC_MeasureSimi/OpenCV_VC_MeasureSimi/ConsoleApplication/fish_1.jpg";
	cv::Mat imagem = cv::imread(caminho);
	cv::imshow("Imagem", imagem);
	cv::waitKey(0);
	
	//Para segundo commit 

	return 0;

}