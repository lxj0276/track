#include <vector>

#include "detect_table.hpp"
#include "RTree.h"
#include "heuristic_filter.hpp"
#include "homogenous_regions.hpp"

using namespace std;
using namespace cv;

Mat gray2binary(const Mat& gray){
  Mat bw;
  adaptiveThreshold(~gray, bw, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY, 15, -2);
  return bw;
}

vector<Rect> detect_tables(string filename){
  Mat img = imread(filename.c_str(), IMREAD_GRAYSCALE);  
  if (!img.data)
    cerr << "Problem loading image. " << endl;
  Mat text = gray2binary(img);
  Mat nontext(text.size(), CV_8UC1, Scalar(0));
  heuristic_filter(text, nontext);
  vector<Rect> regions = homogenous_regions(text);
  for (auto& r : regions){
    rectangle(text, r, Scalar(255));
  }
  imshow("regions", text);
  waitKey(0);
}

 main(int argc, char** argv){
  detect_tables(string(argv[1]));
}
