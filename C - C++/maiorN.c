#include <stdio.h>

int maiorN(int S[], int n, int maior){
  if(n <= 0){
    return maior;
  }

  if(S[n] > maior){
    maior = S[n];
  }

  return maiorN(S, n - 1, maior);
}

int main(){
  int S[] = {-4, -6, -1, -2};
  int tam = (sizeof(S)/sizeof(S[0])) - 1;
  printf("%d\n\n", maiorN(S, tam, S[0]));
  for(int i = 0; i <= tam; i++){
    printf("%d\n", S[i]);
  }
  return 0;
}