#pragma once

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <constants definitions> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#define SLIDING_WINDOW_MOVING_PERCENTAGE_INCREMENT 0.1

#define SLIDING_WINDOW_BOX_GROWING_PERCENTAGE_START 0.1
#define SLIDING_WINDOW_BOX_GROWING_PERCENTAGE_INCREMENT 0.1
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </constants definitions> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <includes> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// std includes
#include <vector>
#include <string>
#include <limits>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/nonfree/features2d.hpp>

// project includes
#include "ImageDetector.h"
#include "ImageClassifier.h"
#include "ImageUtils.h"
#include "../libs/PerformanceTimer.h"

// namespace specific imports to avoid namespace pollution
using std::string;
using std::vector;

using cv::Mat;
using cv::Ptr;
using cv::KeyPoint;
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </includes> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <ImageDetectorSlidingWindow>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class ImageDetectorSlidingWindow : public ImageDetector {
	public:
		ImageDetectorSlidingWindow(Ptr<ImageClassifier> imageClassifier);
		virtual ~ImageDetectorSlidingWindow();

		virtual Mat detectTargets(Mat& image, vector<Rect>& targetsBoundingRectanglesOut, bool showTargetBoundingRectangles = true, bool showImageKeyPoints = true, size_t* numberOfWindowsOut = NULL);
};
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </ImageDetectorSlidingWindow>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<