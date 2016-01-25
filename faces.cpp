#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace cv::face;
using namespace std;

int main(int argc, const char *argv[]) {

  Ptr<FaceRecognizer> model = createFisherFaceRecognizer();

  // holds images and labels
  vector<Mat> images;
  vector<int> labels;
  // images for first person
  images.push_back(imread("s1/1.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/2.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/3.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/4.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/5.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/6.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/7.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/8.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("s1/9.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  // images for second person
  images.push_back(imread("s11/1.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);
  images.push_back(imread("s11/2.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);
  images.push_back(imread("s11/3.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);
  
  model->train(images,labels);

  Mat guess = imread("s3/10.pgm", CV_LOAD_IMAGE_GRAYSCALE);
  int label_guess = model->predict(guess);

  cout << label_guess << endl;
  
  return 0;
}
