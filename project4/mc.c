#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M 4000000

void main(void)
{
	int i, n;
	n = 0;
	srand(time(NULL));

	for (i=0; i<M; i++) {
		double x, y, r;
		x = ((double) rand())/RAND_MAX;
		y = ((double) rand())/RAND_MAX;
		r = pow(x,2) + pow(y,2);
		if (r < 1.0)
			n++;
	}
	
	printf("%.6f\n", (4.0 * (((double) n)/((double) M))));
}
