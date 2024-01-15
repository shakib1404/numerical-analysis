#include <stdio.h>
#include <math.h>

#define SIZE 10

int main()
{
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float temp, lambda_new, lambda_old, error, norm;
    int i, j, n, step = 1;

    /* Inputs */
    printf("Enter Order of Matrix: ");
    scanf("%d", &n);
    printf("Enter Tolerable Error: ");
    scanf("%f", &error);

    /* Reading Matrix */
    printf("Enter Coefficient of Matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    /* Reading Initial Guess Vector */
    printf("Enter Initial Guess Vector:\n");
    for (i = 1; i <= n; i++)
    {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
    }

    /* Initializing Lambda_Old */
    lambda_old = 1;

    do
    {
        /* Multiplication */
        for (i = 1; i <= n; i++)
        {
            temp = 0.0;
            for (j = 1; j <= n; j++)
            {
                temp = temp + a[i][j] * x[j];
            }
            x_new[i] = temp;
        }

        /* Finding Largest */
        lambda_new = fabs(x_new[1]);
        for (i = 2; i <= n; i++)
        {
            if (fabs(x_new[i]) > lambda_new)
            {
                lambda_new = fabs(x_new[i]);
            }
        }

        /* Normalization */
        norm = 0.0;
        for (i = 1; i <= n; i++)
        {
            norm += pow((x[i] - x_new[i] / lambda_new), 2);
        }
        norm = sqrt(norm);

        /* Update x with normalized x_new */
        for (i = 1; i <= n; i++)
        {
            x[i] = x_new[i] / lambda_new;
        }

        /* Display */
        printf("\n\nSTEP-%d:\n", step);
        printf("Eigen Value = %f\n", lambda_new);
        printf("Eigen Vector:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%f\t", x[i]);
        }

        step++;
    } while (norm > error);

    return 0;
}
