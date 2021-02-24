// 2.13
// dlya zadannyh X, N nayti summu S=sinx+sinsinx+sinsinsinx+...+sin(...sinx) N raz

#include <stdio.h>
#include <math.h>

double solve(int n, double x, double *result) {
	if (n > 0){
		for(int i = 0; i < n; i++) {
			printf("iteration %d \n", i+1);
			x = sin(x);
			*result = *result + x;
			printf("current term of series %lf\n", x);
			printf("current sum %lf\n", result);
		}
	} else {
		printf("N should be greater than 0\n");
		return 1;
	}
	return 0;
}

int main() {
	double x0;
	int n0;
	double result;
	printf("Enter X\n");
	scanf("%lf", &x0);
	printf("Enter N\n");
	scanf("%d", &n0);
	if (solve(n0, x0, &result) == 1) {
		printf("ERROR\n");
	} else {
		printf("SUM = %.4f\n", result);
	}
	return 0;
}
