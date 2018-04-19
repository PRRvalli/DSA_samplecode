#include <bits/stdc++.h>

using namespace std;

struct job
{   char num;
    int deadline;
    int profit;
    
};



void printJob(job j[]){
	for(int i=0;i<5;i++){
		cout<<"name: "<<j[i].num<<endl;
		cout<<"deadline: "<<j[i].deadline<<endl;
		cout<<"profit: "<<j[i].profit<<endl;
		cout<<endl;

	}
}

bool compareEnd(job a, job b){
    //job *p1 = (job *)a,  *p2 = (job *)b;
    return (a.profit > b.profit);
}  

int compareE(const void* a, const void* b)
{
    job *p1 = (job *)a,  *p2 = (job *)b;
    return (p1->profit - p2->profit);
}


void seq_interval(job j[],int n){
	bool seq[n];
	int count=0,profit=0,k,i;
	int set[n];

	for(i=0;i<n;i++){
		set[i]=-1;seq[i]=false;
	}

	for(i=0;i<n;i++){
		k=j[i].deadline;
		while(k>0){
			if(seq[k]==false){
				seq[k]=true;
				set[k]=i;
				count+=1;
				profit+=j[i].profit;
				break;
			}
			k--;
		}
	}

cout<<"Profit"<<profit<<endl;
for(i=0;i<n;i++){
	if(set[i]!=-1)
		cout<<j[set[i]].num<<"->";
	//cout<<set[i]<<" ";
}

}





int main(){
	int i;
	job J[]= { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},{'d', 1, 25}, {'e', 3, 15}};
	/*for(i=0;i<=5;i++){
		cin>>J[i].start;
		cin>>J[i].end;

	}*/
	int n=sizeof(J)/sizeof(J[0]);
	//cout<<n;
	//qsort(J, n, sizeof(job), compareE);
	sort(J,J+n,compareEnd);
	seq_interval(J,n);
	//printJob(J);



	return 0;
}
