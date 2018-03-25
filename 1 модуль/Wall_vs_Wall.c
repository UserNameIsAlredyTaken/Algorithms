#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

//стенка на стенку
int main(){

	int tests_count;
	scanf("%d", &tests_count);		
	int* results = (int*)malloc(tests_count * sizeof(int));

	for (int i = 0; i < tests_count; i++){
		int fighters, comands;
		scanf("%d%d", &fighters, &comands);

		int f_per_com_average = fighters / comands;//div
		int f_without_extra = f_per_com_average * comands;
		int extra_f = fighters - f_without_extra;//mod

		results[i] = (f_without_extra * (f_without_extra - f_per_com_average)) / 2 + extra_f*(fighters - f_per_com_average - 1) - (extra_f * (extra_f - 1)) / 2;
	}

	for (int i = 0; i < tests_count; i++){
		printf("%d\n", results[i]);
	}
    return 0;
}

