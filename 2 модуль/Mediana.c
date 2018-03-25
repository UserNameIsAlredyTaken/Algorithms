#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int i;
	long x;
	long y;
	double tng;
}point;

double tangens(point min_p, point p) {
	if (min_p.x == p.x) {
		if (p.y - min_p.y > 0) {
			return 1000000001;
		} else {
			return -1000000001;
		}
	}	
	return (p.y - min_p.y) / (double)(p.x - min_p.x);
}

void q_sort(point* points, int left, int right) {
	int i = left, j = right;
	point tmp;
	point pivot = points[(left + right) / 2];

	while (i <= j) {
		while (points[i].tng < pivot.tng) {
			i++;
		}
		while (points[j].tng > pivot.tng) {
			j--;
		}
		if (i <= j) {
			tmp = points[i];
			points[i] = points[j];
			points[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j){
		q_sort(points, left, j);
	}
	if (right > i) {
		q_sort(points, i, right);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	point* p = (point *)malloc(sizeof(point) * n);

	long min_x = 1000000001;
	point p_minx;

	for (int i = 0; i < n; i++) {
		p[i].i = i;		
		scanf("%d%d", &p[i].x, &p[i].y);
		if (p[i].x < min_x) {
			min_x = p[i].x;
			p_minx = p[i];
		}
	}


	point* tng_points = (point *)malloc(sizeof(point) * (n-1));

	for (int i = 0; i < n - 1; i++) {
		if (i >= p_minx.i) {
			tng_points[i] = p[i + 1];
			tng_points[i].tng = tangens(p_minx, p[i + 1]);
		}else{
			tng_points[i] = p[i];
			tng_points[i].tng = tangens(p_minx, p[i]);
		}
	}

	q_sort(tng_points, 0, n-2);
	
	printf("%d %d",p_minx.i+1, tng_points[(n-1)/2].i+1);

	return 0;
}