#include <stdio.h>
void h(int n,char o,char d,char a){
    if(n){
        h(n-1,o,a,d);
        printf("Mova disco %d de %c para %c\n",n,o,d);
        h(n-1,a,d,o);
    }
    }

int main(){
    h(1,'A','C','B');
    return 0;
}