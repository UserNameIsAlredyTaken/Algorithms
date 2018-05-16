#include <stdio.h>
#include <stdlib.h>

void two_max(int* z, int n, int* max1_i, int* max2_i) {
	int max1 = 0;
	int max2 = 0;
	for (int i = 0; i < n; i++) {
		if (z[i] > max1) {
			*max2_i = *max1_i;
			*max1_i = i;
			max2 = max1;
			max1 = z[i];
		} else if(z[i] > max2) {
			*max2_i = i;
			max2 = z[i];
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int* znaks = (int *)malloc(sizeof(int) * n);
	long summ = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &znaks[i]);
		summ += znaks[i];
	}
	if (n == 1) {
		for (int i = 0; i < znaks[0]; i++) {
			printf("%d ", 1);
		}
		return 0;
	}

	int max1_i = -1;
	int max2_i = -1;

	for (int i = 0; i < summ / 2; i++) {
		two_max(znaks, n, &max1_i, &max2_i);
		znaks[max1_i]--;
		printf("%d ", max1_i + 1);
		znaks[max2_i]--;
		printf("%d ", max2_i + 1);
	}

	if (summ % 2) {
		for (int i = 0; i < n; i++) {
			if (znaks[i] != 0) {
				printf("%d ",i + 1);
			}				
		}
	}
	
	return 0;
}