#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void q_sort(long long * coordinats, long long left, long long right) {
	long long i = left, j = right;
	long long tmp;
	long long pivot = coordinats[(left + right) / 2];

	while (i <= j) {
		while (coordinats[i] < pivot) {
			i++;
		}
		while (coordinats[j] > pivot) {
			j--;
		}
		if (i <= j) {
			tmp = coordinats[i];
			coordinats[i] = coordinats[j];
			coordinats[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j) {
		q_sort(coordinats, left, j);
	}
	if (right > i) {
		q_sort(coordinats, i, right);
	}
}

int main() {
	long long n;
	long long dif_sum = 0;	

	scanf("%lld", &n);
	long long* x = (long long*)malloc(sizeof(long long) * n);
	long long* y = (long long*)malloc(sizeof(long long) * n);

	for (long long i = 0; i < n; i++) {
		scanf("%lld%lld", &x[i], &y[i]);
	}
	
	
	q_sort(x, 0, n - 1);
	q_sort(y, 0, n - 1);
	
	for (long long i = 1; i < n; i++) {
		dif_sum += (x[i] - x[i - 1]) * i * (n - i);
	}
	for (long long i = 1; i < n; i++) {
		dif_sum += (y[i] - y[i - 1]) * i * (n - i);
	}
		
	long long result = (long long)(dif_sum * 2 / (n * (n - 1)));

	printf("%lld\n", result);
	return 0;
}

