#include <stdio.h>

void inverteR(int S[], int inicio, int fim){
  if(inicio >= fim){
    return;
  }
  inverteR(S, inicio + 1, fim - 1);

  int temp;
  temp = S[inicio-1];
  S[inicio-1] = S[fim-1];
  S[fim-1] = temp;

}

int main(){
  int S[5] = {1, 2, 3, 4, 5};
  inverteR(S, 1, 5);
  for(int i = 0; i < 5; i++){
    printf("%d  ", S[i]);
  }
  return 0;
}