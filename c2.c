#include "c2.h"

// First order Coulex E2 excitation based on Rev. Mod. Phys. 28 (1956) 432,
// mostly page 457

void initialSetup() {

  dcmin = 0.; // minimum allowed distance of closest approach

  // 18 May 2016
  // ksi values 1.2-2.0 added

  // Table II.8
  ksiArray.push_back(0.0);
  ksiArray.push_back(0.1);
  ksiArray.push_back(0.2);
  ksiArray.push_back(0.3);
  ksiArray.push_back(0.4);
  ksiArray.push_back(0.5);
  ksiArray.push_back(0.6);
  ksiArray.push_back(0.7);
  ksiArray.push_back(0.8);
  ksiArray.push_back(0.9);
  ksiArray.push_back(1.0);
  ksiArray.push_back(1.2);
  ksiArray.push_back(1.4);
  ksiArray.push_back(1.6);
  ksiArray.push_back(1.8);
  ksiArray.push_back(2.0);

  thetaArray.push_back(0.);
  thetaArray.push_back(10.);
  thetaArray.push_back(20.);
  thetaArray.push_back(30.);
  thetaArray.push_back(40.);
  thetaArray.push_back(50.);
  thetaArray.push_back(60.);
  thetaArray.push_back(70.);
  thetaArray.push_back(80.);
  thetaArray.push_back(90.);
  thetaArray.push_back(100.);
  thetaArray.push_back(110.);
  thetaArray.push_back(120.);
  thetaArray.push_back(130.);
  thetaArray.push_back(140.);
  thetaArray.push_back(150.);
  thetaArray.push_back(160.);
  thetaArray.push_back(170.);
  thetaArray.push_back(180.);

  th000.push_back(1.676E-01);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);
  th000.push_back(0.000E+00);

  th010.push_back(1.385E-01);
  th010.push_back(1.403E-01);
  th010.push_back(5.210E-02);
  th010.push_back(1.110E-02);
  th010.push_back(1.788E-03);
  th010.push_back(2.443E-04);
  th010.push_back(2.996E-05);
  th010.push_back(3.403E-06);
  th010.push_back(3.652E-07);
  th010.push_back(3.750E-08);
  th010.push_back(3.719E-09);
  th010.push_back(3.374E-11);
  th010.push_back(2.824E-13);
  th010.push_back(2.227E-15);
  th010.push_back(1.679E-17);
  th010.push_back(1.220E-19);

  th020.push_back(1.178E-01);
  th020.push_back(1.286E-01);
  th020.push_back(1.016E-01);
  th020.push_back(5.780E-02);
  th020.push_back(2.678E-02);
  th020.push_back(1.085E-02);
  th020.push_back(4.005E-03);
  th020.push_back(1.382E-03);
  th020.push_back(4.531E-04);
  th020.push_back(1.427E-04);
  th020.push_back(4.351E-05);
  th020.push_back(3.752E-06);
  th020.push_back(2.998E-07);
  th020.push_back(2.265E-08);
  th020.push_back(1.638E-09);
  th020.push_back(1.144E-10);

  th030.push_back(1.027E-01);
  th030.push_back(1.087E-01);
  th030.push_back(9.810E-02);
  th030.push_back(7.160E-02);
  th030.push_back(4.474E-02);
  th030.push_back(2.508E-02);
  th030.push_back(1.300E-02);
  th030.push_back(6.350E-03);
  th030.push_back(2.960E-03);
  th030.push_back(1.331E-03);
  th030.push_back(5.810E-04);
  th030.push_back(1.032E-04);
  th030.push_back(1.708E-05);
  th030.push_back(2.680E-06);
  th030.push_back(4.032E-07);
  th030.push_back(5.870E-08);

  th040.push_back(9.160E-02);
  th040.push_back(9.430E-02);
  th040.push_back(8.730E-02);
  th040.push_back(6.940E-02);
  th040.push_back(4.895E-02);
  th040.push_back(3.154E-02);
  th040.push_back(1.899E-02);
  th040.push_back(1.085E-02);
  th040.push_back(5.950E-03);
  th040.push_back(3.159E-03);
  th040.push_back(1.631E-03);
  th040.push_back(4.076E-04);
  th040.push_back(9.530E-05);
  th040.push_back(2.118E-05);
  th040.push_back(4.523E-06);
  th040.push_back(9.360E-07);

  th050.push_back(8.320E-02);
  th050.push_back(8.370E-02);
  th050.push_back(7.720E-02);
  th050.push_back(6.340E-02);
  th050.push_back(4.715E-02);
  th050.push_back(3.251E-02);
  th050.push_back(2.113E-02);
  th050.push_back(1.311E-02);
  th050.push_back(7.840E-03);
  th050.push_back(4.553E-03);
  th050.push_back(2.577E-03);
  th050.push_back(7.770E-04);
  th050.push_back(2.203E-04);
  th050.push_back(5.950E-05);
  th050.push_back(1.549E-05);
  th050.push_back(3.913E-06);

  th060.push_back(7.680E-02);
  th060.push_back(7.580E-02);
  th060.push_back(6.900E-02);
  th060.push_back(5.700E-02);
  th060.push_back(4.341E-02);
  th060.push_back(3.095E-02);
  th060.push_back(2.095E-02);
  th060.push_back(1.361E-02);
  th060.push_back(8.550E-03);
  th060.push_back(5.230E-03);
  th060.push_back(3.123E-03);
  th060.push_back(1.054E-03);
  th060.push_back(3.356E-04);
  th060.push_back(1.022E-04);
  th060.push_back(3.001E-05);
  th060.push_back(8.570E-06);

  th070.push_back(7.190E-02);
  th070.push_back(6.970E-02);
  th070.push_back(6.240E-02);
  th070.push_back(5.130E-02);
  th070.push_back(3.932E-02);
  th070.push_back(2.846E-02);
  th070.push_back(1.967E-02);
  th070.push_back(1.311E-02);
  th070.push_back(8.470E-03);
  th070.push_back(5.340E-03);
  th070.push_back(3.294E-03);
  th070.push_back(1.191E-03);
  th070.push_back(4.079E-04);
  th070.push_back(1.339E-04);
  th070.push_back(4.249E-05);
  th070.push_back(1.312E-05);

  th080.push_back(6.800E-02);
  th080.push_back(6.490E-02);
  th080.push_back(5.700E-02);
  th080.push_back(4.643E-02);
  th080.push_back(3.549E-02);
  th080.push_back(2.579E-02);
  th080.push_back(1.798E-02);
  th080.push_back(1.213E-02);
  th080.push_back(7.960E-03);
  th080.push_back(5.100E-03);
  th080.push_back(3.211E-03);
  th080.push_back(1.211E-03);
  th080.push_back(4.338E-04);
  th080.push_back(1.494E-04);
  th080.push_back(4.985E-05);
  th080.push_back(1.621E-05);

  th090.push_back(6.500E-02);
  th090.push_back(6.120E-02);
  th090.push_back(5.270E-02);
  th090.push_back(4.234E-02);
  th090.push_back(3.210E-02);
  th090.push_back(2.326E-02);
  th090.push_back(1.624E-02);
  th090.push_back(1.100E-02);
  th090.push_back(7.270E-03);
  th090.push_back(4.700E-03);
  th090.push_back(2.986E-03);
  th090.push_back(1.153E-03);
  th090.push_back(4.245E-04);
  th090.push_back(1.506E-04);
  th090.push_back(5.190E-05);
  th090.push_back(1.743E-05);

  th100.push_back(6.270E-02);
  th100.push_back(5.830E-02);
  th100.push_back(4.930E-02);
  th100.push_back(3.895E-02);
  th100.push_back(2.920E-02);
  th100.push_back(2.100E-02);
  th100.push_back(1.460E-02);
  th100.push_back(9.880E-03);
  th100.push_back(6.530E-03);
  th100.push_back(4.232E-03);
  th100.push_back(2.699E-03);
  th100.push_back(1.054E-03);
  th100.push_back(3.936E-04);
  th100.push_back(1.420E-04);
  th100.push_back(4.983E-05);
  th100.push_back(1.708E-05);

  th110.push_back(6.080E-02);
  th110.push_back(5.590E-02);
  th110.push_back(4.651E-02);
  th110.push_back(3.617E-02);
  th110.push_back(2.676E-02);
  th110.push_back(1.905E-02);
  th110.push_back(1.314E-02);
  th110.push_back(8.840E-03);
  th110.push_back(5.820E-03);
  th110.push_back(3.769E-03);
  th110.push_back(2.402E-03);
  th110.push_back(9.390E-04);
  th110.push_back(3.526E-04);
  th110.push_back(1.282E-04);
  th110.push_back(4.538E-05);
  th110.push_back(1.572E-05);

  th120.push_back(5.930E-02);
  th120.push_back(5.410E-02);
  th120.push_back(4.428E-02);
  th120.push_back(3.391E-02);
  th120.push_back(2.475E-02);
  th120.push_back(1.741E-02);
  th120.push_back(1.190E-02);
  th120.push_back(7.940E-03);
  th120.push_back(5.200E-03);
  th120.push_back(3.345E-03);
  th120.push_back(2.123E-03);
  th120.push_back(8.260E-04);
  th120.push_back(3.904E-04);
  th120.push_back(1.125E-04);
  th120.push_back(3.990E-05);
  th120.push_back(1.387E-05);

  th130.push_back(5.820E-02);
  th130.push_back(5.260E-02);
  th130.push_back(4.252E-02);
  th130.push_back(3.210E-02);
  th130.push_back(2.311E-02);
  th130.push_back(1.606E-02);
  th130.push_back(1.086E-02);
  th130.push_back(7.180E-03);
  th130.push_back(4.660E-03);
  th130.push_back(2.979E-03);
  th130.push_back(1.879E-03);
  th130.push_back(7.240E-04);
  th130.push_back(2.691E-04);
  th130.push_back(9.730E-05);
  th130.push_back(3.439E-05);
  th130.push_back(1.193E-05);

  th140.push_back(5.730E-02);
  th140.push_back(5.150E-02);
  th140.push_back(4.115E-02);
  th140.push_back(3.068E-02);
  th140.push_back(2.182E-02);
  th140.push_back(1.499E-02);
  th140.push_back(1.003E-02);
  th140.push_back(6.570E-03);
  th140.push_back(4.224E-03);
  th140.push_back(2.678E-03);
  th140.push_back(1.677E-03);
  th140.push_back(6.370E-04);
  th140.push_back(2.344E-04);
  th140.push_back(8.400E-05);
  th140.push_back(2.947E-05);
  th140.push_back(1.016E-05);

  th150.push_back(5.660E-02);
  th150.push_back(5.070E-02);
  th150.push_back(4.013E-02);
  th150.push_back(2.961E-02);
  th150.push_back(2.085E-02);
  th150.push_back(1.418E-02);
  th150.push_back(9.390E-03);
  th150.push_back(6.090E-03);
  th150.push_back(3.888E-03);
  th150.push_back(2.445E-03);
  th150.push_back(1.519E-03);
  th150.push_back(5.690E-04);
  th150.push_back(2.069E-04);
  th150.push_back(7.330E-05);
  th150.push_back(2.546E-05);
  th150.push_back(8.700E-06);

  th160.push_back(5.620E-02);
  th160.push_back(5.010E-02);
  th160.push_back(3.942E-02);
  th160.push_back(2.887E-02);
  th160.push_back(2.017E-02);
  th160.push_back(1.361E-02);
  th160.push_back(8.950E-03);
  th160.push_back(5.760E-03);
  th160.push_back(3.650E-03);
  th160.push_back(2.280E-03);
  th160.push_back(1.407E-03);
  th160.push_back(5.210E-04);
  th160.push_back(1.870E-04);
  th160.push_back(6.560E-05);
  th160.push_back(2.254E-05);
  th160.push_back(7.630E-06);

  th170.push_back(5.590E-02);
  th170.push_back(4.980E-02);
  th170.push_back(3.900E-02);
  th170.push_back(2.844E-02);
  th170.push_back(1.977E-02);
  th170.push_back(1.328E-02);
  th170.push_back(8.690E-03);
  th170.push_back(5.570E-03);
  th170.push_back(3.509E-03);
  th170.push_back(2.181E-03);
  th170.push_back(1.340E-03);
  th170.push_back(4.918E-04);
  th170.push_back(1.751E-04);
  th170.push_back(6.090E-05);
  th170.push_back(2.078E-05);
  th170.push_back(6.980E-06);

  th180.push_back(5.580E-02);
  th180.push_back(4.969E-02);
  th180.push_back(3.887E-02);
  th180.push_back(2.829E-02);
  th180.push_back(1.963E-02);
  th180.push_back(1.316E-02);
  th180.push_back(8.600E-03);
  th180.push_back(5.500E-03);
  th180.push_back(3.462E-03);
  th180.push_back(2.148E-03);
  th180.push_back(1.318E-03);
  th180.push_back(4.822E-04);
  th180.push_back(1.712E-04);
  th180.push_back(5.930E-05);
  th180.push_back(2.019E-05);
  th180.push_back(6.760E-06);

  // Large angle differential cross section
  // "E4ish" shape
  // 0.5*[1-cos(theta)]
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);
  // th000.push_back(0.000E+00);

  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);
  // th010.push_back(7.596E-03);

  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);
  // th020.push_back(3.015E-02);

  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);
  // th030.push_back(6.699E-02);

  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);
  // th040.push_back(1.170E-01);

  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);
  // th050.push_back(1.786E-01);

  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);
  // th060.push_back(2.500E-01);

  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);
  // th070.push_back(3.290E-01);

  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);
  // th080.push_back(4.132E-01);

  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);
  // th090.push_back(5.000E-01);

  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);
  // th100.push_back(5.868E-01);

  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);
  // th110.push_back(6.710E-01);

  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);
  // th120.push_back(7.500E-01);

  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);
  // th130.push_back(8.214E-01);

  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);
  // th140.push_back(8.830E-01);

  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);
  // th150.push_back(9.330E-01);

  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);
  // th160.push_back(9.698E-01);

  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);
  // th170.push_back(9.924E-01);

  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);
  // th180.push_back(1.000E+00);

  fthksi.push_back(th000);
  fthksi.push_back(th010);
  fthksi.push_back(th020);
  fthksi.push_back(th030);
  fthksi.push_back(th040);
  fthksi.push_back(th050);
  fthksi.push_back(th060);
  fthksi.push_back(th070);
  fthksi.push_back(th080);
  fthksi.push_back(th090);
  fthksi.push_back(th100);
  fthksi.push_back(th110);
  fthksi.push_back(th120);
  fthksi.push_back(th130);
  fthksi.push_back(th140);
  fthksi.push_back(th150);
  fthksi.push_back(th160);
  fthksi.push_back(th170);
  fthksi.push_back(th180);
}

