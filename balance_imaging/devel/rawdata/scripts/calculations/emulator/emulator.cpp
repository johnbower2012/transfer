#include<iostream>
#include<iomanip>
#include<cmath>
#include "lib/emulator_class.cpp"
#include<armadillo>

double calc_llh(arma::mat target, arma::mat model, int cutoff){
  double sum=0.0;
  for(int i=0;i<cutoff;i++){
    sum += (target(i) - model(i))*(target(i) - model(i));
  }
  return -sum/2.0;
}

int main(int argc, char* argv[]){
  int train = 1000;
  int test = 719;
  int param = 4;
  int observables=12;
  int hp = 3;
  double epsilon=1e-8;
  int INT;
  std::string fileName, betaName,hypName,dest_folder;

  arma::mat X = arma::zeros<arma::mat>(train,param);
  arma::mat X_s = arma::zeros<arma::mat>(test,param);
  arma::mat range = arma::zeros<arma::mat>(param,2);
  arma::mat H = arma::zeros<arma::mat>(observables,hp);
  arma::mat beta = arma::zeros<arma::mat>(observables,param+1);
  arma::mat Y = arma::zeros<arma::mat>(train,observables);
  arma::mat y = arma::zeros<arma::mat>(train,1);

  if(argc<5){
    printf("Improper usage. Please enter 'fileName betaName hyperpName dest_folder' on same line.\n");
    exit(1);
  } else{
    fileName = argv[1];
    betaName = argv[2];
    hypName = argv[3];
    dest_folder = argv[4];
  }
  
  load_data_file(fileName,X,Y);
  load_beta_file(betaName,beta);
  load_file(hypName,H);

  for(int i=0;i<param;i++){
    range(i,0) = 0.1;
    range(i,1) = 1.5;
  }
  X_s = construct_latinhypercube_sampling(test,range);
  /*
  emulator gauss(X,H,beta,epsilon);
  arma::mat output = gauss.emulate(X_s,Y);
  std::string printname = dest_folder + "test.dat";
  write_output(output,param,observables,printname);
  printname = dest_folder + "train.dat";
  write_trainset(X, Y, printname);
  */

  //  arma::mat mllh = arma::zeros<arma::mat>(train,5);
  // double llh;
  
  std::ofstream ofile;
  ofile.open("likelihood.dat");
  for(int i=0;i<train;i++){
    arma::mat X_temp = X;
    arma::mat Y_temp = Y;
    X_s.row(0) = X.row(i);
    X_temp.shed_row(i);
    arma::mat target = Y.row(i);
    Y_temp.shed_row(i);

    emulator gauss(X,H,beta,epsilon);
    arma::mat output = gauss.emulate(X_s,Y);

    arma::mat Y_s = arma::zeros<arma::mat>(1,observables);
    for(int j=0;j<observables;j++){
      Y_s.col(j) = output.col(param+j);
    }
    llh = calc_llh(target,Y_s,INT);
    for(int i=0;i<param;i++){
      ofile << X_s(0,i) << " ";
    }
    ofile << llh << std::endl;

    X_s.print();
    target.print();
    Y_s.print();
    
    printf("llh: %f\n",llh);
  }
  ofile.close();

  return 0;
}
