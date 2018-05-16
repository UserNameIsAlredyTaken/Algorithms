#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define biggest 1000000000
typedef struct {
    size_t number;
    double angle;
} dot;

typedef struct point {
    long long x;
    long long y;
} point_t;

double angle(point_t min_p, point_t p) {
    if (min_p.x == p.x) {
        if (p.y - min_p.y > 0) {
            return biggest;
        } else {
            return -biggest;
        }
    }
    return (p.y - min_p.y) / (double)(p.x - min_p.x);
}
void quickSort(dot* a, int left, int right) {
    int i = left, j = right;
    dot middle = a[(left + right) / 2];

    while (i <= j) {
        while (a[i].angle < middle.angle) {
            i++;
        }
        while (a[j].angle > middle.angle) {
            j--;
        }
        if (i <= j) {
            dot tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j){
        quickSort(a, left, j);
    }
    if (right > i) {
        quickSort(a, i, right);
    }
}

int main() {
    unsigned short count;
    scanf("%hu", &count);
    point_t * points = (point_t*)malloc(count * sizeof(point_t));
    long long minX;
    int minNumber;
    for (size_t i = 0; i < count; i++) {
        scanf("%lld%lld", &points[i].x, &points[i].y);
        if (!i || minX > points[i].x) {
            minX = points[i].x;
            minNumber = i;
        }
    }
    size_t k = 0;
    dot * dots = (dot*)malloc((count - 1) * sizeof(dot));
    for(size_t i = 0;i< count;i++)
    {
        if(i!=minNumber) {
            dots[k].number = i;
            dots[k].angle = angle(points[minNumber], points[i]);
            k++;
        }
    }
    quickSort(dots, 0, count-2);
    printf("%d %d", dots[(count - 1)/2].number + 1,minNumber + 1);
    return 0;
}