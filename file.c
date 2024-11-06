#include<stdio.h>
void main(){
FILE* fp[2];
fp[0]=fopen("vamsi","w");
fp[1]=fopen("vamsi","r");
char s[10]="vamsikr";
char s1[10]="kr";
int i;
fprintf(fp[0],"%s",s);
fclose(fp[0]);
fscanf(fp[1],"%s",s1);
printf("%s",s1);
}
