#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 30
#define TOL (1e-9)
#define X0 0
#define STEP_SIZE (M_PI / (N - 1))
#define START (M_PI/2)

double kepler (double x, double y)
{
	// Assume eccentricity is 0.9
	return (y - (0.9 * sin(y)) - x);
}

double keplerPrime (double y) {
	// Assume eccentricity is 0.9
	return (1 - (0.9 * cos(y)));
}

void main(void)
{
	int i;
	double p, pi, fpi, fppi;

	printf("n,x,y\n");

  // Iterate through N steps
  for (i = 0; i < N; i++) {
		double x = X0 + STEP_SIZE * i;
		pi = x;

		while(1) {
			fpi = kepler(x, pi);
			fppi = keplerPrime(pi);
			
			p = pi - (fpi/fppi);

			if (abs(p - pi) < TOL && abs(fpi) < TOL)
				break;
			
			pi = p;
		}
		
		printf("%d,%.8f,%.8f\n", i, x, p);
	}
}
