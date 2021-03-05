//2021-03-04

#ifndef SYSTEM_IMG_PREPROCESSOR_H
#define SYSTEM_IMG_PREPROCESSOR_H

#include<memory>
#include"util/logging.h"
#include"util/threading.h"

using namespace UTIL;

namespace stereo{

namespace inner{
    struct ImageData;
}

class ImgPreprocessor : public Thread{
public:
    struct Options{
        //TODO
    };
    ImgPreprocessor() = delete;
    ImgPreprocessor(
        const Options& opt,
        JobQueue<ImageData>* input_queue_ptr,
        JobQueue<ImageData>* output_queue_ptr);

private:
    const Options options_;
    void Run();

    JobQueue<ImageData>* input_queue_ptr_;
    JobQueue<ImageData>* output_queue_ptr_;

};

}// namespace
#endif