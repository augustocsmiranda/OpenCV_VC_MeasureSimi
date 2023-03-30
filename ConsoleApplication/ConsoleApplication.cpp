#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <vector>

/*
using namespace std;
using namespace cv;

int main()
{
	// Carrega as duas imagens
	Mat img1 = imread("C:/Users/kusan/Downloads/vsCodePython/Peixe_1.jpg");
	Mat img2 = imread("C:/Users/kusan/Downloads/vsCodePython/Peixe_2.jpg");
	Mat outPut;

	// Converte as imagens para escala de cinza
	Mat gray1, gray2;
	cvtColor(img1, gray1, COLOR_BGR2GRAY);
	cvtColor(img2, gray2, COLOR_BGR2GRAY);

	// Calcula a similaridade usando o Ìndice de similaridade estrutural (SSIM)
	//

	// Verificar o link abaixo para entender o erro do TM_CCOEFF_NORMED
	//
	//https://docs.opencv.org/4.x/df/dfb/group__imgproc__object.html


	double similarity;
	matchTemplate(gray1, gray2, outPut, TM_CCOEFF_NORMED);
	similarity = outPut.at<float>(0, 0);


	// Exibe o valor da similaridade na tela
	cout << "A similaridade entre as imagens È " << similarity << endl;

	// Encontra objetos similares nas imagens usando o algoritmo SIFT
	Ptr<SIFT> sift = SIFT::create();
	vector<KeyPoint> kp1, kp2;
	Mat des1, des2;
	sift->detectAndCompute(gray1, noArray(), kp1, des1);
	sift->detectAndCompute(gray2, noArray(), kp2, des2);
	BFMatcher bf(NORM_L2);
	vector<vector<DMatch>> matches;
	bf.knnMatch(des1, des2, matches, 2);
	vector<DMatch> good;
	for (size_t i = 0; i < matches.size(); ++i)
	{
		if (matches[i][0].distance < 0.75 * matches[i][1].distance)
		{
			good.push_back(matches[i][0]);
		}
	}

	// Cria uma imagem em branco para desenhar os contornos
	int h1 = gray1.rows, w1 = gray1.cols;
	int h2 = gray2.rows, w2 = gray2.cols;
	Mat result(max(h1, h2), w1 + w2, CV_8UC3, Scalar(0, 0, 0));
	img1.copyTo(result(Rect(0, 0, w1, h1)));
	img2.copyTo(result(Rect(w1, 0, w2, h2)));

	// Desenha os contornos nos objetos similares encontrados
	for (size_t i = 0; i < good.size(); ++i)
	{
		Point2f pt1 = kp1[good[i].queryIdx].pt;
		Point2f pt2 = kp2[good[i].trainIdx].pt;
		pt2.x += w1;
		line(result, pt1, pt2, Scalar(0, 255, 0), 2);
	}

	// Codifica as imagens para exibi-las sem a GUI do OpenCV
	vector<uchar> buf1, buf2, buf3;
	imencode(".png", img1, buf1);
	imencode(".png", img2, buf2);
	imencode(".png", result, buf3);

	// Exibe as imagens usando a biblioteca Pillow

	Mat im1 = imdecode(buf1, IMREAD_COLOR);
	Mat im2 = imdecode(buf2, IMREAD_COLOR);
	Mat im3 = imdecode(buf3, IMREAD_COLOR);

	// Redimensionando a imagem 3 para 1024x768
	resize(im1, im1, Size(1920, 1080));
	resize(im2, im2, Size(1920, 1080));
	resize(im3, im3, Size(1920, 1080));

	imshow("Imagem 1", im1);
	imshow("Imagem 2", im2);
	imshow("Imagem 3", im3);
	waitKey(0);


	return 0;
}
/*
---------------- -

=======
>>>>>>> parent of 74d0a40 (Altera√ß√£o do c√≥digo teste para o c√≥digo principal)
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

}*/

/*
// OK FUNCIONANDO

int main(int argc, char** argv)
{
	// Carrega a imagem original e a imagem do template
	cv::Mat img = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/fish_2.jpg", cv::IMREAD_COLOR);
	cv::Mat templ = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/fish_1.jpg", cv::IMREAD_COLOR);

	// Cria a imagem resultado
	cv::Mat result;

	// Realiza o template matching com o mÈtodo TM_CCORR_NORMED
	cv::matchTemplate(img, templ, result, cv::TM_CCORR_NORMED);

	// Define o threshold para aceitar uma correspondÍncia
	double threshold = 0.8;
	cv::Mat mask = (result >= threshold);

	// Encontra os locais das correspondÍncias
	std::vector<cv::Point> locations;
	cv::findNonZero(mask, locations);

	// Desenha um ret‚ngulo ao redor das correspondÍncias encontradas
	for (int i = 0; i < locations.size(); i++)
	{
		cv::Rect r(locations[i].x, locations[i].y, templ.cols, templ.rows);
		cv::rectangle(img, r, cv::Scalar(0, 0, 255), 2);
	}

	// Exibe a imagem resultado
	cv::imshow("Resultado", img);
	cv::waitKey();

	return 0;
}*/

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	// Verifica se foram passados os nomes das duas imagens como argumentos
	/*if (argc < 3)
	{
		std::cerr << "Usage: " << argv[0] << " <image1> <image2>" << std::endl;
		return 1;
	}*/

	// Carrega as imagens
	Mat img1 = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Lenna2.png", IMREAD_COLOR);
	Mat img2 = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Lenna.png", IMREAD_COLOR);

	// Verifica se as imagens foram carregadas corretamente
	if (img1.empty() || img2.empty())
	{
		std::cerr << "Failed to load image(s)." << std::endl;
		return 1;
	}

	// Define a escala m·xima e mÌnima para a busca do objeto
	double scale_max = 2.0;
	double scale_min = 0.5;

	// Define a quantidade de escalas a serem testadas
	int num_scales = 10;

	// Define o mÈtodo de comparaÁ„o
	int method = TM_CCOEFF_NORMED;

	// Cria uma janela para mostrar as imagens
	namedWindow("Object Detection", WINDOW_NORMAL);

	// Realiza a busca do objeto em diferentes escalas na primeira imagem
	for (int i = 0; i < num_scales; i++)
	{
		double scale = scale_min + (scale_max - scale_min) * i / (num_scales - 1);

		Mat img_scaled;
		resize(img1, img_scaled, Size(), scale, scale);

		Mat result;
		matchTemplate(img_scaled, img2, result, method);

		double min_val, max_val;
		Point min_loc, max_loc;
		minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);

		// Se a escala for igual a 1.0, marca o objeto encontrado na imagem original
		if (scale == 1.0)
		{
			rectangle(img1, max_loc, Point(max_loc.x + img2.cols, max_loc.y + img2.rows), Scalar(0, 255, 0), 2);
		}

		std::cout << "Scale: " << scale << ", Match: " << max_val << std::endl;
	}

	// Mostra as imagens com os objetos marcados
	imshow("Object Detection", img1);
	waitKey(0);

	return 0;
}
