#include "stdafx.h"
#include < math.h >
#include <stdio.h>
#include <stdlib.h>

int buffer_table[10][256][512];
int result_table[512][512];
int figure = 0;

int logarifm(int x) {
	int result = 0;
	while (x) {
		x /= 2;
		result++;
	}
	return result - 1;
}

 void copy(int table[][512], int buffer[][512], int quarter, int length){
	switch (quarter){
	case 0:
		for (int i = 0; i < length; i++){
			for (int j = 0; j < length; j++){
				table[i][j] = buffer[i][j];
			}
		}
	case 1:
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				table[i][j + length] = buffer[i][j];
			}
		}
	case 2:
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				table[i + length][j] = buffer[i][j];
			}
		}
	case 3:
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				table[i + length][j + length] = buffer[i][j];
			}
		}
	}	 
}

void recurs_draw(int length, int x, int y, int table[][512]){
	
	if (length == 2) {
		figure++;

		for(int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {

				if ((i == x) && (j == y)) {
					table[i][j] = 0;
				}else{
					table[i][j] = figure;
				}

			}				
		}

	}else if ((x < length / 2) && (y < length / 2)) {

		
		recurs_draw(length / 2, x, y, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 0, length/2);

		recurs_draw(length / 2, length / 2 - 1, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 1, length / 2);

		recurs_draw(length / 2, 0, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 2, length / 2);

		recurs_draw(length / 2, 0, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 3, length / 2);

		figure++;
		table[length / 2 - 1][length / 2] = figure;
		table[length / 2][length / 2 - 1] = figure;
		table[length / 2][length / 2] = figure;
		
	}else if ((x < length / 2) && (y >= length / 2)) {

		recurs_draw(length / 2, length / 2 - 1, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 0, length / 2);

		recurs_draw(length / 2, x, y - (length / 2), buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 1, length / 2);

		recurs_draw(length / 2, 0, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 2, length / 2);

		recurs_draw(length / 2, 0, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 3, length / 2);

		figure++;
		table[length / 2 - 1][length / 2 - 1] = figure;
		table[length / 2][length / 2 - 1] = figure;
		table[length / 2][length / 2] = figure;

	}else if ((x >= length / 2) && (y < length / 2)) {

		recurs_draw(length / 2, length / 2 - 1, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 0, length / 2);

		recurs_draw(length / 2, length / 2 - 1, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 1, length / 2);

		recurs_draw(length / 2, x - (length / 2), y, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 2, length / 2);

		recurs_draw(length / 2, 0, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 3, length / 2);

		figure++;
		table[length / 2 - 1][length / 2 - 1] = figure;
		table[length / 2 - 1][length / 2] = figure;
		table[length / 2][length / 2] = figure;

	}else if ((x >= length / 2) && (y >= length / 2)) {

		recurs_draw(length / 2, length / 2 - 1, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 0, length / 2);

		recurs_draw(length / 2, length / 2 - 1, 0, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 1, length / 2);

		recurs_draw(length / 2, 0, length / 2 - 1, buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 2, length / 2);

		recurs_draw(length / 2, x - (length / 2), y - (length / 2), buffer_table[logarifm(length)]);
		copy(table, buffer_table[logarifm(length)], 3, length / 2);

		figure++;
		table[length / 2 - 1][length / 2 - 1] = figure;
		table[length / 2 - 1][length / 2] = figure;
		table[length / 2][length / 2 - 1] = figure;

	}
}

int main(){
	int n;
	int length;
	int x;
	int y;

	scanf("%d %d %d", &n, &x, &y);
	x--; y--;
	length = 1 << n;

	if ((length*length - 1) % 3 != 0){
		printf("-1");
	}else{		
		recurs_draw(length, x, y, result_table);
		
		for(int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				printf("%d ", result_table[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}