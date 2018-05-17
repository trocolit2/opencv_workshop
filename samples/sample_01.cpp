// Sample 01, How to instanciate a image by cv::Mat, and how to set pixel color.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>



cv::Scalar lineParameters( cv::Point2f pt_1,
                           cv::Point2f pt_2,
                           cv::Point color){

  float dot_slope, dot_bias;
  // y=ax+b
  dot_slope = (pt_2.y - pt_1.y) / (pt_2.x - pt_1.x);
  // -> b= y -ax
  dot_bias = pt_1.y - dot_slope*pt_1.x;

  float color_slope, color_bias;

  color_slope = (color.y - color.x)/ (pt_2.x - pt_1.x);
  color_bias = color.y - color_slope*pt_2.x;

  return cv::Scalar(dot_slope, dot_bias, color_slope, color_bias);

}




int main( int argc, char** argv )
{
    std::cout << "Initial program" << std::endl;

    //Simple approach
    // gray color, values between 0 ~ 255 (2^8 = 256)
    cv::Mat1b image_1b = cv::Mat1b::zeros(480,640);
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

    //show the image size, and the number of channels
    std::cout << " IMAGE_1b SIZE " << image_1b.size()
              << " | CHANNEL " << image_1b.channels()
              << std::endl;

    std::cout << " IMAGE_3b SIZE " << image_3b.size()
              << " | CHANNEL " << image_3b.channels()
              << std::endl;
//
//     // show the black images
    // cv::imshow( "image_1b", image_1b);
    // cv::imshow( "image_3b", image_3b);
    // // cv::imshow( "image_1f", image_1f);
    // // cv::imshow( "image_3f", image_3f);
    //
    // // wait press any key to continuos
    // std::cout << cv::Mat3b::zeros(3,3) + cv::Scalar(255, 128, 25) << std::endl;
    // cv::waitKey();
//
// ////////////////////////////////////
//     // set a pixel color in gray
    image_1b[250][250] = 255;
//
//     // set a pixel color in RGB

//     image_3b[250][249][0] = 255; //B
//     image_3b[251][249][0] = 255; //B
//     image_3b[252][249][0] = 255; //B
//     image_3b[253][249][0] = 255; //B
//
//     image_3b[250][251][1] = 255; //G
//     image_3b[251][251][1] = 255; //G
//     image_3b[252][251][1] = 255; //G
//     image_3b[253][251][1] = 255; //G
//
//     image_3b[250][252][2] = 255; //R
//     image_3b[251][252][2] = 255; //R
//     image_3b[252][252][2] = 255; //R
//     image_3b[253][252][2] = 255; //R
//     image_3b[254][252][2] = 255; //R
// //
//     cv::imshow( "image_1b", image_1b);
//     cv::imshow( "image_3b", image_3b);
// //
//     cv::waitKey();

// ////////////////////////////////////////////////////////
    // for (size_t i = 10; i < 200; i++)
    //   for (size_t j = 20; j < 300; j++) {
    //     image_1b[i][j] = 255-i+j;
    //   }

cv::Scalar params = lineParameters(
                        cv::Point(0,image_1b.rows), // start point
                        cv::Point(image_1b.cols, 0), // end point
                        cv::Point(0,255)); // color range

  std::cout <<" params" << params << std::endl;
  for (size_t i = 0; i < image_1b.cols; i++){
      int pose_y = params[0]*i + params[1];
      int color = params[2]*i + params[3];
      image_1b[pose_y][i]= color;

      cv::imshow( "image_1b", image_1b);
      cv::waitKey(1);
    }


    // cv::imshow( "image_3b", image_3b);
    cv::waitKey();

    return 0;
}
