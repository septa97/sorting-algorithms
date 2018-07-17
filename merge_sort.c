#include <stdio.h>
#include <malloc.h>

void merge(int arr[], int l, int m, int r) {
    int *A, *B, c, i = 0, j = 0, k = l, left_size = m-l+1, right_size = r-m;

    A = (int *)malloc(sizeof(int) * left_size);
    B = (int *)malloc(sizeof(int) * right_size);

    for (c = 0; c < left_size; c++) A[c] = arr[c+l];
    for (c = 0; c < right_size; c++) B[c] = arr[c+m+1];

    while (i < left_size && j < right_size) {
        if (A[i] < B[j]) arr[k++] = A[i++];
        else arr[k++] = B[j++];
    }

    while (i < left_size) arr[k++] = A[i++];
    while (j < right_size) arr[k++] = B[j++];

    free(A);
    free(B);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, i, *A;
    scanf("%d", &n);

    A = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    merge_sort(A, 0, n-1);

    for (i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}
