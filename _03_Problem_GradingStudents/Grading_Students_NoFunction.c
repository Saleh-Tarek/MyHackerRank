#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
int Num,i,grade[10],x;
printf("Enter the total number of grades.\n");
scanf("%d",&Num);
for(i = 0; i < Num; i++){
scanf("%d",&grade[i]);
}
	printf("Output.\n");

for(i = 0; i < Num; i++){

x = (grade[i]+4)/5;
x *= 5;
if(x>=40 && (x-grade[i])<3)
{
	grade[i]=x;
	printf("%d\n",grade[i]);
}
else
	printf("Student Failed.\n");

}
return 0;
}