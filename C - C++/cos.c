#include <stdio.h>
#include <math.h>

double fat(int n) {
    if(n == 1){
        return 1;
    }

    return n * fat(n - 1);
}

double cosen(int x, int n) {
    double res = 0.0;
    int exp = 2;
    int sinal = 1;

    for (int i = 1; i <= n; i++) {
        res += sinal * pow(x, exp) / fat(exp);
        sinal *= -1;
        // if (i % 2 == 0) {
        //     res += pow(x, exp) / fat(exp);
        // } else {
        //     res -= pow(x, exp) / fat(exp);
        // }

        exp += 2;
    }

    return res;
}

int main() {
    double x = 270 * M_PI / 180;
    double resultado = cosen(x, 100);
    printf("Cosseno de %f graus: %f\n", x, resultado);

    return 0;
}