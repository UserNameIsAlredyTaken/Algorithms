#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void recurs_func(int* stones, int* result, int max_iteration,int iteration, int a, int b) {
	if (iteration == max_iteration) {
		if (a > b) {
			if (a - b < *result) {
				*result = a - b;
			}			
		}else{
			if (b - a < *result) {
				*result = b - a;
			}
		}
	}else{
		recurs_func(stones, result, max_iteration, iteration + 1, a + stones[iteration], b);
		recurs_func(stones, result, max_iteration, iteration + 1, a, b + stones[iteration]);
	}
}

int main(){
	int stones_count;
	scanf("%d", &stones_count);
	int* stones = (int*)malloc(stones_count * sizeof(int));

	for (int i = 0; i < stones_count; i++) {
		scanf("%d", &stones[i]);
	}

	int result = 100001;

	recurs_func(stones, &result, stones_count, 0, 0, 0);
		
	printf("%d", result);

    return 0;
}

