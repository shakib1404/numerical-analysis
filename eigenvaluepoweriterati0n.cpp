#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the matrix size: ";
    cin>>n;
    double matrix[n][n];
    double initial_eigen_vector[n][1];
    double new_eigen_vector[n][1],eucledian_distance=0,lambda_previous=1,lambda_new;
    cout<<"Enter the matrix:"<<endl;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }
    cout<<"Enter the initial eigen vector which is not zero:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>initial_eigen_vector[i][0];
    }
    while(1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<1;j++)
            {
                new_eigen_vector[i][j]=0;
                for(k=0;k<n;k++)
                {
                    new_eigen_vector[i][j]+=matrix[i][k]*initial_eigen_vector[k][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            eucledian_distance+=new_eigen_vector[i][0]*new_eigen_vector[i][0];
        }
        eucledian_distance=sqrt(eucledian_distance);
        for(i=0;i<n;i++)
        {
            new_eigen_vector[i][0]=new_eigen_vector[i][0]/eucledian_distance;
            cout<<new_eigen_vector[i][0]<<" ";
        }
        cout<<eucledian_distance<<endl;
        lambda_new=eucledian_distance;
        if(fabs(lambda_new-lambda_previous)<.000001)
        {
            break;
        }
        lambda_previous=lambda_new;
        eucledian_distance=0;
        for(i=0;i<n;i++)
        {
            initial_eigen_vector[i][0]=new_eigen_vector[i][0];
        }
    }
    cout<<eucledian_distance<<endl;
    for(i=0;i<n;i++)
    {
        cout<<new_eigen_vector[i][0]<<" "<<endl;
    }
}
