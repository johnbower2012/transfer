#include "distributions.h"
using namespace std;

CDistribution::CDistribution(){
}

void CDistribution::GenX(int ab,double &x,double &weight){
}

CDistInvCosh::CDistInvCosh(string parsfilename){
	int ab,ng=10;
	width=new double[4];
	g=new double *[4];
	for(ab=0;ab<4;ab++)
		g[ab]=new double[ng+1];
	
	parameter::ReadParsFromFile(parmap,parsfilename.c_str());
	
	width[0]=parameter::getD(parmap,"InvCoshPar_uu_width",1.0);
	width[1]=parameter::getD(parmap,"InvCoshPar_ud_width",1.0);
	width[2]=parameter::getD(parmap,"InvCoshPar_us_width",1.0);
	width[3]=parameter::getD(parmap,"InvCoshPar_ss_width",1.0);
	
	g[0][0]=parameter::getD(parmap,"InvCoshPar_uu_g0",1.0);
	g[0][1]=parameter::getD(parmap,"InvCoshPar_uu_g1",0.0);
	g[0][2]=parameter::getD(parmap,"InvCoshPar_uu_g2",0.0);
	g[0][3]=parameter::getD(parmap,"InvCoshPar_uu_g3",0.0);
	g[0][4]=parameter::getD(parmap,"InvCoshPar_uu_g4",0.0);
	g[0][5]=parameter::getD(parmap,"InvCoshPar_uu_g5",0.0);
	g[0][6]=parameter::getD(parmap,"InvCoshPar_uu_g6",0.0);
	g[0][7]=parameter::getD(parmap,"InvCoshPar_uu_g7",0.0);
	g[0][8]=parameter::getD(parmap,"InvCoshPar_uu_g8",0.0);
	g[0][9]=parameter::getD(parmap,"InvCoshPar_uu_g9",0.0);
	g[0][10]=parameter::getD(parmap,"InvCoshPar_uu_g10",0.0);
	
	g[1][0]=parameter::getD(parmap,"InvCoshPar_ud_g0",1.0);
	g[1][1]=parameter::getD(parmap,"InvCoshPar_ud_g1",0.0);
	g[1][2]=parameter::getD(parmap,"InvCoshPar_ud_g2",0.0);
	g[1][3]=parameter::getD(parmap,"InvCoshPar_ud_g3",0.0);
	g[1][4]=parameter::getD(parmap,"InvCoshPar_ud_g4",0.0);
	g[1][5]=parameter::getD(parmap,"InvCoshPar_ud_g5",0.0);
	g[1][6]=parameter::getD(parmap,"InvCoshPar_ud_g6",0.0);
	g[1][7]=parameter::getD(parmap,"InvCoshPar_ud_g7",0.0);
	g[1][8]=parameter::getD(parmap,"InvCoshPar_ud_g8",0.0);
	g[1][9]=parameter::getD(parmap,"InvCoshPar_ud_g9",0.0);
	g[1][10]=parameter::getD(parmap,"InvCoshPar_ud_g10",0.0);
	
	g[2][0]=parameter::getD(parmap,"InvCoshPar_us_g0",1.0);
	g[2][1]=parameter::getD(parmap,"InvCoshPar_us_g1",0.0);
	g[2][2]=parameter::getD(parmap,"InvCoshPar_us_g2",0.0);
	g[2][3]=parameter::getD(parmap,"InvCoshPar_us_g3",0.0);
	g[2][4]=parameter::getD(parmap,"InvCoshPar_us_g4",0.0);
	g[2][5]=parameter::getD(parmap,"InvCoshPar_us_g5",0.0);
	g[2][6]=parameter::getD(parmap,"InvCoshPar_us_g6",0.0);
	g[2][7]=parameter::getD(parmap,"InvCoshPar_us_g7",0.0);
	g[2][8]=parameter::getD(parmap,"InvCoshPar_us_g8",0.0);
	g[2][9]=parameter::getD(parmap,"InvCoshPar_us_g9",0.0);
	g[2][10]=parameter::getD(parmap,"InvCoshPar_us_g10",0.0);
	
	g[3][0]=parameter::getD(parmap,"InvCoshPar_ss_g0",1.0);
	g[3][1]=parameter::getD(parmap,"InvCoshPar_ss_g1",0.0);
	g[3][2]=parameter::getD(parmap,"InvCoshPar_ss_g2",0.0);
	g[3][3]=parameter::getD(parmap,"InvCoshPar_ss_g3",0.0);
	g[3][4]=parameter::getD(parmap,"InvCoshPar_ss_g4",0.0);
	g[3][5]=parameter::getD(parmap,"InvCoshPar_ss_g5",0.0);
	g[3][6]=parameter::getD(parmap,"InvCoshPar_ss_g6",0.0);
	g[3][7]=parameter::getD(parmap,"InvCoshPar_ss_g7",0.0);
	g[3][8]=parameter::getD(parmap,"InvCoshPar_ss_g8",0.0);
	g[3][9]=parameter::getD(parmap,"InvCoshPar_ss_g9",0.0);
	g[3][10]=parameter::getD(parmap,"InvCoshPar_ss_g10",0.0);
	
	invcoshcalc=new CInvCoshCalc(ng);
}

