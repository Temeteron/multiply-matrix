#include <stdio.h>
#include <math.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h> 

int num_of_elements;

// int a[num_of_elements], b[num_of_elements];

int main (int argc, char *argv[]) {
	num_of_elements = 10;
	int a[num_of_elements][num_of_elements], b[num_of_elements][num_of_elements];
	int result[num_of_elements][num_of_elements], i, j, k;
	

	// Initializing all elements of 'a' matrix
    for (i = 0; i < num_of_elements; ++i) {
        for( j = 0; j < num_of_elements; ++j) {
            a[i][j] = rand();
        }
    }

    // Initializing all elements of 'b' matrix
    for (i=0; i<num_of_elements; ++i) {
        for( j=0; j<num_of_elements; ++j) {
            b[i][j] = rand();
        }
    }

	// Initializing all elements of result matrix to 0
    for (i = 0; i < num_of_elements; ++i) {
        for(j = 0; j < num_of_elements; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying matrices a and b and
    // storing result in result matrix
    for (i = 0; i < num_of_elements; ++i) {
        for (j = 0; j < num_of_elements; ++j) {
            for (k = 0; k < num_of_elements; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Displaying the result
    printf("\nOutput Matrix:\n");
    for (i = 0; i < num_of_elements; ++i) {
        for (j = 0; j < num_of_elements; ++j) {
            printf("%d  ", result[i][j]);
            if(j == num_of_elements-1)
                printf("\n\n");
        }
    }



	return 0;
}

