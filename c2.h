#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>

#define AMUMEV     931.49410242
#define DEG2RAD    0.01745329252 // conversion factor from deg to radians
#define AHC        1.439964535   // fine struct const*hbar*c in MeV*fm
#define TWOPI      6.28318530718
#define PI         3.14159265359

void calculateCrossSection();
void initialSetup();
void Calcfthksi(double,std::vector<double>*);
void SetupLookupGenerator();
double GetTheta();
double FineThetaFunction(double,double,double,double,double,double,double);
double GetKsi(double);
double dfdOmega(double,double);
double dfofTheta(double,std::vector<double>*);


double doubleRand() {
  return double(rand()) / (double(RAND_MAX) + 1.0);
}

int ReactionFlag;

std::vector<double> ksiArray;
std::vector<double> thetaArray;
std::vector<double> th000;
std::vector<double> th010;
std::vector<double> th020;
std::vector<double> th030;
std::vector<double> th040;
std::vector<double> th050;
std::vector<double> th060;
std::vector<double> th070;
std::vector<double> th080;
std::vector<double> th090;
std::vector<double> th100;
std::vector<double> th110;
std::vector<double> th120;
std::vector<double> th130;
std::vector<double> th140;
std::vector<double> th150;
std::vector<double> th160;
std::vector<double> th170;
std::vector<double> th180;
std::vector<std::vector<double> > fthksi;
std::vector<double> thefth;
std::vector<double> thbin;
std::vector<double> fbin;
std::vector<int> thlookup;
double thef;
double sigmaFace;
int    sumProj;
double ksiFace;
double EprimeFace;
double A1,Z1,A2,Z2;
double Tau, BE2;
double KE; //kinetic energy of the projectile in the lab frame
int projEx;
double Eex;
double DEp;

double vlab; //lab velocity (units of c)
double vcm; //centre of mass velocity (units of c)
double ecm; //centre of mass energy (MeV)
double barrier; //Coulomb barrier (MeV)

double dcmin; // minimum allowed distance of closest approach in fm

