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
    // print_array(A, n);

    time1 = (double)clock();  // Get initial time
    time1 = time1 / CLOCKS_PER_SEC;  // In seconds

    algorithm(A, n);

    timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;

    printf("\nThe sorted list:\n");
    // print_array(A, n);

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

void algorithm(int A[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}