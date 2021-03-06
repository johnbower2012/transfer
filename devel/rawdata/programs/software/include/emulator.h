#ifndef __EMULATOR_H__
#define __EMULATOR_H__

#include<Eigen/Dense>
#include<chrono>
#include<random>
#include<cmath>
#include<iostream>
#include "parametermap.h"

void AddOnesColumn(Eigen::MatrixXd matrix, Eigen::MatrixXd &outMatrix);

class CEmulator{
 public:
  virtual ~CEmulator(){}
  virtual void Construct(Eigen::MatrixXd newX, Eigen::MatrixXd newY, CParameterMap MAP) =0;
  virtual Eigen::MatrixXd Emulate(Eigen::MatrixXd testX) =0;
};


class CGaussianProcess : public CEmulator{
 public:
  int trainPoints;
  int paramCount;
  int obsCount;
  int hyperparamCount; 
  
  double Epsilon; //Numerical stability factor for matrix inversion, 1e-8 by default
  double SigmaF; //Variance of func to be emulated
  double CharacLength; //Length overwhich func varies
  double SigmaNoise; //Noise of func
  Eigen::VectorXd Noise;

  Eigen::MatrixXd X;
  Eigen::MatrixXd Y;
  Eigen::MatrixXd Hyperparameters;
  Eigen::MatrixXd Beta;

  std::vector<Eigen::MatrixXd> Kernel;
  std::vector<Eigen::MatrixXd> KernelInv;
  std::vector<Eigen::MatrixXd> HMatrix;

  CGaussianProcess();
  ~CGaussianProcess(){}
  CGaussianProcess(Eigen::MatrixXd newX, Eigen::MatrixXd newY, CParameterMap MAP);
  CGaussianProcess(Eigen::MatrixXd newX, Eigen::MatrixXd newY, std::string filename);
  void Construct(Eigen::MatrixXd newX, Eigen::MatrixXd newY, CParameterMap MAP);
  void Construct(Eigen::MatrixXd newX, Eigen::MatrixXd newY, std::string filename);

  void ConstructHyperparameters();  
  void ConstructBeta();
  void RegressionLinearFunction();
  
  Eigen::MatrixXd KernelFunction(Eigen::MatrixXd A, Eigen::MatrixXd B, int obsIndex);
  Eigen::MatrixXd RegressionLinearFunction(Eigen::MatrixXd testX, int obsIndex);

  Eigen::MatrixXd Emulate(Eigen::MatrixXd testX);
  Eigen::MatrixXd Emulate_NR(Eigen::MatrixXd testX);
};



#endif