//proj=1 if the angle is for the projectile, 0 for the target recoil
double CMToLabAngleDeg(double CMAngleDeg, int proj){
  double v = 0.;
  double ang=0.;
  double pcm = sqrt((ecm-Eex)*2.0/(1/(A1*AMUMEV) + 1/(A2*AMUMEV))); //momentum of each particle in the centre of mass frame (MeV/c), corrected for excitation energy
  if(proj==1){
    //projectile
    v = pcm/(A1*AMUMEV);
  }else{
    //target recoil
    v = pcm/(A2*AMUMEV);
  }
  //printf("ang: %f, pcm: %f, v: %f, vcm:%f\n",CMAngleDeg,pcm,v,vcm);
  ang = atan2(sin(CMAngleDeg*DEG2RAD), cos(CMAngleDeg*DEG2RAD) + (vcm / v)) / DEG2RAD;
  if(ang<0.)
    ang*=-1;
  return ang;
}

void calculateCrossSection() {

  // double      tauIn; // not currently used
  double theta;
  //double Eprime;
  //double t, tbar;
  //double phi;
  double dc; // distance of closest approach in fm
  double c, ce;

  //Eprime = KE - (A1 + A2) / A2 * Eex; // internal energy of the center of mass 1/2*mu*Vrel^2
  //tbar = sqrt(KE / Eprime);
  //t = A1 / A2 * tbar;

  // clear vectors needed
  thefth.clear();
  thbin.clear();
  fbin.clear();
  thlookup.clear();

  
  // printf("KEin %.4f theta %.4f ndc %.4f\n",KE,theta,dc);
  // getc(stdin);

  // std::cout<<"f "<<dfdOmega(ksi,theta)<<" face
  // "<<dfofTheta(theta,&thefth)<<std::endl; getc(stdin);

  DEp = (1. + A1 / A2) * Eex; // Eq. II C.4 and explanation below (CM internal
                             // energy 1/2*mu*Vrel^2)
  EprimeFace = KE - DEp;
  ksiFace = GetKsi(KE);
  c = 4.819 * A1 / Z1 / Z1 / (1. + A1 / A2) /
      (1. + A1 / A2); // Eq. II C.17 the case of E2 with Z1 instead of Z2, see
                      // Sec. II A.6
  ce = c * (KE - DEp) * BE2; // Part of Eq. II C.15

  Calcfthksi(ksiFace, &thefth);
  // std::cout<<"Printing thefth for ksi "<<ksiFace<<std::endl;
  // std::vector<double>::iterator it;
  // it=thefth.begin();
  // for(;it<thefth.end();it++)
  //   std::cout<<(*it)<<std::endl;
  // getc(stdin);

  SetupLookupGenerator();

  theta = GetTheta(); // in the CM
  // printf("theta = %.2f\n",theta);

  dc = 0.5 * AHC * Z1 * Z2 / KE * (1 + A1 / A2) *
       (1 + 1 / sin(0.5 * theta * DEG2RAD));

  sigmaFace = ce * thef; // Full Eq. II C.15, cross section on the target face in barns


  printf("\nCALCULATION RESULTS\n");
  printf("-------------------\n\n");
  //printf("ksi=%f, ce=%f, thef=%f\n",ksiFace,ce,thef);

  printf("ksi : %6.3f\n\n",ksiFace);

  printf("Scattered particle       Scattered particle     Differential x-sec         x-sec into\n");
  printf("    CM angle (deg)          lab angle (deg)     at bin centre (b)             bin (b)\n");
  for (int i=0;i<=17;i++){
    double lowAngLab = CMToLabAngleDeg(i*10.0,projEx);
    double highAngLab = CMToLabAngleDeg((i+1)*10.0,projEx);

    double solidAng = (cos(i*10.0*DEG2RAD) - cos((i+1)*10.0*DEG2RAD))*TWOPI;
    printf("     %3i - %3i deg      %6.2f - %6.2f deg             %10.5f       %10.5f b\n", i*10, (i+1)*10, lowAngLab, highAngLab, ce * dfdOmega(ksiFace, (i+0.5)*10.0), ce * dfdOmega(ksiFace, (i+0.5)*10.0) * solidAng);
  }

  printf("\n");
  printf("Total cross section                  : %10.4f b\n", sigmaFace);
  printf("Minimum distance of closest approach : %10.4f fm\n",dc);
}

