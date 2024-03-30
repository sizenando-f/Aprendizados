#include <stdio.h>
#include <math.h>

double fat(int n) {
    if(n == 1){
        return 1;
    }

    return n * fat(n - 1);
}

double cosen(int dg, int n) {
    double res = 1.0;
    int exp = 2;
    double x = dg * M_PI / 180;

    if(dg == 90 || dg == 270){
        return 0.0;
    } else if(dg == 0){
        return 1.0;
    } else if(dg == 180){
        return -1.0;
    }

    if(n > 100){
        n = 100;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            res += pow(x, exp) / fat(exp);
        } else {
            res -= pow(x, exp) / fat(exp);
        }

        exp += 2;
    }

    return res;
}

int main() {
    int x, n;
    printf("Insira o grau: ");
    scanf("%d", &x);
    printf("Insira o valor de N: ");
    scanf("%d", &n);

    double resultado = cosen(x, n);

    printf("Cosseno de %d graus: %f\n", x, resultado);

    return 0;
}