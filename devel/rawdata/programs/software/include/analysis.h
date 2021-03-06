#ifndef __ANALYSIS_H__
#define __ANALYSIS_H__

#include<Eigen/Dense>
#include<vector>
#include<iostream>
#include "system.h"

class CAnalysis{
 public:
  Eigen::MatrixXd Data;
  Eigen::MatrixXd Tilde;
  Eigen::MatrixXd Z;

  Eigen::VectorXd Mean;
  Eigen::MatrixXd Error;

  Eigen::MatrixXd Covariance;

  Eigen::VectorXd EigenValues;
  Eigen::MatrixXd EigenVectors;  

  CAnalysis();

  void ComputeMean();
  void SumErrorInQuadrature(Eigen::MatrixXd Error2);
  void SumErrorInQuadrature(Eigen::VectorXd error2);
  void ComputeTilde();
  void InvertTilde();
  void ComputeCovariance();
  void EigenSolve();
  void EigenSort();
  void ComputeZ();
};

void RemoveRow(Eigen::MatrixXd& matrix, unsigned int rowToRemove);
void RemoveColumn(Eigen::MatrixXd& matrix, unsigned int colToRemove);

void AddOnesRow(Eigen::MatrixXd matrix, Eigen::MatrixXd &outMatrix);
void AddOnesColumn(Eigen::MatrixXd matrix, Eigen::MatrixXd &outMatrix);

void ScaleMatrixColumns(Eigen::MatrixXd Matrix,Eigen::VectorXd &Mean, Eigen::VectorXd &Std, Eigen::MatrixXd &Scaled);
void ScaleMatrixRows(Eigen::MatrixXd Matrix,Eigen::VectorXd &Mean, Eigen::VectorXd &Stdd, Eigen::MatrixXd &Scaled);
void ScaleMatrixColumnsUniform(Eigen::MatrixXd Matrix,Eigen::MatrixXd &MinMax, Eigen::MatrixXd &Scaled);
void ScaleMatrixRowsUniform(Eigen::MatrixXd Matrix,Eigen::MatrixXd &MinMax, Eigen::MatrixXd &Scaled);

void AverageColumns(Eigen::VectorXd &average, Eigen::MatrixXd matrix);
void AverageRows(Eigen::VectorXd &average, Eigen::MatrixXd matrix);

void SumInQuadrature(Eigen::MatrixXd &sum, Eigen::MatrixXd A, Eigen::MatrixXd B);
void SumInQuadrature(Eigen::MatrixXd &sum, Eigen::MatrixXd A, Eigen::VectorXd b);
void SumInQuadrature(Eigen::VectorXd &sum, Eigen::VectorXd a, Eigen::VectorXd b);
/*
void CalculatePercentageError(Eigen::VectorXd &Error, Eigen::MatrixXd ExpObs, double fraction);
void CalculateError(Eigen::VectorXd &Error, Eigen::MatrixXd ExpObs, int obs);
void CalculateError_Variance(Eigen::MatrixXd &Error, Eigen::MatrixXd Obs);
void CalculateError_Variance(Eigen::VectorXd &Error, Eigen::MatrixXd Obs);

void TildeFunction(Eigen::MatrixXd &tilde, Eigen::VectorXd mean, Eigen::VectorXd error, Eigen::MatrixXd matrix);
void TildeFunction(Eigen::MatrixXd &tilde, Eigen::VectorXd mean, Eigen::MatrixXd error, Eigen::MatrixXd matrix);
void ReverseTildeFunction(Eigen::MatrixXd tilde, Eigen::VectorXd mean, Eigen::MatrixXd error, Eigen::MatrixXd &matrix);
void CovarianceFunction(Eigen::MatrixXd &cov, Eigen::VectorXd &mean, Eigen::MatrixXd matrix);
void CovarianceFunction_NoMean(Eigen::MatrixXd &cov, Eigen::MatrixXd matrix);

void EigenSolve(Eigen::VectorXd &eigenvalues, Eigen::MatrixXd &eigenvectors, Eigen::MatrixXd matrix);
void FindMax(Eigen::VectorXd vector, int &index, double &max);
void FindMax(Eigen::MatrixXd vector, int &index, double &max);
void EigenSort(Eigen::VectorXd &eigval, Eigen::MatrixXd &eigvec);

void ZerothMoment(Eigen::MatrixXd Function, double &Moment, double &MomentError);
void FirstMoment(Eigen::MatrixXd Function, double &Moment, double &MomentError);
void SecondMoment(Eigen::MatrixXd Function, double &Moment, double &MomentError);
void MatrixMoments(std::vector<Eigen::MatrixXd> Matrix, Eigen::VectorXd DelX, Eigen::MatrixXd &ObsX, Eigen::MatrixXd &ObsError);

void linearRegressionLeastSquares(Eigen::MatrixXd Y, Eigen::MatrixXd X, Eigen::MatrixXd &Beta);
void ConstructHyperparameters(Eigen::MatrixXd Matrix,Eigen::MatrixXd &HyperParameters);
void ConstructWidths(Eigen::VectorXd &Widths, Eigen::MatrixXd &Range, int parameters, double fraction);
void ComputeFit(Eigen::MatrixXd ModelZ, Eigen::MatrixXd EmulatorZ, Eigen::MatrixXd &outMatrix);

void Extract5(Eigen::MatrixXd &outMatrix, Eigen::MatrixXd inMatrix);
void ExtractOnly10(Eigen::MatrixXd &outMatrix, Eigen::MatrixXd inMatrix);
void ExtractOnly20(Eigen::MatrixXd &outMatrix, Eigen::MatrixXd inMatrix);

void ConductModelAnalysis(std::string infoldername, std::string outfoldername, std::string delimiter, int start, int finish, Eigen::MatrixXd &ModelZ, Eigen::MatrixXd &ExpZ);
*/
#endif
