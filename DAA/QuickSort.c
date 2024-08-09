#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void algorithm(int A[], int n);

void generate_best_case(int A[], int n);
void generate_worst_case(int A[], int n);
void generate_average_case(int A[], int n);

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

    time1 = (double)clock();  // Get initial time
    time1 = time1 / CLOCKS_PER_SEC;  // In seconds

    algorithm(A, n);

    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (A[j] < pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

void quick_sort(int A[], int low, int high)
{
    if (low < high) {
        int pi = partition(A, low, high);

        quick_sort(A, low, pi - 1);
        quick_sort(A, pi + 1, high);
    }
}

void algorithm(int A[], int n)
{
    quick_sort(A, 0, n - 1);
}