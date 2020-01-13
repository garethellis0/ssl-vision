#pragma once

#include <VarTypes.h>
#include <QObject>
#include <opencv2/opencv.hpp>

using namespace VarTypes;

class CameraIntrinsicParameters : public QObject {
  Q_OBJECT

private:
  VarDouble *focal_length_x;
  VarDouble *focal_length_y;
  VarDouble *principal_point_x;
  VarDouble *principal_point_y;

  VarDouble *dist_coeff_k1;
  VarDouble *dist_coeff_k2;
  VarDouble *dist_coeff_p1;
  VarDouble *dist_coeff_p2;
  VarDouble *dist_coeff_k3;

public:
  CameraIntrinsicParameters();
  ~CameraIntrinsicParameters() override;

  void updateConfigValues();
  void reset();

  VarList *settings;

  cv::Mat camera_mat;
  cv::Mat dist_coeffs;

  // derived matrices for faster computation
  cv::Mat camera_mat_inv;
public slots:
  void updateCameraMat();
  void updateDistCoeffs();
};

class CameraExtrinsicParameters : public QObject {
  Q_OBJECT

private:
  VarDouble *rvec_x;
  VarDouble *rvec_y;
  VarDouble *rvec_z;

  VarDouble *tvec_x;
  VarDouble *tvec_y;
  VarDouble *tvec_z;

public:
  CameraExtrinsicParameters();
  ~CameraExtrinsicParameters() override;

  void updateConfigValues();
  void reset();

  VarList *settings;

  cv::Mat rvec;
  cv::Mat tvec;

  // derived matrices for faster computation
  cv::Mat rotation_mat_inv;
  cv::Mat right_side_mat_inv;

public slots:
  void updateRVec();
  void updateTVec();
};