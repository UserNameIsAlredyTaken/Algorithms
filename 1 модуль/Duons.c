#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define CORNER_CONNECTIONS_COUNT 3
#define CORNERS_COUNT 8
#define MAX_COUNT_OF_ACTIONS 1000
#define CHARS_IN_ACTION 3

const int connections[CORNERS_COUNT][3] = { { 1,3,4 },
{ 0,2,5 },
{ 1,3,6 },
{ 0,2,7 },
{ 0,5,7 },
{ 1,4,6 },
{ 2,5,7 },
{ 3,4,6 } };

const int diagonals[CORNERS_COUNT] = {6,7,4,5,2,3,0,1};

int find_max(int* cameras) {
	int max = 0;
	int max_i = -1;
	for (int i = 0; i < CORNERS_COUNT; i++) {
		if (cameras[i] > max) {
			max = cameras[i];
			max_i = i;
		}
	}
	return max_i;
}

int duons_are_there(int* cameras){
	for (int i = 0; i < CORNERS_COUNT; i++){
		if (cameras[i] != 0) { return 1; }
	}
	return 0;
}

int duon_has_neighbors(int* cameras, int duon_number) {
	for (int i = 0; i < CORNER_CONNECTIONS_COUNT; i++) {
		if (cameras[connections[duon_number][i]] != 0) { return 1; }
	}
	return 0;
}

int duon_has_diag_neighbor(int* cameras, int duon_number){
	if (cameras[diagonals[duon_number]] != 0) { return 1; }
	return 0;
}

void result_append(char* result,int* result_length, char char1, char char2, char sign){
	result[*result_length] = char1;
	result[*result_length +1] = char2;
	result[*result_length +2] = sign;
	*result_length += CHARS_IN_ACTION;	
}

int main(){
	char* result = (char*)malloc(MAX_COUNT_OF_ACTIONS * CHARS_IN_ACTION * sizeof(char));
	int result_length = 0;
	char minus = '-';
	char plus = '+';

	char letters[CORNERS_COUNT] = { 'A','B','C','D','E','F','G','H' };
		
	int cameras[CORNERS_COUNT];
	for (int i = 0; i < CORNERS_COUNT; i++) {
		scanf("%d", &cameras[i]);
	}

	int sum = 0;
	for (int i = 0; i < CORNERS_COUNT; i++) {
		sum += cameras[i];
	}
	if (sum % 2 != 0) {
		printf("IMPOSSIBLE");
		return 0;
	}

	while (duons_are_there(cameras)) {
		int max_i = find_max(cameras);

		if(duon_has_neighbors(cameras,max_i)){
			for (int i = 0; i < CORNER_CONNECTIONS_COUNT; i++) {
				while ((cameras[connections[max_i][i]] > 0) && (cameras[max_i] > 0)) {
					cameras[max_i] --;
					cameras[connections[max_i][i]] --;
					result_append(result, &result_length, letters[max_i], letters[connections[max_i][i]], minus);
				}
			}
		}else if(duon_has_diag_neighbor(cameras, max_i)){
			while ((cameras[diagonals[max_i]] > 0) && (cameras[max_i] > 0)) {
				result_append(result, &result_length, letters[connections[max_i][0]], letters[connections[diagonals[max_i]][0]], plus);
				cameras[max_i] --;
				cameras[diagonals[max_i]] --;
				result_append(result, &result_length, letters[max_i], letters[connections[max_i][0]], minus);
				result_append(result, &result_length, letters[diagonals[max_i]], letters[connections[diagonals[max_i]][0]], minus);
			}			
		}else{
			printf("IMPOSSIBLE");
			return 0;
		}
	}
	int x = result_length / CHARS_IN_ACTION;
	for (int i = 0; i < result_length; i+= CHARS_IN_ACTION) {
		printf("%c", result[i]);
		printf("%c", result[i+1]);
		printf("%c", result[i+2]);
		printf("\n");
	}
    return 0;
}

