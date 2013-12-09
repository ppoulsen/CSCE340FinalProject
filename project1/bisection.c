#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30
#define TOL (1e-9)
#define X0 0
#define STEP_SIZE (M_PI / (N - 1))
#define LOWER (0.0 - TOL)
#define UPPER (M_PI + TOL)

double kepler (double x, double y)
{
	// Assume eccentricity is 0.9
	return (y - (0.9 * sin(y)) - x);
}

void main(void)
{
	int i;
	double a, b, p, fa, fb, fp;

	printf("n,x,y\n");

  // Iterate through N steps
  for (i = 0; i < N; i++) {
		double x = X0 + STEP_SIZE * i;
		a = LOWER;
		b = UPPER;

		fa = kepler(x, a);
		fb = kepler(x, b);
		
		while(1) {
			p = (a + b)/2;
			fp = kepler(x, p);
			
			if ((fp == 0) || ((b-a)/2 < TOL))
				break;
			if ((fa * fp) > 0) {
				a = p;
				fa = fp;
			} else
				b = p;
		}
		
		printf("%d,%.8f,%.8f\n", i, x, p);
	}
}
