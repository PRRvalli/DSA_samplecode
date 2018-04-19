#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
using namespace std;

/******************************
Structures are used here 
insert_heap(element,position)
	position is length of array  
delete_heap(length)
	length of the array
build_heap(length)
 	builds heap 
*******************************/

struct ARRAY
{
    int value;
    int arr_num;
    
};
struct ARRAY arr[1000]={0};
int curSize=0;

void print_heap(int length){
	for(int i=1;i<=length;i++)
		cout<<arr[i].value<<" ";
	cout<<"done \n";	

}

int minChild(int pos){

    if((2*pos+1)>curSize)
        return (2*pos);
    else{
            if(arr[2*pos].value<arr[2*pos+1].value)
              return (2*pos);
            else
              return (2*pos+1);
      }

}


void percolate_up(int pos){
    // i can still find the element from "pos" 
    int parent,temp;
    temp=arr[pos].value;
    parent=floor(pos/2);
    if(parent>0){
        if(arr[pos].value<arr[parent].value){
            arr[pos].value=arr[parent].value;
            arr[parent].value=temp;

            percolate_up(parent);
        }
    }

    /*
    if(arr[pos]<arr[parent]){
        arr[pos]=arr[parent];
        if(parent>1)
            percolate_up(pos);
        else
            arr[parent]=element;     
    }
    else 
        arr[pos]=element;

   */     
}

void percolate_down(int pos){
    // only if it has child it will come to this method

    int temp,m;
    temp=arr[pos].value;
    if((2*pos)<=curSize){


        m=minChild(pos);
        if(temp>arr[m].value){
            arr[pos].value=arr[m].value;
            arr[m].value=temp;
            percolate_down(m);
        }
        

    
        
    }
    

    

}



void insert_heap(int element){
    curSize+=1;
    arr[curSize].value=element;
    arr[curSize].arr_num=1;
    cout<<"element"<<element<<"\n";
    //cout<<"Current size"<<curSize<<"\n";
    percolate_up(curSize);
        
    
}
int findMin(){
    return arr[1].value;
}

int delete_min(){
    // pos: max array size is indexed from 0;
    int m;
    m=findMin();
    arr[1].value=arr[curSize].value;
    curSize-=1;
    //cout<<"Current size"<<curSize<<"\n";
    percolate_down(1);
	return m;

}

void build_heap(int arr_list[],int num){
    // add all the elements to the array
    // now run this build heap for loop
    for(int iter=0;iter < num;iter++){
        curSize+=1;
        arr[curSize].value=arr_list[iter];
        arr[curSize].arr_num=1;
        //print_heap(curSize);
    }

    int i;
    for(i=floor(curSize/2);i>0;i--) {
        percolate_down(i);
        //print_heap(curSize);

    }
    print_heap(curSize);
}

void movedown(int pos, int x){
    int left,right;
    if(arr[pos].value < x){
        cout<<arr[pos].value<<" ";
        left=2*pos;
        right=2*pos + 1;
        if((left<=curSize)&&(arr[left].value < x)){
            movedown(left, x);
        }
        if((right<=curSize)&&(arr[right].value < x)){
            movedown(right,x);
        }
    }



}



int main(){
    int length,i,arr_list[50]={0};
    length=0;
    //arr_list[16]={16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	for(i=50;i>0;i--){
	
	//length+=1;
	//insert_heap(i);
	//print_heap(length);
	arr_list[50-i]=i;
	}
    build_heap(arr_list,50);
	i=1;
	/*for(i=1;i<=50;i++){
	
	//length=16;
	cout<<""<<delete_min()<<" ";
	length=length-1;
	//print_heap(curSize);
	
	
	}*/
    cout<<"print the order\n";
    movedown(1, 16);


    return 0;
}

