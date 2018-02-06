//opencv
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
//C
#include <stdio.h>
//C++
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace cv;
using namespace std;

int main() {
  cv::Mat img = cv::imread("img.bmp", CV_LOAD_IMAGE_COLOR);
  Mat bgr[3];
  split(img,bgr);

  FILE *fp1 = NULL;
  FILE *fp2 = NULL;

  fp1 = fopen("Bank0Memory1.mif", "a");
  fp2 = fopen("Bank0Memory2.mif", "a");

  fprintf(fp1, "DEPTH = 4096;\n");
  fprintf(fp2, "DEPTH = 4096;\n");
  fprintf(fp1, "WIDTH = 16;\n");
  fprintf(fp2, "WIDTH = 16;\n");
  fprintf(fp1, "ADDRESS_RADIX = HEX;\n");
  fprintf(fp2, "ADDRESS_RADIX = HEX;\n");
  fprintf(fp1, "DATA_RADIX = HEX;\n\n");
  fprintf(fp2, "DATA_RADIX = HEX;\n\n");
  fprintf(fp1, "CONTENT\n");
  fprintf(fp2, "CONTENT\n");
  fprintf(fp1, "BEGIN\n");
  fprintf(fp2, "BEGIN\n");
  int addr = 0;
  int zero = 0;

  for (int i = 0; i < 2; i++){              //ajustar o tamanho com a memoria
    for (int j = 0; j < img.cols; j++) {
      fprintf(fp1, "%03x : ", addr);                //4096 endereços
      fprintf(fp1, "%04x", bgr[0].at<uchar>(i,j));  //16bits
      fprintf(fp1, "%04x\n", bgr[1].at<uchar>(i,j));
      fprintf(fp2, "%03x : ", addr);
      fprintf(fp2, "%04x", zero);                   //completa com zero os bits mais significativos
      fprintf(fp2, "%04x\n", bgr[2].at<uchar>(i,j));
      addr++;
    }
  }

  fprintf(fp1, "\nEND;");
  fprintf(fp2, "\nEND;");

  fclose(fp1);
  fclose(fp2);

  return 0;
}