void SetupLookupGenerator() {
  unsigned i;
  int k;
  double F, slope;
  std::vector<int> limits;

  for (i = 1; i < thetaArray.size(); i++) {
    thbin.push_back(0.5 * (thetaArray[i - 1] + thetaArray[i]));
    F = thefth[i - 1] * cos(thetaArray[i - 1] * DEG2RAD);
    F -= thefth[i] * cos(thetaArray[i] * DEG2RAD);
    slope = thefth[i] - thefth[i - 1];
    slope /= (thetaArray[i] - thetaArray[i - 1]);
    slope /= DEG2RAD;
    F += slope *
         (sin(thetaArray[i] * DEG2RAD) - sin(thetaArray[i - 1] * DEG2RAD));
    F *= TWOPI;
    fbin.push_back(F);
  }
  thef = 0;
  for (i = 0; i < thbin.size(); i++)
    thef += fbin[i];
  limits.push_back(0);
  F = 0.;
  for (i = 0; i < thbin.size(); i++) {
    F += fbin[i];
    limits.push_back(int(10000. * F / thef));
  }

  for (i = 1; i < limits.size(); i++)
    for (k = limits[i - 1]; k < limits[i]; k++)
      thlookup.push_back(i - 1);
}


double GetKsi(double KE) {
  // double vi,vf;
  double zeta, sqz;
  // double a;
  double eti, etf, nu, ksi;
  // double etit,nut,ksit;
  // vi=sqrt(2.*KE/A1/XAMU);           // Eq. II C.2 truly v/c not v, this is
  // the relative speed before the colision
  // same in the lab and in the centre of mass - not currently used
  zeta = DEp / KE; // Eq. II C.5 dimensionless
  sqz = sqrt(1 - zeta);
  // vf=vi*sqz;                        // Eq. II C.6 v/c not v, relative speed
  // after the collision, to see use the target-fixed coordinate frame - not
  // currently used a=0.7199*(1.+A1/A2)*Z1*Z2/KE/sqz; // Eq. II C.7 in fm -
  // not currently used
  eti = 0.5 * Z1 * Z2 * sqrt(A1 / 10.008 / KE);  // Eq. II C.8
  etf = eti / sqz;                               // Eq. II C.9
  nu = 2. * sqrt(1 / eti / eti - 1 / etf / etf); // Eq. II C.10 top
  // nut=4/Z1/Z2*sqrt(10.008*DEp/A1); // Eq. II C.10 bottom, equal to prev.
  // line etit=2*sqrt(zeta)/nu;            // Eq. II C.11
  ksi = 2 / nu * sqrt(zeta) * (1 / sqz - 1); // Eq. II C.12
  // ksit=0.079051*Z1*Z2*sqrt(A1)*DEp/(KE-0.5*DEp)/sqrt(KE-0.5*DEp)*(1+0.15625*DEp*DEp/KE/KE);
  // // Eq II C.13 - unused so far

  // printf("E %8.4f [MeV] beta_i %8.4f [%%] %8.4f [%%] a %8.4f
  // [fm]\n",KE,vi*100,vf*100,a); printf("eta_i %8.4f eta_f %8.4f\n",eti,etf);
  // printf("eta_i %8.4f eta_i %8.4f\n",eti,etit);
  // printf("nu    %8.4f [%%] nu_t  %8.4f [%%]\n",nu*100,nut*100);
  // printf("ksi   %8.4f\n",ksi);

  return ksi;
}

