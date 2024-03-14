#include <stdio.h>

int verificaN(int S[], int n, int x){
  if(n < 0){
    return 0;
  }

  if(S[n] == x){
    return 1;
  }

  return verificaN(S, n - 1, x);
}

int main(){
  int S[] = {1, 2, 3};
  int tam = (sizeof(S)/sizeof(S[0])) - 1;
  printf("%d", verificaN(S, tam, 5));
  return 0;
}