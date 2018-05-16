#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <search.h>
#include <memory.h>

typedef struct point {
    unsigned long long x;
    unsigned long long y;
} point_t;

int compareY(const point_t * a, const point_t * b) {
        return b->y - a->y;
}

int compareX(const point_t * a, const point_t * b) {
    return b->x - a->x;
}

unsigned long long progression(unsigned long long n)
{
    unsigned long long sum = 0;
    for (unsigned long long i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    unsigned long long count;
    scanf("%llu", &count);
    point_t * points = (point_t*)malloc(count * sizeof(point_t));
    for (size_t i = 0; i < count; i++) {
        scanf("%llu%llu", &points[i].x, &points[i].y);
    }
    point_t * pointsSecond = (point_t*)malloc(count * sizeof(point_t));
    memcpy(pointsSecond, points, count * sizeof(point_t));
    unsigned long long counter = progression(count - 1);
    qsort(points, count, sizeof(point_t), compareX);
    qsort(pointsSecond, count, sizeof(point_t), compareY);
    unsigned long long result = 0;
    for (size_t i = 0; i < count - 1; i++) {
        result += (points[i].x - points[i+1].x) * (count - i - 1) * (i + 1);
        result += (pointsSecond[i].y - pointsSecond[i+1].y) * (count - i - 1) * (i + 1);
    }
    printf("%llu", result/counter);
    return 0;
}