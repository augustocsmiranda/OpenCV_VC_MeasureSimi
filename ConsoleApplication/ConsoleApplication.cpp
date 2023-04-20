#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <vector>

//Imagens para teste
//Imagens serão adicionadas no github
//Lenna.png
//Lenna2.png
//Lenna3.png
//Lenna4.png

//Peixe_1.jpg
//Peixe_2.jpg

//fish_1.jpg
//fish_2.jpg
//fish_3.jpg


//Bola_1.png
//Bola_2.png
//Bola_3.png



//TM_CCOFF - FUNCIONANDO

/*
int main()
{
	// Carrega a imagem base e a imagem com o objeto a ser encontrado
	cv::Mat img_base = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	cv::Mat img_obj = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	// Verifica se as imagens foram carregadas corretamente
	if (img_base.empty() || img_obj.empty())
	{
		std::cerr << "Erro ao carregar imagens." << std::endl;
		return -1;
	}

	// Cria uma matriz para armazenar o resultado do template matching
	cv::Mat result;
	int result_cols = img_base.cols - img_obj.cols + 1;
	int result_rows = img_base.rows - img_obj.rows + 1;
	result.create(result_rows, result_cols, CV_32FC1);

	// Realiza o template matching com o método cv::TM_CCOEFF
	cv::matchTemplate(img_base, img_obj, result, cv::TM_CCOEFF);

	// Define um limiar para considerar a correspondência encontrada
	double threshold = 0.8;

	// Encontra os pontos onde a correspondência foi encontrada
	cv::Point max_loc;
	cv::minMaxLoc(result, nullptr, nullptr, nullptr, &max_loc);

	// Verifica se a correspondência atingiu o limiar definido
	if (result.at<float>(max_loc) >= threshold)
	{
		// Desenha um retângulo na imagem base indicando a correspondência encontrada
		cv::rectangle(img_base, max_loc, cv::Point(max_loc.x + img_obj.cols, max_loc.y + img_obj.rows), cv::Scalar(0, 255, 0), 2);
		std::cout << "Objeto encontrado na imagem base." << std::endl;
	}
	else
	{
		std::cout << "Objeto não encontrado na imagem base." << std::endl;
	}

	// Exibe as imagens com o resultado
	cv::imshow("Imagem base", img_base);
	cv::imshow("Imagem com objeto", img_obj);
	cv::waitKey();

	return 0;
}
*/


// OK FUNCIONANDO imagens diferentes, tamanho do objeto igual

//TM_CCOEFF_NORMED   