double GetTheta() {
  // returns the scattering angle in the CM according to Tab. II.8 p. 464
  double xeps = 0.0001;
  int bin;
  double th1, th2, f1, f2, F, r, x1, x2, y1, y2, y;
  double th;
  // first look up the bin
  bin = thlookup[(int)(doubleRand() * thlookup.size())];
  th1 = thetaArray[bin];
  th2 = thetaArray[bin + 1];
  f1 = thefth[bin];
  f2 = thefth[bin + 1];

  F = fbin[bin] / TWOPI;
  r = doubleRand();

  x1 = th1;
  y1 = FineThetaFunction(x1, th1, th2, f1, f2, F, r);
  if (fabs(y1) < xeps)
    return th1;

  x2 = th2;
  y2 = FineThetaFunction(x2, th1, th2, f1, f2, F, r);
  if (fabs(y2) < xeps)
    return th2;

  th = thbin[bin];
  while (fabs(y = FineThetaFunction(th, th1, th2, f1, f2, F, r)) > xeps) {
    if (y < 0) {
      x1 = th;
      y1 = y;
    }
    if (y >= 0) {
      x2 = th;
      y2 = y;
    }
    th = x1 - y1 * (x2 - x1) / (y2 - y1);
  }

  return th;
}

double FineThetaFunction(double th, double th1, double th2, double f1,
                         double f2, double F, double r) {
  double f, g, dth, df;
  dth = th2 - th1;
  df = f2 - f1;
  f = f1 + (th - th1) * df / dth;
  g = f1 * cos(th1 * DEG2RAD) - f * cos(th * DEG2RAD) +
      df / dth / DEG2RAD * (sin(th * DEG2RAD) - sin(th1 * DEG2RAD));
  return g / F - r;
}

