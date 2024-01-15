

#include <stdio.h>
#include <math.h>
#define MAX 3
#define EPS 0.1

int main (void) {
  int i, j, k, det=1;
  double x[MAX][MAX+1]= {{4,-3,1,-8},{-2,1,-3,-4},{1,-1,2,3}};
  double inv[MAX][2*MAX];
  double ratio,temp;

    //printing the given matrix
  for (i=0; i<MAX; i++ ){
    for (j=0; j<MAX+1; j++ )
      printf("%7.2lf "  ,x[i][j]);
    printf("\n");
  }
  printf("\n");

    //creating inv matrix
   for (i=0; i<MAX; i++ ){
    for (j=0; j<MAX; j++ )
      inv[i][j]=x[i][j];

  }

  for(i=0;i<MAX;i++){
      for(j=0;j<MAX;j++)
      {
           if(i==j)
           {
                inv[i][j+MAX] = 1;
           }
           else
           {
                inv[i][j+MAX] = 0;
           }
      }
 }

  for (i=0; i<MAX-1; i++ ) {
    if (fabs(x[i][i]) < EPS) {
      for (j=i+1; j<MAX; j++ ){
        if (fabs(x[j][i]) > EPS) {
          for (k=i; k<MAX+1; k++ )
          {
            temp = x[i][k];
            x[i][k] = x[j][k];
            x[j][k] = temp;
          }
          break;
        }
      }
    }

    for (j=i+1; j<MAX; j++ ){
      ratio = x[j][i]/x[i][i];
      for (k=i; k<MAX+1; k++ )
      {
        x[j][k] = x[j][k] - ratio * x[i][k];
      }
    }
  }

  for (i=0; i<MAX; i++ ){
    for (j=0; j<MAX+1; j++ )
      printf("%7.2lf "  ,x[i][j]);
    printf("\n");
  }
  printf("\n");

  // Back-substitution
    double solution[MAX];
    for (i = MAX - 1; i >= 0; i--) {
        solution[i] = x[i][MAX];
        for (j = i + 1; j < MAX; j++) {
            solution[i] -= x[i][j] * solution[j];
        }
        solution[i] /= x[i][i];
    }

    // Printing the result
    printf("Solution:\n");
    for (i = 0; i < MAX; i++) {
        printf("x%d = %7.2lf\n", i + 1, solution[i]);
    }



  printf("The determinant is : ");
  for(int i=0;i<MAX;i++) det*=x[i][i];
  printf("%d\n",det);

for(i=0;i<MAX;i++)
 {
      for(j=0;j<2*MAX;j++)
      {
        printf("%6.3lf\t",inv[i][j]);
      }
      printf("\n");
 }
 printf("\n\n\n");
   for(i=0;i<MAX;i++){
      for(j=0;j<MAX;j++){
           if(i!=j)
           {
                ratio = inv[j][i]/inv[i][i];
                for(k=0;k<2*MAX;k++)
                {
                    inv[j][k] = inv[j][k] - ratio*inv[i][k];
                }
           }
      }
 }
 /* Row Operation to Make Principal Diagonal to 1 */
 for(i=0;i<MAX;i++)
 {
      for(j=MAX;j<2*MAX;j++)
      {
        inv[i][j] = inv[i][j]/inv[i][i];
      }
 }
 /* Displaying Inverse Matrix */
 printf("\nInverse Matrix is:\n");
 for(i=0;i<MAX;i++)
 {
      for(j=MAX;j<2*MAX;j++)
      {
        printf("%6.3lf\t",inv[i][j]);
      }
      printf("\n");
 }

    return 0;
}

