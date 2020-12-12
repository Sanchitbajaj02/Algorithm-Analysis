// Strassen Matrix Multiplication
#include <stdio.h>
#include <time.h>

void strassen(int a[2][2], int b[2][2])
{
    int c[2][2], i, j;
    int P, Q, R, S, T, U, V;

    P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    Q = (a[1][0] + a[1][1]) * b[0][0];
    R = a[0][0] * (b[0][1] - b[1][1]);
    S = a[1][1] * (b[1][0] - b[0][0]);
    T = (a[0][0] + a[0][1]) * b[1][1];
    U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = P + S - T + V;
    c[0][1] = R + T;
    c[1][0] = Q + S;
    c[1][1] = P - Q + R + U;

    printf("\nAfter multiplication using \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", c[i][j]);
    }
}
int main()
{
    int a[2][2], b[2][2], c[2][2], i, j;
    time_t start, end;
    start = time(NULL);

    printf("\n Enter the 4 elements of first matrix: ");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &a[i][j]);

    printf("\n Enter the 4 elements of second matrix: ");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &b[i][j]);

    printf("\n The first matrix is\n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", a[i][j]);
    }

    printf("\n The second matrix is\n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", b[i][j]);
    }

    strassen(a, b);

    end = time(NULL);
    printf("\n Time taken by the program is %.2f seconds", difftime(end, start));
    return 0;
}