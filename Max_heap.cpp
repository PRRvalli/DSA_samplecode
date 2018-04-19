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
struct ARRAY Arr[1000]={0};
int curSize=0;
int max_heap=-1;

void print_heap(int length){
	cout<<"current size:"<<curSize<<endl; 
    for(int i=1;i<=length;i++)
		cout<<Arr[i].value<<" ";
	cout<<"\n";	

}

int maxChild(int pos){

    if((2*pos+1)>curSize)
        return (2*pos);
    else{
            if(Arr[2*pos].value>Arr[2*pos+1].value)
              return (2*pos);
            else
              return (2*pos+1);
      }

}


void percolate_up(int pos){
    // i can still find the element from "pos" 
    int parent,temp;
    temp=Arr[pos].value;
    parent=floor(pos/2);
    if(parent>0){
        if(Arr[pos].value>Arr[parent].value){
            Arr[pos].value=Arr[parent].value;
            Arr[parent].value=temp;

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
    temp=Arr[pos].value;
    if((2*pos)<=curSize){

        m=maxChild(pos);
        if(temp<Arr[m].value){
            Arr[pos].value=Arr[m].value;
            Arr[m].value=temp;
            percolate_down(m);
        } 
    }
}



void insert_heap(int element){
    curSize+=1;
    Arr[curSize].value=element;
    Arr[curSize].arr_num=1;
    //cout<<"element"<<element<<"\n";
    //cout<<"Current size"<<curSize<<"\n";
    percolate_up(curSize);
        
    
}
int findMax(){
    return Arr[1].value;
}

int delete_max(){
    // pos: max array size is indexed from 0;
    int m;
    m=findMax();
    Arr[1].value=Arr[curSize].value;
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
        Arr[curSize].value=arr_list[iter];
        Arr[curSize].arr_num=1;
        //print_heap(curSize);
    }

    int i;
    for(i=floor(curSize/2);i>0;i--) {
        percolate_down(i);
        //print_heap(curSize);

    }
    print_heap(curSize);
}

/*
void movedown(int pos, int x){
    // not sure what this move down does
    int left,right;
    if(arr[pos].value < x){
        cout<<arr[pos].value<<" ";
        left=2*pos;
        right=2*pos + 1;
        if((left<=curSize)&&(arr[left].value > x)){
            movedown(left, x);
        }
        if((right<=curSize)&&(arr[right].value > x)){
            movedown(right,x);
        }
    }



}

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

int main(){
    // arr_list being the input list 
    int length,i,k,arr_list[50]={0};

    
    k=10;  // this should be the size of the heap
    int result[k]={0};
	for(i=1;i<=20;i++){
	
    	arr_list[i]=genRand(0,100);
        if(curSize < k){
            insert_heap(arr_list[i]);
            print_heap(curSize);
                }
        else if(curSize==k){
            if(arr_list[i]<findMax()){
               Arr[1].value=arr_list[i];
               percolate_down(1);
               print_heap(curSize);
            }

            }
        else 
            cout<<"ERROR";    
	}

    for(i=0;i<k;i++){
        result[k-1-i]=findMax();
        
        delete_max();
    }
    for(i=0;i<k;i++){
        
        cout<<result[i]<<" ";
        
    }
    return 0;
}

