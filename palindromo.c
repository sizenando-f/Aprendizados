#include <stdio.h>

void palindromo(int S[], int inicio, int fim, int *n){
  if(inicio >= fim){
    return;
  }

  if(S[inicio] != S[fim]){
    *n = 1;
    return;
  }

  palindromo(S, inicio + 1, fim - 1, n);
};

int main(){
  int n = 0;
  int S[] = {1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};

  palindromo(S, 0, 10, &n);

  n ? printf("Nao eh um palindrom") : printf("Eh um palindromo");
  return 0;
}