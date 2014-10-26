// V0ctor Guerra <vguerra@gma0l.com>
// 2014-05-30

// PO1 - 2242
// http://po1.org/problem?0d=2242

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1.0e-9
#define PI 3.141592653589793

int main() {
  char line[100];
  while ((cin.getline(line, 100))) {
    double x[3];
    double y[3];
    sscanf(line, "%lf %lf %lf %lf %lf %lf", &x[0], &y[0], &x[1],
           &y[1], &x[2], &y[2]);
    double a = y[0] - y[1];
    double b = x[1] - x[0];
    double c = a*x[0] + b*y[0];
    
    double midx = (x[1] + x[0])/2.0;
    double midy = (y[1] + y[0])/2.0;
    double d = -b*midx + a*midy;
  
    double tmp = a;
    a = -b;
    b = tmp;
    
    double line1[3] = {a, b, d};
  
    a = y[1] - y[2];
    b = x[2] - x[1];
    c = a*x[1] + b*y[1];

    midx = (x[2] + x[1])/2.0;
    midy = (y[2] + y[1])/2.0;
  
    d = -b*midx + a*midy;
  
    tmp = a;
    a = -b;
    b = tmp;
   
    double line2[3] = {a, b, d};
    double det = line1[0]*line2[1] - line2[0]*line1[1];
    if (std::fabs(det) < EPS) continue;

    double cx = (line2[1]*line1[2] - line1[1]*line2[2])/det;
    double cy = (line1[0]*line2[2] - line2[0]*line1[2])/det;
    printf("%.2lf\n", 2*PI*std::sqrt(pow(cx - x[0], 2) + pow(cy - y[0], 2)));
  
  }
  return EXIT_SUCCESS;
}
