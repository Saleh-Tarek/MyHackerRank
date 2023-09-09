#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int* breakingRecords(int scores_count, int* scores, int* result_count) {
   // int * arr= (int *) malloc(result_count * sizeof(int));
    static int a[2]={0,0};
    int max_score, min_score, max_count=0, min_count=0 ;
        max_score = scores[0];
        min_score = scores[0];
    for (int i =1; i< scores_count; i++)
    {
        printf("max_score = %d, max_count= %d, min_score=%d, min_count=%d\n", max_score,max_count,min_score,min_count);/*just a trace*/

        if(max_score < scores[i])
        {
            max_score=scores[i];
            max_count++;
            a[0]++;
        }
        else if (min_score > scores[i])
        {
            min_score= scores[i];
            min_count++;
            a[1]++;
        }
    }
    a[0]= max_count;
    a[1]= min_count;
return a;

}

int main(){
int n;
scanf("%d",&n);
int scores[10000];
int count;
for(int score_i = 0; score_i < n; score_i++){
scanf("%d",&scores[score_i]);
}
int* result = breakingRecords(n, scores, &count);
// your code goes here
printf("The output:\n");
for(int score_i = 0; score_i < 2; score_i++){
printf("%d ",*(result+score_i));
}
return 0;
}


