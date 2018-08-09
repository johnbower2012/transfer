#include<iostream>
#include<fstream>
#include<cmath>
#include "armadillo"
#include "../lib/pricomana.cpp"
#include "../lib/observables_class.cpp"

void load_file(std::string fileName, arma::mat &file){
  int load = file.n_rows;
  int param = file.n_cols;
  std::ifstream ifile;
  ifile.open(fileName);
  for(int i=0;i<load;i++){
    for(int j=0;j<param;j++){
      ifile >> file(i,j);
    }
  }
  ifile.close();
}
int main(int argc, char* argv[]){
  std::string *infilename,*outfilename;
  int observables,obs_file,files,lines,runs,param;
  int i,j,k;
  infilename = new std::string[observables];
  outfilename = new std::string[observables];
  std::string dest_folder;
  std::string exp_folder;
  std::string source_folder;
  std::string error_name;
  std::string param_name;
  std::string exp_name;

  param=4;
  files=4;
  obs_file=3;
  observables=files*obs_file;

  if(argc<7+files){
    std::cout << "Improper input. Enter also 'lines runs observables ifn*[7]' on same line." << std::endl;
    exit(1);
  }
  else{
    infilename = new std::string[files];
    source_folder = argv[1];
    exp_folder = argv[2];
    dest_folder = argv[3];
    lines=atoi(argv[4]);
    runs=atoi(argv[5]);
    files=atoi(argv[6]);
    for(i=0;i<files;i++){
      infilename[i]=argv[7+i];
    }
  }
  printf("Arguments read in as:\n");
  printf("observables.x %s %d %d %d",dest_folder.c_str(),lines,runs,files);
  for(i=0;i<files;i++){
    printf(" %s",infilename[i].c_str());
  }
  printf("\n");


  /*********
	     LOAD FILE
	     CALCULATE OBS_MAT
  *********/
  arma::mat *val_matrix, obs_matrix;
  arma::vec delY_vec, obs_error;
  val_matrix = new arma::mat[files];
  obs_matrix = arma::zeros<arma::mat>(runs,observables);
  delY_vec = arma::zeros<arma::vec>(lines);
  obs_error = arma::zeros<arma::vec>(observables);

  load_file(files, lines, runs, infilename, delY_vec, val_matrix);
  obs_matrix_moments(files,obs_file,val_matrix,delY_vec,obs_matrix);


  /*********
	     CONDUCT PCA
	     PRINT
  *********/

  arma::mat tval_matrix,zcov_matrix,eigvec_matrix,print_matrix;
  arma::vec eigval_vec,mean_vec;
  print_matrix = arma::zeros<arma::mat>(observables,observables+1);
  tval_matrix = arma::zeros<arma::mat>(observables,observables);
  zcov_matrix = arma::zeros<arma::mat>(observables,observables);
  eigvec_matrix = arma::zeros<arma::mat>(observables,observables);
  eigval_vec = arma::zeros<arma::vec>(observables);
  mean_vec = arma::zeros<arma::vec>(observables);

  arma::mat err = arma::zeros<arma::mat>(1,observables);
  arma::mat y_tilde = arma::zeros<arma::mat>(lines,observables);
  arma::mat parameters = arma::zeros<arma::mat>(runs,param);
  arma::mat exp_data = arma::zeros<arma::mat>(1,observables);

  //LOAD FILES
  error_name = exp_folder + "moments_error.dat";
  load_file(error_name,err);
  printf("%s loaded.\n",error_name.c_str());
  for(int i=0;i<observables;i++){
    obs_error(i) = err(0,i);
  }
  param_name = dest_folder + "moments_parameters.dat";
  load_file(param_name,parameters);
  printf("%s loaded.\n",param_name.c_str());

  exp_name = exp_folder + "moments_exp_data.dat";
  load_file(exp_name,exp_data);
  printf("%s loaded.\n",exp_name.c_str());
  

  //COMPUTE Z_MATRIX
  tilde_function(obs_matrix,obs_error,mean_vec,y_tilde);
  tval_matrix = calculate_tmatrix_function(obs_matrix, obs_error, eigval_vec, eigvec_matrix, mean_vec, zcov_matrix);

  //PRINT RESULTS
  print_fractional_sum(eigval_vec);
  eigval_vec.print("+++++ eigvalues +++++");
  eigvec_matrix.print("+++++ eigvectors +++++");

  //WRITE FILES
  for(i=0;i<observables;i++){
    print_matrix(i,0) = eigval_vec(i);
    for(j=0;j<observables;j++){
      print_matrix(i,j+1) = eigvec_matrix(j,i);
    }
  }

  std::string printname;
  std::string title;
  /*
  printname = dest_folder + "moments_model_data.dat";
  title = "#pipi ppbar pK KK\n#m0 m1 m2";
  print_file(printname,obs_matrix);
  printf("%s saved to file.\n",printname.c_str());

  printname = dest_folder + "moments_model_data_tilde.dat";
  title = "#pipi ppbar pK KK\n#m0 m1 m2";
  print_file(printname,y_tilde);
  printf("%s saved to file.\n",printname.c_str());
  */
  printname = dest_folder + "moments_errors.dat";
  title="#pipi/ppbar/pK/KK";
  print_file(printname,obs_error);
  printf("%s saved to file.\n",printname.c_str());

  printname = dest_folder + "moments_means.dat";
  title="#pipi/ppbar/pK/KK";
  print_file(printname,mean_vec);
  printf("%s saved to file.\n",printname.c_str());

  printname = dest_folder + "moments_model_eigvec.dat";
  title = "#colvec\n#pipi ppbar pK KK\n#m0 m1 m2";
  print_file(printname,eigvec_matrix);
  printf("%s saved to file.\n",printname.c_str());

  printname = dest_folder + "moments_model_pca.dat";
  title = "#eigval col -- eigvec rows\n#pipi ppbar pK KK\n#m0 m1 m2";
  print_file(printname,title,print_matrix);
  printf("%s saved to file.\n",printname.c_str());

  print_matrix = tval_matrix;
  printname = dest_folder + "moments_model_z.dat";
  title = "#y~*eigvec";
  print_file(printname,print_matrix);
  printf("%s saved to file.\n",printname.c_str());

  print_matrix = arma::zeros<arma::mat>(runs,param+observables);
  for(int i=0;i<param;i++){
    print_matrix.col(i) = parameters.col(i);
  }
  for(int i=0;i<observables;i++){
    print_matrix.col(i+param) = tval_matrix.col(i);
  }
  printname = dest_folder + "moments_plot.dat";
  title = "#param+model_z.s";
  print_file(printname,print_matrix);
  printf("%s saved to file.\n",printname.c_str());

  arma::mat exp_tilde = arma::zeros<arma::mat>(1,observables);
  for(int i=0;i<observables;i++){
    exp_tilde(0,i) = (exp_data(0,i) - mean_vec(i))/obs_error(i);
  }
  arma::mat exp_z = exp_tilde*eigvec_matrix;
  printname = dest_folder + "moments_exp_z.dat";
  title = "#exp_z";
  print_file(printname,exp_z);
  printf("%s saved to file.\n",printname.c_str());
  
  
  delete[] val_matrix;
  delete[] infilename;
  delete[] outfilename;

  return 0;
}

