#include <stdio.h>

int fat(int x){
  if(x == 1){
    return 1;
  }

  return x * fat(x-1);
}

float cos(int x, int n, int cont, int den){
  if(cont == x){
    if(cont%2 == 0){
      return (x**2)/fat(den);
    }
    return (-(x**2)/fat(den));
  }

  return 1 - cos(x, n, cont + 1, den + 2)
  
}

int main(){
  printf("%d", fat(4));
  return 0;
}