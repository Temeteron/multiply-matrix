#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>
#define SIZE 512

int result[SIZE][SIZE];

//void calc1 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calcK (int a[SIZE][SIZE], int b[SIZE][SIZE],int step);

// n=512 και k=1, 2, 4, 8, 16
int main (int argc, char *argv[]) {
	int a[SIZE][SIZE], b[SIZE][SIZE];
	int i, j;
	

	// Initializing all elements of 'a' matrix
    for (i = 0; i < SIZE; ++i) {
        for( j = 0; j < SIZE; ++j) {
            a[i][j] =rand();
        }
    }

    // Initializing all elements of 'b' matrix
    for (i = 0; i < SIZE; ++i) {
        for( j = 0; j < SIZE; ++j) {
            b[i][j] =rand();
        }
    }

	// Initializing all elements of result matrix to 0
    for (i = 0; i < SIZE; ++i) {
        for(j = 0; j < SIZE; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying matrices a and b and
    // storing result in result matrix
    // STEP == 1
//    calc1(a, b);
	calcK(a, b,1);
    calcK(a, b,2);
    calcK(a, b,4);
    calcK(a, b,8);
    calcK(a, b,16);
    calcK(a, b,32);
	calcK(a, b,64);
    // Displaying the result
    // printf("\nOutput Matrix:\n");
    // for (i = 0; i < SIZE; ++i) {
    //     for (j = 0; j < SIZE; ++j) {
    //         printf("%d  ", result[i][j]);
    //         if(j == SIZE-1)
    //             printf("\n\n");
    //     }
    // }



	return 0;
}

//For s=1 is normal multiplication because each chunk is (1*SIZE)*(SIZE*1) calculating 1 element blocks of C
// STEP s=1,2,4,8,16,32 For each s*SIZE submatrix A multiply it with every SIZE*s chunk of B to produce the s*s block of C (row-major production)
void calcK (int a[SIZE][SIZE], int b[SIZE][SIZE],int step) {
	clock_t begin,end;
	int  s,ca,cb,i,j,k;
	s=step;
	
	for (i = 0; i < SIZE; ++i) {
        for(j = 0; j < SIZE; ++j) {
            result[i][j] = 0;
        }
    }
  
	begin = clock();
	for(ca=0; ca<SIZE; ca=ca+s){
		for(cb=0; cb<SIZE; cb=cb+s){
			for (i = ca; i < ca+s; ++i) {
				for (j = cb; j < cb+s; ++j) {
					for (k = 0; k < SIZE; ++k) {
						result[i][j] += a[i][k] * b[k][j];
					}
				}
			}
		}
	}

    end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC for step %d : %lf\n",s, time_spent);
	//for debugging printf("%d  %d  %d\n", result[0][0],result[1][0],result[3][3]);
}