/*
using namespace cv;
using namespace std;

int main()
{
	// Carrega a imagem de referência e a imagem a ser pesquisada
	Mat img1 = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Bola_1.png", IMREAD_COLOR);
	Mat img2 = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Bola_2.png", IMREAD_COLOR);

	//Lenna com Lenna3 = OK
	//Peixe_1 com Peixe_2 = OK
	//Lenna com Lenna4 = OK

	// Verifica se as imagens foram carregadas corretamente
	if (img1.empty() || img2.empty())
	{
		cout << "Erro ao carregar as imagens!" << endl;
		return -1;
	}

	// Define o método de comparação de template
	int method = TM_CCOEFF_NORMED;

	// Define o threshold para aceitar uma correspondência
	double threshold = 0.8;

	// Realiza o template matching
	Mat result;
	matchTemplate(img2, img1, result, method);

	// Encontra os locais das correspondências
	vector<Point> locations;
	findNonZero(result >= threshold, locations);

	// Desenha um retângulo em cada correspondência encontrada
	for (size_t i = 0; i < locations.size(); i++)
	{
		Point pt = locations[i];
		Rect r(pt.x, pt.y, img1.cols, img1.rows);
		rectangle(img2, r, Scalar(0, 0, 255), 2);
	}

	// Exibe a imagem com os retângulos
	imshow("Imagem Pesquisada", img2);
	waitKey(0);

	return 0;
}
*/
//TM_CCORR
//OK FUNCIONANDO
/*
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	// Carrega a imagem base e a imagem com o objeto a ser encontrado
	cv::Mat img_base = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	cv::Mat img_obj = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");

	// Verifica se as imagens foram carregadas corretamente
	if (img_base.empty() || img_obj.empty())
	{
		std::cerr << "Erro ao carregar imagens." << std::endl;
		return -1;
	}

	// Cria uma matriz para armazenar o resultado do template matching
	cv::Mat result;
	int result_cols = img_base.cols - img_obj.cols + 1;
	int result_rows = img_base.rows - img_obj.rows + 1;
	result.create(result_rows, result_cols, CV_32FC1);

	// Realiza o template matching com o método cv::TM_CCORR
	cv::matchTemplate(img_base, img_obj, result, cv::TM_CCORR);

	// Define um limiar para considerar a correspondência encontrada
	double threshold = 0.8;

	// Encontra os pontos onde a correspondência foi encontrada
	cv::Point max_loc;
	cv::minMaxLoc(result, nullptr, nullptr, nullptr, &max_loc);

	// Verifica se a correspondência atingiu o limiar definido
	if (result.at<float>(max_loc) >= threshold)
	{
		// Desenha um retângulo na imagem base indicando a correspondência encontrada
		cv::rectangle(img_base, max_loc, cv::Point(max_loc.x + img_obj.cols, max_loc.y + img_obj.rows), cv::Scalar(0, 255, 0), 2);
		std::cout << "Objeto encontrado na imagem base." << std::endl;
	}
	else
	{
		std::cout << "Objeto não encontrado na imagem base." << std::endl;
	}

	// Exibe as imagens com o resultado
	cv::imshow("Imagem base", img_base);
	cv::imshow("Imagem com objeto", img_obj);
	cv::waitKey();

	return 0;
}*/

//OK FUNCIONANDO
//TM_CCORR_NORMED
/*
int main()
{
	// Carrega a imagem base e a imagem com o objeto a ser encontrado
	cv::Mat img_base = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	cv::Mat img_obj = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");

	// Verifica se as imagens foram carregadas corretamente
	if (img_base.empty() || img_obj.empty())
	{
		std::cerr << "Erro ao carregar imagens." << std::endl;
		return -1;
	}

	// Cria uma matriz para armazenar o resultado do template matching
	cv::Mat result;
	int result_cols = img_base.cols - img_obj.cols + 1;
	int result_rows = img_base.rows - img_obj.rows + 1;
	result.create(result_rows, result_cols, CV_32FC1);

	// Realiza o template matching com o método cv::TM_CCORR_NORMED
	cv::matchTemplate(img_base, img_obj, result, cv::TM_CCORR_NORMED);

	// Define um limiar para considerar a correspondência encontrada
	double threshold = 0.8;

	// Encontra os pontos onde a correspondência foi encontrada
	cv::Point max_loc;
	cv::minMaxLoc(result, nullptr, nullptr, nullptr, &max_loc);

	// Verifica se a correspondência atingiu o limiar definido
	if (result.at<float>(max_loc) >= threshold)
	{
		// Desenha um retângulo na imagem base indicando a correspondência encontrada
		cv::rectangle(img_base, max_loc, cv::Point(max_loc.x + img_obj.cols, max_loc.y + img_obj.rows), cv::Scalar(0, 255, 0), 2);
		std::cout << "Objeto encontrado na imagem base." << std::endl;
	}
	else
	{
		std::cout << "Objeto não encontrado na imagem base." << std::endl;
	}

	// Exibe as imagens com o resultado
	cv::imshow("Imagem base", img_base);
	cv::imshow("Imagem com objeto", img_obj);
	cv::waitKey();

	return 0;
}
*/


//cv::TM_SQDIFF

//OK FUNCIONANDO

