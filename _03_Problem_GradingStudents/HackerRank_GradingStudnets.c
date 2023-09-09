/*HackerRank code*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int* gradingStudents(int grades_count, int* grades, int* result_count) {
    * result_count = grades_count;
    int iterator, x;
    for (iterator =0; iterator<grades_count; iterator++)
    {
        x = (grades[iterator]+4)/5;
       // x = (38+4)/5;

        //x = (*(grades+iterator)+4)/5; // grade 41-> 45 x= 9
        x*=5; //x=45 x=40
        
        //if(grades[iterator]>=38&&((x - grades[iterator])<3))
        if(x>=40&&((x - grades[iterator])<3))
        {
            //grades[iterator] == 43 ,44
            grades[iterator] =x;
        }
        else 
        {
            //Do nothing
        }
        /*
        if(x>=40&&((x - grades[iterator])<3))
        {
            //grades[iterator] == 43 ,44
            grades[iterator] =x;
         printf("success %d"grades[iterator])

        }
        else if (x >= 40)
        {
         printf("success %d"grades[iterator])
        ]
        else {
            printf(failed)
            
        }
        */
        
    } 
    return grades;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int grades_count = parse_int(ltrim(rtrim(readline())));

    int* grades = malloc(grades_count * sizeof(int));

    for (int i = 0; i < grades_count; i++) {
        int grades_item = parse_int(ltrim(rtrim(readline())));

        *(grades + i) = grades_item;
    }

    int result_count;
    /* Function call inside main function*/
    int* result = gradingStudents(grades_count, grades, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}














/*
---
grade 					     	x
40 +4 = (int)(44/5)      = 8 	40
41 +4 = (int)(45/5) 	 = 9 	45
42 +4 = (int)(46/5 =9.2) = 9  	45
43 +4 = (int)(47/5 = 9.4)= 9  	45
44 +4 = (int)(48/5 = 9.6)= 9 	45
45 +4 = (int)(49/5= 9) = 9 	45
/5 == 8
+x == >45 -->9 == int 
9*5 =45
45 - grade
X - grade = var 
45 -41 = 4
45 -42 = 3
45 -43 = 2
45 -44 = 1
if (var <3)
{
grade =x 
print(grade) 45 45 
}
else
{
print (grade) 41 42 43 
}



+x == < 50 -->10
>45 / 5 == 9 


*/