void CDistInvCosh::GenX(int ab,double &x,double &weight){
	int n,ng=invcoshcalc->ng;
	x=invcoshcalc->GetRandomXFromInvCosh();
	//	double Z=0.0;
	weight=0.0;
	for(n=0;n<=ng;n++){
		weight+=invcoshcalc->GetG(n,x/width[ab])*g[ab][n];
		//Z+=invcoshcalc->I(n)*g[ab][n];
	}
	weight*=0.5*PI/(invcoshcalc->GetG(0,x));//*g[ab][0]);
	x*=width[ab];
}

CInvCoshCalc::CInvCoshCalc(int ngset){
	ng=ngset;
	arma::mat A;
	arma::vec x,y,ytest;
	int n,nprime,m,mprime;
	double norm,overlap;
	I.resize(2*ng+2);
	I(0)=0.5*PI;
	I(1)=1.0;
	for(n=2;n<=2*ng+1;n++){
		I(n)=I(n-2)*double(n-1)/double(n);
		//printf("I(%d)=%15.10e\n",n,I(n));
	}
	a.resize(ng+1,ng+1);
	a.zeros();
	a(0,0)=1.0;
	for(n=1;n<=ng;n++){
		a(n,n)=1.0;
		A.resize(n,n);
		A.zeros();
		x.resize(n);
		y.resize(n);
		ytest.resize(n);
		for(nprime=0;nprime<n;nprime++){
			for(m=0;m<n;m++){
				A(nprime,m)=0.0;
				for(mprime=0;mprime<=nprime;mprime++){
					A(nprime,m)+=I(m+mprime+1)*a(nprime,mprime);
				}
			}
		}
		for(nprime=0;nprime<n;nprime++){
			y(nprime)=0.0;
			for(mprime=0;mprime<=nprime;mprime++)
				y(nprime)+=I(n+mprime+1)*a(nprime,mprime);
		}
		arma::solve(x,A,y);
		for(m=0;m<n;m++)
			a(n,m)=-x(m);
		norm=0.0;
		for(m=0;m<=n;m++){
			for(mprime=0;mprime<=n;mprime++){
				norm+=a(n,m)*a(n,mprime)*I(m+mprime+1);
			}
		}
		if(norm<0.0){
			printf("norm(%d)=%g\n",n,norm);
			printf("negative norm, try making ng smaller\n");
			exit(1);
		}
		x=x/sqrt(norm);
		y=y/sqrt(norm);
		//ytest=A*x-y;
		//ytest.print("ytest:");
		for(m=0;m<=n;m++)
			a(n,m)=a(n,m)/sqrt(norm);
	}
	seed=1234;
	rng=mt19937(seed);
	uniform_dist=uniform_real_distribution<double>(0,1);
	// to reset seed, xxx.invcoshcalc.rng=mt19937(newseed);
}

double CInvCoshCalc::GetRandomXFromInvCosh(){
	// returns random number from dist (2/pi)/cosh(x)
	return asinh(tan(0.5*PI*uniform_dist(rng)));
}

double CInvCoshCalc::GetG(int n,double x){
	double G,coshx;
	int m;
	coshx=cosh(x);
	G=0.0;
	for(m=0;m<=n;m++){
		G+=a(n,m)*pow(coshx,-m-1);
	}
	return G;
}

