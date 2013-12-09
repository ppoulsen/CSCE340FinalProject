#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30
#define TOL (1e-9)
#define X0 0
#define STEP_SIZE (M_PI / (N - 1))

double kepler (double x, double y)
{
	// Assume eccentricity is 0.9
	return (y - (0.9 * sin(y)) - x);
}

void main(void)
{
	int i;
	double p, pi, pj, fpj, fpi;
	
	// Iterate through N steps
	for (i = 0; i < N; i++) {
		double x = X0 + STEP_SIZE * i;
		pi = x;
		pj = x - TOL; 
		
		fpi = kepler(x, pi);
		fpj = kepler(x, pj);
		
		while(1) {
			p = pj - fpj * (pj - pi)/(fpj - fpi);
			if (abs(p - pj) < TOL)
				break;
			
			pi = pj;
			fpi = fpj;
			pj = p;
			fpj = kepler(x, pj);
		}
		
		printf("%d,%.8f,%.8f\n", i, x, p);
	}
}
