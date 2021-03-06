#ifndef TRACK_UTILITY_HPP
#define TRACK_UTILITY_HPP

#include <opencv2/opencv.hpp>
#include <vector>
#include "tree_helper.hpp"

cv::Rect stats2rect(const cv::Mat& stats, int i);

struct Line{
  int l, r;
  Line(int l, int r): l(l), r(r){};
  int length() const{
    return r-l;
  }
};

struct ComponentStats{
  int index;
  cv::Rect r;
  int area, bb_area;
  double density, hwratio;
  ComponentStats(cv::Rect r, int area, int i);
};

struct ImageMeta{
  int width, height;
  tree::RT t_tree, nt_tree;
  ImageMeta(int width, int height, std::vector<ComponentStats>& text, std::vector<ComponentStats>& nontext);
};

struct ImageDataBox{
  cv::Mat text, nontext;
  std::vector<ComponentStats> textData, nontextData;
  ImageDataBox(cv::Mat& text, cv::Mat& nontext);
};

ComponentStats stats2component(const cv::Mat& stats, int statsIndex, int compIndex = -1);
std::vector<ComponentStats> statistics(cv::Mat& img);
std::vector<cv::Rect> boundingVector(cv::Mat& img);

void find_lines(const cv::Mat& hist, std::vector<Line>& text, std::vector<Line>& space);
void find_all_lines(const cv::Mat& hist, std::vector<Line>& text, std::vector<Line>& space);

#endif
