#include <stdio.h>

int producto(int,int);

int main (void){
    int num = 3;
    int num2 = 9;

    int res = producto(num,num2);
    printf("%d",res);
}

int producto(int a,int b){
    if(b == 1){
       return a; 
    }
    return a + producto(a,b-1);
}
