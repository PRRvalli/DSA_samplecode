#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
using namespace std;
/*struct ARRAY
{
    int value;
    //int arr_num;
    
};
struct ARRAY arr[1000]={0};
*/
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

void print_array(int start,int en){
	for(int i=start;i<=en;i++)
		cout<<arr[i].value<<" ";
	cout<<"\n";	

}

void kmin(int k,int n){
	int min,pos;
	
	//int min=FLT_MAX;

	for(int i=0; i<n-1;i++){
		if(i<k){
		min=arr[i].value;
		for(int j=i+1;j<n;j++){
			if(arr[j].value<min){
				min=arr[j].value;
				pos=j;
			}
		}
		swap(arr[i].value,arr[pos].value);
	}
}
}


int main(){
	int i,A[1000]={0};
	int value=20;
	int k;
	// value will be n - total number of elements
	k=7;
	for(i=1;i<=value;i++){
	
	arr[value-i].value=genRand((20+i*2), (50+i*3));
	}
	cout<<endl;
	print_array(0,value-1);
	kmin(k,value);
	print_array(0,value-1);
	print_array(0,k-1);

	return 0;
}