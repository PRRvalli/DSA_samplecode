#include <bits/stdc++.h>
using namespace std;
int arr[1000]={0};

void insert_heap(int element,int pos){
	int temp,parent;
	parent=floor((pos+1)/2)-1;
	temp=pos;
	while(parent>0){
		if(arr[parent]>element){
			temp=parent;
			arr[pos]=arr[parent];
		}
		else{
			break;
			
		}
		parent=floor((temp+1)/2)-1;
	}
	arr[temp]=element;
}

int delete_heap(int pos){
	// pos: max array size is indexed from 0;
	int min_element,array_size,temp;
	int c1,c2; 
	min_element=arr[0];
	array_size=pos-1;
	temp=arr[pos];
	while(c1<=array_size){

	} 


}
int main(){
	int last,i;




	return 0;
}


