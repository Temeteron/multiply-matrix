#include "libraries.h"

int result[SIZE][SIZE];

void calc1 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calc2 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calc4 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calc8 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calc16 (int a[SIZE][SIZE], int b[SIZE][SIZE]);
void calc32 (int a[SIZE][SIZE], int b[SIZE][SIZE]);

// n=512 και k=1, 2, 4, 8, 16
int main (int argc, char *argv[]) {
	int a[SIZE][SIZE], b[SIZE][SIZE];
	int i, j;
	

	// Initializing all elements of 'a' matrix
    for (i = 0; i < SIZE; ++i) {
        for( j = 0; j < SIZE; ++j) {
            a[i][j] = rand();
        }
    }

    // Initializing all elements of 'b' matrix
    for (i = 0; i < SIZE; ++i) {
        for( j = 0; j < SIZE; ++j) {
            b[i][j] = rand();
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
    // Multiply by blocks with step==1, 2, 4, 8, 16, 32
    calc1(a, b);
    calc2(a, b);
    calc4(a, b);
    calc8(a, b);
    calc16(a, b);
    calc32(a, b);


	return 0;
}

// STEP == 1
void calc1 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int i, j, k;

	for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            for (k = 0; k < SIZE; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC1: %lf\n", time_spent);
}

// STEP == 2
void calc2 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int temp, s = 2;

    for(int jj=0;jj<SIZE;jj+= s){
        for(int kk=0;kk<SIZE;kk+= s){
                for(int i=0;i<SIZE;i++){
                        for(int j = jj; j<((jj+s)>SIZE?SIZE:(jj+s)); j++){
                                temp = 0;
                                for(int k = kk; k<((kk+s)>SIZE?SIZE:(kk+s)); k++){
                                        temp += a[i][k]*b[k][j];
                                }
                                result[i][j] += temp;
                        }
                }
        }
	}

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC2: %lf\n", time_spent);
}

// STEP == 4
void calc4 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int temp, s = 4;

    for(int jj=0;jj<SIZE;jj+= s){
        for(int kk=0;kk<SIZE;kk+= s){
                for(int i=0;i<SIZE;i++){
                        for(int j = jj; j<((jj+s)>SIZE?SIZE:(jj+s)); j++){
                                temp = 0;
                                for(int k = kk; k<((kk+s)>SIZE?SIZE:(kk+s)); k++){
                                        temp += a[i][k]*b[k][j];
                                }
                                result[i][j] += temp;
                        }
                }
        }
	}

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC4: %lf\n", time_spent);
}

// STEP == 8
void calc8 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int temp, s = 8;

    for(int jj=0;jj<SIZE;jj+= s){
        for(int kk=0;kk<SIZE;kk+= s){
                for(int i=0;i<SIZE;i++){
                        for(int j = jj; j<((jj+s)>SIZE?SIZE:(jj+s)); j++){
                                temp = 0;
                                for(int k = kk; k<((kk+s)>SIZE?SIZE:(kk+s)); k++){
                                        temp += a[i][k]*b[k][j];
                                }
                                result[i][j] += temp;
                        }
                }
        }
	}

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC8: %lf\n", time_spent);
}

// STEP == 16
void calc16 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int temp, s = 16;

    for(int jj=0;jj<SIZE;jj+= s){
        for(int kk=0;kk<SIZE;kk+= s){
                for(int i=0;i<SIZE;i++){
                        for(int j = jj; j<((jj+s)>SIZE?SIZE:(jj+s)); j++){
                                temp = 0;
                                for(int k = kk; k<((kk+s)>SIZE?SIZE:(kk+s)); k++){
                                        temp += a[i][k]*b[k][j];
                                }
                                result[i][j] += temp;
                        }
                }
        }
	}

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC16: %lf\n", time_spent);
}

// STEP == 32
void calc32 (int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	clock_t begin = clock();
	int temp, s = 32;

    for(int jj=0;jj<SIZE;jj+= s){
        for(int kk=0;kk<SIZE;kk+= s){
                for(int i=0;i<SIZE;i++){
                        for(int j = jj; j<((jj+s)>SIZE?SIZE:(jj+s)); j++){
                                temp = 0;
                                for(int k = kk; k<((kk+s)>SIZE?SIZE:(kk+s)); k++){
                                        temp += a[i][k]*b[k][j];
                                }
                                result[i][j] += temp;
                        }
                }
        }
	}

    clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time spent in function CALC32: %lf\n", time_spent);
}

