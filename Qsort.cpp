#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
using namespace std;



/*struct node 
{
  int data;
  struct node *left;
  struct node *right;
};
*/
// Quick sort 
int genRand(int lower, int high){
	static bool first = true;
   if ( first ) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
	return (lower + (rand()%(high-lower+1)));
	//25 + ( std::rand() % ( 63 - 25 + 1 ) )
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}
void print_array(int arr[],int start,int en){
	for(int i=start;i<=en;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";	

}
int partition(int arr[], int lower, int high){
	// generate random pivot
	int pivot,i,pos,j;
	pos=genRand(lower,high);
	//cout<<"pos"<<pos<<endl;
	pivot=arr[pos];
	//cout<<"pivot"<<pivot<<endl;
	swap(arr[pos],arr[high]);
	//print_array(arr,lower,high);
	j=lower-1;
	for(i=lower;i<=high-1;i++){
		if(arr[i]<=pivot){
			j=j+1;
			//cout<<arr[i]<<" "<<arr[j]<<" "<<i<<" "<<j<<endl;
			swap(arr[i],arr[j]);
			//print_array(arr,lower,high);

		}
		

	}
	swap(arr[j+1],arr[high]);
	//cout<<"end"<<endl;
	//print_array(arr,lower,high);
	return j+1;

}


void quickSort(int arr[], int low, int high){
	int pi;
	if(low<high){
		pi = partition(arr, low, high);
		
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);

	}

}

int findpivort(int arr[], int low, int high, int middle){
	// returns the middle element

	int pi;

	
		pi = partition(arr, low, high);
		if(pi==middle){
			//cout<<"here\n";
			//quickSort(arr,low,pi);
			return pi;
		}
		else if(pi>middle)
			findpivort(arr, low, pi-1,middle);
		else if(pi<middle)
			findpivort(arr, pi+1, high,middle);
		else
			cout<<"error";
		

	

}

int main(){
	int A[] = {-2,-5,7,1,0,10,8,9,4,12,15,-11};
	int k=4,pi;
	//for(int i=0;i<k;i++)
	//	cout<<"found: "<<findpivort(A,0,10,i)<<endl;
	pi=findpivort(A,0,11,k-1);
	//cout<<"pivot"<<A[pi]<<endl;
	print_array(A,0,k-1);
	quickSort(A,0,pi-1);

	print_array(A,0,k-1);
	return 0;
}
