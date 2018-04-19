#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
using namespace std;

int max_fun(int a, int b){
	return(a>b)?a:b;
}

int knapsack(int Weight[], int Value[],int max_w,int n){
	//int n = sizeof(Value)/sizeof(Value[0]);
	int matrix[n+1][max_w+1]={0};
	int i,j;

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=max_w;j++)
		{
			if(i==0 || j==0)
				matrix[i][j]=0;

			else if(Weight[i-1] <= j){
				matrix[i][j]=max_fun(Value[i-1]+matrix[i-1][max_w-Weight[i-1]], matrix[i-1][j]);
				//K[i][w] = max_fun(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
			}
			else
				matrix[i][j]=matrix[i-1][j];				
		}
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=max_w;j++)
		{
			cout<<matrix[i][j]<<" ";

		}
	cout<<"\n";
	}
	//return 1;
	return matrix[n][max_w];
}

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w,j;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max_fun(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			cout<<K[i][j]<<" ";

		}
	cout<<"\n";
	}
   return K[n][W];
}



int main(){
	int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d\n", knapSack(W,wt,val,n));
    printf("%d\n", knapsack(wt,val,W,n));
	return 0;
}