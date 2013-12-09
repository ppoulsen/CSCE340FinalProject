#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define A 0
#define B (1 / sqrt(2))

double pi_finder (double x)
{
	return (8 * (sqrt(1 - pow(x,2.0)) - x));
}

void init_to_zero(double R[][N], int length) {
	int i,j;
	for (i=0; i<length; i++) {
		for (j=0; j<length; j++) {
			R[i][j] = 0.0;
		}
	}
}

void main(void)
{
	int i,j;
	double h;
	double R[N][N];
	
	h = B;
	init_to_zero(R, N);
	
	// First element
	R[0][0] = (h/2) * (pi_finder(A) + pi_finder(B));
	
	// Fill First Column by trapezoid rule
	for (i=1; i<N; i++) {
		int k;
		h = h/2;
		R[i][0] = 0.5 * R[i-1][0];
		for (k=0; k < pow(2, i-1); k++) {
			R[i][0] = R[i][0] + h * pi_finder(A + (2 * k + 1) * h);
		}
	}
	
	// Richardson Extrapolation for Remaining Elements
	for (i=1; i<N; i++) {
		for (j=i; j<N; j++) {
			R[j][i] = R[j][i-1] + (R[j][i-1] - R[j-1][i-1])/(pow(4,i) - 1);
		}
	}
	
	// Print Results
	for (i=0; i<N; i++) {
		short first = 1;
		for (j=0; j<N; j++) {
			if (first)
				first = 0;
			else
				printf(",");
			if(R[i][j])
				printf("%.12f", R[i][j]);
		}
		printf("\n");
	}
	
}