/*
int main()
{
	// Carrega a imagem base e a imagem com o objeto a ser encontrado
	cv::Mat img_base = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	cv::Mat img_obj = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");

	// Verifica se as imagens foram carregadas corretamente
	if (img_base.empty() || img_obj.empty())
	{
		std::cerr << "Erro ao carregar imagens." << std::endl;
		return -1;
	}

	// Cria uma matriz para armazenar o resultado do template matching
	cv::Mat result;
	int result_cols = img_base.cols - img_obj.cols + 1;
	int result_rows = img_base.rows - img_obj.rows + 1;
	result.create(result_rows, result_cols, CV_32FC1);

	// Realiza o template matching com o método cv::TM_SQDIFF
	cv::matchTemplate(img_base, img_obj, result, cv::TM_SQDIFF);

	// Encontra os pontos onde a correspondência foi encontrada
	cv::Point min_loc;
	cv::minMaxLoc(result, nullptr, nullptr, &min_loc, nullptr);

	// Desenha um retângulo na imagem base indicando a correspondência encontrada
	cv::rectangle(img_base, min_loc, cv::Point(min_loc.x + img_obj.cols, min_loc.y + img_obj.rows), cv::Scalar(0, 255, 0), 2);

	// Exibe as imagens com o resultado
	cv::imshow("Imagem base", img_base);
	cv::imshow("Imagem com objeto", img_obj);
	cv::waitKey();

	return 0;
}
*/


//TM_SQDIFF_NORMED
//OK FUNCIONANDO

/*
int main()
{
	// Carrega a imagem base e a imagem com o objeto a ser encontrado
	cv::Mat img_base = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");
	cv::Mat img_obj = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/bola_1.png");

	// Verifica se as imagens foram carregadas corretamente
	if (img_base.empty() || img_obj.empty())
	{
		std::cerr << "Erro ao carregar imagens." << std::endl;
		return -1;
	}

	// Cria uma matriz para armazenar o resultado do template matching
	cv::Mat result;
	int result_cols = img_base.cols - img_obj.cols + 1;
	int result_rows = img_base.rows - img_obj.rows + 1;
	result.create(result_rows, result_cols, CV_32FC1);

	// Realiza o template matching com o método cv::TM_SQDIFF_NORMED
	cv::matchTemplate(img_base, img_obj, result, cv::TM_SQDIFF_NORMED);

	// Define um limiar para considerar a correspondência encontrada
	double threshold = 0.01;

	// Encontra os pontos onde a correspondência foi encontrada
	cv::Point min_loc;
	cv::minMaxLoc(result, nullptr, nullptr, &min_loc, nullptr);

	// Verifica se a correspondência atingiu o limiar definido
	if (result.at<float>(min_loc) <= threshold)
	{
		// Desenha um retângulo na imagem base indicando a correspondência encontrada
		cv::rectangle(img_base, min_loc, cv::Point(min_loc.x + img_obj.cols, min_loc.y + img_obj.rows), cv::Scalar(0, 255, 0), 2);
		std::cout << "Objeto encontrado na imagem base." << std::endl;
	}
	else
	{
		std::cout << "Objeto não encontrado na imagem base." << std::endl;
	}

	// Exibe as imagens com o resultado
	cv::imshow("Imagem base", img_base);
	cv::imshow("Imagem com objeto", img_obj);
	cv::waitKey();

	return 0;
}
*/

/**************************************************************************************************/

/*PROJETO PARTE 2 - 3ª VA*/


