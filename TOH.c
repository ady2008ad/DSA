#include <stdio.h>

void TOH(int n,char source, char aux, char dest){
    if(n==1){
        printf("%c -> %c\n",source,dest);
        return ;
    }
    TOH(n-1, source, dest, aux);
    printf("%c -> %c\n",source,dest);
    TOH(n-1, aux, source, dest);
}

int main(){

    TOH(3,'A','B','C');
    return 0;
}