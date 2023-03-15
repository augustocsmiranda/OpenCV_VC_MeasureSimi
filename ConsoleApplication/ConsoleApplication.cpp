#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

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

    // Calcula a similaridade usando o �ndice de similaridade estrutural (SSIM)
    // 

    // Verificar o link abaixo para entender o erro do TM_CCOEFF_NORMED
    // 
    //https://docs.opencv.org/4.x/df/dfb/group__imgproc__object.html
    

    double similarity;
    matchTemplate(gray1, gray2, outPut, TM_CCOEFF_NORMED);
    similarity = outPut.at<float>(0, 0);


    // Exibe o valor da similaridade na tela
    cout << "A similaridade entre as imagens � " << similarity << endl;

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
>>>>>>> parent of 74d0a40 (Alteração do código teste para o código principal)
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