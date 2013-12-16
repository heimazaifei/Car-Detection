#pragma once


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <constants definitions> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#define VOCABULARY_TAG "Vocabulary"
#define VOCABULARY_EXTENSION ".xml"
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </constants definitions> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <includes> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// std includes
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

// OpenCV includes
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/nonfree/features2d.hpp>

// project includes
#include "ImagePreprocessor.h"


// namespace specific imports to avoid namespace pollution
using std::vector;
using std::string;
using std::stringstream;
using std::ifstream;
using std::getline;

using cv::Mat;
using cv::Rect;
using cv::RotatedRect;
using cv::Ptr;
using cv::KeyPoint;
using cv::FeatureDetector;
using cv::DescriptorExtractor;
using cv::DescriptorMatcher;
using cv::BOWTrainer;
using cv::BOWImgDescriptorExtractor;
using cv::FileStorage;
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </includes> <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <BowVocabulary>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class BowVocabulary {
	public:
		BowVocabulary(Ptr<FeatureDetector> featureDetector, Ptr<DescriptorExtractor> descriptorExtractor, Ptr<DescriptorMatcher> descriptorMatcher, Ptr<BOWTrainer> bowTrainer,
			Ptr<ImagePreprocessor> imagePreprocessor, string vocabularyFilename = "vocabulary.xml");
		virtual ~BowVocabulary();

		bool loadVocabulary(Mat& vocabularyOut);
		bool saveVocabulary(const Mat& vocabularyOut);
		bool computeVocabulary(Mat& vocabularyOut, string vocabularyImgsList);


		// ------------------------------------------------------------------------------  <gets | sets> -------------------------------------------------------------------------------
		Ptr<FeatureDetector> getFeatureDetector() const { return _featureDetector; }
		void setFeatureDetector(Ptr<FeatureDetector> val) { _featureDetector = val; }
		Ptr<DescriptorExtractor> getDescriptorExtractor() const { return _descriptorExtractor; }
		void setDescriptorExtractor(Ptr<DescriptorExtractor> val) { _descriptorExtractor = val; }
		Ptr<DescriptorMatcher> getDescriptorMatcher() const { return _descriptorMatcher; }
		void setDescriptorMatcher(Ptr<DescriptorMatcher> val) { _descriptorMatcher = val; }

		Ptr<BOWTrainer> getBowTrainer() const { return _bowTrainer; }
		void setBowTrainer(Ptr<BOWTrainer> val) { _bowTrainer = val; }
		Ptr<BOWImgDescriptorExtractor> getBowImgDescriptorExtractor() const { return _bowImgDescriptorExtractor; }
		void setBowImgDescriptorExtractor(Ptr<BOWImgDescriptorExtractor> val) { _bowImgDescriptorExtractor = val; }


		Ptr<ImagePreprocessor> getImagePreprocessor() const { return _imagePreprocessor; }
		void setImagePreprocessor(Ptr<ImagePreprocessor> val) { _imagePreprocessor = val; }

		string getVocabularyFilename() const { return _vocabularyFilename; }
		void setVocabularyFilename(string val) { _vocabularyFilename = val; }
		// ------------------------------------------------------------------------------  </gets | sets> ------------------------------------------------------------------------------

	private:
		Ptr<FeatureDetector> _featureDetector;		
		Ptr<DescriptorExtractor> _descriptorExtractor;		
		Ptr<DescriptorMatcher> _descriptorMatcher;
		
		Ptr<BOWTrainer> _bowTrainer;				
		Ptr<BOWImgDescriptorExtractor> _bowImgDescriptorExtractor;
		
		Ptr<ImagePreprocessor> _imagePreprocessor;
		
		string _vocabularyFilename;
};
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </BowVocabulary>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<