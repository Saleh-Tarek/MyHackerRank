#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int* gradingStudents(int grades_count, int* grades); 

int main(){
int Num,i,grade[10],* arr,x;
printf("Enter the total number of grades.\n");
scanf("%d",&Num);
for(i = 0; i < Num; i++){
scanf("%d",&grade[i]);
}
	printf("Output.\n");

arr=gradingStudents(Num,grade);

for(i = 0; i < Num; i++){
	printf("%d\n",arr[i]);

}
return 0;
}

int* gradingStudents(int grades_count, int* grades) 
{
int i, x;
for( i = 0; i < grades_count; i++){

x = (grades[i]+4)/5;
x *= 5;
if(x>=40 && (x-grades[i])<3)
{
	grades[i]=x;
	printf("%d\n",grades[i]);
}
else if(x<40)
{
	printf("Student Failed%d.\n",grades[i]);
}

}
return grades;
}