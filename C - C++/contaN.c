#include <stdio.h>

int contaN(int S[], int n, int soma){
  if(n <= 0){
    return S[n] + soma;
  }

  soma = contaN(S, n - 1, soma);
  return S[n] + soma;
}

int main(){
  int S[] = {1, 2, 3};
  int tam = (sizeof(S)/sizeof(S[0])) - 1;
  printf("%d", contaN(S, tam, 0));
  return 0;
}