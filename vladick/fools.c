#include <stdio.h>
#include <stdlib.h>

void step(const unsigned short* signs, unsigned short k, unsigned short* max_pointer1, unsigned short* max_pointer2) {
    unsigned short max1 = 0;
    unsigned short max2 = 0;
    for (unsigned short i = 0; i < k; i++) {
        if (signs[i] > max1) {
            *max_pointer2 = *max_pointer1;
            *max_pointer1 = i;
            max2 = max1;
            max1 = signs[i];
        }
        else if(signs[i] > max2) {
            *max_pointer2 = i;
            max2 = signs[i];
        }
    }
}

void print(unsigned short sign_pointer) {
    printf("%d ", sign_pointer + 1);
}

int main() {
    unsigned short k;
    unsigned short signs_count = 0;
    unsigned short max_pointer1 = 0;
    unsigned short max_pointer2 = 0;
    scanf("%hu", &k);
    unsigned short* signs = (unsigned short *)malloc(sizeof(unsigned short) * k);
    for (unsigned short i = 0; i < k; i++) {
        scanf("%hu", &signs[i]);
        signs_count += signs[i];
    }
    if (k == 1) {
        for (unsigned short i = 0; i < signs[0]; i++) {
            print(0);
        }
        return 0;
    }
    for (unsigned short i = 0; i < signs_count / 2; i++) {
        step(signs, k, &max_pointer1, &max_pointer2);
        signs[max_pointer1]--;
        signs[max_pointer2]--;
        print(max_pointer1);
        print(max_pointer2);
    }
    if (signs_count % 2) {
        for (unsigned short i = 0; i < k; i++) {
            if (signs[i] != 0) {
                print(i);
            }
        }
    }
}