double dfdOmega(double ksi, double theta) {
  /***** ALERT: nasty memory leak!! *****/
  /*
     vector memory never deallocated
     when you leave scope!
  */
  // std::vector<double>* fth=new std::vector<double>;
  // Calcfthksi(ksi,fth);
  // return dfofTheta(theta,fth);

  std::vector<double> *fth = new std::vector<double>;
  double dfT = 0.;
  Calcfthksi(ksi, fth);
  dfT = dfofTheta(theta, fth);
  delete fth; // free the memory!
  return dfT;
}
double dfofTheta(double theta, std::vector<double> *fth) {
  unsigned i;
  double x1, y1, x2, y2, x, y;

  // std::cout<<"Printing thefth"<<std::endl;
  // std::vector<double>::iterator it;
  // it=fth->begin();
  // for(;it<fth->end();it++)
  //   std::cout<<(*it)<<std::endl;
  // getc(stdin);

  for (i = 1; i < thetaArray.size(); i++)
    if ((theta >= thetaArray[i - 1]) && (theta < thetaArray[i]))
      break;
  x1 = thetaArray[i - 1];
  y1 = (*fth)[i - 1];
  x2 = thetaArray[i];
  y2 = (*fth)[i];
  x = theta;
  y = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
  return y;
}

void Calcfthksi(double ksi, std::vector<double> *fth) {
  int shift;
  double x1, x2, y1, y2, y, dx;

  if ((ksi < 0.) || (ksi > 2.)) {
    printf("ERROR: The value of ksi (%f) is outside of the currently programed range of [0:2]\n",ksi);
    exit(-1);
  }
  shift = 0;
  std::vector<double>::iterator itksi = ksiArray.begin();
  for (; itksi < ksiArray.end() - 1; itksi++) {
    if ((ksi >= (*itksi)) && (ksi <= (*(itksi + 1))))
      break;
    shift++;
  }
  x1 = *itksi;
  x2 = *(itksi + 1);
  dx = x2 - x1;

  std::vector<double>::iterator it;
  std::vector<std::vector<double> >::iterator itfthksi = fthksi.begin();
  for (; itfthksi < fthksi.end(); itfthksi++) {
    it = (*itfthksi).begin();
    y1 = *(it + shift);
    y2 = *(it + shift + 1);
    y = y1 + (y2 - y1) / dx * (ksi - x1);
    fth->push_back(y);
  }

}

