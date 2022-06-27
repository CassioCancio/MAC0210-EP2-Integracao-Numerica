#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int N; 
double * X, * F;

void imprimirPolinomio(double * coef){
    // Imprime o polinômio de forma mais visível.
    printf("P(x) = ");
    for (int i = N-1; i >= 0; i--){
        if(coef[i] > 0) printf("+ ");
        else if(coef[i] == 0) continue;
        printf("%.8g*x^%d ",coef[i],i);
    } printf("\n\n");
}


double * polinomioInterpolador(){
    // Interpola os pontos dados com o método de Lagrange

    // Coeficientes das variáveis
    double * coeficientes = (double*) malloc(N*sizeof(double));
    
    // Limpando memória
    for (int i = 0; i < N; i++) coeficientes[i] = 0;
    
    // Para cada L_i
    for (int i = 0; i < N; i++){
        double denominador = 1;
        double lagrange[N], auxiliar[N];

        // Limpando memória
        for (int j = 0; j < N; j++) lagrange[j] = 0;

        // Inicializando o polinômio
        lagrange[0] = 1;

        // Para cada (x-x_j)*(x*x_j+1)...
        for (int j = 0; j < N; j++){
            if(i == j) continue;

            // Constroi denominador de L_i
            denominador *= (X[i] - X[j]); 

            // Faz o polinômio L_i*x
            for (int k = 0; k < N-1; k++) auxiliar[k+1] = lagrange[k];

            // Faz o polinômio L_i*x_j 
            for (int k = 0; k < N; k++) lagrange[k] *= -X[j];

            // Soma os dois
            for (int k = 1; k < N; k++) lagrange[k] += auxiliar[k];
        }

        // Soma os L_i aos coeficientes finais
        for (int j = 0; j < N; j++) coeficientes[j] += (lagrange[j]*F[i])/denominador;
    }

    return coeficientes;
}

double areaTrapezio(){
    // Calcula a área pela regra do trapézio composto
    double area = 0;
    for (int i = 0; i < N-1; i++)
        area += (F[i]+F[i+1])*(X[i+1]-X[i])/2;
    return area;
}

double areaSimpson(){
    // Calcula a área pela regra de Simpson composto
    double area = 0;
    for (int i = 0; i < N-2; i+=2){
        area += (X[i+2]-X[i])/6 * (F[i] + 4*F[i+1] + F[i+2]);
    }
    return area;
}

int main(){
    // 1 - digite N, o número de entradas fornecidas;
    // 2 - digite os N valores de X
    // 3 - digite os N valores de F(x)

    scanf("%d",&N);

    X = (double*) malloc(N*sizeof(double));
    F = (double*) malloc(N*sizeof(double));

    for (int i = 0; i < N; i++) scanf("%lf",&X[i]);
    for (int i = 0; i < N; i++) scanf("%lf",&F[i]);

    double * coef = polinomioInterpolador();
    double trapezio = areaTrapezio();
    double simpson = areaSimpson();
    
    printf("INTERPOLADOR:\n");
    imprimirPolinomio(coef);

    printf("ÁREAS:\n");
    printf("Trapézio composto: %lf\n", trapezio);
    printf("Simpson composto: %lf\n", simpson);
}