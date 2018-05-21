// Sample 02, read image from file, read video from file, read sequence of pictures.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <string>

#define DATASET_PATH "../../dataset/"
#define PICTURE_FILE "image_00.jpg"
#define VIDEO_FILE "video_00.mp4"
int main(int argc, char const *argv[]) {

  std::string path = std::string( DATASET_PATH );
  std::string picture = std::string( PICTURE_FILE );
  std::string video = std::string( VIDEO_FILE );

  std::cout << "Read image: " << path+picture << std::endl;
  cv::Mat input;
  input = cv::imread( path+picture );
  cv::imshow( picture, input );
  cv::waitKey();

//////////////////////////////////

  std::cout << "Read video: " << path+video << std::endl;
  cv::VideoCapture cap_video( path+video );
  uint i = 0;
  while(cap_video.read(input)){
    std::cout << "Frame: " << ++i << std::endl;
    cv::imshow( video, input );
    cv::waitKey(1);
  }

//////////////////////////////////

  std::string sequence = "image_%02d.jpg";
  std::cout << "Sequence picture: " << path+sequence << std::endl;
  cv::VideoCapture cap_seq( path+sequence );
  i = 0;
  while(cap_seq.read(input)){
    std::cout << "Picture: " << ++i << std::endl;
    cv::imshow( "sequence", input );
    cv::waitKey();
  }


  return 0;
}
