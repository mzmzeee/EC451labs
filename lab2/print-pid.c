#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Tge proccess ID is %d\n",(int)getpid());
    printf("The parent proccess ID is %d\n",(int)getppid());
    return 0;
}