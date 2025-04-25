#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return ia - ib;
}

double calculate_mean(int *arr, int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double calculate_median(int *arr, int n) {
    int *copy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    qsort(copy, n, sizeof(int), compare_ints);

    double med;
    if (n % 2 == 1) {
        med = copy[n/2];
    } else {
        med = (copy[n/2 - 1] + copy[n/2]) / 2.0;
    }
    free(copy);
    return med;
}

int *calculate_mode(int *arr, int n, int *mode_count) {
    int *copy = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) copy[i] = arr[i];
    qsort(copy, n, sizeof(int), compare_ints);

    int max_count = 1, curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (copy[i] == copy[i-1]) {
            curr_count++;
        } else {
            if (curr_count > max_count) max_count = curr_count;
            curr_count = 1;
        }
    }
    if (curr_count > max_count) max_count = curr_count;

    int *modes = malloc(n * sizeof(int));
    *mode_count = 0;
    curr_count = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && copy[i] == copy[i-1]) {
            curr_count++;
        } else {
            if (curr_count == max_count) {
                modes[*mode_count] = copy[i-1];
                (*mode_count)++;
            }
            curr_count = 1;
        }
    }

    free(copy);
    return modes;
}

int main(void) {
    int data[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);

    double mean   = calculate_mean(data, n);
    double median = calculate_median(data, n);

    int mode_count;
    int *modes = calculate_mode(data, n, &mode_count);

    printf("Mean:   %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode:   ");
    for (int i = 0; i < mode_count; i++) {
        printf("%d ", modes[i]);
    }
    printf("\n");

    free(modes);
    return 0;
}
