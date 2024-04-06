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

double fix_dg(double dg){
    while(dg > 360){
        dg -= 360;
    }

    return dg;
}

double fix_radian(double radian){
    while(radian > 6.283185307179586){
        radian -= 6.283185307179586;
    }

    return radian;
}

double cosen_rad(double rad, int n) {
    double res = 1.0;
    int exp = 2;

    rad = rad < 0 ? rad*(-1) : rad;
    rad = fix_radian(rad);

    if(rad == 1.570796326794896 || rad == 4.712388980384689){
        return 0.0;
    } else if(rad == 0.0 || rad == 6.283185307179586){
        return 1.0;
    } else if(rad == 3.141592653589793){
        return -1.0;
    }

    if(n > 100){
        printf("\033[0;31m");
        printf("\n  [ #<- ] ERRO: Valor de N excedeu o limite, reduzindo para 100...\n");
        printf("\033[0;37m");
        n = 100;
    } else if(n < 0){
        printf("\033[0;31m");
        printf("\n  [ #<- ] ERRO: Valor de N eh menor 0, aumentando para 1...\n");
        printf("\033[0;37m");
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

    if(dg == 90.0 || dg == 270.0){
        return 0.0;
    } else if(dg == 0.0 || dg == 360.0){
        return 1.0;
    } else if(dg == 18.0){
        return -1.0;
    }

    if(n > 100){
        printf("\033[0;31m");
        printf("\n[ #<- ] ERRO: Valor de N excedeu o limite, reduzindo para 100...\n");
        printf("\033[0;37m");
        n = 100;
    } else if(n < 0){
        printf("\033[0;31m");
        printf("\n[ #<- ] ERRO: Valor de N eh menor 0, aumentando para 1...\n");
        printf("\033[0;37m");
        n = 1;
    }

    dg = dg < 0 ? dg*(-1) : dg;
    double fixed_dg = fix_dg(dg);
    double x = to_radian(fixed_dg);

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
        printf(" ________  ________  ________   ________  _______   ________   ________\n");
        printf("|\\   ____\\|\\   __  \\|\\   ____\\ |\\   ____\\|\\  ___ \\ |\\   ___  \\|\\   __  \\ \n");
        printf("\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\___|_\\ \\  \\___|\\ \\   __/|\\ \\  \\\\ \\  \\ \\  \\|\\  \\ \n");
        printf(" \\ \\  \\    \\ \\  \\\\\\  \\ \\_____  \\\\ \\_____  \\ \\  \\_|/_\\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \n");
        printf("  \\ \\  \\____\\ \\  \\\\\\  \\|____|\\  \\\\|____|\\  \\ \\  \\_|\ \\ \\  \\\\ \\  \\ \\  \\\\\\  \\ \n");
        printf("   \\ \\_______\\ \\_______\\____\\_\\  \\ ____\\_\\  \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \n");
        printf("    \\|_______|\\|_______|\\_________\\\\_________\\|_______|\\|__| \\|__|\\|_______| \n");
        printf("                       \\|_________\\|_________| \n");
        printf("\033[0;37m");
        printf("\033[0;34m[ 1 ]\033[0;37m GRAU\n");
        printf("\033[0;34m[ 2 ]\033[0;37m RADIANO\n");
        printf("\033[0;34m[ 3 ]\033[0;37m SAIR\n");
        printf("=============================\n");
        printf("Escolha o tipo de entrada > ");
        printf("\033[1;34m");
        scanf("%d", &entrada);
        printf("\033[0;37m");
        switch (entrada){
            case 1:
                printf("[ <- ] Insira o valor em grau (ex.: 90) > ");
                getchar();
                printf("\033[1;34m");
                scanf("%f", &dg);
                printf("\033[0;37m");
                do{
                    printf("[ <- ] Insira o valor de N (max.: 100) > ");
                    getchar();
                    printf("\033[1;34m");
                    scanf("%d", &n);
                    printf("\033[0;37m");
                    if(n == 0){
                        printf("\033[0;31m");
                        printf("[ #<- ] ERRO: Insira outro valor diferente de 0\n");
                        printf("\033[0;37m");
                    }
                }while(n == 0);
                resultado = cosen_dg(dg, n);
                printf("\033[0;32m");
                printf("\n[ -> ] Cosseno de \033[4;32m%.2f\033[0;32m graus:\033[1;32m %.15f\n\n", dg, resultado);
                printf("\033[0;37m");
                break;
            case 2:
                printf("[ <- ] Insira o valor em radiano (ex.: 1.570796) > ");
                getchar();
                printf("\033[1;34m");
                scanf("%f", &x);
                printf("\033[0;37m");
                do{
                    printf("[ <- ] Insira o valor de N (max.: 100) > ");
                    getchar();
                    printf("\033[1;34m");
                    scanf("%d", &n);
                    printf("\033[0;37m");
                    if(n == 0){
                        printf("\033[0;31m");
                        printf("[ #<- ] ERRO: Insira outro valor diferente de 0\n");
                        printf("\033[0;37m");
                    }
                } while(n == 0); 
                resultado = cosen_rad(x, n);
                printf("\033[0;32m");
                printf("\n[ -> ] Cosseno de \033[4;32m%f\033[0;32m radianos:\033[1;32m %.15f\n\n", x, resultado);
                printf("\033[0;37m");
                break;
            case 3:
                printf("\033[0;32m");
                printf("\n[ -> ] Programa encerrado\n");
                printf("\033[0;37m");
                break;
            default:
                printf("\033[0;31m");
                printf("\n[ #<- ] ERRO: Opcao invalida, tente novamente\n");
                printf("\033[0;37m");
                break;
        }
        system("pause");
    }while(entrada != 3);

    return 0;
}