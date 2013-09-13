#pragma once

#include <opencv2/opencv.hpp>
#include <node.h>
#include <node_buffer.h>
#include <v8.h>

    std::string toDataUri(cv::Mat& img, const char * imageMimeType = "image/png");
    
    struct ScopedTimer
    {
        inline ScopedTimer()
        {
            m_startTime = cv::getTickCount();
        }
        
        inline float executionTimeMs() const
        {
            return (cv::getTickCount() - m_startTime) * 1000. / cv::getTickFrequency();
        }
        
        int64_t m_startTime;
    };


    class ObjectBuilder
    {
    public:
        typedef v8::Local<v8::Object> NodeObject;

        ObjectBuilder(NodeObject& obj);

        ObjectBuilder& Set(const char * name, int value);
        ObjectBuilder& Set(const char * name, size_t value);
        ObjectBuilder& Set(const char * name, float value);
        ObjectBuilder& Set(const char * name, const char * value);
        ObjectBuilder& Set(const char * name, const std::string& value);

    private:
        NodeObject& m_object;
    };