//C:/Users/kusan/Downloads/IMG_OPENCV/Rua_movimentada_temp.jpg
//C:/Users/kusan/Downloads/MG_OPENCV/Rua_movimentada.jpg

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//if (argc < 3)
	//{
	//	cout << "Not enough parameters" << endl;
	//	cout << "Usage:\n" << argv[0] << " <image_name> <template_name>" << endl;
	//	return -1;
	//}

	// carrega a imagem e o template


	//Imagens que estarão no projeto
	//dois_homens_template.jpg  - dois_homens.jpg
	//Rua_movimentada_temp.jpg  - Rua_movimentada.jpg
	//gear_imagem_temp.png      - gear_imagem.png


	Mat img = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Imagem e Template para comparar/gear_imagem.png", IMREAD_COLOR);
	Mat templ = imread("C:/Users/kusan/Downloads/IMG_OPENCV/Imagem e Template para comparar/gear_imagem_temp.png", IMREAD_COLOR);

	// verifica se a leitura dos arquivos foi feita corretamente
	if (img.empty() || templ.empty())
	{
		cout << "Can't read one of the images" << endl;
		return -1;
	}

	// cria janelas para visualização dos resultados
	namedWindow("Source Image", WINDOW_AUTOSIZE);
	namedWindow("Template Image", WINDOW_AUTOSIZE);
	namedWindow("Result Image", WINDOW_AUTOSIZE);

	// exibe as imagens carregadas nas janelas
	imshow("Source Image", img);
	imshow("Template Image", templ);

	// vetor de métodos de correspondência de modelos a serem testados
	vector<int> match_methods = { TM_SQDIFF, TM_SQDIFF_NORMED, TM_CCORR, TM_CCORR_NORMED, TM_CCOEFF, TM_CCOEFF_NORMED };

	std::vector<cv::Mat> results(match_methods.size());
	std::vector<std::string> match_names(match_methods.size());


	// cria uma matriz para armazenar os resultados de cada método de correspondência de modelos
	Mat result;

	// armazena os valores de similaridade para cada método de correspondência de modelos
	vector<double> match_values;

	// executa cada método de correspondência de modelos e armazena seus resultados e valores de similaridade


	for (int i = 0; i < match_methods.size(); i++)
	{
		// executa o método de correspondência de modelos atual
		matchTemplate(img, templ, result, match_methods[i]);

		// encontra o valor mínimo ou máximo da matriz de resultados, dependendo do método de correspondência de modelos
		double match_value;
		if (match_methods[i] == TM_SQDIFF || match_methods[i] == TM_SQDIFF_NORMED)
		{
			match_value = 1 - result.at<float>(0, 0);
		}
		else
		{
			Point match_loc;
			minMaxLoc(result, NULL, &match_value, NULL, &match_loc);
		}

		// armazena o valor de similaridade calculado
		match_values.push_back(match_value);

		// exibe o resultado atual na janela de resultados
		Mat result_display;
		cvtColor(result, result_display, COLOR_GRAY2BGR);
		rectangle(result_display, Point(0, 0), Point(result.cols - 1, result.rows - 1), Scalar(0, 255, 0), 2);
		imshow("Result Image", result_display);

		
		//waitKey(5000);
		waitKey(0);
	}

	// exibe os valores de similaridade calculados para cada método de correspondência de modelos
	cout << "Match values: ";
	for (int i = 0; i < match_methods.size(); i++)
	{
		cout << match_values[i] << " ";
	}
	cout << endl;

	waitKey();

	// Mostra as imagens resultantes de cada método de correspondência
	for (int i = 0; i < match_methods.size(); i++)
	{
		Mat result = results[i];
		double minVal, maxVal;
		Point minLoc, maxLoc;
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		// Mostra a correspondência com a maior correspondência (ou menor distância no caso de TM_SQDIFF)
		Mat img_display;
		img.copyTo(img_display);
		rectangle(img_display, maxLoc, Point(maxLoc.x + templ.cols, maxLoc.y + templ.rows), Scalar::all(0), 2, 8, 0);
		imshow(match_names[i], img_display);
	}

	// Aguarda a tecla 'ESC' ser pressionada para sair do programa
	//while (true)
	//{
		//if (waitKey(30) == 27) break;
		//waitKey();
	//}
	waitKey();
	return 0;
}


/*
int main(int argc, char** argv)
{

	cv::Mat image = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/Rua_movimentada.jpg");

	if (image.empty()) {
		std::cout << "Imagem não encontrada!" << std::endl;
		return -1;
	}

	cv::namedWindow("Imagem Original", cv::WINDOW_NORMAL);
	cv::imshow("Imagem Original", image);
	cv::waitKey(0);

	cv::Mat image_temp = cv::imread("C:/Users/kusan/Downloads/IMG_OPENCV/Rua_movimentada_temp.jpg");

	if (image_temp.empty()) {
		std::cout << "Imagem não encontrada!" << std::endl;
		return -1;
	}

	cv::namedWindow("Imagem Temporária", cv::WINDOW_NORMAL);
	cv::imshow("Imagem Temporária", image_temp);
	cv::waitKey(0);
}*/