int main(int argc, char *argv[]) {

  if (argc == 1) {
    printf("\nc2\n");
    printf("Coulex Calculator -- calculates reaction cross-sections\nCurrently only E2 excitation is implemented.\n\n");
    printf("c2 -Ap VALUE -Zp VALUE -At VALUE -Zt VALUE -Ep VALUE -mode VALUE -Eex VALUE -tau VALUE\n");
    printf("   Ap: Projectile mass number (eg. 20 for 20Mg)\n");
    printf("   Zp: Projectile atomic number (eg. 12 for 20Mg)\n");
    printf("   At: Target mass number (eg. 12 for 12C)\n");
    printf("   Zt: Target atomic number (eg. 6 for 12C)\n");
    printf("   Ep: Projectile lab energy (in MeV)\n");
    printf("   mode: Excitation energy mode (0 = target, 1 = projectile excitation)\n");
    printf("   Eex: Excitation energy (in MeV)\n");
    printf("   tau: Lifetime of excited state (in ps)\n");
    exit(-1);
  }

  //initialize parameter values
  A1=0;
  Z1=0;
  A2=0;
  Z2=0;
  KE=0.;
  projEx=0;
  Eex=0.;
  Tau=0.;


  int i;
  for(i=0;i<(argc-1);i++){
    if(strcmp(argv[i],"-Ap")==0){
      A1=atoi(argv[i+1]);
    }else if(strcmp(argv[i],"-Zp")==0){
      Z1=atoi(argv[i+1]);
    }else if(strcmp(argv[i],"-At")==0){
      A2=atoi(argv[i+1]);
    }else if(strcmp(argv[i],"-Zt")==0){
      Z2=atoi(argv[i+1]);
    }else if(strcmp(argv[i],"-Ep")==0){
      KE=atof(argv[i+1]);
    }else if(strcmp(argv[i],"-mode")==0){
      if(atoi(argv[i+1])==0){
        projEx=0;
      }else{
        projEx=1;
      }
    }else if(strcmp(argv[i],"-Eex")==0){
      Eex=atof(argv[i+1]);
    }else if(strcmp(argv[i],"-tau")==0){
      Tau=atof(argv[i+1]);
    }

  }

  //check all values
  if (Eex <= 0.) {
    printf("ERROR: Excitation energy must be a positive value (specify using -Eex VALUE).\n");
    exit(0);
  }
  if (KE <= 0.) {
    printf("ERROR: Projectile (beam) energy must be a positive value (specify using -Ep VALUE).\n");
    exit(0);
  }
  if (A1 <= 0.) {
    printf("ERROR: Projectile mass number must be a positive value (specify using -Ap VALUE).\n");
    exit(0);
  }
  if (Z1 <= 0.) {
    printf("ERROR: Projectile atomic number must be a positive value (specify using -Zp VALUE).\n");
    exit(0);
  }
  if (A2 <= 0.) {
    printf("ERROR: Target mass number must be a positive value (specify using -At VALUE).\n");
    exit(0);
  }
  if (Z2 <= 0.) {
    printf("ERROR: Target atomic number must be a positive value (specify using -Zt VALUE).\n");
    exit(0);
  }
  if(Z1 > A1){
    printf("ERROR: Projectile atomic number (-Zp) cannot be larger than it's mass number (-Ap).\n");
    exit(0);
  }
  if(Z2 > A2){
    printf("ERROR: Target atomic number (-Zt) cannot be larger than it's mass number (-At).\n");
    exit(0);
  }

  if (projEx) {
    printf("Using projectile excitation.\n");
    if (Tau > 0){
      BE2 = 5. * 0.082 / Tau / pow(Eex, 5.); // from Eq. II A.56 multiplied by ahc (a = fine struct. const.)
    }else {
      printf("Projectile de-excitation lifetime must be a positive value (specify using -tau VALUE).\n");
      exit(0);
    }
  } else {
    printf("Using target recoil excitation.\n");
    if (Tau > 0){
      BE2 = 5. * 0.082 / Tau / pow(Eex, 5.); // from Eq. II A.56 multiplied by ahc (a = fine struct. const.)
    }else {
      printf("Target recoil de-excitation lifetime must be a positive value (specify using -tau VALUE).\n");
      exit(0);
    }
  }

  //centre-of-mass calculation (classical)
  vlab = sqrt(2.0*A1*AMUMEV*KE)/(A1*AMUMEV); //projectile lab speed in units of c
  vcm = sqrt(2.0*A1*AMUMEV*KE)/((A1+A2)*AMUMEV); //in units of c
  ecm = 0.5 * ( (A1*AMUMEV*(vlab-vcm)*(vlab-vcm)) + (A2*AMUMEV*vcm*vcm) );
  barrier=1.44*Z1*Z2/(1.2*(pow(A1,1/3.) + pow(A2,1/3.) ) + 5);

  printf("Projectile Energy                   : %6.2f MeV\n", KE);
  printf("Projectile A                        : %6d\n", (int)A1);
  printf("Projectile Z                        : %6d\n", (int)Z1);
  if (projEx) {
    printf("Projectile excitation energy        : %6.3f MeV\n", Eex);
    printf("Projectile deexcitation lifetime    : %6.2f ps\n", Tau);
    printf("Projectile B(E2,0+=>2+)             : %6.2f e^2b^2\n", BE2);
  }
  printf("Target recoil A                     : %6d\n", (int)A2);
  printf("Target recoil Z                     : %6d\n", (int)Z2);
  if (!projEx) {
    printf("Target recoil excitation energy     : %6.3f MeV\n", Eex);
    printf("Target recoil deexcitation lifetime : %6.2f ps\n", Tau);
    printf("Target recoil B(E2,0+=>2+)          : %6.2f e^2b^2\n", BE2);
  }

  printf("Inital projectile velocity (lab)    : %6.3f c\n",vlab);
  printf("Centre-of-mass velocity             : %6.3f c\n",vcm);
  printf("Centre-of-mass energy               : %6.2f MeV\n",ecm);
  printf("Coulomb barrier energy              : %6.2f MeV\n",barrier);
  if(ecm < Eex){
    printf("ERROR: Not enough energy in the centre of mass (%5.3f MeV) to excite to the specified excitation energy (%5.3f MeV).\n",ecm,Eex);
    exit(0);
  }
  

  initialSetup();
  calculateCrossSection();
}