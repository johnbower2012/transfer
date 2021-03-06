#ifndef __distributions_h__
#define __distributions_h__
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <random>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>
#include <armadillo>
#include "parametermap.h"
#include "constants.h"

using namespace std;

class CDistribution{
public:
	CDistribution();
	string parsfilename;
	parameterMap parmap;
	virtual void GenX(int ab,double &x,double &weight);
};

class CInvCoshCalc;

class CDistInvCosh : public CDistribution{
public:
	CDistInvCosh(string parsfilename);
	double *width;
	double **g;
	void GenX(int ab,double &x,double &weight);
	CInvCoshCalc *invcoshcalc;
};

class CInvCoshCalc{
public:
	int ng;
	CInvCoshCalc(int ng);
	double GetG(int n,double x);
	arma::mat a;
	arma::vec I;
	void TestOverlap();
	void CalcOverlap(int n,int nprime);
	void CalcOverlapNumerical(int n,int nprime);
	void CalcOverlapVec(int n);
	void IntegrateInvCosh(double x);
	double GetRandomXFromInvCosh();
	int seed;
	mt19937 rng;
	std::uniform_real_distribution<double> uniform_dist;
};

#endif
