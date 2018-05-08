#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main( int argc, char** argv )
{
    std::cout << "Initial program" << std::endl;

    //Simple approach
    // gray color, values between 0 ~ 255 (2^8 = 256)
    cv::Mat1b image_1b = cv::Mat1b::zeros(500,500);
    // RGB color, values between 0 ~ 255 (2^8 = 256)
    cv::Mat3b image_3b = cv::Mat3b::zeros(500,500);

    // gray color, values between 0.0 ~ 1.0  (2^32)
    // cv::Mat1f image_1f = cv::Mat1f::zeros(500,500);
    // RGB color, values between 0.0 ~ 1.0  (2^32)
    // cv::Mat3f image_3f = cv::Mat3f::zeros(500,500);

    //Normal approach
    // cv::Mat image_1b = cv::Mat::zeros(500,500, CV_8UC1);
    // cv::Mat image_3b = cv::Mat::zeros(500,500, CV_8UC3);

    // cv::Mat image_1f = cv::Mat::zeros(500,500, CV_32FC1);
    // cv::Mat image_3f = cv::Mat::zeros(500,500, CV_32FC3);

    std::cout << " IMAGE_1b SIZE " << image_1b.size()
              << " | CHANNEL " << image_1b.channels()
              << std::endl;

    std::cout << " IMAGE_3b SIZE " << image_3b.size()
              << " | CHANNEL " << image_3b.channels()
              << std::endl;



    cv::imshow( "image_1b", image_1b);
    cv::imshow( "image_3b", image_3b);
    // cv::imshow( "image_1f", image_1f);
    // cv::imshow( "image_3f", image_3f);
    cv::waitKey(0);

    return 0;
}
