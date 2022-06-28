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
double monte_carlo_SIN(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        double u = (r-a)/(b-a);
        double x = u*(b-a)+a;
        ans+= sin(x)*(b-a); 
    }
    return ans/n;
}
double monte_carlo_CUBICO(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        double u = (r-a)/(b-a);
        double x = u*(b-a)+a;
        ans+= x*x*x*(b-a);
    }
    return ans/n;
}

double monte_carlo_EXP(int a, int b, int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    for(int i = 0;i<n;i++){
        r = randfrom(a,b);
        double u = (r-a)/(b-a);
        double x = u*(b-a)+a;
        ans+= exp(-x)*(b-a);
    }
    return ans/n;
}
double monte_carlo_PI(int n){
    srand (time ( NULL));
    double r;
    double ans = 0;
    int points = 0;
    for(int i = 0;i<n;i++){
        double x = randfrom(0,1);
        double y = randfrom(0,1);
        if(x*x+y*y<=1){
            ans+=1;
        }
    }
    return 4*ans/n;
}

void teste1(){
    printf("Resultados 1)\n");
    double ans = 0.4863853762357;
    int point_values[5] = {10,100,1000,10000,100000};
    for(int i=0;i<5;i++){
        printf("Usando %d pontos: Valor = %lf ; Erro = %lf\n",point_values[i],monte_carlo_SIN(0,1,point_values[i]),ans-monte_carlo_SIN(0,1,point_values[i]));
    }
    printf("\n");
}
void teste2(){
    printf("Resultados 2)\n");
    double ans = 580;
    int point_values[5] = {10,100,1000,10000,100000};
    for(int i=0;i<5;i++){
        printf("Usando %d pontos: Valor = %lf ; Erro = %lf\n",point_values[i],monte_carlo_CUBICO(3, 7, point_values[i]),ans-monte_carlo_CUBICO(3, 7, point_values[i]));
    }
    printf("\n");
}
void teste3(){
    printf("Resultados 3)\n");
    double ans = 1;
    int point_values[5] = {10,100,1000,10000,100000};
    for(int i=0;i<5;i++){
        printf("Usando %d pontos: Valor = %lf ; Erro = %lf\n",point_values[i],monte_carlo_EXP(0, 10000, point_values[i]),ans-monte_carlo_EXP(0, 10000, point_values[i]));
    }
    printf("\n");
}
void testepi(){
    printf("Resultados 4)\n");
    double ans = 3.14159265359;
    int point_values[5] = {10,100,1000,10000,100000};
    for(int i=0;i<5;i++){
        printf("Usando %d pontos: Valor = %lf ; Erro = %lf\n",point_values[i],monte_carlo_PI(point_values[i]),ans-monte_carlo_PI(point_values[i]));
    }
    printf("\n");
}





int main() {
   teste1();
   teste2();
   teste3();
   testepi();
   return 0;
}
