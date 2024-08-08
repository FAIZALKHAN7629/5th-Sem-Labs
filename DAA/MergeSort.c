#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void algorithm(int A[], int n);

void generate_best_case(int A[], int n);
void generate_worst_case(int A[], int n);
void generate_average_case(int A[], int n);

void print_array(int A[], int n);

int main(void)
{
    int n, choice;
    int *A;
    double time1, timedif;
    size_t space_before, space_after, space_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate space and measure it
    A = (int *)malloc(n * sizeof(int));
    space_before = n * sizeof(int);

    printf("Choose the case for array initialization:\n");
    printf("1. Best Case\n");
    printf("2. Worst Case\n");
    printf("3. Average Case\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            generate_best_case(A, n);
            break;
        case 2:
            generate_worst_case(A, n);
            break;
        case 3:
            generate_average_case(A, n);
            break;
        default:
            printf("Invalid choice!\n");
            free(A);
            return -1;
    }

    printf("\nThe unsorted list:\n");
    print_array(A, n);

    time1 = (double)clock();  // Get initial time
    time1 = time1 / CLOCKS_PER_SEC;  // In seconds

    algorithm(A, n);

    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

    printf("\nThe sorted list:\n");
    print_array(A, n);

    printf("The elapsed time is %f seconds\n", timedif);

    // Estimate space complexity
    space_after = n * sizeof(int);  // Assume no additional space was used
    space_used = space_after - space_before;

    printf("Estimated space used is %zu bytes\n", space_used);

    free(A);
    return 0;
}

void generate_best_case(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }
}

void generate_worst_case(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
}

void generate_average_case(int A[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100;  // Generates random numbers between 0 and 99
    }
}

void print_array(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void merge(int A[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);

        merge(A, left, mid, right);
    }
}

void algorithm(int A[], int n)
{
    merge_sort(A, 0, n - 1);
}