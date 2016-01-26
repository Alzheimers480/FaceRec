#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace cv::face;
using namespace std;

static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, CV_LOAD_IMAGE_GRAYSCALE));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

int main(int argc, const char *argv[]) {

  Ptr<FaceRecognizer> model = createLBPHFaceRecognizer();
  vector<Mat> images;
  vector<int> labels;


  read_csv(argv[1], images, labels);
  // images for first person
  /*images.push_back(imread("non-git/s1/1.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/2.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/3.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/4.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/5.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/6.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/7.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/8.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);
  images.push_back(imread("non-git/s1/9.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(0);

   images for second person
  images.push_back(imread("non-git/s11/1.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);
  images.push_back(imread("non-git/s11/2.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);
  images.push_back(imread("non-git/s11/3.pgm", CV_LOAD_IMAGE_GRAYSCALE)); labels.push_back(1);*/
  
  model->train(images,labels);
  
  Mat guess = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);
  int label; double confidence;
  model->predict(guess, label, confidence);
  
  cout << "Label:" << label << endl;
  cout << "Confidence: " << confidence << endl;
  
  return 0;
}
