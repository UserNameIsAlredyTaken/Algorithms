// Giperperehod.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (((X) < (Y)) ? (Y) : (X))

int main(){

	int count_of_p;
	scanf("%d", &count_of_p);
	int current_p;
	int result = 0;
	int current_sum = 0;

	for (int i = 0; i < count_of_p; i++){
		scanf("%d", &current_p);
		current_sum += current_p;
		current_sum = MAX(current_sum,0);
		result = MAX(result, current_sum);
	}
	printf("%d", result);
    return 0;
}

