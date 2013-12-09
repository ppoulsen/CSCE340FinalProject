#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 91
#define STEP_SIZE_DEG 1.0
#define STEP_SIZE (STEP_SIZE_DEG * (M_PI / 180.0))

double F(double x)
{
	return (sqrt(1.0 - 0.25 * pow(sin(x),2.0)));
}

void init_to_zero(double *rk_4, int length) {
	int i;
	for (i=0; i<length; i++) {
		rk_4[i] = 0.0;
	}
}

void main(void)
{
	int i;
	double rk_4[N];
	
	rk_4[0] = 0.0;
	
	for (i=1; i<N; i++) {
		double t = STEP_SIZE * i;
		double x = rk_4[i-1];
		double k_1 = STEP_SIZE * F(t);
		double k_2 = STEP_SIZE * F(t + STEP_SIZE/2);
		double k_3 = k_2;
		double k_4 = STEP_SIZE * F(t + STEP_SIZE);
		rk_4[i] = x + (k_1 + 2 * k_2 + 2 * k_3 + k_4)/6.0;
	}
	
	for (i=0; i< N; i++)
		printf("%d, %.8f\n", i, rk_4[i]);
}
