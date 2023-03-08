#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/*
using namespace std;
using namespace cv;

int main()
{
    // Load two images
    Mat img1 = imread("C:/Users/kusan/Downloads/vsCodePython/fish_1.jpg", IMREAD_GRAYSCALE);
    Mat img2 = imread("C:/Users/kusan/Downloads/vsCodePython/fish_2.jpg", IMREAD_GRAYSCALE);

    // Create a matrix to store the matching result
    Mat matchResult;

    // Match the images using cv::matchTemplate with cv::TemplateMatchModes
    matchTemplate(img1, img2, matchResult, TM_CCOEFF_NORMED);

    // Define the threshold for similarity
    double threshold = 0.7;

    // Find the location of the best match in the matching result matrix
    Point bestMatch;
    minMaxLoc(matchResult, NULL, NULL, NULL, &bestMatch);

    // Check if the best match is above the threshold
    if (matchResult.at<float>(bestMatch.y, bestMatch.x) >= threshold)
    {
        // Define the dimensions of the object found in the image
        int objectWidth = img2.cols;
        int objectHeight = img2.rows;

        // Define the top-left and bottom-right corners of the rectangle
        Point topLeft(bestMatch.x, bestMatch.y);
        Point bottomRight(bestMatch.x + objectWidth, bestMatch.y + objectHeight);

        // Draw a rectangle around the object in both images
        rectangle(img1, topLeft, bottomRight, Scalar(255, 0, 0), 2);
        rectangle(img2, topLeft, bottomRight, Scalar(255, 0, 0), 2);
    }

    // Display the images
    namedWindow("Image 1", WINDOW_NORMAL);
    namedWindow("Image 2", WINDOW_NORMAL);
    imshow("Image 1", img1);
    imshow("Image 2", img2);
    waitKey(0);

    return 0;
}*/


using namespace std;
using namespace cv;

int main()
{
    // Carrega as duas imagens 
    Mat img1 = imread("C:/Users/kusan/Downloads/vsCodePython/fish_2.jpg");
    Mat img2 = imread("C:/Users/kusan/Downloads/vsCodePython/fish_1.jpg");
    Mat outPut;

    // Converte as imagens para escala de cinza
    Mat gray1, gray2;
    cvtColor(img1, gray1, COLOR_BGR2GRAY);
    cvtColor(img2, gray2, COLOR_BGR2GRAY);

    // Calcula a similaridade usando o Ìndice de similaridade estrutural (SSIM)
    // 
    //N„o consigo identificar o por que disto. irei verificar depois llkkok
    // Verificar o link abaixo para entender o erro do TM_CCOEFF_NORMED
    // 
    //https://docs.opencv.org/4.x/df/dfb/group__imgproc__object.html
    
    //n„o existe nenhum construtor adequado para converter de "cv::TemplateMatchsModes" para "cv::debug_build_guard::_OutputArray"

    //double similarity = matchTemplate(gray1, gray2, outPut,TM_CCOEFF_NORMED)[0][0];

    //double similarity = matchTemplate(gray1, gray2, OutputArray(outPut), TM_CCOEFF_NORMED)[0][0];

    double similarity;
    matchTemplate(gray1, gray2, outPut, TM_CCOEFF_NORMED);
    similarity = outPut.at<float>(0, 0);


    //double similarity = matchTemplate(gray1, gray2, TM_CCOEFF)[0][0];

    //double similarity = matchTemplate(gray1, gray2, TM_CCOEFF_NORMED)[0][0];
    //double similarity = matchTemplate(gray1, gray2, static_cast<int>(TM_CCOEFF_NORMED))[0][0];

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
    /*
    Mat im1 = imdecode(buf1, IMREAD_COLOR);
    Mat im2 = imdecode(buf2, IMREAD_COLOR);
    Mat im3 = imdecode(buf3, IMREAD_COLOR);
    imshow("Imagem 1", im1);
    imshow("Imagem 2", im2);
    imshow("Imagem 3", im3);
    waitKey(0);*/

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