#include<stdio.h>
#include<stdlib.h>
void main(){
int *p=malloc(sizeof(int));
free(p);
free(p);

}
