#include <stdio.h>
#include <math.h>
#include <windows.h>

double fat(int n) {
    if(n == 1){
        return 1;
    }

    return n * fat(n - 1);
}

double to_radian(double x) {return (x * M_PI )/ 180;}; 

double cosen_rad(double rad, int n) {
    double res = 1.0;
    int exp = 2;

    if(rad == 1.570779 || rad == 4.712388){
        return 0.0;
    } else if(rad == 0.0 || rad == 6.283185){
        return 1.0;
    } else if(rad == 3.141592){
        return -1.0;
    }

    if(n > 100){
        printf("\nERRO: Valor de N excedeu o limite, reduzindo para 100...\n");
        n = 100;
    } else if(n < 0){
        printf("\nERRO: Valor de N eh menor 0, aumentando para 1...\n");
        n = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            res += pow(rad, exp) / fat(exp);
        } else {
            res -= pow(rad, exp) / fat(exp);
        }

        exp += 2;
    }

    return res;
}

double cosen_dg(double dg, int n) {
    double res = 1.0;
    int exp = 2;

    if(dg == 90 || dg == 270){
        return 0.0;
    } else if(dg == 0 || dg == 360){
        return 1.0;
    } else if(dg == 180){
        return -1.0;
    }

    if(n > 100){
        printf("\nERRO: Valor de N excedeu o limite, reduzindo para 100...\n");
        n = 100;
    } else if(n < 0){
        printf("\nERRO: Valor de N eh menor 0, aumentando para 1...\n");
        n = 1;
    }

    double x = to_radian(dg);

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
    int n;
    double resultado;
    float dg, x;
    int entrada = 0;
    do{
        system("cls");
        printf("---- COSSENO ----\n");
        printf("|1. GRAU        |\n");
        printf("|2. RADIANO     |\n");
        printf("|3. SAIR        |\n");
        printf("-----------------\n");
        printf("Escolha o tipo de entrada: ");
        scanf("%d", &entrada);
        system("cls");
        switch (entrada){
            case 1:
                printf("--- Insira o valor em grau (ex.: 90): ");
                getchar();
                scanf("%f", &dg);
                printf("--- Insira o valor de N (max.: 100): ");
                getchar();
                scanf("%d", &n);
                resultado = cosen_dg(dg, n);
                printf("\nCosseno de %.2f graus: %f\n\n", dg, resultado);
                break;
            case 2:
                printf("--- Insira o valor em radiano (ex.: 1.570796): ");
                getchar();
                scanf("%f", &x);
                printf("--- Insira o valor de N (max.: 100): ");
                getchar();
                scanf("%d", &n);
                resultado = cosen_rad(x, n);
                printf("\nCosseno de %f graus: %f\n\n", x, resultado);
                break;
            case 3:
                printf("\nEncerrando programa...\n");
                break;
            default:
                printf("\nERRO: Opcao invalida, tente novamente\n");
                break;
        }
        system("pause");
    }while(entrada != 3);

    return 0;
}