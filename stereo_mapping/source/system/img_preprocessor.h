//2021-03-04

#ifndef SYSTEM_IMG_PREPROCESSOR_H
#define SYSTEM_IMG_PREPROCESSOR_H

#include<memory>

//cv
#include <opencv2/opencv.hpp>

#include"util/logging.h"
#include"util/threading.h"

#include"data_que.h"

using namespace UTIL;

namespace stereo_mapper{

class ImgPreprocessor : public Thread{
public:
    struct Options{
        //TODO
    };
    ImgPreprocessor() = delete;
    ImgPreprocessor(
        const Options& opt,
        JobQueue<inner::ImageData>* input_queue_ptr,
        JobQueue<inner::ImageData>* output_queue_ptr);

private:
    const Options options_;
    void Run();

    JobQueue<inner::ImageData>* input_queue_ptr_;
    JobQueue<inner::ImageData>* output_queue_ptr_;

};

}// namespace
#endif