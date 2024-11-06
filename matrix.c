#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
void *first_row1(void*fun);
void *second_row1(void *fun);
void *third_row1(void *fun);
 int a[3][3],b[3][3];
int j=0,k=0;int f_r,s_r,t_r;
pthread_t first_row,second_row,third_row;
void *first_row1(void *fun){
int i=0,s=0;int pro;
f_r=0;
for(;i<3;i++){
	pro=0;
	f_r=0;
for(s=0;s<3;s++){
pro=a[k][s]*b[s][i];
f_r=f_r+pro;
}
printf("%d ",f_r);
}
k++;
int l;

l=pthread_create(&second_row,0,second_row1,0);
if(l){
	perror("second_row");
exit(0);
}
pthread_join(second_row,0);
pthread_exit(0);
}
void *second_row1(void *fun){
int i=0,s=0,pro=0;
s_r=0;
for(;i<3;i++){
	pro=0;
	s_r=0;
for(s=0;s<3;s++){
pro=a[k][s]*b[s][i];
s_r=s_r+pro;
}
printf("%d ",s_r);
}
k++;
int l;
l=pthread_create(&third_row,0,third_row1,0);
if(l){
	perror("third_row");
exit(0);
}
pthread_join(third_row,0);
pthread_exit(0);
}
void *third_row1(void *fun){
int i=0,s=0,pro=0;
t_r=0;
for(;i<3;i++){
	pro=0;
	t_r=0;
for(s=0;s<3;s++){
pro=a[k][s]*b[s][i];
t_r=t_r+pro;
}
printf("%d ",t_r);
}
pthread_exit(0);
}
void main(){
	int first_matrix_row,first_matrix_column,second_matrix_row,second_matrix_column; 
	scanf("%d %d %d %d",&first_matrix_row,&first_matrix_column,&second_matrix_row,&second_matrix_column);
	if(first_matrix_row!=second_matrix_column){
      printf("the first_matrix_row is must be equal to the second_matrix_column");
      return ;
	}
	int i=0,j=0;
	for(;i<first_matrix_row;i++)
		for(j=0;j<first_matrix_column;j++)
			scanf("%d",&a[i][j]);
      for(i=0;i<second_matrix_row;i++)
	      for(j=0;j<second_matrix_column;j++)
		      scanf("%d",&b[i][j]);
      
	for(i=0;i<first_matrix_row;i++){
		for(j=0;j<first_matrix_column;j++){
			printf("%d ",a[i][j]);}
printf("\n");
			}
printf("\n");

	for(i=0;i<second_matrix_column;i++){
		for(j=0;j<second_matrix_column;j++){
			printf("%d ",b[i][j]);

		}
printf("\n");
}
int k;

k=pthread_create(&first_row,0,first_row1,0);
if(k){
	perror("first_row");
exit(0);
}
pthread_join(first_row,0);
}
