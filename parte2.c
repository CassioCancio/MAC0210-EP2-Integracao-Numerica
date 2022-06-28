#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}
double mct1(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        ans+= sin(r); 
    }
    return ans/n;
}
double mct2(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        double x= 4*r+3;
        ans+= x*x*x*4;
    }
    return ans/n;
}

double mct3(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        double x = r*RAND_MAX;
        ans+= exp(-x)*RAND_MAX; 
    }
    return ans/n;
}
double pi(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    int points = 0;
    for(int i = 0;i<n;i++){
        double x = randfrom(a,b);
        double y = randfrom(a,b);
        if(x*x+y*y<=1){
            ans+=1;
        }
    }
    return 4*ans/n;
}

int main() {
   // printf() displays the string inside quotation
   printf("Hello, World!");
   double t = sin(0);
   double k1 = mct1(0,1,10000000);
   double k2 = mct2(0,1,10000000);
   double k3 = mct3(0,1,10000000);
   double p = pi(0,1,10000000);
   return 0;
}