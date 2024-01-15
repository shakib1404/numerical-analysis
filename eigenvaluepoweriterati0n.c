#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the matrix size: ");
    scanf("%d", &n);

    double matrix[n][n];
    double initial_eigen_vector[n][1];
    double new_eigen_vector[n][1], eucledian_distance = 0, lambda_previous = 1, lambda_new;

    printf("Enter the matrix:\n");
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    printf("Enter the initial eigen vector which is not zero:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &initial_eigen_vector[i][0]);
    }

    while (1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 1; j++)
            {
                new_eigen_vector[i][j] = 0;
                for (k = 0; k < n; k++)
                {
                    new_eigen_vector[i][j] += matrix[i][k] * initial_eigen_vector[k][j];
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            eucledian_distance += new_eigen_vector[i][0] * new_eigen_vector[i][0];
        }

        eucledian_distance = sqrt(eucledian_distance);

        for (i = 0; i < n; i++)
        {
            new_eigen_vector[i][0] = new_eigen_vector[i][0] / eucledian_distance;
            printf("%lf ", new_eigen_vector[i][0]);
        }

        printf("%lf\n", eucledian_distance);

        lambda_new = eucledian_distance;

        if (fabs(lambda_new - lambda_previous) < 0.000001)
        {
            break;
        }

        lambda_previous = lambda_new;
        eucledian_distance = 0;

        for (i = 0; i < n; i++)
        {
            initial_eigen_vector[i][0] = new_eigen_vector[i][0];
        }
    }

    printf("%lf\n", eucledian_distance);

    for (i = 0; i < n; i++)
    {
        printf("%lf\n", new_eigen_vector[i][0]);
    }

    return 0;
}

