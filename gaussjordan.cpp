#include<stdio.h>
#include<bits/stdc++.h>
#define Max 10

double x[Max];
int a[3][4]={{2,6,2,6},
              {4,9,2,8},
              {6,3,4,3}
};

float ratio;


 void gaussjordan()
 {
     for(int i=0;i<3;i++)
{


        for(int j=0;j<3;j++)
     {
         if(i!=j)
         {
              ratio=a[j][i]/a[i][i];


         for(int k=0;k<=3;k++)
         {
             a[j][k]=a[j][k]-a[i][k]*ratio;
         }
         }
     }
}

     for(int i=0;i<3;i++)
     {
         x[i]=a[i][3]/a[i][i];
         printf("%lf\n",x[i]);
     }



 }
int main()
{
    gaussjordan();

}
