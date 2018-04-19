#include <bits/stdc++.h>

using namespace std;

struct job
{
    int start;
    int end;
    
};



void printJob(job j[]){
	for(int i=0;i<=5;i++){
		cout<<"Start"<<j[i].start<<endl;
		cout<<"End"<<j[i].end<<endl;
		cout<<endl;

	}
}

bool compareEnd(job a, job b){
    //job *p1 = (job *)a,  *p2 = (job *)b;
    return (a.end < b.end);
}  

int compareE(const void* a, const void* b)
{
    job *p1 = (job *)a,  *p2 = (job *)b;
    return (p1->end - p2->end);
}

void seq_interval(job j[],int n){
	int prev,count=1;
	prev=j[0].end;
	cout<<"1."<<j[0].start<<" to "<<j[0].end<<endl;
	count+=1;
	for(int i=1;i<n;i++){
		if(j[i].start>=prev){
			cout<<count<<"."<<j[i].start<<" to "<<j[i].end<<endl;
			prev=j[i].end;
			count+=1;
		}

	}

	cout<<count<<endl;
}


int main(){
	int i;
	job J[]= {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
	/*for(i=0;i<=5;i++){
		cin>>J[i].start;
		cin>>J[i].end;

	}*/
	int n=sizeof(J)/sizeof(J[0]);
	cout<<n;
	//qsort(J, n, sizeof(job), compareE);
	sort(J,J+n,compareEnd);
	seq_interval(J,n);
	//printJob(J);



	return 0;
}
