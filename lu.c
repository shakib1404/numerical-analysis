#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 3
#define EPS 0.1

int main(){
int i,j,k;
double sum;
double sol[max];
  double a[max][max]= { {7,-3,5}, {1,4,3}, {3,-2,6}};
  double u[max][max],l[max][max]={{1,0,0},{0,1,0},{0,0,1}};
  double final[max][max];
  double z,temp;

	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%4.2lf\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	/*for(i=0;i<max-1;i++){
		if(fabs(mat[i][i]<EPS)){
			for(j=i+1;j<max;j++){
				if(fabs(mat[j][i]<EPS)){
					for(k=i;k<max+1;k++){
						temp=mat[i][k];
						mat[i][k]=mat[j][k];
						mat[j][k]=temp;
					}
					break;
				}
			}
		}
	}*/


	for(i=0;i<max-1;i++){
		for(j=i+1;j<max;j++){
			z=a[j][i]/a[i][i];
			for(k=i;k<max;k++){
				a[j][k]=a[j][k]-z*a[i][k];
				l[j][i]=z;
			}
		}
	}

	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
		u[i][j]=a[i][j];
		}
	}

	printf("the u matrix-\n");
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%4.2lf\t",u[i][j]);
		}
		printf("\n");
	}
  printf("\n");

  printf("the l matrix-\n");
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%4.2lf\t",l[i][j]);
		}
		printf("\n");
	}
  printf("\n");

//multiplication

	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			sum=0;
				for(k=0;k<max;k++){
					sum=sum+(l[i][k]*u[k][j]);
				}
			final[i][j]=sum;

		}

	}

printf("the resultant matrix-\n");
	for(i=0;i<max;i++){
		for(j=0;j<max;j++){
			printf("%4.2lf\t",final[i][j]);
		}
		printf("\n");}



return 0;
}
