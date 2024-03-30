#include <stdio.h>
#include <math.h>

double fat(int n) {
    if(n == 1){
        return 1;
    }

    return n * fat(n - 1);
}

double to_radian(int x) return dg * M_PI / 180; 

double cosen(int dg, int n) {
    double res = 1.0;
    int exp = 2;

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
    int dg, n;
    double x, resultado;
    int entrada = 0;
    do{
        system("cls");
        printf("---- COSSENO ----\n");
        printf("1. GRAU         |\n");
        printf("2. RADIANO      |\n");
        printf("3. SAIR         |\n");
        printf("-----------------\n");
        printf("Escolha o tipo de entrada: ");
        scanf("%d", &entrada);

        switch (entrada){
            case 1:
                printf("Insira o grau: ");
                scanf("%d", &dg);
                printf("Insira o valor de N: ");
                scanf("%d", &n);
                x = to_radian(dg);
                resultado = cosen(x, n);
                break;
            case 2:
                printf("Insira o radiano: ");
                scanf("%d", &x);
                printf("Insira o valor de N: ");
                scanf("%d", &n);
                resultado = cosen(x, n);
                break;
            case 3:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida, tente novamente\n");
                break;
        }
        printf("Cosseno de %d graus: %f\n", x, resultado);
        system("pause");
    }while(entrada != 3);
    

    



    return 0;
}